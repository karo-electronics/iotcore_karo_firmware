/** @file
* Description: KaRo TX8MEVK Resource Hub Proxy
*
*  Copyright (c) 2019, Microsoft Corporation. All rights reserved.
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
*/

Device(RHPX)
{
  Name(_HID, "MSFT8000")
  Name(_CID, "MSFT8000")
  Name(_UID, 1)

  Name(_CRS, ResourceTemplate()
  {
    // Index 0
    I2CSerialBus(0xFFFF,, 0,, "\\_SB.I2C2",,,,)



    // Index 1
    SPISerialBus (          // SCLK - GPIO5_IO10 (138) - J1003 pin 23
                            // MOSI - GPIO5_IO11 (139) - J1003 pin 19
                            // MISO - GPIO5_IO12 (140) - J1003 pin 21
                            // SS0  - GPIO5_IO13 (141) - J1003 pin 24
      0,                    // Device selection (CE0)
      PolarityLow,          // Device selection polarity
      FourWireMode,         // wiremode
      0,                    // databit len - placeholder
      ControllerInitiated,  // slave mode
      0,                    // connection speed - placeholder
      ClockPolarityLow,     // clock polarity
      ClockPhaseFirst,      // clock phase
      "\\_SB.SPI2",         // ResourceSource: SPI bus controller name
      0,                    // ResourceSourceIndex
                            // Resource usage
                            // DescriptorName: creates name for offset of resource descriptor
    )                       // Vendor Data





    // GPIO1_IO00 GPIO1_IO00 --> module pin 152
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 0 } // 0 * 32 + 0
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 0 }

    // GPIO1_IO02 GPIO1_IO02 --> module pin 153
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 2 } // 0 * 32 + 2
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 2 }

    // GPIO1_IO04 GPIO1_IO04 --> module pin 154
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 4 } // 0 * 32 + 4
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 4 }

    // GPIO1_IO05 GPIO1_IO05 --> module pin 155
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 5 } // 0 * 32 + 5
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 5 }

    // GPIO1_IO06 GPIO1_IO06 --> module pin 156
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 6 } // 0 * 32 + 6
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 6 }

    // GPIO1_IO07 GPIO1_IO07 --> module pin 157
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 7 } // 0 * 32 + 7
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 7 }

    // GPIO1_IO08 GPIO1_IO08 --> module pin 158
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 8 } // 0 * 32 + 8
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 8 }

    // GPIO1_IO09 GPIO1_IO09 --> module pin 159
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 9 } // 0 * 32 + 9
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 9 }

    // GPIO1_IO10 GPIO1_IO10 --> module pin 161
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 10 } // 0 * 32 + 10
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 10 }

    // GPIO1_IO11 GPIO1_IO11 --> module pin 162
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 11 } // 0 * 32 + 11
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 11 }






    // GPIO3_IO00 NAND_ALE --> module pin 103
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 64 } // 2 * 32 + 0
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 64 }

    // GPIO3_IO01 NAND_CE0_B --> module pin 104
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 65 } // 2 * 32 + 1
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 65 }

    // GPIO3_IO02 NAND_CE1_B --> module pin 105
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 66 } // 2 * 32 + 2
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 66 }

    // GPIO3_IO03 NAND_CE2_B --> module pin 106
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 67 } // 2 * 32 + 3
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 67 }

    // GPIO3_IO04 NAND_CE3_B --> module pin 107
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 68 } // 2 * 32 + 4
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 68 }

    // GPIO3_IO05 NAND_CLE --> module pin 112
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 69 } // 2 * 32 + 5
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 69 }

    // GPIO3_IO06 NAND_DATA00 --> module pin 108
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 70 } // 2 * 32 + 6
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 70 }

    // GPIO3_IO07 NAND_DATA01 --> module pin 109
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 71 } // 2 * 32 + 7
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 71 }




    // GPIO3_IO09 NAND_DATA03 --> module pin 110
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 73 } // 2 * 32 + 9
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 73 }



    // GPIO3_IO14 NAND_DQS --> module pin 113
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 78 } // 2 * 32 + 14
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 78 }

    // GPIO3_IO15 RE_B --> module pin 114
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 79 } // 2 * 32 + 15
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 79 }

    // GPIO3_IO16 NAND_READY_B - module pin 115
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 80 } // 2 * 32 + 16
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 80 }

    // GPIO3_IO20 PAD_SIA5_RXC - J1003 pin 40
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 84 } // 2 * 32 + 20
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 84 }

    // GPIO3_IO21 PAD_SIA5_RXD0 - J1003 pin 38
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 85 } // 2 * 32 + 21
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 85 }

    // GPIO3_IO22 PAD_SIA5_RXD1 - J1003 pin 37
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 86 } // 2 * 32 + 22
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 86 }

    // GPIO3_IO23 PAD_SIA5_RXD2 - J1003 pin 36
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 87 } // 2 * 32 + 23
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 87 }

    // GPIO3_IO24 PAD_SIA5_RXD3 - J1003 pin 35
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 88 } // 2 * 32 + 24
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 88 }


    // GPIO4_IO00 PAD_SAI1_RXFS - module pin 178
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 96 } // 3 * 32 + 0
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 96 }

    // GPIO4_IO01 PAD_SAI1_RXC - module pin 180
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 97 } // 3 * 32 + 1
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 97 }

    // GPIO4_IO02 PAD_SAI1_RXD0 - module pin 184
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 98 } // 3 * 32 + 2
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 98 }

    // GPIO4_IO03 PAD_SAI1_RXD1 - module pin 185
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 99 } // 3 * 32 + 3
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 99 }

    // GPIO4_IO04 PAD_SAI1_RXD2 - module pin 186
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 100 } // 3 * 32 + 4
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 100 }

    // GPIO4_IO05 PAD_SAI1_RXD3 - module pin 187
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 101 } // 3 * 32 + 5
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 101 }

    // GPIO4_IO06 PAD_SAI1_RXD4 - module pin 188
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 102 } // 3 * 32 + 6
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 102 }

    // GPIO4_IO07 PAD_SAI1_RXD5 - module pin 189
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 103 } // 3 * 32 + 7
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 103 }

    // GPIO4_IO08 PAD_SAI1_RXD6 - module pin 190
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 104 } // 3 * 32 + 8
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 104 }

    // GPIO4_IO09 PAD_SAI1_RXD7 - module pin 191
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 105 } // 3 * 32 + 9
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 105 }

    // GPIO4_IO12 PAD_SAI1_TXD0 - module pin 192
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 108 } // 3 * 32 + 12
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 108 }

    // GPIO4_IO13 PAD_SAI1_TXD1 - module pin 193
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 109 } // 3 * 32 + 13
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 109 }

    // GPIO4_IO14 PAD_SAI1_TXD2 - module pin 194
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 110 } // 3 * 32 + 14
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 110 }

    // GPIO4_IO15 PAD_SAI1_TXD3 - module pin 195
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 111 } // 3 * 32 + 15
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 111 }

    // GPIO4_IO16 PAD_SAI1_TXD4 - module pin 196
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 112 } // 3 * 32 + 16
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 112 }

    // GPIO4_IO17 PAD_SAI1_TXD5 - module pin 197
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 113 } // 3 * 32 + 17
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 113 }

    // GPIO4_IO18 PAD_SAI1_TXD6 - module pin 198
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 114 } // 3 * 32 + 18
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 114 }

    // GPIO4_IO19 PAD_SAI1_TXD7 - module pin 199
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 115 } // 3 * 32 + 19
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 115 }




    // GPIO4_IO10 PAD_SAI1_TXFS - module pin 179
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 106 } // 3 * 32 + 10
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 106 }

    // GPIO4_IO11 PAD_SAI1_TXC - module pin 181
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 107 } // 3 * 32 + 11
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 107 }






    // GPIO4_IO20 PAD_SAI1_MCLK - module pin 182
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 116 } // 3 * 32 + 20
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 116 }











    // GPIO5_IO03 PAD_SPDIF_TX - module pin 144
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 131 } // 4 * 32 + 3
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 131 }

    // GPIO5_IO04 PAD_SPDIF_RX - module pin 143
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 132 } // 4 * 32 + 4
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 132 }

    // GPIO5_IO05 PAD_SPDIF_EXT_CLK - module pin 146
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 133 } // 4 * 32 + 5
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 133 }

    // GPIO5_IO06 PAD_ECSPI1_SCLK - module pin 68 (UART3_RXD)
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 134 } // 4 * 32 + 6
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 134 }

    // GPIO5_IO07 PAD_ECSPI1_MOSI - module pin 67 (UART3_TXD)
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 135 } // 4 * 32 + 7
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 135 }

    // GPIO5_IO08 PAD_ECSPI1_MISO - module pin 70 (UART3_CTS)
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 136 } // 4 * 32 + 8
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 136 }

    // GPIO5_IO09 PAD_ECSPI1_SS0 - module pin 69 (UART3_RTS)
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 137 } // 4 * 32 + 9
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 137 }

    // GPIO5_IO10 PAD_ECSPI2_SCLK - J1003 pin 23
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 138 } // 4 * 32 + 10
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 138 }

    // GPIO5_IO11 PAD_ECSPI2_MOSI - J1003 pin 19
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 139 } // 4 * 32 + 11
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 139 }

    // GPIO5_IO12 PAD_ECSPI2_MISO - J1003 pin 21
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 140 } // 4 * 32 + 12
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 140 }

    // GPIO5_IO13 PAD_ECSPI2_SS0 - J1003 pin 24
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 141 } // 4 * 32 + 13
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 141 }




    // GPIO5_IO18 PAD_I2C3_SCL - module pin 148
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 146 } // 4 * 32 + 18
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 146 }

    // GPIO5_IO19 PAD_I2C3_SDA - module pin 149
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 147 } // 4 * 32 + 19
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 147 }

    // GPIO5_IO20 PAD_I2C4_SCL - module pin 150
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 148 } // 4 * 32 + 20
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 148 }

    // GPIO5_IO21 PAD_I2C4_SDA - module pin 151
    GpioIO(Shared, PullDown, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 149 } // 4 * 32 + 21
    GpioInt(Edge, ActiveBoth, Shared, PullDown, 0, "\\_SB.GPIO",) { 149 }


  })

  Name(_DSD, Package()
  {
    ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
    Package()
    {
      // I2C bus 2
      Package(2) { "bus-I2C-I2C2", Package() { 0 }},

      // SPI bus 2
      // Reference clock is 24 MHz

      Package(2) { "bus-SPI-SPI2", Package() { 1 }},
      Package(2) { "SPI2-MinClockInHz", 46 },                              // 46 Hz
      Package(2) { "SPI2-MaxClockInHz", 12000000 },                        // 12 MHz
      Package(2) { "SPI2-SupportedDataBitLengths", Package() { 8,16,32 }}, // Data bit length

      // GPIO Pin Count and supported drive modes
      Package (2) { "GPIO-PinCount", 157 },
      Package (2) { "GPIO-UseDescriptorPinNumbers", 1 },

      // InputHighImpedance, InputPullUp, InputPullDown, OutputCmos
      Package (2) { "GPIO-SupportedDriveModes", 0x0F },
    }
  })
}
