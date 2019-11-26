/*
 * Copyright 2019 Lothar Waßmann <LW@KARO-electronics.de>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <errno.h>
#include <fsl_esdhc.h>
#include <spl.h>
#include <mmc.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx8mm_pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <power/pmic.h>
#include <power/bd71837.h>
#include "ddr/ddr.h"

DECLARE_GLOBAL_DATA_PTR;

void spl_dram_init(void)
{
	ddr_init();
}

#define I2C_PAD_CTRL		MUX_PAD_CTRL(PAD_CTL_PE |	\
					     PAD_CTL_HYS |	\
					     PAD_CTL_PUE |	\
					     PAD_CTL_DSE6)

struct i2c_pads_info i2c_pad_info1 = {
	.scl = {
		.i2c_mode = IMX8MM_PAD_I2C1_SCL_I2C1_SCL | I2C_PAD_CTRL,
		.gpio_mode = IMX8MM_PAD_I2C1_SCL_GPIO5_IO14 | I2C_PAD_CTRL,
		.gp = IMX_GPIO_NR(5, 14),
	},
	.sda = {
		.i2c_mode = IMX8MM_PAD_I2C1_SDA_I2C1_SDA | I2C_PAD_CTRL,
		.gpio_mode = IMX8MM_PAD_I2C1_SDA_GPIO5_IO15 | I2C_PAD_CTRL,
		.gp = IMX_GPIO_NR(5, 15),
	},
};

struct i2c_pads_info i2c_pad_info2 = {
	.scl = {
		.i2c_mode = IMX8MM_PAD_I2C2_SCL_I2C2_SCL | I2C_PAD_CTRL,
		.gpio_mode = IMX8MM_PAD_I2C2_SCL_GPIO5_IO16 | I2C_PAD_CTRL,
		.gp = IMX_GPIO_NR(5, 16),
	},
	.sda = {
		.i2c_mode = IMX8MM_PAD_I2C2_SDA_I2C2_SDA | I2C_PAD_CTRL,
		.gpio_mode = IMX8MM_PAD_I2C2_SDA_GPIO5_IO17 | I2C_PAD_CTRL,
		.gp = IMX_GPIO_NR(5, 17),
	},
};




#define USDHC_PAD_CTRL		MUX_PAD_CTRL(PAD_CTL_PE |	\
					     PAD_CTL_PUE |	\
					     PAD_CTL_FSEL2 |	\
					     PAD_CTL_DSE6)

#define USDHC_GPIO_PAD_CTRL	MUX_PAD_CTRL(PAD_CTL_PE |	\
					     PAD_CTL_HYS |	\
					     PAD_CTL_PUE |	\
					     PAD_CTL_DSE6)

static const iomux_v3_cfg_t tx8mm_usdhc1_pads[] = {
	IMX8MM_PAD_SD1_CLK_USDHC1_CLK | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_CMD_USDHC1_CMD | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_DATA0_USDHC1_DATA0 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_DATA1_USDHC1_DATA1 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_DATA2_USDHC1_DATA2 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_DATA3_USDHC1_DATA3 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_DATA4_USDHC1_DATA4 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_DATA5_USDHC1_DATA5 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_DATA6_USDHC1_DATA6 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_DATA7_USDHC1_DATA7 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD1_STROBE_USDHC1_STROBE | USDHC_GPIO_PAD_CTRL,
	IMX8MM_PAD_SD1_RESET_B_USDHC1_RESET_B | USDHC_GPIO_PAD_CTRL,
};

static const iomux_v3_cfg_t tx8mm_usdhc2_pads[] = {
	IMX8MM_PAD_SD2_CLK_USDHC2_CLK | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD2_CMD_USDHC2_CMD | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD2_DATA0_USDHC2_DATA0 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD2_DATA1_USDHC2_DATA1 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD2_DATA2_USDHC2_DATA2 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD2_DATA3_USDHC2_DATA3 | USDHC_PAD_CTRL,
	IMX8MM_PAD_SD2_CD_B_GPIO2_IO12 | USDHC_GPIO_PAD_CTRL,
};

static const iomux_v3_cfg_t tx8mm_usdhc3_pads[] = {
	IMX8MM_PAD_NAND_WE_B_USDHC3_CLK | USDHC_PAD_CTRL,
	IMX8MM_PAD_NAND_WP_B_USDHC3_CMD | USDHC_PAD_CTRL,
	IMX8MM_PAD_NAND_DATA04_USDHC3_DATA0 | USDHC_PAD_CTRL,
	IMX8MM_PAD_NAND_DATA05_USDHC3_DATA1 | USDHC_PAD_CTRL,
	IMX8MM_PAD_NAND_DATA06_USDHC3_DATA2 | USDHC_PAD_CTRL,
	IMX8MM_PAD_NAND_DATA07_USDHC3_DATA3 | USDHC_PAD_CTRL,
	IMX8MM_PAD_NAND_DATA02_GPIO3_IO8 | USDHC_GPIO_PAD_CTRL,
};

static struct tx8m_esdhc_cfg {
	struct fsl_esdhc_cfg cfg;
	int clk;
	const iomux_v3_cfg_t *pads;
	size_t num_pads;
	int cd_gpio;
} tx8mm_sdhc_cfgs[] = {
	{
		.cfg = {
			.esdhc_base = USDHC1_BASE_ADDR,
			.max_bus_width = 8,
		},
		.clk = MXC_ESDHC_CLK,
		.pads = tx8mm_usdhc1_pads,
		.num_pads = ARRAY_SIZE(tx8mm_usdhc1_pads),
		.cd_gpio = -EINVAL,
	},
	{
		.cfg = {
			.esdhc_base = USDHC2_BASE_ADDR,
			.max_bus_width = 4,
		},
		.clk = MXC_ESDHC2_CLK,
		.pads = tx8mm_usdhc2_pads,
		.num_pads = ARRAY_SIZE(tx8mm_usdhc2_pads),
		.cd_gpio = IMX_GPIO_NR(2, 12),
	},
	{
		.cfg = {
			.esdhc_base = USDHC3_BASE_ADDR,
			.max_bus_width = 4,
		},
		.clk = MXC_ESDHC3_CLK,
		.pads = tx8mm_usdhc3_pads,
		.num_pads = ARRAY_SIZE(tx8mm_usdhc3_pads),
		.cd_gpio = IMX_GPIO_NR(3, 8),
	},
};

int board_mmc_init(bd_t *bis)
{
	int ret;
	/*
	 * According to the board_mmc_init() the following map is done:
	 * (U-Boot device node)    (Physical Port)
	 * mmc0                    USDHC1 (eMMC)
	 * mmc1                    USDHC2
	 * mmc2                    USDHC3
	 */

	for (size_t i = 0; i < CONFIG_SYS_FSL_USDHC_NUM; i++) {
		struct mmc *mmc;
		struct tx8m_esdhc_cfg *cfg;

		if (i >= ARRAY_SIZE(tx8mm_sdhc_cfgs)) {
			printf("Warning: more USDHC controllers configured (%u) than supported by the board: %zu\n",
			       CONFIG_SYS_FSL_USDHC_NUM,
			       ARRAY_SIZE(tx8mm_sdhc_cfgs));
			return -EINVAL;
		}

		cfg = &tx8mm_sdhc_cfgs[i];
		cfg->cfg.sdhc_clk = mxc_get_clock(cfg->clk);
		imx_iomux_v3_setup_multiple_pads(cfg->pads, cfg->num_pads);

		ret = fsl_esdhc_initialize(bis, &cfg->cfg);
		if (ret) {
			printf("Failed to initialize MMC%zu: %d\n", i, ret);
			continue;
		}

		mmc = find_mmc_device(i);
		if (mmc == NULL) {
			printf("mmc device %zi not found\n", i);
			continue;
		}
		if (board_mmc_getcd(mmc)) {
			ret = mmc_init(mmc);
			if (ret) {
				printf("mmc_init(mmc%zi) failed: %d\n", i, ret);
			}
		} else {
			debug("No Medium found in MMC slot %zi\n", i);
		}
	}
	return 0;
}

