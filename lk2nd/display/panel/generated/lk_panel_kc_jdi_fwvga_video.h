// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2014, The Linux Foundation. All rights reserved. (FIXME)

#ifndef _PANEL_KC_JDI_FWVGA_VIDEO_H_
#define _PANEL_KC_JDI_FWVGA_VIDEO_H_

#include <mipi_dsi.h>
#include <panel_display.h>
#include <panel.h>
#include <string.h>

static struct panel_config kc_jdi_fwvga_video_panel_data = {
	.panel_node_id = "qcom,mdss_dsi_kc_jdi_fwvga_video",
	.panel_controller = "dsi:0:",
	.panel_compatible = "qcom,mdss-dsi-panel",
	.panel_type = 0,
	.panel_destination = "DISPLAY_1",
	/* .panel_orientation not supported yet */
	.panel_framerate = 60,
	.panel_lp11_init = 0,
	.panel_init_delay = 0,
};

static struct panel_resolution kc_jdi_fwvga_video_panel_res = {
	.panel_width = 480,
	.panel_height = 854,
	.hfront_porch = 64,
	.hback_porch = 52,
	.hpulse_width = 4,
	.hsync_skew = 0,
	.vfront_porch = 6,
	.vback_porch = 3,
	.vpulse_width = 1,
	/* Borders not supported yet */
};

static struct color_info kc_jdi_fwvga_video_color = {
	.color_format = 24,
	.color_order = DSI_RGB_SWAP_RGB,
	.underflow_color = 0xff,
	/* Borders and pixel packing not supported yet */
};

