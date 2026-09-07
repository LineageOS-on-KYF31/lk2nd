/* Copyright (c) 2014-2015, 2017-2018, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of The Linux Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <debug.h>
#include <smem.h>
#include <err.h>
#include <msm_panel.h>
#include <mipi_dsi.h>
#include <pm8x41.h>
#include <pm8x41_wled.h>
#include <board.h>
#include <mdp3.h>
#include <scm.h>
#include <platform/clock.h>
#include <platform/gpio.h>
#include <platform/iomap.h>
#include <platform/timer.h>
#include <target/display.h>
#include <regulator.h>
#include <i2c_qup.h>
#include <blsp_qup.h>
#include <mipi_dsi_i2c.h>
#include "spmi.h"

#include "target/led.h"

#include "include/panel.h"
#include "include/display_resource.h"
#include "gcdb_display.h"

#define VCO_DELAY_USEC 1000
#define GPIO_STATE_LOW 0
#define GPIO_STATE_HIGH 2
#define RESET_GPIO_SEQ_LEN 3
#define PWM_DUTY_US 13
#define PWM_PERIOD_US 27
#define PM8916_VER 0x20000

/*---------------------------------------------------------------------------*/
/* GPIO configuration                                                        */
/*---------------------------------------------------------------------------*/
/*pin_source, pin_id, pin_strength, pin_direction, pin_pull, pin_state*/
static struct gpio_pin reset_gpio = {
  "msmgpio", 2, 3, 1, 0, 1
};

static struct gpio_pin enable_gpio = {
  "msmgpio", 97, 3, 1, 0, 1
};

static struct gpio_pin bkl_gpio = {
  "msmgpio", 37, 3, 1, 0, 1
};

static struct gpio_pin spi_bkl_gpio = {
	"msmgpio", 60, 3, 1, 0, 1
};

static struct gpio_pin bob_gpio = {
  "pm8941_gpios", 12, 2, 1, 0, 1
};
static bool display_efuse = false;

static void mdss_dsi_uniphy_pll_sw_reset_8909(uint32_t pll_base)
{
	writel(0x01, pll_base + 0x0068); /* PLL TEST CFG */
	mdelay(1);
	writel(0x00, pll_base + 0x0068); /* PLL TEST CFG */
	mdelay(1);
}

static void dsi_pll_toggle_lock_detect_8909(uint32_t pll_base)
{
	writel(0x04, pll_base + 0x0064); /* LKDetect CFG2 */
	udelay(1);
	writel(0x05, pll_base + 0x0064); /* LKDetect CFG2 */
	udelay(512);
}

static void dsi_pll_sw_reset_8909(uint32_t pll_base)
{
	writel(0x01, pll_base + 0x0068); /* PLL TEST CFG */
	udelay(1);
	writel(0x00, pll_base + 0x0068); /* PLL TEST CFG */
}

static uint32_t dsi_pll_enable_seq_1_8909(uint32_t pll_base)
{
	uint32_t rc;

	dsi_pll_sw_reset_8909(pll_base);
	/*
	 * Add hardware recommended delays between register writes for
	 * the updates to take effect. These delays are necessary for the
	 * PLL to successfully lock
	 */

	writel(0x34, pll_base + 0x0070); /* CAL CFG1*/
	writel(0x01, pll_base + 0x0020); /* GLB CFG */
	writel(0x05, pll_base + 0x0020); /* GLB CFG */
	writel(0x0f, pll_base + 0x0020); /* GLB CFG */
	udelay(500);

	dsi_pll_toggle_lock_detect_8909(pll_base);
	rc = readl(pll_base + 0x00c0) & 0x01;

	return rc;
}

static uint32_t dsi_pll_enable_seq_2_8909(uint32_t pll_base)
{
	uint32_t rc;

	dsi_pll_sw_reset_8909(pll_base);

	/*
	 * Add hardware recommended delays between register writes for
	 * the updates to take effect. These delays are necessary for the
	 * PLL to successfully lock
	 */
	writel(0x14, pll_base + 0x0070); /* CAL CFG1*/
	writel(0x01, pll_base + 0x0020); /* GLB CFG */
	writel(0x05, pll_base + 0x0020); /* GLB CFG */
	udelay(3);
	writel(0x0f, pll_base + 0x0020); /* GLB CFG */
	udelay(500);

	dsi_pll_toggle_lock_detect_8909(pll_base);
	rc = readl(pll_base + 0x00c0) & 0x01;

	return rc;
}

