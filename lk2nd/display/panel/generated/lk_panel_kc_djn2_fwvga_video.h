// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2014, The Linux Foundation. All rights reserved. (FIXME)

#ifndef _PANEL_KC_DJN2_FWVGA_VIDEO_H_
#define _PANEL_KC_DJN2_FWVGA_VIDEO_H_

#include <mipi_dsi.h>
#include <panel_display.h>
#include <panel.h>
#include <string.h>

static struct panel_config kc_djn2_fwvga_video_panel_data = {
	.panel_node_id = "qcom,mdss_dsi_kc_djn2_fwvga_video",
	.panel_controller = "dsi:0:",
	.panel_compatible = "qcom,mdss-dsi-panel",
	.panel_type = 0,
	.panel_destination = "DISPLAY_1",
	/* .panel_orientation not supported yet */
	.panel_framerate = 60,
	.panel_lp11_init = 1,
	.panel_init_delay = 0,
};

static struct panel_resolution kc_djn2_fwvga_video_panel_res = {
	.panel_width = 480,
	.panel_height = 854,
	.hfront_porch = 30,
	.hback_porch = 30,
	.hpulse_width = 10,
	.hsync_skew = 0,
	.vfront_porch = 10,
	.vback_porch = 10,
	.vpulse_width = 4,
	/* Borders not supported yet */
};

static struct color_info kc_djn2_fwvga_video_color = {
	.color_format = 24,
	.color_order = DSI_RGB_SWAP_RGB,
	.underflow_color = 0xff,
	/* Borders and pixel packing not supported yet */
};

