/** @file
*
*  Copyright (c) 2018 Microsoft Corporation. All rights reserved.
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#ifndef _IPU_H_
#define _IPU_H_

#define IPU1_BASE      0x02600000
#define IPU2_BASE      0x02A00000

#define IpuRead32(IPU_BASE, OFFSET) \
            MmioRead32((UINT32)((UINT8 *)IPU_BASE + OFFSET))

#define IpuWrite32(IPU_BASE, OFFSET, VALUE) \
            MmioWrite32((UINT32)((UINT8 *)IPU_BASE + OFFSET), VALUE)

#define DiRead32(DI_BASE, OFFSET) \
            MmioRead32((UINT32)((UINT8 *)DI_BASE + OFFSET))

#define DiWrite32(DI_BASE, OFFSET, VALUE) \
            MmioWrite32((UINT32)((UINT8 *)DI_BASE + OFFSET), VALUE)

// IPU Registers
#define IPU_IPU_CONF_OFFSET                     0x00000000
#define IPU_SISG_CTRL0_OFFSET                   0x00000004
#define IPU_SISG_CTRL1_OFFSET                   0x00000008
#define IPU_SISG_SET_OFFSET                     0x0000000C
#define IPU_SISG_CLR_OFFSET                     0x00000024
#define IPU_IPU_INT_CTRL_1_OFFSET               0x0000003C
#define IPU_IPU_INT_CTRL_2_OFFSET               0x00000040
#define IPU_IPU_INT_CTRL_3_OFFSET               0x00000044
#define IPU_IPU_INT_CTRL_4_OFFSET               0x00000048
#define IPU_IPU_INT_CTRL_5_OFFSET               0x0000004C
#define IPU_IPU_INT_CTRL_6_OFFSET               0x00000050
#define IPU_IPU_INT_CTRL_7_OFFSET               0x00000054
#define IPU_IPU_INT_CTRL_8_OFFSET               0x00000058
#define IPU_IPU_INT_CTRL_9_OFFSET               0x0000005C
#define IPU_IPU_INT_CTRL_10_OFFSET              0x00000060
#define IPU_IPU_INT_CTRL_11_OFFSET              0x00000064
#define IPU_IPU_INT_CTRL_12_OFFSET              0x00000068
#define IPU_IPU_INT_CTRL_13_OFFSET              0x0000006C
#define IPU_IPU_INT_CTRL_14_OFFSET              0x00000070
#define IPU_IPU_INT_CTRL_15_OFFSET              0x00000074
#define IPU_IPU_SDMA_EVENT_1_OFFSET             0x00000078
#define IPU_IPU_SDMA_EVENT_2_OFFSET             0x0000007C
#define IPU_IPU_SDMA_EVENT_3_OFFSET             0x00000080
#define IPU_IPU_SDMA_EVENT_4_OFFSET             0x00000084
#define IPU_IPU_SDMA_EVENT_7_OFFSET             0x00000088
#define IPU_IPU_SDMA_EVENT_8_OFFSET             0x0000008C
#define IPU_IPU_SDMA_EVENT_11_OFFSET            0x00000090
#define IPU_IPU_SDMA_EVENT_12_OFFSET            0x00000094
#define IPU_IPU_SDMA_EVENT_13_OFFSET            0x00000098
#define IPU_IPU_SDMA_EVENT_14_OFFSET            0x0000009C
#define IPU_IPU_SRM_PRI1_OFFSET                 0x000000A0
#define IPU_IPU_SRM_PRI2_OFFSET                 0x000000A4
#define IPU_IPU_FS_PROC_FLOW1_OFFSET            0x000000A8
#define IPU_IPU_FS_PROC_FLOW2_OFFSET            0x000000AC
#define IPU_IPU_FS_PROC_FLOW3_OFFSET            0x000000B0
#define IPU_IPU_FS_DISP_FLOW1_OFFSET            0x000000B4
#define IPU_IPU_FS_DISP_FLOW2_OFFSET            0x000000B8
#define IPU_IPU_SKIP_OFFSET                     0x000000BC
#define IPU_IPU_DISP_ALT_CONF_OFFSET            0x000000C0
#define IPU_IPU_DISP_GEN_OFFSET                 0x000000C4
#define IPU_IPU_DISP_ALT1_OFFSET                0x000000C8
#define IPU_IPU_DISP_ALT2_OFFSET                0x000000CC
#define IPU_IPU_DISP_ALT3_OFFSET                0x000000D0
#define IPU_IPU_DISP_ALT4_OFFSET                0x000000D4
#define IPU_IPU_SNOOP_OFFSET                    0x000000D8
#define IPU_IPU_MEM_RST_OFFSET                  0x000000DC
#define IPU_IPU_PM_OFFSET                       0x000000E0
#define IPU_IPU_GPR_OFFSET                      0x000000E4
#define IPU_IPU_INT_STAT_1_OFFSET               0x000000E8
#define IPU_IPU_INT_STAT_2_OFFSET               0x000000EC
#define IPU_IPU_INT_STAT_3_OFFSET               0x000000F0
#define IPU_IPU_INT_STAT_4_OFFSET               0x000000F4
#define IPU_IPU_INT_STAT_5_OFFSET               0x000000F8
#define IPU_IPU_INT_STAT_6_OFFSET               0x000000FC
#define IPU_IPU_INT_STAT_7_OFFSET               0x00000100
#define IPU_IPU_INT_STAT_8_OFFSET               0x00000104
#define IPU_IPU_INT_STAT_9_OFFSET               0x00000108
#define IPU_IPU_INT_STAT_10_OFFSET              0x0000010C
#define IPU_IPU_INT_STAT_11_OFFSET              0x00000110
#define IPU_IPU_INT_STAT_12_OFFSET              0x00000114
#define IPU_IPU_INT_STAT_13_OFFSET              0x00000118
#define IPU_IPU_INT_STAT_14_OFFSET              0x0000011C
#define IPU_IPU_INT_STAT_15_OFFSET              0x00000120
#define IPU_IPU_CUR_BUF_0_OFFSET                0x00000124
#define IPU_IPU_CUR_BUF_1_OFFSET                0x00000128
#define IPU_IPU_ALT_CUR_BUF_0_OFFSET            0x0000012C
#define IPU_IPU_ALT_CUR_BUF_1_OFFSET            0x00000130
#define IPU_IPU_SRM_STAT_OFFSET                 0x00000134
#define IPU_IPU_PROC_TASKS_STAT_OFFSET          0x00000138
#define IPU_IPU_DISP_TASKS_STAT_OFFSET          0x0000013C
#define IPU_IPU_CH_BUF0_RDY0_OFFSET             0x00000140
#define IPU_IPU_CH_BUF0_RDY1_OFFSET             0x00000144
#define IPU_IPU_CH_BUF1_RDY0_OFFSET             0x00000148
#define IPU_IPU_CH_BUF1_RDY1_OFFSET             0x0000014C
#define IPU_IPU_CH_DB_MODE_SEL0_OFFSET          0x00000150
#define IPU_IPU_CH_DB_MODE_SEL1_OFFSET          0x00000154
#define IPU_IPU_ALT_CH_BUF0_RDY0_OFFSET         0x00000158
#define IPU_IPU_ALT_CH_BUF0_RDY1_OFFSET         0x0000015C
#define IPU_IPU_ALT_CH_BUF1_RDY0_OFFSET         0x00000160
#define IPU_IPU_ALT_CH_BUF1_RDY1_OFFSET         0x00000164
#define IPU_IPU_ALT_CH_DB_MODE_SEL0_OFFSET      0x00000168
#define IPU_IPU_ALT_CH_DB_MODE_SEL1_OFFSET      0x0000016C
#define CSP_IPUV3_CPMEM_REGS_OFFSET             0x00100000

// IPU DIx Registers
#define IPU_DIx_GENERAL_OFFSET                  0x00000000
#define IPU_DIx_BS_CLKGEN0_OFFSET               0x00000004
#define IPU_DIx_BS_CLKGEN1_OFFSET               0x00000008
#define IPU_DIx_SW_GEN0_1_OFFSET                0x0000000C
#define IPU_DIx_SW_GEN0_2_OFFSET                0x00000010
#define IPU_DIx_SW_GEN0_3_OFFSET                0x00000014
#define IPU_DIx_SW_GEN0_4_OFFSET                0x00000018
#define IPU_DIx_SW_GEN0_5_OFFSET                0x0000001C
#define IPU_DIx_SW_GEN0_6_OFFSET                0x00000020
#define IPU_DIx_SW_GEN0_7_OFFSET                0x00000024
#define IPU_DIx_SW_GEN0_8_OFFSET                0x00000028
#define IPU_DIx_SW_GEN0_9_OFFSET                0x0000002C
#define IPU_DIx_SW_GEN1_1_OFFSET                0x00000030
#define IPU_DIx_SW_GEN1_2_OFFSET                0x00000034
#define IPU_DIx_SW_GEN1_3_OFFSET                0x00000038
#define IPU_DIx_SW_GEN1_4_OFFSET                0x0000003C
#define IPU_DIx_SW_GEN1_5_OFFSET                0x00000040
#define IPU_DIx_SW_GEN1_6_OFFSET                0x00000044
#define IPU_DIx_SW_GEN1_7_OFFSET                0x00000048
#define IPU_DIx_SW_GEN1_8_OFFSET                0x0000004C
#define IPU_DIx_SW_GEN1_9_OFFSET                0x00000050
#define IPU_DIx_SYNC_AS_GEN_OFFSET              0x00000054
#define IPU_DIx_DW_GEN_OFFSET                   0x00000058
#define IPU_DIx_DW_SET0_OFFSET                  0x00000088
#define IPU_DIx_DW_SET1_OFFSET                  0x000000B8
#define IPU_DIx_DW_SET2_OFFSET                  0x000000E8
#define IPU_DIx_DW_SET3_OFFSET                  0x00000118
#define IPU_DIx_STP_REP_OFFSET                  0x00000148
#define IPU_DIx_STP_REP_9_OFFSET                0x00000158
#define IPU_DIx_SER_CONF_OFFSET                 0x0000015C
#define IPU_DIx_SSC_OFFSET                      0x00000160
#define IPU_DIx_POL_OFFSET                      0x00000164
#define IPU_DIx_AW0_OFFSET                      0x00000168
#define IPU_DIx_AW1_OFFSET                      0x0000016C
#define IPU_DIx_SCR_CONF_OFFSET                 0x00000170
#define IPU_DIx_STAT_OFFSET                     0x00000174

// IPU IDMAC Registers
#define IPU_IDMAC_LOCK_EN_1                     0x00008024
#define IPU_IDMAC_LOCK_EN_2                     0x00008028

// IPU DisplayInterface0 Registers
#define IPU_DISPLAY_INTERFACE_0_OFFSET          0x00040000
#define IPU_DI0_BS_CLKGEN0_OFFSET               0x00040004
#define IPU_DI0_BS_CLKGEN1_OFFSET               0x00040008
#define IPU_DI0_SW_GEN0_1_OFFSET                0x0004000C
#define IPU_DI0_SW_GEN0_2_OFFSET                0x00040010
#define IPU_DI0_SW_GEN0_3_OFFSET                0x00040014
#define IPU_DI0_SW_GEN0_4_OFFSET                0x00040018
#define IPU_DI0_SW_GEN0_5_OFFSET                0x0004001C
#define IPU_DI0_SW_GEN0_6_OFFSET                0x00040020
#define IPU_DI0_SW_GEN0_7_OFFSET                0x00040024
#define IPU_DI0_SW_GEN0_8_OFFSET                0x00040028
#define IPU_DI0_SW_GEN0_9_OFFSET                0x0004002C
#define IPU_DI0_SW_GEN1_1_OFFSET                0x00040030
#define IPU_DI0_SW_GEN1_2_OFFSET                0x00040034
#define IPU_DI0_SW_GEN1_3_OFFSET                0x00040038
#define IPU_DI0_SW_GEN1_4_OFFSET                0x0004003C
#define IPU_DI0_SW_GEN1_5_OFFSET                0x00040040
#define IPU_DI0_SW_GEN1_6_OFFSET                0x00040044
#define IPU_DI0_SW_GEN1_7_OFFSET                0x00040048
#define IPU_DI0_SW_GEN1_8_OFFSET                0x0004004C
#define IPU_DI0_SW_GEN1_9_OFFSET                0x00040050
#define IPU_DI0_SYNC_AS_GEN_OFFSET              0x00040054
#define IPU_DI0_DW_GEN_OFFSET                   0x00040058
#define IPU_DI0_DW_SET0_OFFSET                  0x00040088
#define IPU_DI0_DW_SET1_OFFSET                  0x000400B8
#define IPU_DI0_DW_SET2_OFFSET                  0x000400E8
#define IPU_DI0_DW_SET3_OFFSET                  0x00040118
#define IPU_DI0_STP_REP_OFFSET                  0x00040148
#define IPU_DI0_STP_REP_9_OFFSET                0x00040158
#define IPU_DI0_SER_CONF_OFFSET                 0x0004015C
#define IPU_DI0_SSC_OFFSET                      0x00040160
#define IPU_DI0_POL_OFFSET                      0x00040164
#define IPU_DI0_AW0_OFFSET                      0x00040168
#define IPU_DI0_AW1_OFFSET                      0x0004016C
#define IPU_DI0_SCR_CONF_OFFSET                 0x00040170
#define IPU_DI0_STAT_OFFSET                     0x00040174

// IPU DisplayInterface1 Registers
#define IPU_DISPLAY_INTERFACE_1_OFFSET          0x00048000
#define IPU_DI1_BS_CLKGEN0_OFFSET               0x00048004
#define IPU_DI1_BS_CLKGEN1_OFFSET               0x00048008
#define IPU_DI1_SW_GEN0_1_OFFSET                0x0004800C
#define IPU_DI1_SW_GEN0_2_OFFSET                0x00048010
#define IPU_DI1_SW_GEN0_3_OFFSET                0x00048014
#define IPU_DI1_SW_GEN0_4_OFFSET                0x00048018
#define IPU_DI1_SW_GEN0_5_OFFSET                0x0004801C
#define IPU_DI1_SW_GEN0_6_OFFSET                0x00048020
#define IPU_DI1_SW_GEN0_7_OFFSET                0x00048024
#define IPU_DI1_SW_GEN0_8_OFFSET                0x00048028
#define IPU_DI1_SW_GEN0_9_OFFSET                0x0004802C
#define IPU_DI1_SW_GEN1_1_OFFSET                0x00048030
#define IPU_DI1_SW_GEN1_2_OFFSET                0x00048034
#define IPU_DI1_SW_GEN1_3_OFFSET                0x00048038
#define IPU_DI1_SW_GEN1_4_OFFSET                0x0004803C
#define IPU_DI1_SW_GEN1_5_OFFSET                0x00048040
#define IPU_DI1_SW_GEN1_6_OFFSET                0x00048044
#define IPU_DI1_SW_GEN1_7_OFFSET                0x00048048
#define IPU_DI1_SW_GEN1_8_OFFSET                0x0004804C
#define IPU_DI1_SW_GEN1_9_OFFSET                0x00048050
#define IPU_DI1_SYNC_AS_GEN_OFFSET              0x00048054
#define IPU_DI1_DW_GEN_OFFSET                   0x00048058
#define IPU_DI1_DW_SET0_OFFSET                  0x00048088
#define IPU_DI1_DW_SET1_OFFSET                  0x000480B8
#define IPU_DI1_DW_SET2_OFFSET                  0x000480E8
#define IPU_DI1_DW_SET3_OFFSET                  0x00048118
#define IPU_DI1_STP_REP_OFFSET                  0x00048148
#define IPU_DI1_STP_REP_9_OFFSET                0x00048158
#define IPU_DI1_SER_CONF_OFFSET                 0x0004815C
#define IPU_DI1_SSC_OFFSET                      0x00048160
#define IPU_DI1_POL_OFFSET                      0x00048164
#define IPU_DI1_AW0_OFFSET                      0x00048168
#define IPU_DI1_AW1_OFFSET                      0x0004816C
#define IPU_DI1_SCR_CONF_OFFSET                 0x00048170
#define IPU_DI1_STAT_OFFSET                     0x00048174

#endif  /* _IPU_H_ */