static char kc_jdi_fwvga_video_on_cmd_0[] = {
	0x01, 0x00, 0x05, 0x80
};
static char kc_jdi_fwvga_video_on_cmd_1[] = {
	0x36, 0xc0, 0x15, 0x80
};
static char kc_jdi_fwvga_video_on_cmd_2[] = {
	0x3a, 0x70, 0x15, 0x80
};
static char kc_jdi_fwvga_video_on_cmd_3[] = {
	0xb0, 0x04, 0x23, 0x80
};
static char kc_jdi_fwvga_video_on_cmd_4[] = {
	0x03, 0x00, 0x29, 0xc0, 0xb3, 0x00, 0x80, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_5[] = {
	0x03, 0x00, 0x29, 0xc0, 0xb6, 0x32, 0x83, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_6[] = {
	0x17, 0x00, 0x29, 0xc0, 0xb8, 0x01, 0x07, 0x0b,
	0xff, 0xff, 0xe4, 0xd4, 0x0f, 0x0f, 0x18, 0x18,
	0x90, 0x90, 0x00, 0x02, 0x0c, 0x1d, 0x37, 0x5a,
	0x87, 0xbe, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_7[] = {
	0x05, 0x00, 0x29, 0xc0, 0xb9, 0x01, 0xff, 0x00,
	0x08, 0xff, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_8[] = {
	0x07, 0x00, 0x29, 0xc0, 0xc0, 0x01, 0x56, 0x65,
	0x00, 0x00, 0x00, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_9[] = {
	0x06, 0x00, 0x29, 0xc0, 0xc1, 0x00, 0x10, 0x00,
	0x01, 0x12, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_10[] = {
	0x03, 0x00, 0x29, 0xc0, 0xc3, 0x00, 0x05, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_11[] = {
	0x02, 0x00, 0x29, 0xc0, 0xc4, 0x03, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_12[] = {
	0x0f, 0x00, 0x29, 0xc0, 0xc5, 0x40, 0x01, 0x06,
	0x01, 0x76, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1e,
	0x04, 0x00, 0x00, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_13[] = {
	0x0d, 0x00, 0x29, 0xc0, 0xc8, 0x0d, 0x1b, 0x19,
	0x1c, 0x20, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xff, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_14[] = {
	0x0d, 0x00, 0x29, 0xc0, 0xc9, 0x0d, 0x1f, 0x1f,
	0x1e, 0x22, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xff, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_15[] = {
	0x0d, 0x00, 0x29, 0xc0, 0xca, 0xcd, 0x54, 0x4e,
	0x0f, 0x17, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xff, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_16[] = {
	0x05, 0x00, 0x29, 0xc0, 0xd0, 0x22, 0x24, 0xa3,
	0xb8, 0xff, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_17[] = {
	0x06, 0x00, 0x29, 0xc0, 0xd1, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_18[] = {
	0x03, 0x00, 0x29, 0xc0, 0xd2, 0xb3, 0x00, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_19[] = {
	0x03, 0x00, 0x29, 0xc0, 0xd3, 0x33, 0x03, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_20[] = {
	0x02, 0x00, 0x29, 0xc0, 0xd5, 0x06, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_21[] = {
	0x02, 0x00, 0x29, 0xc0, 0xd6, 0x01, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_22[] = {
	0x09, 0x00, 0x29, 0xc0, 0xd7, 0x09, 0x00, 0x84,
	0x81, 0x61, 0xbc, 0xb5, 0x05, 0xff, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_23[] = {
	0x07, 0x00, 0x29, 0xc0, 0xd8, 0x04, 0x25, 0x90,
	0x4c, 0x92, 0x00, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_24[] = {
	0x04, 0x00, 0x29, 0xc0, 0xd9, 0x5b, 0x7f, 0x00
};
static char kc_jdi_fwvga_video_on_cmd_25[] = {
	0x02, 0x00, 0x29, 0xc0, 0xdd, 0x3c, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_26[] = {
	0x02, 0x00, 0x29, 0xc0, 0xde, 0x42, 0xff, 0xff
};
static char kc_jdi_fwvga_video_on_cmd_27[] = {
	0xb0, 0x03, 0x23, 0x80
};
static char kc_jdi_fwvga_video_on_cmd_28[] = {
	0x11, 0x00, 0x05, 0x80
};
static char kc_jdi_fwvga_video_on_cmd_29[] = {
	0x29, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd kc_jdi_fwvga_video_on_command[] = {
	{ sizeof(kc_jdi_fwvga_video_on_cmd_0), kc_jdi_fwvga_video_on_cmd_0, 10 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_1), kc_jdi_fwvga_video_on_cmd_1, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_2), kc_jdi_fwvga_video_on_cmd_2, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_3), kc_jdi_fwvga_video_on_cmd_3, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_4), kc_jdi_fwvga_video_on_cmd_4, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_5), kc_jdi_fwvga_video_on_cmd_5, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_6), kc_jdi_fwvga_video_on_cmd_6, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_7), kc_jdi_fwvga_video_on_cmd_7, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_8), kc_jdi_fwvga_video_on_cmd_8, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_9), kc_jdi_fwvga_video_on_cmd_9, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_10), kc_jdi_fwvga_video_on_cmd_10, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_11), kc_jdi_fwvga_video_on_cmd_11, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_12), kc_jdi_fwvga_video_on_cmd_12, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_13), kc_jdi_fwvga_video_on_cmd_13, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_14), kc_jdi_fwvga_video_on_cmd_14, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_15), kc_jdi_fwvga_video_on_cmd_15, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_16), kc_jdi_fwvga_video_on_cmd_16, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_17), kc_jdi_fwvga_video_on_cmd_17, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_18), kc_jdi_fwvga_video_on_cmd_18, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_19), kc_jdi_fwvga_video_on_cmd_19, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_20), kc_jdi_fwvga_video_on_cmd_20, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_21), kc_jdi_fwvga_video_on_cmd_21, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_22), kc_jdi_fwvga_video_on_cmd_22, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_23), kc_jdi_fwvga_video_on_cmd_23, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_24), kc_jdi_fwvga_video_on_cmd_24, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_25), kc_jdi_fwvga_video_on_cmd_25, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_26), kc_jdi_fwvga_video_on_cmd_26, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_27), kc_jdi_fwvga_video_on_cmd_27, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_28), kc_jdi_fwvga_video_on_cmd_28, 0 },
	{ sizeof(kc_jdi_fwvga_video_on_cmd_29), kc_jdi_fwvga_video_on_cmd_29, 0 },
};

