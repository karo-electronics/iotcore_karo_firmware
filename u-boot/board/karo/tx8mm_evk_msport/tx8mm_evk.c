/*
 * Copyright 2018 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <console.h>
#include <malloc.h>
#include <errno.h>
#include <asm/io.h>
#include <miiphy.h>
#include <netdev.h>
#include <led.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm-generic/gpio.h>
#include <fsl_esdhc.h>
#include <mmc.h>
#include <asm/arch/imx8mm_pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/gpio.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/arch/clock.h>
#include <asm/armv8/mmu.h>
#include <spl.h>
#include <asm/mach-imx/dma.h>
#include <power/pmic.h>
#include <power/bd71837.h>
#include <usb.h>
#include <sec_mipi_dsim.h>
#include <imx_mipi_dsi_bridge.h>
#include <mipi_dsi_panel.h>
#include <asm/mach-imx/video.h>
#include <dm/uclass.h>

DECLARE_GLOBAL_DATA_PTR;

#define UART_PAD_CTRL	(PAD_CTL_DSE6 | PAD_CTL_FSEL1)
#define WDOG_PAD_CTRL	(PAD_CTL_DSE6 | PAD_CTL_ODE | PAD_CTL_PUE | PAD_CTL_PE)
#define I2C_PAD_CTRL	(PAD_CTL_DSE6 | PAD_CTL_HYS | PAD_CTL_PUE | PAD_CTL_PE)
#define GPIO_PAD_CTRL	(PAD_CTL_DSE2 | PAD_CTL_HYS)

static iomux_v3_cfg_t const uart_pads[] = {
	/* pads of the first UART, pins 59-62 */
	IMX8MM_PAD_UART1_TXD_UART1_TX | MUX_PAD_CTRL(UART_PAD_CTRL),
	IMX8MM_PAD_UART1_RXD_UART1_RX | MUX_PAD_CTRL(UART_PAD_CTRL),
	IMX8MM_PAD_UART3_TXD_UART1_RTS_B | MUX_PAD_CTRL(UART_PAD_CTRL),
	IMX8MM_PAD_UART3_RXD_UART1_CTS_B | MUX_PAD_CTRL(UART_PAD_CTRL),

	/* pads of the second UART, pins 63-66 */
	IMX8MM_PAD_UART2_TXD_UART2_TX | MUX_PAD_CTRL(UART_PAD_CTRL),
	IMX8MM_PAD_UART2_RXD_UART2_RX | MUX_PAD_CTRL(UART_PAD_CTRL),
	IMX8MM_PAD_UART4_TXD_UART2_RTS_B | MUX_PAD_CTRL(UART_PAD_CTRL),
	IMX8MM_PAD_UART4_RXD_UART2_CTS_B | MUX_PAD_CTRL(UART_PAD_CTRL),

	/* pads of the second UART, pins 67-71 */
	IMX8MM_PAD_ECSPI1_MOSI_UART3_TX | MUX_PAD_CTRL(UART_PAD_CTRL),
	IMX8MM_PAD_ECSPI1_SCLK_UART3_RX | MUX_PAD_CTRL(UART_PAD_CTRL),
	IMX8MM_PAD_ECSPI1_SS0_UART3_RTS_B | MUX_PAD_CTRL(UART_PAD_CTRL),
	IMX8MM_PAD_ECSPI1_MISO_UART3_CTS_B | MUX_PAD_CTRL(UART_PAD_CTRL),
};



/* i2c busses used on TX8MMini Evk

	I2C1: module interal, connected to PMIC
	I2C2: connected to module pins 41/40 connected to 	X11 of EVK
                                                    	SN65DS183 MIPI/LVDS converter of EVK
														SGTL5000 of EVK
														MPC7940 of EVK
	I2C3: connected to module pins 148/149 connected to X10(18) / X9(19) of EVK
	I2C4: connected to module pins 150/151 connecte to X9(20), X14(1) / X10(19) 0f EVK

	we only configure I2C1 and I2C2 here

*/

struct i2c_pads_info i2c_pad_info1 = {
	.scl = {
		.i2c_mode = IMX8MM_PAD_I2C1_SCL_I2C1_SCL | MUX_PAD_CTRL(I2C_PAD_CTRL) | MUX_MODE_SION,
		.gpio_mode = IMX8MM_PAD_I2C1_SCL_GPIO5_IO14 | MUX_PAD_CTRL(I2C_PAD_CTRL),
		.gp = IMX_GPIO_NR(5, 14),
	},
	.sda = {
		.i2c_mode = IMX8MM_PAD_I2C1_SDA_I2C1_SDA | MUX_PAD_CTRL(I2C_PAD_CTRL) | MUX_MODE_SION,
		.gpio_mode = IMX8MM_PAD_I2C1_SDA_GPIO5_IO15 | MUX_PAD_CTRL(I2C_PAD_CTRL),
		.gp = IMX_GPIO_NR(5, 15),
	},
};