static uint32_t dsi_pll_enable_seq_3_8909(uint32_t pll_base)
{
	uint32_t rc;

	dsi_pll_sw_reset_8909(pll_base);

	/*
	 * Add hardware recommended delays between register writes for
	 * the updates to take effect. These delays are necessary for the
	 * PLL to successfully lock
	 */
	writel(0x04, pll_base + 0x0070); /* CAL CFG1*/
	writel(0x01, pll_base + 0x0020); /* GLB CFG */
	writel(0x05, pll_base + 0x0020); /* GLB CFG */
	udelay(3);
	writel(0x0f, pll_base + 0x0020); /* GLB CFG */
	udelay(500);

	dsi_pll_toggle_lock_detect_8909(pll_base);
	rc = readl(pll_base + 0x00c0) & 0x01;

	return rc;
}

static uint32_t dsi_pll_enable_seq_8909(uint32_t pll_base)
{
	uint32_t pll_locked = 0;
	uint32_t counter = 0;

	do {
		pll_locked = dsi_pll_enable_seq_1_8909(pll_base);

		dprintf(SPEW, "TSMC pll locked status is %d\n", pll_locked);
		++counter;
	} while (!pll_locked && (counter < 3));

	if (!pll_locked) {
		counter = 0;
		do {
			pll_locked = dsi_pll_enable_seq_2_8909(pll_base);

			dprintf(SPEW, "GF P1 pll locked status is %d\n",
				pll_locked);
			++counter;
		} while (!pll_locked && (counter < 3));
	}

	if (!pll_locked) {
		counter = 0;
		do {
			pll_locked = dsi_pll_enable_seq_3_8909(pll_base);

			dprintf(SPEW, "GF P2 pll locked status is %d\n",
				pll_locked);
			++counter;
		} while (!pll_locked && (counter < 3));
	}

	return pll_locked;
}

#define LV5216_I2C_SLAVE_ADDR   0x74
#define BL_GPIO_EN              0   /* GPIO used to enable the backlight IC */

static struct qup_i2c_dev *lv5216_i2c_dev = NULL;
static uint8_t lv5216_initialized = 0;

/* Register/value pairs written on init */
struct lv5216_reg lv5216_init_regs[] = {
    { 0x01, 0x00 }, { 0x02, 0x08 }, { 0x03, 0x48 }, { 0x06, 0x0A },
    { 0x07, 0x08 }, { 0x08, 0x0A }, { 0x09, 0x9F }, { 0x0A, 0x02 },
    { 0x0B, 0x80 }, { 0x0C, 0x00 }, { 0x0D, 0x00 }, { 0x0E, 0x00 },
    { 0x0F, 0x00 }, { 0x10, 0x00 }, { 0x11, 0x00 }, { 0x12, 0x00 },
    { 0x13, 0x00 }, { 0x14, 0x07 }, { 0x16, 0x07 }, { 0x17, 0x07 },
    { 0x18, 0x07 }, { 0x19, 0x07 }, { 0x1A, 0x1F }, { 0x1B, 0x1F },
    { 0x1C, 0x1F }, { 0x1D, 0x1F }, { 0x1E, 0x1F }, { 0x1F, 0x37 },
    { 0x20, 0x47 }, { 0x21, 0x47 }, { 0x22, 0x67 }, { 0x23, 0x67 },
    { 0x24, 0x67 }, { 0x25, 0x67 }, { 0x26, 0xAA }, { 0x27, 0xB8 },
    { 0x00, 0x81 }  /* Power Reg */
};
#define LV5216_INIT_COUNT (sizeof(lv5216_init_regs) / sizeof(lv5216_init_regs[0]))

struct lv5216_reg lv5216_backlight_on[]  = { { 0x01, 0x1F } };
struct lv5216_reg lv5216_backlight_off[] = { { 0x01, 0x00 } };

/*
 * Sends `count` register/value pairs over I2C to the LV5216.
 * Returns 1 on success, 0 on failure.
 */
int lv5216_send(struct lv5216_reg *buf, int count)
{
    int i;
    int retries;
    int ret;
    struct i2c_msg msg;
    uint8_t payload[2];

    for (i = 0; i < count; i++) {
        payload[0] = buf[i].reg;
        payload[1] = buf[i].val;

        msg.addr  = LV5216_I2C_SLAVE_ADDR;
        msg.flags = 0;
        msg.len   = 2;
        msg.buf   = payload;

        retries = 5;
        do {
            ret = qup_i2c_xfer(lv5216_i2c_dev, &msg, 1);
            if (ret == 1)
                break;
            retries--;
        } while (retries > 0);

        if (retries == 0)
            return 0;
    }

    return 1;
}