static char kc_djn2_fwvga_video_on_cmd_0[] = {
	0x06, 0x00, 0x29, 0xc0, 0xff, 0xff, 0x98, 0x06,
	0x04, 0x01, 0xff, 0xff
};
static char kc_djn2_fwvga_video_on_cmd_1[] = {
	0x0a, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_2[] = {
	0x20, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_3[] = {
	0x23, 0x02, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_4[] = {
	0x25, 0x0a, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_5[] = {
	0x26, 0x0d, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_6[] = {
	0x27, 0x28, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_7[] = {
	0x28, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_8[] = {
	0x30, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_9[] = {
	0x31, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_10[] = {
	0x34, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_11[] = {
	0x35, 0x07, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_12[] = {
	0x40, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_13[] = {
	0x41, 0x77, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_14[] = {
	0x42, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_15[] = {
	0x43, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_16[] = {
	0x44, 0x06, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_17[] = {
	0x45, 0x02, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_18[] = {
	0x46, 0x33, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_19[] = {
	0x47, 0x33, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_20[] = {
	0x50, 0xa0, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_21[] = {
	0x51, 0xa0, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_22[] = {
	0x52, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_23[] = {
	0x53, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_24[] = {
	0x54, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_25[] = {
	0x55, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_26[] = {
	0x56, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_27[] = {
	0x57, 0x20, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_28[] = {
	0x58, 0x90, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_29[] = {
	0x60, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_30[] = {
	0x61, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_31[] = {
	0x62, 0x06, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_32[] = {
	0x63, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_33[] = {
	0x80, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_34[] = {
	0x81, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_35[] = {
	0x82, 0x0a, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_36[] = {
	0xa0, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_37[] = {
	0xa1, 0x0e, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_38[] = {
	0xa2, 0x18, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_39[] = {
	0xa3, 0x0f, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_40[] = {
	0xa4, 0x07, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_41[] = {
	0xa5, 0x0e, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_42[] = {
	0xa6, 0x06, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_43[] = {
	0xa7, 0x04, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_44[] = {
	0xa8, 0x09, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_45[] = {
	0xa9, 0x0c, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_46[] = {
	0xaa, 0x0e, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_47[] = {
	0xab, 0x07, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_48[] = {
	0xac, 0x0f, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_49[] = {
	0xad, 0x10, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_50[] = {
	0xae, 0x09, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_51[] = {
	0xaf, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_52[] = {
	0xc0, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_53[] = {
	0xc1, 0x0e, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_54[] = {
	0xc2, 0x18, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_55[] = {
	0xc3, 0x0f, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_56[] = {
	0xc4, 0x07, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_57[] = {
	0xc5, 0x0e, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_58[] = {
	0xc6, 0x06, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_59[] = {
	0xc7, 0x04, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_60[] = {
	0xc8, 0x09, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_61[] = {
	0xc9, 0x0c, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_62[] = {
	0xca, 0x0e, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_63[] = {
	0xcb, 0x07, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_64[] = {
	0xcc, 0x0f, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_65[] = {
	0xcd, 0x10, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_66[] = {
	0xce, 0x09, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_67[] = {
	0xcf, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_68[] = {
	0x06, 0x00, 0x29, 0xc0, 0xff, 0xff, 0x98, 0x06,
	0x04, 0x02, 0xff, 0xff
};
static char kc_djn2_fwvga_video_on_cmd_69[] = {
	0x40, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_70[] = {
	0x06, 0x00, 0x29, 0xc0, 0xff, 0xff, 0x98, 0x06,
	0x04, 0x06, 0xff, 0xff
};
static char kc_djn2_fwvga_video_on_cmd_71[] = {
	0x00, 0x21, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_72[] = {
	0x01, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_73[] = {
	0x02, 0x60, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_74[] = {
	0x03, 0x02, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_75[] = {
	0x04, 0x03, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_76[] = {
	0x05, 0x03, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_77[] = {
	0x06, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_78[] = {
	0x07, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_79[] = {
	0x08, 0x07, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_80[] = {
	0x09, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_81[] = {
	0x0a, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_82[] = {
	0x0b, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_83[] = {
	0x0c, 0x0a, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_84[] = {
	0x0d, 0x0a, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_85[] = {
	0x0e, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_86[] = {
	0x0f, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_87[] = {
	0x10, 0x44, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_88[] = {
	0x11, 0x40, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_89[] = {
	0x12, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_90[] = {
	0x13, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_91[] = {
	0x14, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_92[] = {
	0x15, 0xc0, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_93[] = {
	0x16, 0x08, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_94[] = {
	0x17, 0x05, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_95[] = {
	0x18, 0x05, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_96[] = {
	0x19, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_97[] = {
	0x1a, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_98[] = {
	0x1b, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_99[] = {
	0x20, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_100[] = {
	0x21, 0x23, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_101[] = {
	0x22, 0x45, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_102[] = {
	0x23, 0x67, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_103[] = {
	0x24, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_104[] = {
	0x25, 0x23, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_105[] = {
	0x26, 0x45, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_106[] = {
	0x27, 0x67, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_107[] = {
	0x30, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_108[] = {
	0x31, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_109[] = {
	0x32, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_110[] = {
	0x33, 0x86, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_111[] = {
	0x34, 0x68, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_112[] = {
	0x35, 0xba, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_113[] = {
	0x36, 0xba, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_114[] = {
	0x37, 0xab, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_115[] = {
	0x38, 0xab, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_116[] = {
	0x39, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_117[] = {
	0x3a, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_118[] = {
	0x3b, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_119[] = {
	0x3c, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_120[] = {
	0x3d, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_121[] = {
	0x3e, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_122[] = {
	0x3f, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_123[] = {
	0x40, 0x22, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_124[] = {
	0x52, 0x12, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_125[] = {
	0x53, 0x12, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_126[] = {
	0x54, 0x03, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_127[] = {
	0x06, 0x00, 0x29, 0xc0, 0xff, 0xff, 0x98, 0x06,
	0x04, 0x07, 0xff, 0xff
};
static char kc_djn2_fwvga_video_on_cmd_128[] = {
	0x00, 0x51, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_129[] = {
	0x02, 0x00, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_130[] = {
	0x06, 0x02, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_131[] = {
	0x17, 0x33, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_132[] = {
	0xb3, 0x10, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_133[] = {
	0x06, 0x00, 0x29, 0xc0, 0xff, 0xff, 0x98, 0x06,
	0x04, 0x05, 0xff, 0xff
};
static char kc_djn2_fwvga_video_on_cmd_134[] = {
	0x00, 0x02, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_135[] = {
	0x06, 0x00, 0x29, 0xc0, 0xff, 0xff, 0x98, 0x06,
	0x04, 0x00, 0xff, 0xff
};
static char kc_djn2_fwvga_video_on_cmd_136[] = {
	0x51, 0xff, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_137[] = {
	0x55, 0x01, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_138[] = {
	0x53, 0x24, 0x23, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_139[] = {
	0x11, 0x00, 0x05, 0x80
};
static char kc_djn2_fwvga_video_on_cmd_140[] = {
	0x29, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd kc_djn2_fwvga_video_on_command[] = {
	{ sizeof(kc_djn2_fwvga_video_on_cmd_0), kc_djn2_fwvga_video_on_cmd_0, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_1), kc_djn2_fwvga_video_on_cmd_1, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_2), kc_djn2_fwvga_video_on_cmd_2, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_3), kc_djn2_fwvga_video_on_cmd_3, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_4), kc_djn2_fwvga_video_on_cmd_4, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_5), kc_djn2_fwvga_video_on_cmd_5, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_6), kc_djn2_fwvga_video_on_cmd_6, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_7), kc_djn2_fwvga_video_on_cmd_7, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_8), kc_djn2_fwvga_video_on_cmd_8, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_9), kc_djn2_fwvga_video_on_cmd_9, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_10), kc_djn2_fwvga_video_on_cmd_10, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_11), kc_djn2_fwvga_video_on_cmd_11, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_12), kc_djn2_fwvga_video_on_cmd_12, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_13), kc_djn2_fwvga_video_on_cmd_13, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_14), kc_djn2_fwvga_video_on_cmd_14, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_15), kc_djn2_fwvga_video_on_cmd_15, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_16), kc_djn2_fwvga_video_on_cmd_16, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_17), kc_djn2_fwvga_video_on_cmd_17, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_18), kc_djn2_fwvga_video_on_cmd_18, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_19), kc_djn2_fwvga_video_on_cmd_19, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_20), kc_djn2_fwvga_video_on_cmd_20, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_21), kc_djn2_fwvga_video_on_cmd_21, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_22), kc_djn2_fwvga_video_on_cmd_22, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_23), kc_djn2_fwvga_video_on_cmd_23, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_24), kc_djn2_fwvga_video_on_cmd_24, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_25), kc_djn2_fwvga_video_on_cmd_25, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_26), kc_djn2_fwvga_video_on_cmd_26, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_27), kc_djn2_fwvga_video_on_cmd_27, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_28), kc_djn2_fwvga_video_on_cmd_28, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_29), kc_djn2_fwvga_video_on_cmd_29, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_30), kc_djn2_fwvga_video_on_cmd_30, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_31), kc_djn2_fwvga_video_on_cmd_31, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_32), kc_djn2_fwvga_video_on_cmd_32, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_33), kc_djn2_fwvga_video_on_cmd_33, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_34), kc_djn2_fwvga_video_on_cmd_34, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_35), kc_djn2_fwvga_video_on_cmd_35, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_36), kc_djn2_fwvga_video_on_cmd_36, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_37), kc_djn2_fwvga_video_on_cmd_37, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_38), kc_djn2_fwvga_video_on_cmd_38, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_39), kc_djn2_fwvga_video_on_cmd_39, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_40), kc_djn2_fwvga_video_on_cmd_40, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_41), kc_djn2_fwvga_video_on_cmd_41, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_42), kc_djn2_fwvga_video_on_cmd_42, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_43), kc_djn2_fwvga_video_on_cmd_43, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_44), kc_djn2_fwvga_video_on_cmd_44, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_45), kc_djn2_fwvga_video_on_cmd_45, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_46), kc_djn2_fwvga_video_on_cmd_46, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_47), kc_djn2_fwvga_video_on_cmd_47, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_48), kc_djn2_fwvga_video_on_cmd_48, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_49), kc_djn2_fwvga_video_on_cmd_49, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_50), kc_djn2_fwvga_video_on_cmd_50, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_51), kc_djn2_fwvga_video_on_cmd_51, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_52), kc_djn2_fwvga_video_on_cmd_52, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_53), kc_djn2_fwvga_video_on_cmd_53, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_54), kc_djn2_fwvga_video_on_cmd_54, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_55), kc_djn2_fwvga_video_on_cmd_55, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_56), kc_djn2_fwvga_video_on_cmd_56, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_57), kc_djn2_fwvga_video_on_cmd_57, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_58), kc_djn2_fwvga_video_on_cmd_58, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_59), kc_djn2_fwvga_video_on_cmd_59, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_60), kc_djn2_fwvga_video_on_cmd_60, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_61), kc_djn2_fwvga_video_on_cmd_61, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_62), kc_djn2_fwvga_video_on_cmd_62, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_63), kc_djn2_fwvga_video_on_cmd_63, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_64), kc_djn2_fwvga_video_on_cmd_64, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_65), kc_djn2_fwvga_video_on_cmd_65, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_66), kc_djn2_fwvga_video_on_cmd_66, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_67), kc_djn2_fwvga_video_on_cmd_67, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_68), kc_djn2_fwvga_video_on_cmd_68, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_69), kc_djn2_fwvga_video_on_cmd_69, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_70), kc_djn2_fwvga_video_on_cmd_70, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_71), kc_djn2_fwvga_video_on_cmd_71, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_72), kc_djn2_fwvga_video_on_cmd_72, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_73), kc_djn2_fwvga_video_on_cmd_73, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_74), kc_djn2_fwvga_video_on_cmd_74, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_75), kc_djn2_fwvga_video_on_cmd_75, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_76), kc_djn2_fwvga_video_on_cmd_76, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_77), kc_djn2_fwvga_video_on_cmd_77, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_78), kc_djn2_fwvga_video_on_cmd_78, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_79), kc_djn2_fwvga_video_on_cmd_79, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_80), kc_djn2_fwvga_video_on_cmd_80, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_81), kc_djn2_fwvga_video_on_cmd_81, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_82), kc_djn2_fwvga_video_on_cmd_82, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_83), kc_djn2_fwvga_video_on_cmd_83, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_84), kc_djn2_fwvga_video_on_cmd_84, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_85), kc_djn2_fwvga_video_on_cmd_85, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_86), kc_djn2_fwvga_video_on_cmd_86, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_87), kc_djn2_fwvga_video_on_cmd_87, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_88), kc_djn2_fwvga_video_on_cmd_88, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_89), kc_djn2_fwvga_video_on_cmd_89, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_90), kc_djn2_fwvga_video_on_cmd_90, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_91), kc_djn2_fwvga_video_on_cmd_91, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_92), kc_djn2_fwvga_video_on_cmd_92, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_93), kc_djn2_fwvga_video_on_cmd_93, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_94), kc_djn2_fwvga_video_on_cmd_94, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_95), kc_djn2_fwvga_video_on_cmd_95, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_96), kc_djn2_fwvga_video_on_cmd_96, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_97), kc_djn2_fwvga_video_on_cmd_97, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_98), kc_djn2_fwvga_video_on_cmd_98, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_99), kc_djn2_fwvga_video_on_cmd_99, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_100), kc_djn2_fwvga_video_on_cmd_100, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_101), kc_djn2_fwvga_video_on_cmd_101, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_102), kc_djn2_fwvga_video_on_cmd_102, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_103), kc_djn2_fwvga_video_on_cmd_103, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_104), kc_djn2_fwvga_video_on_cmd_104, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_105), kc_djn2_fwvga_video_on_cmd_105, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_106), kc_djn2_fwvga_video_on_cmd_106, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_107), kc_djn2_fwvga_video_on_cmd_107, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_108), kc_djn2_fwvga_video_on_cmd_108, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_109), kc_djn2_fwvga_video_on_cmd_109, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_110), kc_djn2_fwvga_video_on_cmd_110, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_111), kc_djn2_fwvga_video_on_cmd_111, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_112), kc_djn2_fwvga_video_on_cmd_112, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_113), kc_djn2_fwvga_video_on_cmd_113, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_114), kc_djn2_fwvga_video_on_cmd_114, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_115), kc_djn2_fwvga_video_on_cmd_115, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_116), kc_djn2_fwvga_video_on_cmd_116, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_117), kc_djn2_fwvga_video_on_cmd_117, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_118), kc_djn2_fwvga_video_on_cmd_118, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_119), kc_djn2_fwvga_video_on_cmd_119, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_120), kc_djn2_fwvga_video_on_cmd_120, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_121), kc_djn2_fwvga_video_on_cmd_121, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_122), kc_djn2_fwvga_video_on_cmd_122, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_123), kc_djn2_fwvga_video_on_cmd_123, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_124), kc_djn2_fwvga_video_on_cmd_124, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_125), kc_djn2_fwvga_video_on_cmd_125, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_126), kc_djn2_fwvga_video_on_cmd_126, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_127), kc_djn2_fwvga_video_on_cmd_127, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_128), kc_djn2_fwvga_video_on_cmd_128, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_129), kc_djn2_fwvga_video_on_cmd_129, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_130), kc_djn2_fwvga_video_on_cmd_130, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_131), kc_djn2_fwvga_video_on_cmd_131, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_132), kc_djn2_fwvga_video_on_cmd_132, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_133), kc_djn2_fwvga_video_on_cmd_133, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_134), kc_djn2_fwvga_video_on_cmd_134, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_135), kc_djn2_fwvga_video_on_cmd_135, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_136), kc_djn2_fwvga_video_on_cmd_136, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_137), kc_djn2_fwvga_video_on_cmd_137, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_138), kc_djn2_fwvga_video_on_cmd_138, 0 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_139), kc_djn2_fwvga_video_on_cmd_139, 120 },
	{ sizeof(kc_djn2_fwvga_video_on_cmd_140), kc_djn2_fwvga_video_on_cmd_140, 0 },
};