struct i2c_pads_info i2c_pad_info2 = {
	.scl = {
		.i2c_mode = IMX8MM_PAD_I2C2_SCL_I2C2_SCL | MUX_PAD_CTRL(I2C_PAD_CTRL) | MUX_MODE_SION,
		.gpio_mode = IMX8MM_PAD_I2C2_SCL_GPIO5_IO16 | MUX_PAD_CTRL(I2C_PAD_CTRL),
		.gp = IMX_GPIO_NR(5, 16),
	},
	.sda = {
		.i2c_mode = IMX8MM_PAD_I2C2_SDA_I2C2_SDA | MUX_PAD_CTRL(I2C_PAD_CTRL) | MUX_MODE_SION,
		.gpio_mode = IMX8MM_PAD_I2C2_SDA_GPIO5_IO17 | MUX_PAD_CTRL(I2C_PAD_CTRL),
		.gp = IMX_GPIO_NR(5, 17),
	},
};



#ifdef CONFIG_FSL_FSPI
#define QSPI_PAD_CTRL	(PAD_CTL_DSE2 | PAD_CTL_HYS)
static iomux_v3_cfg_t const qspi_pads[] = {
	IMX8MM_PAD_NAND_ALE_QSPI_A_SCLK | MUX_PAD_CTRL(QSPI_PAD_CTRL | PAD_CTL_PE | PAD_CTL_PUE),
	IMX8MM_PAD_NAND_CE0_B_QSPI_A_SS0_B | MUX_PAD_CTRL(QSPI_PAD_CTRL),

	IMX8MM_PAD_NAND_DATA00_QSPI_A_DATA0 | MUX_PAD_CTRL(QSPI_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA01_QSPI_A_DATA1 | MUX_PAD_CTRL(QSPI_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA02_QSPI_A_DATA2 | MUX_PAD_CTRL(QSPI_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA03_QSPI_A_DATA3 | MUX_PAD_CTRL(QSPI_PAD_CTRL),
};

int board_qspi_init(void)
{
	imx_iomux_v3_setup_multiple_pads(qspi_pads, ARRAY_SIZE(qspi_pads));

	set_clk_qspi();

	return 0;
}
#endif



/* only ECSPI2 is available on TX8MM EVK */
#ifdef CONFIG_MXC_SPI
#define SPI_PAD_CTRL	(PAD_CTL_DSE2 | PAD_CTL_HYS)

static iomux_v3_cfg_t const ecspi2_pads[] = {
	IMX8MM_PAD_ECSPI2_SCLK_ECSPI2_SCLK | MUX_PAD_CTRL(SPI_PAD_CTRL),
	IMX8MM_PAD_ECSPI2_MOSI_ECSPI2_MOSI | MUX_PAD_CTRL(SPI_PAD_CTRL),
	IMX8MM_PAD_ECSPI2_MISO_ECSPI2_MISO | MUX_PAD_CTRL(SPI_PAD_CTRL),
	IMX8MM_PAD_ECSPI2_SS0_GPIO5_IO13 | MUX_PAD_CTRL(NO_PAD_CTRL),
};

static void setup_spi(void)
{
	imx_iomux_v3_setup_multiple_pads(ecspi2_pads, ARRAY_SIZE(ecspi2_pads));
	gpio_request(IMX_GPIO_NR(5, 13), "ECSPI2 CS");
}

int board_spi_cs_gpio(unsigned bus, unsigned cs)
{
	if (bus == 0) {
		printf("%s: error, requested cs gpio for unsupported spi bus %d\n",
		       __func__, bus);
		return -1;
	}
	else
		return IMX_GPIO_NR(5, 13);
}
#endif



/* NAND is not supported by the TX8MMini EVK */
#ifdef CONFIG_NAND_MXS
#define NAND_PAD_CTRL	(PAD_CTL_DSE6 | PAD_CTL_FSEL2 | PAD_CTL_HYS)
#define NAND_PAD_READY0_CTRL (PAD_CTL_DSE6 | PAD_CTL_FSEL2 | PAD_CTL_PUE)
static iomux_v3_cfg_t const gpmi_pads[] = {
	IMX8MM_PAD_NAND_ALE_RAWNAND_ALE | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_CE0_B_RAWNAND_CE0_B | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_CLE_RAWNAND_CLE | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA00_RAWNAND_DATA00 | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA01_RAWNAND_DATA01 | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA02_RAWNAND_DATA02 | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA03_RAWNAND_DATA03 | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA04_RAWNAND_DATA04 | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA05_RAWNAND_DATA05	| MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA06_RAWNAND_DATA06	| MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_DATA07_RAWNAND_DATA07	| MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_RE_B_RAWNAND_RE_B | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_READY_B_RAWNAND_READY_B | MUX_PAD_CTRL(NAND_PAD_READY0_CTRL),
	IMX8MM_PAD_NAND_WE_B_RAWNAND_WE_B | MUX_PAD_CTRL(NAND_PAD_CTRL),
	IMX8MM_PAD_NAND_WP_B_RAWNAND_WP_B | MUX_PAD_CTRL(NAND_PAD_CTRL),
};

static void setup_gpmi_nand(void)
{
	printf("%s: error, trying to initialise unsupported NAND flash\n",
		       __func__);

	imx_iomux_v3_setup_multiple_pads(gpmi_pads, ARRAY_SIZE(gpmi_pads));
}
#endif  /* CONFIG_NAND_MXS */



int board_early_init_f(void)
{


	imx_iomux_v3_setup_multiple_pads(uart_pads, ARRAY_SIZE(uart_pads));





#ifdef CONFIG_NAND_MXS
	setup_gpmi_nand(); /* SPL will call the board_early_init_f */
#endif

	return 0;
}

#ifdef CONFIG_BOARD_POSTCLK_INIT
int board_postclk_init(void)
{
	/* TODO */
	return 0;
}
#endif


int dram_init(void)
{
	/* rom_pointer[1] contains the size of RAM occupied by TEE */
	if (rom_pointer[1])
		gd->ram_size = PHYS_SDRAM_SIZE - ALIGN(rom_pointer[1], PAGE_SIZE);
	else
		gd->ram_size = PHYS_SDRAM_SIZE;

	return 0;
}

int board_fix_fdt(void *blob)
{
	return 0;
}


#ifdef CONFIG_OF_BOARD_SETUP
#include <asm/setup.h>
#include <asm/bootm.h>

int ft_board_setup(void *blob, bd_t *bd)
{
	struct tag_serialnr serno;
	char serno_str[64 / 4 + 1];

	get_board_serial(&serno);
	snprintf(serno_str, sizeof(serno_str), "%08x%08x",
		 serno.high, serno.low);

	printf("serial-number: %s\n", serno_str);

	fdt_setprop(blob, 0, "serial-number", serno_str, strlen(serno_str));
	fsl_fdt_fixup_dr_usb(blob, bd);
	return 0;
}
#endif








#ifdef CONFIG_FEC_MXC

#define MDIO_PAD_CTRL		MUX_PAD_CTRL(PAD_CTL_DSE6 |	\
					        PAD_CTL_PE |	\
					        PAD_CTL_PUE)

#define FEC_IN_PAD_CTRL		MUX_PAD_CTRL(PAD_CTL_FSEL2)

#define FEC_OUT_PAD_CTRL	MUX_PAD_CTRL(PAD_CTL_FSEL2 |	\
					     PAD_CTL_DSE6)

static const iomux_v3_cfg_t tx8mm_fec_pads[] = {
	IMX8MM_PAD_ENET_MDC_ENET1_MDC | MDIO_PAD_CTRL, /* 0x146 */
	IMX8MM_PAD_ENET_MDIO_ENET1_MDIO | MDIO_PAD_CTRL,
	IMX8MM_PAD_ENET_TD2_ENET1_TX_CLK | MUX_MODE_SION | FEC_IN_PAD_CTRL, /* 0x40000016 */
	IMX8MM_PAD_ENET_TD0_ENET1_RGMII_TD0 | FEC_OUT_PAD_CTRL, /* 0x16 */
	IMX8MM_PAD_ENET_TD1_ENET1_RGMII_TD1 | FEC_OUT_PAD_CTRL, /* 0x16 */
	IMX8MM_PAD_ENET_RD0_ENET1_RGMII_RD0 | FEC_IN_PAD_CTRL, /* 0x90 */
	IMX8MM_PAD_ENET_RD1_ENET1_RGMII_RD1 | FEC_IN_PAD_CTRL, /* 0x90 */
	IMX8MM_PAD_ENET_RXC_ENET1_RX_ER | FEC_IN_PAD_CTRL, /* 0x90 */
	IMX8MM_PAD_ENET_RX_CTL_ENET1_RGMII_RX_CTL | FEC_IN_PAD_CTRL, /* 0x90 */
	IMX8MM_PAD_ENET_TX_CTL_ENET1_RGMII_TX_CTL | FEC_OUT_PAD_CTRL, /* 0x16 */
};

static int tx8mm_etnphy_init(void)
{
	int ret;
	struct gpio_desc enet0_pwr;
	struct gpio_desc enet0_rst;

	ret = dm_gpio_lookup_name("gpio1_23", &enet0_pwr);
	if (ret) {
		printf("Failed to lookup ENET0_PWR GPIO: %d\n", ret);
		return ret;
	}

	ret = dm_gpio_lookup_name("gpio1_29", &enet0_rst);
	if (ret) {
		printf("Failed to lookup ENET0_RST GPIO: %d\n", ret);
		return ret;
	}

	ret = dm_gpio_request(&enet0_pwr, "ENET0_PWR");
	if (ret) {
		printf("Failed to request ENET0_PWR GPIO: %d\n", ret);
		return ret;
	}

	ret = dm_gpio_request(&enet0_rst, "ENET0_RST");
	if (ret) {
		printf("Failed to request ENET0_RST GPIO: %d\n", ret);
		return ret;
	}

	dm_gpio_set_dir_flags(&enet0_rst, GPIOD_IS_OUT);
	dm_gpio_set_dir_flags(&enet0_pwr, GPIOD_IS_OUT);
	dm_gpio_set_value(&enet0_rst, 0);
	dm_gpio_set_value(&enet0_pwr, 1);

	imx_iomux_v3_setup_multiple_pads(tx8mm_fec_pads,
					 ARRAY_SIZE(tx8mm_fec_pads));

	mdelay(25);
	dm_gpio_set_value(&enet0_rst, 1);
	mdelay(10);
	return 0;
}


static int tx8mm_setup_fec(void)
{
	struct iomuxc_gpr_base_regs *iomuxc_gpr_regs =
		(void *)IOMUXC_GPR_BASE_ADDR;
	unsigned char mac[6];

	int ret;

	set_clk_enet(ENET_50MHZ);

	/* Use 50M anatop REF_CLK1 for ENET1, not from external */
	setbits_le32(&iomuxc_gpr_regs->gpr[1],
		     IOMUXC_GPR_GPR1_GPR_ENET1_TX_CLK_SEL_MASK);

	imx_get_mac_from_fuse(0, mac);
	printf("MAC addr: %pM\n", mac);

/*
	ret = eth_env_set_enetaddr("ethaddr", mac);

	if (ret)
		printf("[%s]: error, setting ethernet address\n", __func__);
*/
	return tx8mm_etnphy_init();
}

int board_phy_config(struct phy_device *phydev)
{
	if (phydev->drv->config)
		phydev->drv->config(phydev);

	return 0;
}
#else
static inline int tx8mm_setup_fec(void)
{
	return 0;
}
#endif





















#ifdef CONFIG_USB
#define USB_H1_VBUS		IMX_GPIO_NR(1, 14)
#define USB_H1_OC		IMX_GPIO_NR(1, 15)

#define USB_OTG_VBUS	IMX_GPIO_NR(1, 12)
#define USB_OTG_OC		IMX_GPIO_NR(1, 13)

static iomux_v3_cfg_t const usb_pads[] = {
	IMX8MM_PAD_GPIO1_IO14_GPIO1_IO14 | MUX_PAD_CTRL(GPIO_PAD_CTRL),
	IMX8MM_PAD_GPIO1_IO15_GPIO1_IO15 | MUX_PAD_CTRL(GPIO_PAD_CTRL),
	IMX8MM_PAD_GPIO1_IO12_GPIO1_IO12 | MUX_PAD_CTRL(GPIO_PAD_CTRL),
	IMX8MM_PAD_GPIO1_IO13_GPIO1_IO13 | MUX_PAD_CTRL(GPIO_PAD_CTRL),
};


/**
 * board_usb_phy_mode - override usb phy mode
 * @port:	usb host/otg port
 *
 * Target board specific, override usb_phy_mode.
 * When usb-otg is used as usb host port, iomux pad usb_otg_id can be
 * left disconnected in this case usb_phy_mode will not be able to identify
 * the phy mode that usb port is used.
  *
 * Return: USB_INIT_DEVICE or USB_INIT_HOST
 */
int board_usb_phy_mode(int port)
{
	printf("[%s]: +++   port=%d\n", __func__, port);

	printf("[%s]: --\n", __func__);

	return USB_INIT_HOST;
}




/**
 * board_ehci_hcd_init - set usb vbus voltage
 * @port:      usb otg port
 *
 * Target board specific, setup iomux pad to setup supply vbus voltage
 * for usb otg port. 
 *
 * Return: 0 Success
 */
int board_ehci_hcd_init(int port)
{
	printf("[%s]: +++   port=%d\n", __func__, port);

	imx_iomux_v3_setup_multiple_pads(usb_pads, ARRAY_SIZE(usb_pads));

	gpio_request(USB_H1_VBUS, "usb_h1_pwr");
	gpio_request(USB_H1_OC, "usb_h1_oc");
	gpio_request(USB_OTG_VBUS, "usb_otg_vbus");
	gpio_request(USB_OTG_OC, "usb_otg_oc");


	gpio_direction_input(USB_H1_OC);
	gpio_direction_input(USB_OTG_OC);



	if (port == 0)
		gpio_direction_output(USB_OTG_VBUS, 1);
	if (port == 1)
		gpio_direction_output(USB_H1_VBUS, 1);
	printf("[%s]: ---\n", __func__);
	return 0;
}



/**
 * board_ehci_power - enables/disables usb vbus voltage
 * @port:      usb otg port
 * @on:        on/off vbus voltage
 *
 * Enables/disables supply vbus voltage for usb otg port.
  *
 * Return: 0 Success
 */
int board_ehci_power(int port, int on)
{
	printf("[%s]: +++   port=%d   on=%d\n", __func__, port, on);
	printf("[%s]: ---\n", __func__);
	return 0;
}







/**
 * board_ehci_usb_phy_mode - override usb phy mode
 * @port:	usb host/otg port
 *
 * Target board specific, override usb_phy_mode.
 * When usb-otg is used as usb host port, iomux pad usb_otg_id can be
 * left disconnected in this case usb_phy_mode will not be able to identify
 * the phy mode that usb port is used.
 * Machine file overrides board_usb_phy_mode.
 * When the extcon property is set in DTB, machine must provide this function, otherwise
 * it will default return HOST.
 *
 * Return: USB_INIT_DEVICE or USB_INIT_HOST
 */
int board_ehci_usb_phy_mode(struct udevice *dev)
{
	printf("[%s]: +++\n", __func__);

	printf("[%s]: ---   returning USB_INIT_HOST !!!\n", __func__);

	return USB_INIT_HOST;
}


int board_usb_init(int index, enum usb_init_type init)
{
	int ret = 0;

	printf("\n[%s]: +++ index=%d, type=%d\n", __func__, index, init);


	imx8m_usb_power(index, true);


	return ret;
}




int board_usb_cleanup(int index, enum usb_init_type init)
{
	int ret = 0;

	printf("[%s]: +++ index=%d, type=%d\n", __func__, index, init);


	imx8m_usb_power(index, false);
	return ret;
}










#endif

static const iomux_v3_cfg_t tx8mm_gpio_pads[] = {
	IMX8MM_PAD_SD2_RESET_B_GPIO2_IO19 | MUX_PAD_CTRL(GPIO_PAD_CTRL),
};





#ifdef CONFIG_SHOW_ACTIVITY
enum {
	LED_STATE_INIT = -1,
	LED_STATE_OFF,
	LED_STATE_ON,
	LED_STATE_DISABLED,
};

static int led_state = LED_STATE_DISABLED;
static bool tx8m_temp_check_enabled = true;
static struct udevice *leddev;
static struct udevice *thermaldev;

#define TEMPERATURE_HOT		80
#define TEMPERATURE_MIN		-40

static inline int calc_blink_rate(void)
{
	int cpu_temp;
	static int last_temp = INT_MAX;
	static int avg_count;

	if (!tx8m_temp_check_enabled)
		return CONFIG_SYS_HZ;

	if (!thermaldev || thermal_get_temp(thermaldev, &cpu_temp))
		return CONFIG_SYS_HZ / 2;

	if (last_temp == INT_MAX) {
		last_temp = cpu_temp;
	} else if (cpu_temp != last_temp) {
		static int cpu_temps[4];

		if (thermal_get_temp(thermaldev, &cpu_temps[avg_count]))
			return CONFIG_SYS_HZ / 2;
		if (++avg_count >= ARRAY_SIZE(cpu_temps)) {
			int bad = -1;
			int i;

			for (i = 0; i < avg_count; i++) {
				if (cpu_temp != cpu_temps[i])
					bad = i;
			}
			if (bad < 0) {
				debug("CPU temperature changed from %d to %d\n",
				      last_temp, cpu_temp);
				last_temp = cpu_temp;
			} else {
				debug("Spurious CPU temperature reading %d -> %d -> %d\n",
				      cpu_temp, cpu_temps[bad], cpu_temps[i - 1]);
			}
			avg_count = 0;
		}
	} else {
		avg_count = 0;
	}
	return CONFIG_SYS_HZ + CONFIG_SYS_HZ / 10 -
		(last_temp - TEMPERATURE_MIN) * CONFIG_SYS_HZ /
		(TEMPERATURE_HOT - TEMPERATURE_MIN);
}

void show_activity(int arg)
{
	static int blink_rate;
	static ulong last;
	int ret;

//	printf("[%s]:+++ led_state = %d\n", __func__, led_state);
	if (led_state == LED_STATE_DISABLED)
		return;

	if (led_state == LED_STATE_INIT) {
		last = get_timer(0);
		ret = led_set_state(leddev, LEDST_ON);
		if (ret == 0)
			led_state = LED_STATE_ON;
		else
			led_state = LED_STATE_DISABLED;
		blink_rate = calc_blink_rate();
	} else {
		if (get_timer(last) > blink_rate) {
			blink_rate = calc_blink_rate();
			last = get_timer(0);
			if (led_state == LED_STATE_ON) {
				ret = led_set_state(leddev, LEDST_OFF);
			} else {
				ret = led_set_state(leddev, LEDST_ON);
			}
			if (ret == 0)
				led_state = 1 - led_state;
			else
				led_state = LED_STATE_DISABLED;
		}
	}

}

static void tx8m_led_init(void)
{
	int ret;

	ret = led_get_by_label("Heartbeat", &leddev);
	if (ret) {
		printf("Failed to find LED device: %d\n", ret);
		return;
	}

	ret = uclass_get_device_by_name(UCLASS_THERMAL, "cpu-thermal",
					&thermaldev);
	if (ret)
		printf("Failed to find THERMAL device: %d\n", ret);

	led_state = LED_STATE_INIT;
}
#else
static inline void tx8m_led_init(void)
{
printf("%s@%d: \n", __func__, __LINE__);
}
#endif



int board_init(void)
{

#ifdef CONFIG_MXC_SPI
	setup_spi();
#endif

#ifdef CONFIG_FEC_MXC
	tx8mm_setup_fec();
#endif

#ifdef CONFIG_FSL_FSPI
	board_qspi_init();
#endif

	/* I2C initialization */
	setup_i2c(1, CONFIG_SYS_I2C_SPEED, 0x7f, &i2c_pad_info1);
	setup_i2c(2, CONFIG_SYS_I2C_SPEED, 0x7f, &i2c_pad_info2);

#ifdef CONFIG_USB_TX8MM_EVK
	setup_usb();
#endif

	imx_iomux_v3_setup_multiple_pads(tx8mm_gpio_pads,
					 ARRAY_SIZE(tx8mm_gpio_pads));
	tx8m_led_init();

	return 0;
}

int board_mmc_get_env_dev(int devno)
{
	return devno - 1;
}

int mmc_map_to_kernel_blk(int devno)
{
	return devno + 1;
}




#ifdef CONFIG_VIDEO
static const struct sec_mipi_dsim_plat_data imx8mm_mipi_dsim_plat_data = {
	.version	= 0x1060200,
	.max_data_lanes = 4,
	.max_data_rate  = 1500000000ULL,
	.reg_base = MIPI_DSI_BASE_ADDR,
	.gpr_base = CSI_BASE_ADDR + 0x8000,
};

#define DSI_DDR_MODE 0

struct mipi_dsi_client_dev dsi83_dev = {
	.channel = 0,
	.lanes = 4,
	.format = MIPI_DSI_FMT_RGB888,
	.mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_SYNC_PULSE,
		/*	  MIPI_DSI_MODE_EOT_PACKET | MIPI_DSI_MODE_VIDEO_HSE, */
	.name = "DSI83",
};

#define DISPLAY_MIX_SFT_RSTN_CSR	0x00
#define DISPLAY_MIX_CLK_EN_CSR		0x04

   /* 'DISP_MIX_SFT_RSTN_CSR' bit fields */
#define BUS_RSTN_BLK_SYNC_SFT_EN	BIT(6)

   /* 'DISP_MIX_CLK_EN_CSR' bit fields */
#define LCDIF_PIXEL_CLK_SFT_EN		BIT(7)
#define LCDIF_APB_CLK_SFT_EN		BIT(6)

static void disp_mix_bus_rstn_reset(ulong gpr_base, bool reset)
{
	if (!reset)
		/* release reset */
		setbits_le32(gpr_base + DISPLAY_MIX_SFT_RSTN_CSR,
			     BUS_RSTN_BLK_SYNC_SFT_EN);
	else
		/* hold reset */
		clrbits_le32(gpr_base + DISPLAY_MIX_SFT_RSTN_CSR,
			     BUS_RSTN_BLK_SYNC_SFT_EN);
}

static void disp_mix_lcdif_clks_enable(ulong gpr_base, bool enable)
{
	if (enable)
		/* enable lcdif clks */
		setbits_le32(gpr_base + DISPLAY_MIX_CLK_EN_CSR,
			     LCDIF_PIXEL_CLK_SFT_EN | LCDIF_APB_CLK_SFT_EN);
	else
		/* disable lcdif clks */
		clrbits_le32(gpr_base + DISPLAY_MIX_CLK_EN_CSR,
			     LCDIF_PIXEL_CLK_SFT_EN | LCDIF_APB_CLK_SFT_EN);
}

#define LINE_LENGTH	1280
#define H_FRONT_PORCH	64
#define H_BACK_PORCH	4
#define HSYNC_LEN	1
#define VERT_SIZE	800
#define V_FRONT_PORCH	40
#define V_BACK_PORCH	1
#define VSYNC_LEN	1
#define VREFRESH	60

#define BPP	24
#define SYNC_DELAY	64
#define HTOTAL		(HSYNC_LEN + H_BACK_PORCH + LINE_LENGTH + H_FRONT_PORCH)
#define VTOTAL		(VSYNC_LEN + V_BACK_PORCH + VERT_SIZE + V_FRONT_PORCH)
#define PCLK		(HTOTAL * VTOTAL * VREFRESH)
#define DSI_CLK		(PCLK * BPP / 4 / (!!DSI_DDR_MODE + 1))
#define DSI_CLK_DIV	((DSI_CLK + PCLK - 1) / PCLK)
#define LVDS_CLK	(DSI_CLK / DSI_CLK_DIV)
#define LVDS_CLK_DIV	((LVDS_CLK + 12500000) / 25000000 - 1)


static void tx8m_print_video_params(void) 
{
	printf("LINE_LENGTH ............... %d\n", LINE_LENGTH);
	printf("H_FRONT_PORCH ............. %d\n", H_FRONT_PORCH);
	printf("H_BACK_PORCH .............. %d\n", H_BACK_PORCH);
	printf("HSYNC_LEN ................. %d\n", HSYNC_LEN);
	printf("VERT_SIZE ................. %d\n", VERT_SIZE);
	printf("V_FRONT_PORCH ............. %d\n", V_FRONT_PORCH);
	printf("V_BACK_PORCH .............. %d\n", V_BACK_PORCH);
	printf("VSYNC_LEN ................. %d\n", VSYNC_LEN);
	printf("VREFRESH .................. %d\n", VREFRESH);

	printf("BPP ....................... %d\n", BPP);
	printf("SYNC_DELAY ................ %d\n", SYNC_DELAY);
	printf("HTOTAL .................... %d\n", HTOTAL);
	printf("VTOTAL .................... %d\n", VTOTAL);
	printf("PCLK ...................... %u hz\n", PCLK);
	printf("DSI_CLK ................... %u hz\n", DSI_CLK);
	printf("DSI_CLK_DIV ............... %d\n", DSI_CLK_DIV);
	printf("LVDS_CLK .................. %u hz\n", LVDS_CLK);
	printf("LVDS_CLK_DIV .............. %d\n", LVDS_CLK_DIV);


}



static struct dsi83_data {
	u8 addr;
	u8 val;
	u8 mask;
} dsi83_data[] = {
	{ 0x09, 1, },
	{ 0x0d, 0x00, 0x01, },
	{ 0x10, 0x00, 0x18, }, // DSI lanes 0x00: 4 lanes; 0x08: 3 lanes
	{ 0x10, 0x00, 0x01, }, // SOT_ERR_TOL_DIS
	{ 0x11, 0xc0, 0xc0, }, // DSI DATA equalization
	{ 0x11, 0x0c, 0x0c, }, // DSI clock equalization
	{ 0x12, DSI_CLK / 1000000 / 5, }, // DSI clk range 8: 40..45MHz; 9: 45..50MHz; ...
	{ 0x0a, 0x01, 0x01, },
	{ 0x0a, LVDS_CLK_DIV << 1, 0x0e, },
	{ 0x0b, 0x00, 0x03, },
	{ 0x0b, (DSI_CLK_DIV - 1) << 3, 0x7c, },
	{ 0x18, 0x60, 0xe0, }, // DE_NEG HS_NEG VS_NEG
	{ 0x18, 0x08, 0x9, }, // CHA_24BPP_MODE CHA24BPP_FORMAT1
	{ 0x20, LINE_LENGTH % 256, },
	{ 0x21, LINE_LENGTH / 256, },
	{ 0x24, VERT_SIZE % 256, },
	{ 0x25, VERT_SIZE / 256, },
	{ 0x28, SYNC_DELAY % 256, },
	{ 0x29, SYNC_DELAY / 256, },
	{ 0x2c, HSYNC_LEN % 256, },
	{ 0x2d, HSYNC_LEN / 256, },
	{ 0x30, VSYNC_LEN % 256, },
	{ 0x31, VSYNC_LEN / 256, },
	{ 0x34, H_BACK_PORCH + HSYNC_LEN, },
	{ 0x36, V_BACK_PORCH + VSYNC_LEN, },
	{ 0x38, H_FRONT_PORCH, },
	{ 0x3a, V_FRONT_PORCH, },
//	{ 0x3c, 0x10, 0x10, }, // enable CHA_TEST_PATTERN
	{ 0x3c, 0x00, },
	{ 0x0d, 0x01, 0x01, }, // enable PLL
	{ 0xe5, 0xfd, 0xfd, }, // clear error status
};

#define DSI83_SLAVE_ADDR	0x2c

static int dsi83_init(void)
{
	int ret;
	struct udevice *dev;
	struct udevice *chip;
	u8 val;


	debug("DSI clock: %u.%03uMHz dsi_clk_div=%u\n",
	      DSI_CLK / 1000000, DSI_CLK / 1000 % 1000, DSI_CLK_DIV);
	debug("LVDS clock: %u.%03uMHz lvds_clk_range=%u\n",
	      LVDS_CLK / 1000000, LVDS_CLK / 1000 % 1000, LVDS_CLK_DIV);

	ret = uclass_get_device_by_seq(UCLASS_I2C, 1, &dev);
	if (ret) {
		printf("%s: Failed to find I2C bus device: %d\n",
		       __func__, ret);
		return ret;
	}
	ret = dm_i2c_probe(dev, DSI83_SLAVE_ADDR, 0x0, &chip);
	if (ret) {
		printf("%s: I2C probe failed for slave addr %02x: %d\n",
		       __func__, DSI83_SLAVE_ADDR, ret);
		return ret;
	}
	for (size_t i = 0; i < ARRAY_SIZE(dsi83_data); i++) {
		struct dsi83_data *p = &dsi83_data[i];

		ret = dm_i2c_read(chip, p->addr, &val, 1);
		if (ret) {
			printf("%s: Failed to read reg %02x\n",
			       __func__, p->val);
			return ret;
		}
		debug("%s@%d: Read %02x from reg %02x\n",
		      __func__, __LINE__, val, p->addr);
		val = (val & ~p->mask) | p->val;
		debug("%s@%d: Writing %02x to reg %02x\n",
		      __func__, __LINE__, val, p->addr);
		ret = dm_i2c_write(chip, p->addr, &val, 1);
		if (ret) {
			printf("%s: Failed to write %02x to reg %02x\n",
			       __func__, p->val, p->addr);
			return ret;
		}
	}

	mdelay(5);

	ret = dm_i2c_read(chip, 0xe5, &val, 1);
		if (ret) {
			printf("%s: Failed to read reg %02x\n",
			       __func__, 0xE5);
			return ret;
		}
	if (val!=0)
		printf("%s: warning, failed to init dsi83, register E5 returned 0x%02x\n", __func__, val);
	else
		printf("%s: success, dsi83 pll is locked, register E5 returned 0x%02x\n", __func__, val);

	return 0;
}

static const iomux_v3_cfg_t tx8mm_lcd_pads[] = {
	IMX8MM_PAD_GPIO1_IO01_GPIO1_IO1 | MUX_PAD_CTRL(GPIO_PAD_CTRL),    /* pin 42 LED_PWM */
	IMX8MM_PAD_GPIO1_IO04_GPIO1_IO4 | MUX_PAD_CTRL(GPIO_PAD_CTRL),    /* pin 154 LEN_EN */
};

static void tx8m_backlight_enable(void)
{
	int ret;
	struct gpio_desc backlight_control;
	struct gpio_desc lcd_enable;

//	printf("\n[%s]: +++\n", __func__);
	ret = dm_gpio_lookup_name("gpio1_1", &backlight_control);
	if (ret == 0) {
		ret = dm_gpio_request(&backlight_control, "BACKLIGHT_CONTROL");
		if (ret == 0) {
			dm_gpio_set_dir_flags(&backlight_control, GPIOD_IS_OUT);
			dm_gpio_set_value(&backlight_control, 1);
		} else {
			printf("Failed to request BACKLIGHT_CONTROL GPIO: %d\n",
			       ret);
		}
	} else {
		printf("Failed to lookup BACKLIGHT_CONTROL GPIO: %d\n", ret);
	}

	ret = dm_gpio_lookup_name("gpio1_4", &lcd_enable);
	if (ret == 0) {
		ret = dm_gpio_request(&lcd_enable, "LCD_ENABLE");
		if (ret == 0) {
			dm_gpio_set_dir_flags(&lcd_enable, GPIOD_IS_OUT);
			dm_gpio_set_value(&lcd_enable, 1);
		} else {
			printf("Failed to request LCD_ENABLE GPIO: %d\n", ret);
		}
	} else {
		printf("Failed to lookup LCD_ENABLE GPIO: %d\n", ret);
	}

	imx_iomux_v3_setup_multiple_pads(tx8mm_lcd_pads,
					 ARRAY_SIZE(tx8mm_lcd_pads));
//	printf("[%s]: ---\n", __func__);
}

#define FSL_SIP_GPC			0xC2000000
#define FSL_SIP_CONFIG_GPC_PM_DOMAIN	0x3
#define DISPMIX				9
#define MIPI				10

static void do_enable_tx8m_mipi2lvds(struct display_info_t const *disp)
{
	/* tx8m_print_video_params(); */
	/* enable the dispmix & mipi phy power domain */
	call_imx_sip(FSL_SIP_GPC, FSL_SIP_CONFIG_GPC_PM_DOMAIN,
		     DISPMIX, true, 0);
	call_imx_sip(FSL_SIP_GPC, FSL_SIP_CONFIG_GPC_PM_DOMAIN,
		     MIPI, true, 0);

	/* Get lcdif out of reset */
	disp_mix_bus_rstn_reset(imx8mm_mipi_dsim_plat_data.gpr_base, false);
	disp_mix_lcdif_clks_enable(imx8mm_mipi_dsim_plat_data.gpr_base, true);

	sec_mipi_dsim_setup(&imx8mm_mipi_dsim_plat_data);
	imx_mipi_dsi_bridge_attach(&dsi83_dev);
	tx8m_backlight_enable();
	//dsi83_init();
}

static struct display_info_t const panel_info[] = {
	{
		.bus = LCDIF_BASE_ADDR,
		.pixfmt = BPP,
		.enable	= do_enable_tx8m_mipi2lvds,
		.mode	= {
			.name		= "MIPI2LVDS",
			.refresh	= VREFRESH,
			.xres		= LINE_LENGTH,
			.yres		= VERT_SIZE,
			.pixclock	= KHZ2PICOS(PCLK / 1000),
			.left_margin	= H_BACK_PORCH,
			.hsync_len	= HSYNC_LEN,
			.right_margin	= H_FRONT_PORCH,
			.upper_margin	= V_BACK_PORCH,
			.vsync_len	= VSYNC_LEN,
			.lower_margin	= V_FRONT_PORCH,
			.sync		= FB_SYNC_EXT,
			.vmode		= FB_VMODE_NONINTERLACED,
		},
	},
};

int board_video_skip(void)
{
	int ret;
	const char *baseboard = env_get("baseboard");
	const char *panel = env_get("panel");
	size_t i;

	if (had_ctrlc()) {
		printf("<CTRL-C> detected; disabling display\n");
		return 1;
	}

	if (!panel) {
		printf("No LCD panel configured\n");
		return 1;
	}

	if (!baseboard || strcmp(baseboard, "mipi-mb") != 0) {
		printf("No Display support for '%s' baseboard\n",
		       baseboard ?: "unspecified");
		return 1;
	}

	for (i = 0; i < ARRAY_SIZE(panel_info); i++) {
		const struct display_info_t *pi = &panel_info[i];

		if (strcmp(panel, pi->mode.name) != 0)
			continue;

		ret = mxs_lcd_panel_setup(pi->mode,
					  pi->pixfmt,
					  pi->bus);

		if (ret) {
			printf("%s: error, function mxs_lcd_panel_setup failed\n", __func__);
			return ret;
		}

		if (pi->enable) {
			// printf("%s: enabling display %s ...\n", __func__, pi->mode.name);
			pi->enable(panel_info + i);
		}		
		else
			printf("%s: error, cannot enable display %s\n", __func__, pi->mode.name);

		printf("Display: %s (%ux%u)\n", pi->mode.name,
		       pi->mode.xres, pi->mode.yres);
	}
	return ret;
}
#endif













int board_late_init(void)
{
#ifdef CONFIG_ENV_IS_IN_MMC
	board_late_mmc_env_init();
#endif
	dsi83_init();
	return 0;
}