int lv5216_init(void)
{
    if (lv5216_initialized)
        return 0;

    gpio_tlmm_config(0, 0, 1, 0, 0, 1);
    gpio_set(0, 0);
    udelay(50);
    gpio_set(0, 2);
    udelay(50);

    if (!lv5216_i2c_dev) {
        lv5216_i2c_dev = qup_blsp_i2c_init(BLSP_ID_1, QUP_ID_0,
                                            340000,
                                            19200000);
        if (lv5216_i2c_dev == NULL)
            return -1;
    }

    if (!lv5216_send(lv5216_init_regs, LV5216_INIT_COUNT))
        return -1;

    udelay(2000);
    lv5216_initialized = 1;
    return 0;
}

/*
 * Matches the prototype in gcdb_display.h:
 * int target_backlight_ctrl(struct backlight *bl, uint8_t enable);
 */
int target_backlight_ctrl(struct backlight *bl, uint8_t enable)
{
	int ret;
	struct lv5216_reg *cmd;


	if (bl->bl_interface_type == BL_DCS)
		return 0;
	
	dprintf(CRITICAL, "backlight ctrl: enable=%d\n", enable);
	/* Run initialization sequence first */
	ret = lv5216_init();
	if (ret != 0) {
		dprintf(CRITICAL, "lv5216: Initialization failed, skipping backlight ctrl\n");
		return -1;
	}

	/* Select payload based on state */
	if (enable) {
		cmd = lv5216_backlight_on;
	} else {
		cmd = lv5216_backlight_off;
	}
	dprintf(CRITICAL, "sending lv5216_backlight_on\n");
	/* Send single (size 1) command over I2C */
	ret = lv5216_send(cmd, 1);
	if (ret == 0) {
		dprintf(CRITICAL, "lv5216: Failed to send backlight %s command\n", 
		        enable ? "ON" : "OFF");
	}
	dprintf(CRITICAL, "sent lv5216_backlight_on\n");
	return 0;
}

int target_panel_clock(uint8_t enable, struct msm_panel_info *pinfo)
{
	int32_t ret = 0;
	struct mdss_dsi_pll_config *pll_data;
	dprintf(SPEW, "target_panel_clock\n");

	pll_data = pinfo->mipi.dsi_pll_config;
	pll_data->vco_delay = VCO_DELAY_USEC;

	if (enable) {
		mdp_gdsc_ctrl(enable);
		mdss_bus_clocks_enable();
		mdp_clock_enable();

		/*
		 * Enable auto functional gating
		 * on DSI CMD AXI fetch from DDR
		 */
		writel(0x3fbff, MDP_CGC_EN);
		ret = restore_secure_cfg(SECURE_DEVICE_MDSS);
		if (ret) {
			dprintf(CRITICAL,
				"%s: Failed to restore MDP security configs",
				__func__);
			mdp_clock_disable();
			mdss_bus_clocks_disable();
			mdp_gdsc_ctrl(0);
			return ret;
		}
		mdss_dsi_uniphy_pll_sw_reset_8909(pinfo->mipi.pll_base);
		mdss_dsi_auto_pll_config(pinfo->mipi.pll_base,
						pinfo->mipi.ctl_base, pll_data);
		if (!dsi_pll_enable_seq_8909(pinfo->mipi.pll_base))
			dprintf(CRITICAL, "Not able to enable the pll\n");
		gcc_dsi_clocks_enable(pll_data->pclk_m,
				pll_data->pclk_n,
				pll_data->pclk_d);
	} else if(!target_cont_splash_screen()) {
		gcc_dsi_clocks_disable();
		mdp_clock_disable();
		mdss_bus_clocks_disable();
		mdp_gdsc_ctrl(enable);
	}

	return 0;
}

void target_tp_gpio_ctrl(int enable)
{
    dprintf(SPEW, "%s(%d)\n", __func__, enable);

    if (enable) {
        mdelay(1);
        gpio_tlmm_config(18, 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_2MA, GPIO_DISABLE);
        gpio_tlmm_config(19,   0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_2MA, GPIO_DISABLE);
    }
}

int target_panel_reset(uint8_t enable, struct panel_reset_sequence *resetseq,
						struct msm_panel_info *pinfo)
{
	int ret = NO_ERROR;
	uint32_t bob_pmic_gpio = bob_gpio.pin_id;
	uint32_t hw_id = board_hardware_id();
	uint32_t hw_subtype = board_hardware_subtype();
	uint32_t platform = board_platform_id();