static inline struct tx8m_esdhc_cfg *to_tx8m_esdhc_cfg(struct fsl_esdhc_cfg *priv)
{
	for (size_t i = 0; i < ARRAY_SIZE(tx8mm_sdhc_cfgs); i++) {
		struct tx8m_esdhc_cfg *cfg = &tx8mm_sdhc_cfgs[i];

		if (priv->esdhc_base == cfg->cfg.esdhc_base)
			return cfg;
	}
	return NULL;
}

int board_mmc_getcd(struct mmc *mmc)
{
	struct tx8m_esdhc_cfg *cfg = to_tx8m_esdhc_cfg(mmc->priv);

	if (cfg == NULL) {
		printf("Failed to lookup CD GPIO for MMC dev %p\n", mmc->priv);
		return 0;
	}
	if (cfg->cd_gpio < 0)
		return 1;

	return !gpio_get_value(cfg->cd_gpio);
}

#ifdef CONFIG_POWER
#define I2C_PMIC	0
int power_init_board(void)
{
	struct pmic *p;
	int ret;

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

	/* Clear global data */
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
	setup_i2c(1, CONFIG_SYS_I2C_SPEED, 0x7f, &i2c_pad_info2);

#endif
	power_init_board();

	/* DDR initialization */
	spl_dram_init();

	board_init_r(NULL, 0);
}
