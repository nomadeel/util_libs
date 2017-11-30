/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */

#pragma once

/* this is the misc pinmux */
#define MUX_PADDR_BASE 0x70000000
/* the auxiliary pinmux */
#define MUX_AUX_PADDR_BASE 0x70006000

#define TK1_MUX_MISC_PADDR  (MUX_PADDR_BASE)
#define TK1_MUX_MISC_SIZE   0x1000

#define TK1_MUX_AUX_PADDR   (MUX_AUX_PADDR_BASE)
#define TK1_MUX_AUX_SIZE    0x1000

#define GMACFG_ADDR_OFFSET 0x0900

typedef struct mux_sys mux_sys_t;
typedef struct gpio_sys gpio_sys_t;
typedef struct ps_io_ops ps_io_ops_t;

enum mux_feature {
    MUX_FEATURE_UARTA,
    MUX_FEATURE_UARTB,
    MUX_FEATURE_UARTC,
    MUX_FEATURE_UARTD,

    MUX_FEATURE_SPI1,
    MUX_FEATURE_SPI2,
    MUX_FEATURE_SPI3,
    MUX_FEATURE_SPI4,

    MUX_FEATURE_GPIO_PS3,
    MUX_FEATURE_GPIO_PS4,
    MUX_FEATURE_GPIO_PR0,
    MUX_FEATURE_GPIO_PR6,

    MUX_FEATURE_GPIO_PS5,
    MUX_FEATURE_GPIO_PT0,
    MUX_FEATURE_GPIO_PS6,
    MUX_FEATURE_GPIO_PS2,

    MUX_FEATURE_I2C0,
    MUX_FEATURE_I2C1,
    MUX_FEATURE_I2C2,
    MUX_FEATURE_I2C3,
    /* I2C4 and I2C5 don't seem to have recognizable mux pads. */
    // MUX_FEATURE_I2C4,
    // MUX_FEATURE_I2C5,

    MUX_FEATURE_GPIO_PC4,
    MUX_FEATURE_GPIO_PC5,
    MUX_FEATURE_GPIO_PBB1,
    MUX_FEATURE_GPIO_PBB2,

    NMUX_FEATURES
};

/* Please see the TK1 schematic for the signal-to-pad mappings.
 * Please also see section 8.12 of the TegraK1 TRM for these register offsets.
 */
#define MUX_PAD_INDEX(_reg_off) (_reg_off / 4)

