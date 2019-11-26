/*
 * Copyright 2018 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <spl.h>
#include <asm/io.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/arch/imx8mm_pins.h>
#include <asm/arch/sys_proto.h>
#include <power/pmic.h>
#include <power/bd71837.h>
#include <asm/arch/clock.h>
#include <asm/mach-imx/gpio.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <fsl_esdhc.h>
#include <mmc.h>
#include "ddr/ddr.h"

DECLARE_GLOBAL_DATA_PTR;


void spl_dram_init(void)
{
	ddr_init();
}





extern struct i2c_pads_info i2c_pad_info1;
/*
#define I2C_PAD_CTRL	(PAD_CTL_DSE6 | PAD_CTL_HYS | PAD_CTL_PUE | PAD_CTL_PE)
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
struct i2c_pads_info i2c_pad_info1 = {
	.scl = {
		.i2c_mode = IMX8MM_PAD_I2C1_SCL_I2C1_SCL | PC,
		.gpio_mode = IMX8MM_PAD_I2C1_SCL_GPIO5_IO14 | PC,
		.gp = IMX_GPIO_NR(5, 14),
	},
	.sda = {
		.i2c_mode = IMX8MM_PAD_I2C1_SDA_I2C1_SDA | PC,
		.gpio_mode = IMX8MM_PAD_I2C1_SDA_GPIO5_IO15 | PC,
		.gp = IMX_GPIO_NR(5, 15),
	},
};
*/






#define USDHC2_CD_GPIO	IMX_GPIO_NR(2, 18)
#define USDHC3_CD_GPIO	IMX_GPIO_NR(3, 8)

#define USDHC1_EMMC_nReset IMX_GPIO_NR(2, 10)

#define USDHC_PAD_CTRL	(PAD_CTL_DSE6 | PAD_CTL_HYS | PAD_CTL_PUE |PAD_CTL_PE | PAD_CTL_FSEL2)
#define USDHC_PAD_CTRL_DAT3	(PAD_CTL_DSE6 | PAD_CTL_HYS | PAD_CTL_PE | PAD_CTL_FSEL2)
#define USDHC_GPIO_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_DSE1)

// emmc device
static iomux_v3_cfg_t const usdhc1_pads[] = {
	IMX8MM_PAD_SD1_CLK_USDHC1_CLK | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_CMD_USDHC1_CMD | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_DATA0_USDHC1_DATA0 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_DATA1_USDHC1_DATA1 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_DATA2_USDHC1_DATA2 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_DATA3_USDHC1_DATA3 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_DATA4_USDHC1_DATA4 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_DATA5_USDHC1_DATA5 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_DATA6_USDHC1_DATA6 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_DATA7_USDHC1_DATA7 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_STROBE_USDHC1_STROBE | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD1_RESET_B_GPIO2_IO10 | MUX_PAD_CTRL(USDHC_PAD_CTRL),

};

// 1st sdcard reader
static iomux_v3_cfg_t const usdhc2_pads[] = {
	IMX8MM_PAD_SD2_CLK_USDHC2_CLK | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD2_CMD_USDHC2_CMD | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD2_DATA0_USDHC2_DATA0 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD2_DATA1_USDHC2_DATA1 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD2_DATA2_USDHC2_DATA2 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_SD2_DATA3_USDHC2_DATA3 | MUX_PAD_CTRL(USDHC_PAD_CTRL_DAT3),
	IMX8MM_PAD_SD2_CD_B_USDHC2_CD_B | MUX_PAD_CTRL(USDHC_GPIO_PAD_CTRL),
};

