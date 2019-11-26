/*
 * (C) Copyright 2019 Lothar Waßmann <LW@KARO-electronics.de>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <fs.h>
#include <mmc.h>
#include "karo.h"

static void karo_set_fdtsize(void *fdt)
{
	size_t fdtsize = env_get_hex("fdt_size", 0);

	if (fdtsize == fdt_totalsize(fdt)) {
		return;
	}
	debug("FDT size changed from %zu to %u\n",
	      fdtsize, fdt_totalsize(fdt));
	env_set_hex("fdt_size", fdt_totalsize(fdt));
}

int karo_load_fdt(const char *fdt_file)
{
	int ret;
	const char *dev_type = "mmc";
	const char *dev_part = "0";
	ulong fdt_addr = env_get_hex("fdt_addr", _pfx(0x, CONFIG_FDTADDR));
	loff_t size;
	void *fdt;

	printf("loading FDT from %s %s '%s'\n", dev_type, dev_part, fdt_file);

	if (!file_exists(dev_type, dev_part, fdt_file, FS_TYPE_ANY)) {
		printf("'%s' does not exist\n", fdt_file);
		return -ENOENT;
	}
	if (fs_set_blk_dev(dev_type, dev_part, FS_TYPE_ANY))
		return -ENOENT;

	debug("Loading %s to %08lx\n", fdt_file, fdt_addr);
	ret = fs_read(fdt_file, fdt_addr, 0, 0, &size);
	if (ret)
		return ret;
	debug("Read %llu byte from '%s'\n", size, fdt_file);
	fdt = (void *)fdt_addr;
	debug("Checking FDT header @ %p\n", fdt);
	if (fdt_check_header(fdt)) {
		printf("ERROR: No valid DTB found at %p\n", fdt);
		return -EINVAL;
	}
	fdt_shrink_to_minimum(fdt, 4096);
	karo_set_fdtsize(fdt);
	set_working_fdt_addr(fdt_addr);
	return ret;
}
