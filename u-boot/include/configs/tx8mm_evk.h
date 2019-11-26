/*
 * Copyright 2019 Lothar Waßmann <LW@KARO-electronics.de>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __IMX8MM_EVK_H
#define __IMX8MM_EVK_H

#include <linux/sizes.h>
#include <asm/arch/imx-regs.h>

#ifdef CONFIG_SECURE_BOOT
#define CONFIG_CSF_SIZE			SZ_8K
#endif

#define CONFIG_SPL_MAX_SIZE		(148 * 1024)
#define CONFIG_SYS_MONITOR_LEN		SZ_1M
#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION	0x1

#define CONFIG_MXC_SPI
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_STMICRO
#define CONFIG_SF_DEFAULT_BUS  0
#define CONFIG_SF_DEFAULT_SPEED 20000000
#define CONFIG_SF_DEFAULT_MODE (SPI_MODE_0)









#ifdef CONFIG_SPL_BUILD
#define CONFIG_ENABLE_DDR_TRAINING_DEBUG
#define CONFIG_USBD_HS
#define CONFIG_SPL_BSS_START_ADDR	0x00910000
#define CONFIG_SPL_BSS_MAX_SIZE		SZ_8K
#define CONFIG_SYS_SPL_MALLOC_START	0x42200000
#define CONFIG_SYS_SPL_MALLOC_SIZE	SZ_512K
#define CONFIG_SPL_LOAD_FIT_ADDRESS	0

#define CONFIG_MALLOC_F_ADDR		0x00912000 /* malloc f used before GD_FLG_FULL_MALLOC_INIT set */

#define CONFIG_SPL_ABORT_ON_RAW_IMAGE /* For RAW image gives an error info not panic */

#define CONFIG_POWER
#define CONFIG_POWER_I2C
#define CONFIG_POWER_BD71837

#ifndef CONFIG_DM_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC_I2C1
#endif

#if CONFIG_IS_ENABLED(USB_SUPPORT)
#define CONFIG_SYS_USB_FAT_BOOT_PARTITION  1
#define CONFIG_SPL_FS_LOAD_PAYLOAD_NAME "u-boot"
#endif

#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif /* CONFIG_SPL_BUILD */
#define CONFIG_SYS_INIT_SP_ADDR		0x00920000

#define CONFIG_SERIAL_TAG

#define CONFIG_REMAKE_ELF

#define CONFIG_BOARD_EARLY_INIT_R
#ifdef CONFIG_LED
#define CONFIG_SHOW_ACTIVITY
#endif

/* ENET Config */
#ifdef CONFIG_FEC_MXC
#define IMX_FEC_BASE			0x30BE0000
#define CONFIG_FEC_MXC_PHYADDR		0
#define CONFIG_FEC_XCV_TYPE		RMII
#define FEC_QUIRK_ENET_MAC
#endif

#define __pfx(p,v)			(p##v)
#define _pfx(p,v)			__pfx(p, v)

#define CONFIG_FDTADDR			43000000
#define FDTADDR_STR			__stringify(CONFIG_FDTADDR)