	if (((HW_PLATFORM_SUBTYPE_8909_PM660 == hw_subtype) ||
		(HW_PLATFORM_SUBTYPE_8909_PM660_V1 == hw_subtype) ||
		(HW_PLATFORM_SUBTYPE_8909_COMPAL_ALPHA == hw_subtype)) &&
		((MSM8909W == platform) || (APQ8009W == platform)) &&
		(HW_PLATFORM_MTP == hw_id)) {
		struct pm8x41_gpio bobgpio_param = {
			.direction = PM_GPIO_DIR_OUT,
			.vin_sel = 0,
			.out_strength = PM_GPIO_OUT_DRIVE_MED,
			.function = PM_GPIO_FUNC_HIGH,
			.pull = PM_GPIO_PULLDOWN_10,
			.inv_int_pol = PM_GPIO_INVERT,
		};

		pm8x41_gpio_config(bob_pmic_gpio, &bobgpio_param);
		enable_gpio.pin_id = 59;
	}

	target_tp_gpio_ctrl(enable);
	if (enable) {
		if (pinfo->mipi.use_enable_gpio) {
			gpio_tlmm_config(enable_gpio.pin_id, 0,
				enable_gpio.pin_direction, enable_gpio.pin_pull,
				enable_gpio.pin_strength,
				enable_gpio.pin_state);

			gpio_set(enable_gpio.pin_id, 2);
		}

		gpio_tlmm_config(reset_gpio.pin_id, 0,
				reset_gpio.pin_direction, reset_gpio.pin_pull,
				reset_gpio.pin_strength, reset_gpio.pin_state);

		gpio_set(reset_gpio.pin_id, 2);

		/* reset */
		for (int i = 0; i < RESET_GPIO_SEQ_LEN; i++) {
			if (resetseq->pin_state[i] == GPIO_STATE_LOW)
				gpio_set(reset_gpio.pin_id, GPIO_STATE_LOW);
			else
				gpio_set(reset_gpio.pin_id, GPIO_STATE_HIGH);
			mdelay(resetseq->sleep[i]);
		}
	} else if(!target_cont_splash_screen()) {
		gpio_set(reset_gpio.pin_id, 0);
		if (pinfo->mipi.use_enable_gpio)
			gpio_set(enable_gpio.pin_id, 0);
	}

	return ret;
}

#define TP_LDO_BASE  0xC300
void target_tp_ldo_ctrl(int enable)
{
    dprintf(SPEW, "%s(%d)\n", __func__, enable);

    if (enable) {
        /* Disable LDO4 (Bit 7 of EN_CTL at 0xC346) before reconfiguring */
        pmic_spmi_reg_mask_write(TP_LDO_BASE + 0x46, 0x80, 0x00);

        /* Program Touch Panel LDO settings directly */
        pmic_spmi_reg_write(TP_LDO_BASE + 0x40, 0x11); /* MODE: Active / Pin Control */
        pmic_spmi_reg_write(TP_LDO_BASE + 0x42, 0x05); /* VSET_UB (Voltage Upper Byte) */
        pmic_spmi_reg_write(TP_LDO_BASE + 0x41, 0x03); /* VSET_LB (Voltage Lower Byte) */
        pmic_spmi_reg_write(TP_LDO_BASE + 0x45, 0x01); /* PIN_CTL: Hardware enable   */

        /* Enable LDO4 output (Set Bit 7) */
        pmic_spmi_reg_mask_write(TP_LDO_BASE + 0x46, 0x80, 0x80);
    }

    /* Allow Touch Panel power rail to stabilize */
    mdelay(5);
}

int target_ldo_ctrl(uint8_t enable, struct msm_panel_info *pinfo)
{
	uint32_t hw_id = board_hardware_id();
	uint32_t hw_subtype = board_hardware_subtype();
	uint32_t platform = board_platform_id();

	target_tp_ldo_ctrl(enable);
	if (enable) {
		if (((HW_PLATFORM_SUBTYPE_8909_PM660 == hw_subtype) ||
			(HW_PLATFORM_SUBTYPE_8909_PM660_V1 == hw_subtype) ||
			(HW_PLATFORM_SUBTYPE_8909_COMPAL_ALPHA == hw_subtype)) &&
			((MSM8909W == platform) || (APQ8009W == platform)) &&
			(HW_PLATFORM_MTP == hw_id))
			regulator_enable(REG_LDO12 | REG_LDO5 | REG_LDO11 | REG_LDO18);
		else if (pinfo->type == SPI_PANEL)
		{
			regulator_enable(REG_LDO11 | REG_LDO18);
		}
		else
			regulator_enable(REG_LDO2 | REG_LDO15 | REG_LDO17);
	}

	return NO_ERROR;
}
int target_dsi_phy_config(struct mdss_dsi_phy_ctrl *phy_db)
{
	memcpy(phy_db->regulator, panel_regulator_settings, REGULATOR_SIZE);
	memcpy(phy_db->ctrl, panel_physical_ctrl, PHYSICAL_SIZE);
	memcpy(phy_db->strength, panel_strength_ctrl, STRENGTH_SIZE);
	memcpy(phy_db->bistCtrl, panel_bist_ctrl, BIST_SIZE);
	memcpy(phy_db->laneCfg, panel_lane_config, LANE_SIZE);
	return NO_ERROR;
}

