/*
 * (C) Copyright 2016 Toradex
 * Author: Stefan Agner <stefan.agner@toradex.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <spl.h>
#include <usb.h>
#include <g_dnl.h>
#include <sdp.h>

DECLARE_GLOBAL_DATA_PTR;

void board_sdp_cleanup(void)
{
	board_usb_cleanup(CONFIG_SPL_SDP_USB_DEV, USB_INIT_DEVICE);
}

static int spl_sdp_load_image(struct spl_image_info *spl_image,
			      struct spl_boot_device *bootdev)
{
	int ret;
	const int controller_index = CONFIG_SPL_SDP_USB_DEV;

	board_usb_init(controller_index, USB_INIT_DEVICE);

	g_dnl_clear_detach();
	g_dnl_register("usb_dnl_sdp");

	ret = sdp_init(controller_index);
	if (ret) {
		pr_err("SDP init failed: %d\n", ret);
		return -ENODEV;
	}

	/* This command typically does not return but jumps to an image */
	sdp_handle(controller_index);
	pr_err("SDP ended\n");

	return -EINVAL;
}
SPL_LOAD_IMAGE_METHOD("USB SDP", 0, BOOT_DEVICE_BOARD, spl_sdp_load_image);