/* Initial environment variables */
#ifndef CONFIG_TX8MM_UBOOT_MFG
#define CONFIG_EXTRA_ENV_SETTINGS					\
	"append_bootargs=clk_ignore_unused debug\0"			\
	"baseboard=mipi-mb\0"						\
	"board=imx8mm-tx8m-1610\0"					\
	"boot_mode=mmc\0"						\
	"bootargs_mmc=run default_bootargs;"				\
	" setenv bootargs ${bootargs} root=PARTUUID=${uuid_rootfs}"	\
	" ${append_bootargs}\0"						\
	"bootargs_nfs=run default_bootargs;"				\
	" setenv bootargs root=/dev/nfs"				\
	" nfsroot=${nfs_server}:${nfsroot},nolock ${append_bootargs}\0"	\
	"bootcmd_mmc=run loadkernel bootargs_mmc\0"			\
	"bootcmd_nfs=run loadkernel bootargs_nfs\0"			\
	"bootm_cmd=booti ${loadaddr} ${initrd_addr} ${fdt_addr}\0"	\
	"console=ttymxc0,115200 earlycon=ec_imx6q,0x30860000,115200\0"	\
	"default_bootargs=setenv bootargs init=/linuxrc"		\
	" console=${console} panic=-1 ro\0"				\
	"emmc_boot_ack=1\0"						\
	"emmc_boot_part=1\0"						\
	"fdt_addr=" FDTADDR_STR "\0"					\
	"fdt_file=Image-" CONFIG_DEFAULT_FDT_FILE "\0"			\
	"fdt_high=63000000\0"						\
	"fdtsave=save mmc ${mmcdev} ${fdt_addr} ${fdt_file}"		\
	" ${fdt_size}\0"						\
	"initrd_addr=-\0"						\
	"initrd_high=63800000\0"					\
	"linux_image=Image-tx8m-1610.bin\0"				\
	"loadfdt=if test \"${baseboard}\" != \"\";then"			\
	" fdtfile=Image-${board}-${baseboard}.dtb;else"			\
	" fdtfile=Image-${board}.dtb;fi"				\
	";load mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdtfile}\0"	\
	"loadkernel=load mmc ${mmcdev}:${mmcpart} ${loadaddr}"		\
	" ${linux_image}\0"						\
	"mmcdev=0\0"							\
	"mmcpart=1\0"							\
	"panel=MIPI2LVDS\0"						\
	"owner=US\0"						\
	"uuid_rootfs=0cc66cc0-5458-384d-1610-726f6f746673\0"
#else
#define CONFIG_EXTRA_ENV_SETTINGS					\
	"bootcmd=fastboot 0\0"						\
	"emmc_boot_ack=1\0"						\
	"emmc_boot_part=1\0"						\
	"fastboot_dev=mmc\0"						\
	"mmcdev=0\0"
#endif

/* Link Definitions */
#define CONFIG_LOADADDR			40480000

#define CONFIG_SYS_LOAD_ADDR		_pfx(0x,CONFIG_LOADADDR)

#define CONFIG_ENV_OVERWRITE
#if defined(CONFIG_ENV_IS_IN_MMC)
#define CONFIG_ENV_OFFSET		(2048 * 512 - CONFIG_ENV_SIZE)
#else
#error "No supported Environment location defined"
#endif
#define CONFIG_ENV_SIZE			0x1000
#define CONFIG_SYS_MMC_ENV_DEV		0

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		((CONFIG_ENV_SIZE + SZ_2K + SZ_16K) * SZ_1K)

#define CONFIG_SYS_SDRAM_BASE		0x40000000
#define PHYS_SDRAM			0x40000000
#define PHYS_SDRAM_SIZE			SZ_1G
#define CONFIG_NR_DRAM_BANKS		1

#define CONFIG_SYS_MEMTEST_START	PHYS_SDRAM
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MEMTEST_START + (PHYS_SDRAM_SIZE >> 1))

#define CONFIG_MXC_UART_BASE		UART1_BASE_ADDR

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE		2048
#define CONFIG_SYS_MAXARGS		256
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)

/* USDHC */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC

#define CONFIG_SYS_FSL_USDHC_NUM	3
#define CONFIG_SYS_FSL_ESDHC_ADDR	0

#define CONFIG_SUPPORT_EMMC_BOOT	/* eMMC specific */
#define CONFIG_SYS_MMC_IMG_LOAD_PART	1

#ifndef CONFIG_DM_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC_I2C1		/* enable I2C bus 1 */
#define CONFIG_SYS_I2C_MXC_I2C2		/* enable I2C bus 2 */
#define CONFIG_SYS_I2C_MXC_I2C3		/* enable I2C bus 3 */
#define CONFIG_SYS_I2C_SPEED		400000
#endif

#ifdef CONFIG_USB_EHCI_MX7
#define CONFIG_MXC_USB_PORTSC		(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_USB_MAX_CONTROLLER_COUNT	2
#endif

#ifdef CONFIG_VIDEO
#define CONFIG_VIDEO_MXS
#define CONFIG_VIDEO_LOGO
#define CONFIG_SPLASH_SCREEN
#define CONFIG_SPLASH_SCREEN_ALIGN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_VIDEO_BMP_LOGO
#endif

#endif