// 2nd sdcard reader
static iomux_v3_cfg_t const usdhc3_pads[] = {
	IMX8MM_PAD_NAND_WE_B_USDHC3_CLK | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_NAND_WP_B_USDHC3_CMD | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA04_USDHC3_DATA0 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA05_USDHC3_DATA1 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA06_USDHC3_DATA2 | MUX_PAD_CTRL(USDHC_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA07_USDHC3_DATA3 | MUX_PAD_CTRL(USDHC_PAD_CTRL_DAT3),
	IMX8MM_PAD_NAND_DATA02_USDHC3_CD_B | MUX_PAD_CTRL(USDHC_GPIO_PAD_CTRL),
};




/*
 * The evk board uses DAT3 to detect CD card plugin,
 * in u-boot we mux the pin to GPIO when doing board_mmc_getcd.
 */
static iomux_v3_cfg_t const usdhc2_cd_pad =
	IMX8MM_PAD_SD2_DATA3_GPIO2_IO18 | MUX_PAD_CTRL(USDHC_GPIO_PAD_CTRL);

static iomux_v3_cfg_t const usdhc3_cd_pad =
	IMX8MM_PAD_NAND_DATA07_GPIO3_IO13 | MUX_PAD_CTRL(USDHC_GPIO_PAD_CTRL);




static iomux_v3_cfg_t const usdhc2_dat3_pad =
	IMX8MM_PAD_SD2_DATA3_USDHC2_DATA3 |
	MUX_PAD_CTRL(USDHC_PAD_CTRL_DAT3);

static iomux_v3_cfg_t const usdhc3_dat3_pad =
	IMX8MM_PAD_NAND_DATA07_USDHC3_DATA3 |
	MUX_PAD_CTRL(USDHC_PAD_CTRL_DAT3);



static struct fsl_esdhc_cfg usdhc_cfg[3] = {
	{USDHC1_BASE_ADDR, 0, 1},
	{USDHC2_BASE_ADDR, 0, 1},
	{USDHC3_BASE_ADDR, 0, 1},
};

int board_mmc_init(bd_t *bis)
{
	int i, ret;
	/*
	 * According to the board_mmc_init() the following map is done:
	 * (U-Boot device node)    (Physical Port)
	 * mmc0                    USDHC1
	 * mmc1                    USDHC2
	 */

	for (i = 0; i < CONFIG_SYS_FSL_USDHC_NUM; i++) {
		printf("[%s]: init SDHC[%d] \n", __func__, i);
		switch (i) {
		case 0:
			usdhc_cfg[0].sdhc_clk = mxc_get_clock(MXC_ESDHC_CLK);
			imx_iomux_v3_setup_multiple_pads(
				usdhc1_pads, ARRAY_SIZE(usdhc1_pads));
			gpio_request(USDHC1_EMMC_nReset, "usdhc1_reset");
			gpio_direction_output(USDHC1_EMMC_nReset, 0);
			udelay(500);
			gpio_direction_output(USDHC1_EMMC_nReset, 1);
			break;
		case 1:
			usdhc_cfg[1].sdhc_clk = mxc_get_clock(MXC_ESDHC2_CLK);
			imx_iomux_v3_setup_multiple_pads(
				usdhc2_pads, ARRAY_SIZE(usdhc2_pads));
			break;
		case 2:
			usdhc_cfg[2].sdhc_clk = mxc_get_clock(MXC_ESDHC3_CLK);
			imx_iomux_v3_setup_multiple_pads(
				usdhc2_pads, ARRAY_SIZE(usdhc3_pads));
			break;
		default:
			printf("Warning: you configured more USDHC controllers"
				"(%d) than supported by the board\n", i + 1);
			return -EINVAL;
		}

		ret = fsl_esdhc_initialize(bis, &usdhc_cfg[i]);
		if (ret)
			return ret;
	}

	return 0;
}

int board_mmc_getcd(struct mmc *mmc)
{
	struct fsl_esdhc_cfg *cfg = (struct fsl_esdhc_cfg *)mmc->priv;
	int ret = 0;

	switch (cfg->esdhc_base) {
	case USDHC1_BASE_ADDR:
		ret = 1;
		break;
	case USDHC2_BASE_ADDR:
		imx_iomux_v3_setup_pad(usdhc2_cd_pad);
		gpio_request(USDHC2_CD_GPIO, "usdhc2 cd");
		gpio_direction_input(USDHC2_CD_GPIO);

		/*
		 * Since it is the DAT3 pin, this pin is pulled to
		 * low voltage if no card
		 */
		ret = gpio_get_value(USDHC2_CD_GPIO);

		imx_iomux_v3_setup_pad(usdhc2_dat3_pad);
		break;
	case USDHC3_BASE_ADDR:
		imx_iomux_v3_setup_pad(usdhc3_cd_pad);
		gpio_request(USDHC2_CD_GPIO, "usdhc3 cd");
		gpio_direction_input(USDHC3_CD_GPIO);

		/*
		 * Since it is the DAT3 pin, this pin is pulled to
		 * low voltage if no card
		 */
		ret = gpio_get_value(USDHC3_CD_GPIO);

		imx_iomux_v3_setup_pad(usdhc3_dat3_pad);
		break;
	}

	return ret;
}





#ifdef CONFIG_POWER
#define I2C_PMIC	0
int power_init_board(void)
{
	struct pmic *p;
	int ret;

	printf("[%s]: +++\n", __func__);

	ret = power_bd71837_init(I2C_PMIC);
	if (ret)
		printf("power init failed");

	p = pmic_get("BD71837");
	pmic_probe(p);


	/* decrease RESET key long push time from the default 10s to 10ms */
	pmic_reg_write(p, BD71837_PWRONCONFIG1, 0x0);

	/* unlock the PMIC regs */
	pmic_reg_write(p, BD71837_REGLOCK, 0x1);

	/* increase VDD_DRAM to 0.9v for 3Ghz DDR */
	pmic_reg_write(p, BD71837_BUCK5_VOLT, 0x2);

	/* increase NVCC_DRAM_1V35 to 1.35v for DDR3L */
	pmic_reg_write(p, BD71837_BUCK8_VOLT, 0x37);

	/* lock the PMIC regs */
	pmic_reg_write(p, BD71837_REGLOCK, 0x11);
	printf("[%s]: ---\n", __func__);

	return 0;
}
#endif

void spl_board_init(void)
{
	if (!IS_ENABLED(CONFIG_SPL_DISABLE_BANNER_PRINT))
		puts("Normal Boot\n");
}



#ifdef CONFIG_SPL_LOAD_FIT
int board_fit_config_name_match(const char *name)
{
	/* Just empty function now - can't decide what to choose */
	debug("%s: %s\n", __func__, name);

	return 0;
}
#endif



#define UART_PAD_CTRL		MUX_PAD_CTRL(PAD_CTL_FSEL0 |	\
					     PAD_CTL_DSE6)