static char kc_jdi_fwvga_video_off_cmd_0[] = {
	0x28, 0x00, 0x05, 0x80
};
static char kc_jdi_fwvga_video_off_cmd_1[] = {
	0x10, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd kc_jdi_fwvga_video_off_command[] = {
	{ sizeof(kc_jdi_fwvga_video_off_cmd_0), kc_jdi_fwvga_video_off_cmd_0, 20 },
	{ sizeof(kc_jdi_fwvga_video_off_cmd_1), kc_jdi_fwvga_video_off_cmd_1, 100 },
};

static struct command_state kc_jdi_fwvga_video_state = {
	.oncommand_state = 0,
	.offcommand_state = 1,
};

static struct commandpanel_info kc_jdi_fwvga_video_command_panel = {
	/* Unused, this is a video mode panel */
};

static struct videopanel_info kc_jdi_fwvga_video_video_panel = {
	.hsync_pulse = 0,
	.hfp_power_mode = 0,
	.hbp_power_mode = 0,
	.hsa_power_mode = 0,
	.bllp_eof_power_mode = 1,
	.bllp_power_mode = 1,
	.traffic_mode = 1,
	/* This is bllp_eof_power_mode and bllp_power_mode combined */
	.bllp_eof_power = 1 << 3 | 1 << 0,
};

static struct lane_configuration kc_jdi_fwvga_video_lane_config = {
	.dsi_lanes = 2,
	.dsi_lanemap = 0,
	.lane0_state = 1,
	.lane1_state = 1,
	.lane2_state = 0,
	.lane3_state = 0,
	.force_clk_lane_hs = 0,
};

static const uint32_t kc_jdi_fwvga_video_timings[] = {
	0x6d, 0x18, 0x10, 0x00, 0x3a, 0x3e, 0x12, 0x1e, 0x13, 0x03, 0x04, 0x00
};

static struct panel_timing kc_jdi_fwvga_video_timing_info = {
	.tclk_post = 0x04,
	.tclk_pre = 0x18,
};

static struct panel_reset_sequence kc_jdi_fwvga_video_reset_seq = {
	.pin_state = { 0, 1, 1 },
	.sleep = { 10, 10, 10 },
	.pin_direction = 2,
};

static struct backlight kc_jdi_fwvga_video_backlight = {
	.bl_interface_type = BL_WLED,
	.bl_min_level = 1,
	.bl_max_level = 4095,
};

static inline void panel_kc_jdi_fwvga_video_select(struct panel_struct *panel,
						   struct msm_panel_info *pinfo,
						   struct mdss_dsi_phy_ctrl *phy_db)
{
	panel->paneldata = &kc_jdi_fwvga_video_panel_data;
	panel->panelres = &kc_jdi_fwvga_video_panel_res;
	panel->color = &kc_jdi_fwvga_video_color;
	panel->videopanel = &kc_jdi_fwvga_video_video_panel;
	panel->commandpanel = &kc_jdi_fwvga_video_command_panel;
	panel->state = &kc_jdi_fwvga_video_state;
	panel->laneconfig = &kc_jdi_fwvga_video_lane_config;
	panel->paneltiminginfo = &kc_jdi_fwvga_video_timing_info;
	panel->panelresetseq = &kc_jdi_fwvga_video_reset_seq;
	panel->backlightinfo = &kc_jdi_fwvga_video_backlight;
	pinfo->mipi.panel_on_cmds = kc_jdi_fwvga_video_on_command;
	pinfo->mipi.panel_off_cmds = kc_jdi_fwvga_video_off_command;
	pinfo->mipi.num_of_panel_on_cmds = ARRAY_SIZE(kc_jdi_fwvga_video_on_command);
	pinfo->mipi.num_of_panel_off_cmds = ARRAY_SIZE(kc_jdi_fwvga_video_off_command);
	memcpy(phy_db->timing, kc_jdi_fwvga_video_timings, TIMING_SIZE);
	phy_db->regulator_mode = DSI_PHY_REGULATOR_LDO_MODE;
}

#endif /* _PANEL_KC_JDI_FWVGA_VIDEO_H_ */