static char kc_djn2_fwvga_video_off_cmd_0[] = {
	0x28, 0x00, 0x05, 0x80
};
static char kc_djn2_fwvga_video_off_cmd_1[] = {
	0x10, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd kc_djn2_fwvga_video_off_command[] = {
	{ sizeof(kc_djn2_fwvga_video_off_cmd_0), kc_djn2_fwvga_video_off_cmd_0, 20 },
	{ sizeof(kc_djn2_fwvga_video_off_cmd_1), kc_djn2_fwvga_video_off_cmd_1, 100 },
};

static struct command_state kc_djn2_fwvga_video_state = {
	.oncommand_state = 0,
	.offcommand_state = 0,
};

static struct commandpanel_info kc_djn2_fwvga_video_command_panel = {
	/* Unused, this is a video mode panel */
};

static struct videopanel_info kc_djn2_fwvga_video_video_panel = {
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

static struct lane_configuration kc_djn2_fwvga_video_lane_config = {
	.dsi_lanes = 2,
	.dsi_lanemap = 0,
	.lane0_state = 1,
	.lane1_state = 1,
	.lane2_state = 0,
	.lane3_state = 0,
	.force_clk_lane_hs = 0,
};

static const uint32_t kc_djn2_fwvga_video_timings[] = {
	0x6a, 0x16, 0x0e, 0x00, 0x38, 0x3a, 0x12, 0x1c, 0x10, 0x03, 0x04, 0x00
};

static struct panel_timing kc_djn2_fwvga_video_timing_info = {
	.tclk_post = 0x04,
	.tclk_pre = 0x17,
};

static struct panel_reset_sequence kc_djn2_fwvga_video_reset_seq = {
	.pin_state = { 0, 1, 0, 1 },
	.sleep = { 4, 7, 2, 10 },
	.pin_direction = 2,
};

static struct backlight kc_djn2_fwvga_video_backlight = {
	.bl_interface_type = BL_WLED,
	.bl_min_level = 1,
	.bl_max_level = 4095,
};

static inline void panel_kc_djn2_fwvga_video_select(struct panel_struct *panel,
						    struct msm_panel_info *pinfo,
						    struct mdss_dsi_phy_ctrl *phy_db)
{
	panel->paneldata = &kc_djn2_fwvga_video_panel_data;
	panel->panelres = &kc_djn2_fwvga_video_panel_res;
	panel->color = &kc_djn2_fwvga_video_color;
	panel->videopanel = &kc_djn2_fwvga_video_video_panel;
	panel->commandpanel = &kc_djn2_fwvga_video_command_panel;
	panel->state = &kc_djn2_fwvga_video_state;
	panel->laneconfig = &kc_djn2_fwvga_video_lane_config;
	panel->paneltiminginfo = &kc_djn2_fwvga_video_timing_info;
	panel->panelresetseq = &kc_djn2_fwvga_video_reset_seq;
	panel->backlightinfo = &kc_djn2_fwvga_video_backlight;
	pinfo->mipi.panel_on_cmds = kc_djn2_fwvga_video_on_command;
	pinfo->mipi.panel_off_cmds = kc_djn2_fwvga_video_off_command;
	pinfo->mipi.num_of_panel_on_cmds = ARRAY_SIZE(kc_djn2_fwvga_video_on_command);
	pinfo->mipi.num_of_panel_off_cmds = ARRAY_SIZE(kc_djn2_fwvga_video_off_command);
	memcpy(phy_db->timing, kc_djn2_fwvga_video_timings, TIMING_SIZE);
	phy_db->regulator_mode = DSI_PHY_REGULATOR_LDO_MODE;
}

#endif /* _PANEL_KC_DJN2_FWVGA_VIDEO_H_ */