static bool target_splash_disable(void)
{
	uint32_t hw_id = board_hardware_id();
	uint32_t platform_subtype = board_hardware_subtype();
	uint32_t platform = board_platform_id();

	if ((APQ8009 == platform) &&
		(((HW_PLATFORM_MTP == hw_id) &&
		  (HW_PLATFORM_SUBTYPE_DSDA2 == platform_subtype)) ||
		 ((HW_PLATFORM_RCM == hw_id) &&
		 ((HW_PLATFORM_SUBTYPE_SAP == platform_subtype)||
		  (HW_PLATFORM_SUBTYPE_SAP_NOPMI == platform_subtype))) ||
		 ((HW_PLATFORM_MTP == hw_id) &&
		 (HW_PLATFORM_SUBTYPE_INTRINSIC_SOM == platform_subtype)))) {
		dprintf(INFO, "Splash disabled\n");
		return true;
	} else {
		return false;
	}
}

bool is_display_disabled(void)
{
	return display_efuse;
}

bool display_efuse_check(void)
{
	unsigned int i;
	uint32_t efuse = 0;
	uint32_t board_id = board_platform_id();

	for (i = 0; i < ARRAY_SIZE(efuse_data);i++)
		if (board_id == efuse_data[i].board_id) {
			efuse = readl((efuse_data[i].start_address + efuse_data[i].offset));
			display_efuse = (efuse & (efuse_data[i].mask)) >> (efuse_data[i].shift);
	}

	dprintf(INFO,"Efuse register: display disable flag = %d\n",display_efuse);
	return display_efuse;
}

void efuse_display_enable(char *pbuf, uint16_t buf_size)
{
	char *default_str;
	int prefix_display_len = strlen(pbuf);
	if (display_efuse)
		default_str = ";display_disabled:1";
	pbuf += prefix_display_len;
	buf_size -= prefix_display_len;
	strlcpy(pbuf, default_str, buf_size);
}

bool target_display_panel_node(char *pbuf, uint16_t buf_size)
{
	int ret = true;

	if (!target_splash_disable())
		ret = gcdb_display_cmdline_arg(pbuf, buf_size);

	if (display_efuse_check()){
                if (target_splash_disable()){
                        strlcpy(pbuf, DISPLAY_CMDLINE_PREFIX, buf_size);
                        efuse_display_enable(pbuf, buf_size);
                } else
                        efuse_display_enable(pbuf, buf_size);
        }

	return ret;
}

void target_display_init(const char *panel_name)
{
	uint32_t panel_loop = 0;
	int ret = 0;
	struct oem_panel_data oem;

	if (display_efuse_check())
		return;

	set_panel_cmd_string(panel_name);
	oem = mdss_dsi_get_oem_data();

	if (!strcmp(oem.panel, NO_PANEL_CONFIG)
		|| !strcmp(oem.panel, SIM_VIDEO_PANEL)
		|| !strcmp(oem.panel, SIM_CMD_PANEL)
		|| oem.skip) {
		dprintf(INFO, "Selected %s: Skip panel configuration\n",
				oem.panel);
		return;
	}

	if (target_splash_disable())
		return;

	do {
		target_force_cont_splash_disable(false);
		ret = gcdb_display_init(oem.panel, MDP_REV_305, (void *)MIPI_FB_ADDR);
		if (!ret || ret == ERR_NOT_SUPPORTED) {
			break;
		} else {
			target_force_cont_splash_disable(true);
			msm_display_off();
		}
	} while (++panel_loop <= oem_panel_max_auto_detect_panels());

	if (!oem.cont_splash) {
		dprintf(INFO, "Forcing continuous splash disable\n");
		target_force_cont_splash_disable(true);
	}
}

void target_display_shutdown(void)
{
	gcdb_display_shutdown();
}