static const iomux_v3_cfg_t uart_pads[] = {
	IMX8MM_PAD_UART1_RXD_UART1_RX | UART_PAD_CTRL,
	IMX8MM_PAD_UART1_TXD_UART1_TX | UART_PAD_CTRL,
};

static int tx8m_spl_iomux_setup(void)
{
	imx_iomux_v3_setup_multiple_pads(uart_pads, ARRAY_SIZE(uart_pads));
debug("%s@%d:\n", __func__, __LINE__);

	return 0;
}








void board_init_f(ulong dummy)
{
	int ret;

	memset((void *)gd, 0, sizeof(gd_t));

	arch_cpu_init();

	tx8m_spl_iomux_setup();


	timer_init();

	preloader_console_init();

	/* Clear the BSS. */
	memset(__bss_start, 0, __bss_end - __bss_start);

	ret = spl_init();
	if (ret) {
		debug("spl_init() failed: %d\n", ret);
		hang();
	}

	enable_tzc380();

#if !IS_ENABLED(CONFIG_DM_I2C)
	/* Adjust pmic voltage to 1.0V for 800M */
	setup_i2c(0, CONFIG_SYS_I2C_SPEED, 0x7f, &i2c_pad_info1);
#endif

	power_init_board();

	/* DDR initialization */
	spl_dram_init();

	board_init_r(NULL, 0); /* Clear global data */

}