enum mux_pad {
    MUX_PAD_ULPI_DATA0_PO1,
    MUX_PAD_ULPI_DATA1_PO2,
    MUX_PAD_ULPI_DATA2_PO3,
    MUX_PAD_ULPI_DATA3_PO4,
    MUX_PAD_ULPI_DATA4_PO5,
    MUX_PAD_ULPI_DATA5_PO6,
    MUX_PAD_ULPI_DATA6_PO7,
    MUX_PAD_ULPI_DATA7_PO0,
    MUX_PAD_ULPI_CLK_PY0,
    MUX_PAD_ULPI_DIR_PY1,
    MUX_PAD_ULPI_NXT_PY2,
    MUX_PAD_ULPI_STP_PY3,
    MUX_PAD_DAP3_FS_PP0,
    MUX_PAD_DAP3_DIN_PP1,
    MUX_PAD_DAP3_DOUT_PP2,
    MUX_PAD_DAP3_SCLK_PP3,
    MUX_PAD_PV0,
    MUX_PAD_PV1,
    MUX_PAD_SDMMC1_CLK_PZ0,
    MUX_PAD_SDMMC1_CMD_PZ1,
    MUX_PAD_SDMMC1_DAT3_PY4,
    MUX_PAD_SDMMC1_DAT2_PY5,
    MUX_PAD_SDMMC1_DAT1_PY6,
    MUX_PAD_SDMMC1_DAT0_PY7,
    MUX_PAD_CLK2_OUT_PW5 = (0x68 / 4),
    MUX_PAD_CLK2_REQ_PCC5,
    MUX_PAD_HDMI_INT_PN7 = (0x110 / 4),
    MUX_PAD_DDC_SCL_PV4,
    MUX_PAD_DDC_SDA_PV5,
    MUX_PAD_UART2_RXD_PC3 = (0x164 / 4),
    MUX_PAD_UART2_TXD_PC2,
    MUX_PAD_UART2_RTS_N_PJ6,
    MUX_PAD_UART2_CTS_N_PJ5,
    MUX_PAD_UART3_TXD_PW6,
    MUX_PAD_UART3_RXD_PW7,
    MUX_PAD_UART3_CTS_N_PA1,
    MUX_PAD_UART3_RTS_N_PC0,
    MUX_PAD_PU0,
    MUX_PAD_PU1,
    MUX_PAD_PU2,
    MUX_PAD_PU3,
    MUX_PAD_PU4,
    MUX_PAD_PU5,
    MUX_PAD_PU6,
    MUX_PAD_GEN1_I2C_SDA_PC5,
    MUX_PAD_GEN1_I2C_SCL_PC4,
    MUX_PAD_DAP4_FS_PP4,
    MUX_PAD_DAP4_DIN_PP5,
    MUX_PAD_DAP4_DOUT_PP6,
    MUX_PAD_DAP4_SCLK_PP7,
    MUX_PAD_CLK3_OUT_PEE0,
    MUX_PAD_CLK3_REQ_PEE1,
    MUX_PAD_PC7,
    MUX_PAD_PI5,
    MUX_PAD_PI7,
    MUX_PAD_PK0,
    MUX_PAD_PK1,
    MUX_PAD_PJ0,
    MUX_PAD_PJ2,
    MUX_PAD_PK3,
    MUX_PAD_PK4,
    MUX_PAD_PK2,
    MUX_PAD_PI3,
    MUX_PAD_PI6,
    MUX_PAD_PG0,
    MUX_PAD_PG1,
    MUX_PAD_PG2,
    MUX_PAD_PG3,
    MUX_PAD_PG4,
    MUX_PAD_PG5,
    MUX_PAD_PG6,
    MUX_PAD_PG7,
    MUX_PAD_PH0,
    MUX_PAD_PH1,
    MUX_PAD_PH2,
    MUX_PAD_PH3,
    MUX_PAD_PH4,
    MUX_PAD_PH5,
    MUX_PAD_PH6,
    MUX_PAD_PH7,
    MUX_PAD_PJ7,
    MUX_PAD_PB0,
    MUX_PAD_PB1,
    MUX_PAD_PK7,
    MUX_PAD_PI0,
    MUX_PAD_PI1,
    MUX_PAD_PI2,
    MUX_PAD_PI4,
    MUX_PAD_GEN2_I2C_SCL_PT5,
    MUX_PAD_GEN2_I2C_SDA_PT6,
    MUX_PAD_SDMMC4_CLK_PCC4,
    MUX_PAD_SDMMC4_CMD_PT7,
    MUX_PAD_SDMMC4_DAT0_PAA0,
    MUX_PAD_SDMMC4_DAT1_PAA1,
    MUX_PAD_SDMMC4_DAT2_PAA2,
    MUX_PAD_SDMMC4_DAT3_PAA3,
    MUX_PAD_SDMMC4_DAT4_PAA4,
    MUX_PAD_SDMMC4_DAT5_PAA5,
    MUX_PAD_SDMMC4_DAT6_PAA6,
    MUX_PAD_SDMMC4_DAT7_PAA7,
    MUX_PAD_CAM_MCLK_PCC0 = (0x284 / 4),
    MUX_PAD_PCC1,
    MUX_PAD_PBB0,
    MUX_PAD_CAM_I2C_SCL_PBB1,
    MUX_PAD_CAM_I2C_SDA_PBB2,
    MUX_PAD_PBB3,
    MUX_PAD_PBB4,
    MUX_PAD_PBB5,
    MUX_PAD_PBB6,
    MUX_PAD_PBB7,
    MUX_PAD_PCC2,
    MUX_PAD_JTAG_RTCK,
    MUX_PAD_PWR_I2C_SCL_PZ6,
    MUX_PAD_PWR_I2C_SDA_PZ7,
    MUX_PAD_KB_ROW0_PR0,
    MUX_PAD_KB_ROW1_PR1,
    MUX_PAD_KB_ROW2_PR2,
    MUX_PAD_KB_ROW3_PR3,
    MUX_PAD_KB_ROW4_PR4,
    MUX_PAD_KB_ROW5_PR5,
    MUX_PAD_KB_ROW6_PR6,
    MUX_PAD_KB_ROW7_PR7,
    MUX_PAD_KB_ROW8_PS0,
    MUX_PAD_KB_ROW9_PS1,
    MUX_PAD_KB_ROW10_PS2,
    MUX_PAD_KB_ROW11_PS3,
    MUX_PAD_KB_ROW12_PS4,
    MUX_PAD_KB_ROW13_PS5,
    MUX_PAD_KB_ROW14_PS6,
    MUX_PAD_KB_ROW15_PS7,
    MUX_PAD_KB_COL0_PQ0,
    MUX_PAD_KB_COL1_PQ1,
    MUX_PAD_KB_COL2_PQ2,
    MUX_PAD_KB_COL3_PQ3,
    MUX_PAD_KB_COL4_PQ4,
    MUX_PAD_KB_COL5_PQ5,
    MUX_PAD_KB_COL6_PQ6,
    MUX_PAD_KB_COL7_PQ7,
    MUX_PAD_CLK_32K_OUT_PA0,
    MUX_PAD_CORE_PWR_REQ = (0x324 / 4),
    MUX_PAD_CPU_PWR_REQ,
    MUX_PAD_PWR_INT_N,
    MUX_PAD_CLK_32K_IN,
    MUX_PAD_OWR,
    MUX_PAD_DAP1_FS_PN0,
    MUX_PAD_DAP1_DIN_PN1,
    MUX_PAD_DAP1_DOUT_PN2,
    MUX_PAD_DAP1_SCLK_PN3,
    MUX_PAD_DAP_MCLK1_REQ_PEE2,
    MUX_PAD_DAP_MCLK1_PW4,
    MUX_PAD_SPDIF_IN_PK6,
    MUX_PAD_SPDIF_OUT_PK5,
    MUX_PAD_DAP2_FS_PA2,
    MUX_PAD_DAP2_DIN_PA4,
    MUX_PAD_DAP2_DOUT_PA5,
    MUX_PAD_DAP2_SCLK_PA3,
    MUX_PAD_DVFS_PWM_PX0,
    MUX_PAD_GPIO_X1_AUD_PX1,
    MUX_PAD_GPIO_X3_AUD_PX3,
    MUX_PAD_DVFS_CLK_PX2,
    MUX_PAD_GPIO_X4_AUD_PX4,
    MUX_PAD_GPIO_X5_AUD_PX5,
    MUX_PAD_GPIO_X6_AUD_PX6,
    MUX_PAD_GPIO_X7_AUD_PX7,
    MUX_PAD_SDMMC3_CLK_PA6 = (0x390 / 4),
    MUX_PAD_SDMMC3_CMD_PA7,
    MUX_PAD_SDMMC3_DAT0_PB7,
    MUX_PAD_SDMMC3_DAT1_PB6,
    MUX_PAD_SDMMC3_DAT2_PB5,
    MUX_PAD_SDMMC3_DAT3_PB4,
    MUX_PAD_PEX_L0_RST_N_PDD1 = (0x3bc / 4),
    MUX_PAD_PEX_L0_CLKREQ_N_PDD2,
    MUX_PAD_PEX_WAKE_N_PDD3,
    MUX_PAD_PEX_L1_RST_N_PDD5 = (0x3cc / 4),
    MUX_PAD_PEX_L1_CLKREQ_N_PDD6,
    MUX_PAD_HDMI_CEC_PEE3 = (0x3e0 / 4),
    MUX_PAD_SDMMC1_WP_N_PV3,
    MUX_PAD_SDMMC3_CD_N_PV2,
    MUX_PAD_GPIO_W2_AUD_PW2,
    MUX_PAD_GPIO_W3_AUD_PW3,
    MUX_PAD_USB_VBUS_EN0_PN4,
    MUX_PAD_USB_VBUS_EN1_PN5,
    MUX_PAD_SDMMC3_CLK_LB_IN_PEE5,
    MUX_PAD_SDMMC3_CLK_LB_OUT_PEE4,
    MUX_PAD_GMI_CLK_LB,
    MUX_PAD_RESET_OUT_N,
    MUX_PAD_KB_ROW16_PT0,
    MUX_PAD_KB_ROW17_PT1,
    MUX_PAD_USB_VBUS_EN2_PFF1,
    MUX_PAD_PFF2,
    MUX_PAD_DP_HPD_PFF0 = (0x430 / 4),

    NMUX_PADS
};

int tegra_mux_init(volatile void *pinmux_misc, volatile void *pinmux_aux,
               ps_io_ops_t *io_ops,
               gpio_sys_t *gpio_sys, mux_sys_t *self);
