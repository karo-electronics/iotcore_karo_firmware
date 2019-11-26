/*
 * Copyright (C) 2017 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm/mach-imx/sys_proto.h>
#include <linux/types.h>

struct pass_over_info_t {
	uint16_t barker;
	uint16_t len;
	uint32_t g_bt_cfg_shadow;
	uint32_t card_address_mode;
	uint32_t bad_block_count_met;
	uint32_t g_ap_mu;
};

int print_bootinfo(void);
int init_otg_power(void);
void power_off_pd_devices(const char* permanent_on_devices[], int size);
extern unsigned long rom_pointer[];
enum boot_device get_boot_device(void);
bool check_m4_parts_boot(void);
