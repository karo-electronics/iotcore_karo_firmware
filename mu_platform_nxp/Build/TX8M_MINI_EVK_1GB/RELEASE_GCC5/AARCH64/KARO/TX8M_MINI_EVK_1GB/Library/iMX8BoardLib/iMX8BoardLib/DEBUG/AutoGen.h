/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_5189D094_42CF_06DB_02A0_25943364EC9E
#define _AUTOGENH_5189D094_42CF_06DB_02A0_25943364EC9E

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gArmTokenSpaceGuid;
extern GUID giMX8TokenSpaceGuid;
extern GUID giMXPlatformTokenSpaceGuid;
extern GUID gArmPlatformTokenSpaceGuid;
extern GUID gOpteeClientPkgTokenSpaceGuid;

// PPIs
extern GUID gArmMpCoreInfoPpiGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdSystemMemoryBase  27U
extern const UINT64 _gPcd_FixedAtBuild_PcdSystemMemoryBase;
#define _PCD_GET_MODE_64_PcdSystemMemoryBase  _gPcd_FixedAtBuild_PcdSystemMemoryBase
//#define _PCD_SET_MODE_64_PcdSystemMemoryBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSystemMemoryBase 0x40000000
#define _PCD_SIZE_PcdSystemMemoryBase 8
#define _PCD_GET_MODE_SIZE_PcdSystemMemoryBase _PCD_SIZE_PcdSystemMemoryBase
#define _PCD_TOKEN_PcdSystemMemorySize  28U
extern const UINT64 _gPcd_FixedAtBuild_PcdSystemMemorySize;
#define _PCD_GET_MODE_64_PcdSystemMemorySize  _gPcd_FixedAtBuild_PcdSystemMemorySize
//#define _PCD_SET_MODE_64_PcdSystemMemorySize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSystemMemorySize 0x3E000000
#define _PCD_SIZE_PcdSystemMemorySize 8
#define _PCD_GET_MODE_SIZE_PcdSystemMemorySize _PCD_SIZE_PcdSystemMemorySize
#define _PCD_TOKEN_PcdFvBaseAddress  8U
extern const UINT64 _gPcd_FixedAtBuild_PcdFvBaseAddress;
#define _PCD_GET_MODE_64_PcdFvBaseAddress  _gPcd_FixedAtBuild_PcdFvBaseAddress
//#define _PCD_SET_MODE_64_PcdFvBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFvBaseAddress 0x50004000
#define _PCD_SIZE_PcdFvBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdFvBaseAddress _PCD_SIZE_PcdFvBaseAddress
#define _PCD_TOKEN_PcdArmPrimaryCoreMask  46U
extern const UINT32 _gPcd_FixedAtBuild_PcdArmPrimaryCoreMask;
#define _PCD_GET_MODE_32_PcdArmPrimaryCoreMask  _gPcd_FixedAtBuild_PcdArmPrimaryCoreMask
//#define _PCD_SET_MODE_32_PcdArmPrimaryCoreMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdArmPrimaryCoreMask 0xF03
#define _PCD_SIZE_PcdArmPrimaryCoreMask 4
#define _PCD_GET_MODE_SIZE_PcdArmPrimaryCoreMask _PCD_SIZE_PcdArmPrimaryCoreMask
#define _PCD_TOKEN_PcdPcieControlBaseAddress  47U
extern const UINT64 _gPcd_FixedAtBuild_PcdPcieControlBaseAddress;
#define _PCD_GET_MODE_64_PcdPcieControlBaseAddress  _gPcd_FixedAtBuild_PcdPcieControlBaseAddress
//#define _PCD_SET_MODE_64_PcdPcieControlBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPcieControlBaseAddress 0x33800000
#define _PCD_SIZE_PcdPcieControlBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdPcieControlBaseAddress _PCD_SIZE_PcdPcieControlBaseAddress
#define _PCD_TOKEN_PcdPciConfigurationSpaceBaseAddress  48U
extern const UINT64 _gPcd_FixedAtBuild_PcdPciConfigurationSpaceBaseAddress;
#define _PCD_GET_MODE_64_PcdPciConfigurationSpaceBaseAddress  _gPcd_FixedAtBuild_PcdPciConfigurationSpaceBaseAddress
//#define _PCD_SET_MODE_64_PcdPciConfigurationSpaceBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPciConfigurationSpaceBaseAddress 0x40000000
#define _PCD_SIZE_PcdPciConfigurationSpaceBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdPciConfigurationSpaceBaseAddress _PCD_SIZE_PcdPciConfigurationSpaceBaseAddress
#define _PCD_TOKEN_PcdPciConfigurationSpaceSize  49U
extern const UINT64 _gPcd_FixedAtBuild_PcdPciConfigurationSpaceSize;
#define _PCD_GET_MODE_64_PcdPciConfigurationSpaceSize  _gPcd_FixedAtBuild_PcdPciConfigurationSpaceSize
//#define _PCD_SET_MODE_64_PcdPciConfigurationSpaceSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPciConfigurationSpaceSize 0x10000000
#define _PCD_SIZE_PcdPciConfigurationSpaceSize 8
#define _PCD_GET_MODE_SIZE_PcdPciConfigurationSpaceSize _PCD_SIZE_PcdPciConfigurationSpaceSize
#define _PCD_TOKEN_PcdGlobalDataBaseAddress  50U
extern const UINT32 _gPcd_FixedAtBuild_PcdGlobalDataBaseAddress;
#define _PCD_GET_MODE_32_PcdGlobalDataBaseAddress  _gPcd_FixedAtBuild_PcdGlobalDataBaseAddress
//#define _PCD_SET_MODE_32_PcdGlobalDataBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdGlobalDataBaseAddress 0x407E9000
#define _PCD_SIZE_PcdGlobalDataBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdGlobalDataBaseAddress _PCD_SIZE_PcdGlobalDataBaseAddress
#define _PCD_TOKEN_PcdGlobalDataSize  51U
extern const UINT32 _gPcd_FixedAtBuild_PcdGlobalDataSize;
#define _PCD_GET_MODE_32_PcdGlobalDataSize  _gPcd_FixedAtBuild_PcdGlobalDataSize
//#define _PCD_SET_MODE_32_PcdGlobalDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdGlobalDataSize 0x1000
#define _PCD_SIZE_PcdGlobalDataSize 4
#define _PCD_GET_MODE_SIZE_PcdGlobalDataSize _PCD_SIZE_PcdGlobalDataSize
#define _PCD_TOKEN_PcdGpioBankMemoryRange  45U
extern const UINT32 _gPcd_FixedAtBuild_PcdGpioBankMemoryRange;
#define _PCD_GET_MODE_32_PcdGpioBankMemoryRange  _gPcd_FixedAtBuild_PcdGpioBankMemoryRange
//#define _PCD_SET_MODE_32_PcdGpioBankMemoryRange  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdGpioBankMemoryRange 16384
#define _PCD_SIZE_PcdGpioBankMemoryRange 4
#define _PCD_GET_MODE_SIZE_PcdGpioBankMemoryRange _PCD_SIZE_PcdGpioBankMemoryRange
#define _PCD_TOKEN_PcdArmLcdDdrFrameBufferBase  52U
extern const UINT64 _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferBase;
#define _PCD_GET_MODE_64_PcdArmLcdDdrFrameBufferBase  _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferBase
//#define _PCD_SET_MODE_64_PcdArmLcdDdrFrameBufferBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdArmLcdDdrFrameBufferBase 0x40000000
#define _PCD_SIZE_PcdArmLcdDdrFrameBufferBase 8
#define _PCD_GET_MODE_SIZE_PcdArmLcdDdrFrameBufferBase _PCD_SIZE_PcdArmLcdDdrFrameBufferBase
#define _PCD_TOKEN_PcdArmLcdDdrFrameBufferSize  53U
extern const UINT32 _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferSize;
#define _PCD_GET_MODE_32_PcdArmLcdDdrFrameBufferSize  _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferSize
//#define _PCD_SET_MODE_32_PcdArmLcdDdrFrameBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdArmLcdDdrFrameBufferSize 0x007E9000
#define _PCD_SIZE_PcdArmLcdDdrFrameBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdArmLcdDdrFrameBufferSize _PCD_SIZE_PcdArmLcdDdrFrameBufferSize
#define _PCD_TOKEN_PcdCoreCount  13U
extern const UINT32 _gPcd_FixedAtBuild_PcdCoreCount;
#define _PCD_GET_MODE_32_PcdCoreCount  _gPcd_FixedAtBuild_PcdCoreCount
//#define _PCD_SET_MODE_32_PcdCoreCount  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCoreCount 4
#define _PCD_SIZE_PcdCoreCount 4
#define _PCD_GET_MODE_SIZE_PcdCoreCount _PCD_SIZE_PcdCoreCount
#define _PCD_TOKEN_PcdTrustZonePrivateMemoryBase  54U
extern const UINT64 _gPcd_FixedAtBuild_PcdTrustZonePrivateMemoryBase;
#define _PCD_GET_MODE_64_PcdTrustZonePrivateMemoryBase  _gPcd_FixedAtBuild_PcdTrustZonePrivateMemoryBase
//#define _PCD_SET_MODE_64_PcdTrustZonePrivateMemoryBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTrustZonePrivateMemoryBase 0xBE000000
#define _PCD_SIZE_PcdTrustZonePrivateMemoryBase 8
#define _PCD_GET_MODE_SIZE_PcdTrustZonePrivateMemoryBase _PCD_SIZE_PcdTrustZonePrivateMemoryBase
#define _PCD_TOKEN_PcdTrustZonePrivateMemorySize  55U
extern const UINT64 _gPcd_FixedAtBuild_PcdTrustZonePrivateMemorySize;
#define _PCD_GET_MODE_64_PcdTrustZonePrivateMemorySize  _gPcd_FixedAtBuild_PcdTrustZonePrivateMemorySize
//#define _PCD_SET_MODE_64_PcdTrustZonePrivateMemorySize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTrustZonePrivateMemorySize 0x01E00000
#define _PCD_SIZE_PcdTrustZonePrivateMemorySize 8
#define _PCD_GET_MODE_SIZE_PcdTrustZonePrivateMemorySize _PCD_SIZE_PcdTrustZonePrivateMemorySize
#define _PCD_TOKEN_PcdTrustZoneSharedMemoryBase  56U
extern const UINT64 _gPcd_FixedAtBuild_PcdTrustZoneSharedMemoryBase;
#define _PCD_GET_MODE_64_PcdTrustZoneSharedMemoryBase  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemoryBase
//#define _PCD_SET_MODE_64_PcdTrustZoneSharedMemoryBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTrustZoneSharedMemoryBase 0xBFE00000
#define _PCD_SIZE_PcdTrustZoneSharedMemoryBase 8
#define _PCD_GET_MODE_SIZE_PcdTrustZoneSharedMemoryBase _PCD_SIZE_PcdTrustZoneSharedMemoryBase
#define _PCD_TOKEN_PcdTrustZoneSharedMemorySize  57U
extern const UINT64 _gPcd_FixedAtBuild_PcdTrustZoneSharedMemorySize;
#define _PCD_GET_MODE_64_PcdTrustZoneSharedMemorySize  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemorySize
//#define _PCD_SET_MODE_64_PcdTrustZoneSharedMemorySize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTrustZoneSharedMemorySize 0x00200000
#define _PCD_SIZE_PcdTrustZoneSharedMemorySize 8
#define _PCD_GET_MODE_SIZE_PcdTrustZoneSharedMemorySize _PCD_SIZE_PcdTrustZoneSharedMemorySize
#define _PCD_TOKEN_PcdTpm2AcpiBufferBase  58U
extern const UINT64 _gPcd_FixedAtBuild_PcdTpm2AcpiBufferBase;
#define _PCD_GET_MODE_64_PcdTpm2AcpiBufferBase  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferBase
//#define _PCD_SET_MODE_64_PcdTpm2AcpiBufferBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTpm2AcpiBufferBase 0x407EA000
#define _PCD_SIZE_PcdTpm2AcpiBufferBase 8
#define _PCD_GET_MODE_SIZE_PcdTpm2AcpiBufferBase _PCD_SIZE_PcdTpm2AcpiBufferBase
#define _PCD_TOKEN_PcdTpm2AcpiBufferSize  59U
extern const UINT32 _gPcd_FixedAtBuild_PcdTpm2AcpiBufferSize;
#define _PCD_GET_MODE_32_PcdTpm2AcpiBufferSize  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferSize
//#define _PCD_SET_MODE_32_PcdTpm2AcpiBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTpm2AcpiBufferSize 0x3000
#define _PCD_SIZE_PcdTpm2AcpiBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdTpm2AcpiBufferSize _PCD_SIZE_PcdTpm2AcpiBufferSize


#ifdef __cplusplus
}
#endif

#endif
