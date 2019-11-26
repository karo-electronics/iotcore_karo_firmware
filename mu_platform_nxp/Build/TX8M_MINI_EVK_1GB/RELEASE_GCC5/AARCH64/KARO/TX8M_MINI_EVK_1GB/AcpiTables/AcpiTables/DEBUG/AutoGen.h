/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_7E374E25_8E01_4FEE_87F2_390C23C606CD
#define _AUTOGENH_7E374E25_8E01_4FEE_87F2_390C23C606CD

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x7E374E25, 0x8E01, 0x4FEE, {0x87, 0xF2, 0x39, 0x0C, 0x23, 0xC6, 0x06, 0xCD}}

// Guids
extern GUID gArmPlatformTokenSpaceGuid;
extern GUID gArmTokenSpaceGuid;
extern GUID giMXPlatformTokenSpaceGuid;
extern GUID gOpteeClientPkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdCoreCount  13U
#define _PCD_SIZE_PcdCoreCount 4
#define _PCD_GET_MODE_SIZE_PcdCoreCount  _PCD_SIZE_PcdCoreCount 
#define _PCD_VALUE_PcdCoreCount  4U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCoreCount;
#define _PCD_GET_MODE_32_PcdCoreCount  _gPcd_FixedAtBuild_PcdCoreCount
//#define _PCD_SET_MODE_32_PcdCoreCount  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGicDistributorBase  94U
#define _PCD_SIZE_PcdGicDistributorBase 8
#define _PCD_GET_MODE_SIZE_PcdGicDistributorBase  _PCD_SIZE_PcdGicDistributorBase 
#define _PCD_VALUE_PcdGicDistributorBase  0x38800000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdGicDistributorBase;
#define _PCD_GET_MODE_64_PcdGicDistributorBase  _gPcd_FixedAtBuild_PcdGicDistributorBase
//#define _PCD_SET_MODE_64_PcdGicDistributorBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGicRedistributorsBase  95U
#define _PCD_SIZE_PcdGicRedistributorsBase 8
#define _PCD_GET_MODE_SIZE_PcdGicRedistributorsBase  _PCD_SIZE_PcdGicRedistributorsBase 
#define _PCD_VALUE_PcdGicRedistributorsBase  0x38880000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdGicRedistributorsBase;
#define _PCD_GET_MODE_64_PcdGicRedistributorsBase  _gPcd_FixedAtBuild_PcdGicRedistributorsBase
//#define _PCD_SET_MODE_64_PcdGicRedistributorsBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArmArchTimerSecIntrNum  99U
#define _PCD_SIZE_PcdArmArchTimerSecIntrNum 4
#define _PCD_GET_MODE_SIZE_PcdArmArchTimerSecIntrNum  _PCD_SIZE_PcdArmArchTimerSecIntrNum 
#define _PCD_VALUE_PcdArmArchTimerSecIntrNum  29U
extern const  UINT32  _gPcd_FixedAtBuild_PcdArmArchTimerSecIntrNum;
#define _PCD_GET_MODE_32_PcdArmArchTimerSecIntrNum  _gPcd_FixedAtBuild_PcdArmArchTimerSecIntrNum
//#define _PCD_SET_MODE_32_PcdArmArchTimerSecIntrNum  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArmArchTimerIntrNum  100U
#define _PCD_SIZE_PcdArmArchTimerIntrNum 4
#define _PCD_GET_MODE_SIZE_PcdArmArchTimerIntrNum  _PCD_SIZE_PcdArmArchTimerIntrNum 
#define _PCD_VALUE_PcdArmArchTimerIntrNum  30U
extern const  UINT32  _gPcd_FixedAtBuild_PcdArmArchTimerIntrNum;
#define _PCD_GET_MODE_32_PcdArmArchTimerIntrNum  _gPcd_FixedAtBuild_PcdArmArchTimerIntrNum
//#define _PCD_SET_MODE_32_PcdArmArchTimerIntrNum  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArmArchTimerHypIntrNum  102U
#define _PCD_SIZE_PcdArmArchTimerHypIntrNum 4
#define _PCD_GET_MODE_SIZE_PcdArmArchTimerHypIntrNum  _PCD_SIZE_PcdArmArchTimerHypIntrNum 
#define _PCD_VALUE_PcdArmArchTimerHypIntrNum  26U
extern const  UINT32  _gPcd_FixedAtBuild_PcdArmArchTimerHypIntrNum;
#define _PCD_GET_MODE_32_PcdArmArchTimerHypIntrNum  _gPcd_FixedAtBuild_PcdArmArchTimerHypIntrNum
//#define _PCD_SET_MODE_32_PcdArmArchTimerHypIntrNum  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArmArchTimerVirtIntrNum  101U
#define _PCD_SIZE_PcdArmArchTimerVirtIntrNum 4
#define _PCD_GET_MODE_SIZE_PcdArmArchTimerVirtIntrNum  _PCD_SIZE_PcdArmArchTimerVirtIntrNum 
#define _PCD_VALUE_PcdArmArchTimerVirtIntrNum  27U
extern const  UINT32  _gPcd_FixedAtBuild_PcdArmArchTimerVirtIntrNum;
#define _PCD_GET_MODE_32_PcdArmArchTimerVirtIntrNum  _gPcd_FixedAtBuild_PcdArmArchTimerVirtIntrNum
//#define _PCD_SET_MODE_32_PcdArmArchTimerVirtIntrNum  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGlobalDataBaseAddress  50U
#define _PCD_SIZE_PcdGlobalDataBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdGlobalDataBaseAddress  _PCD_SIZE_PcdGlobalDataBaseAddress 
#define _PCD_VALUE_PcdGlobalDataBaseAddress  0x407E9000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdGlobalDataBaseAddress;
#define _PCD_GET_MODE_32_PcdGlobalDataBaseAddress  _gPcd_FixedAtBuild_PcdGlobalDataBaseAddress
//#define _PCD_SET_MODE_32_PcdGlobalDataBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdKdUartInstance  224U
#define _PCD_SIZE_PcdKdUartInstance 4
#define _PCD_GET_MODE_SIZE_PcdKdUartInstance  _PCD_SIZE_PcdKdUartInstance 
#define _PCD_VALUE_PcdKdUartInstance  1U
extern const  UINT32  _gPcd_FixedAtBuild_PcdKdUartInstance;
#define _PCD_GET_MODE_32_PcdKdUartInstance  _gPcd_FixedAtBuild_PcdKdUartInstance
//#define _PCD_SET_MODE_32_PcdKdUartInstance  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTrustZoneSharedMemoryBase  56U
#define _PCD_SIZE_PcdTrustZoneSharedMemoryBase 8
#define _PCD_GET_MODE_SIZE_PcdTrustZoneSharedMemoryBase  _PCD_SIZE_PcdTrustZoneSharedMemoryBase 
#define _PCD_VALUE_PcdTrustZoneSharedMemoryBase  0xBFE00000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemoryBase;
#define _PCD_GET_MODE_64_PcdTrustZoneSharedMemoryBase  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemoryBase
//#define _PCD_SET_MODE_64_PcdTrustZoneSharedMemoryBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTrustZoneSharedMemorySize  57U
#define _PCD_SIZE_PcdTrustZoneSharedMemorySize 8
#define _PCD_GET_MODE_SIZE_PcdTrustZoneSharedMemorySize  _PCD_SIZE_PcdTrustZoneSharedMemorySize 
#define _PCD_VALUE_PcdTrustZoneSharedMemorySize  0x00200000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemorySize;
#define _PCD_GET_MODE_64_PcdTrustZoneSharedMemorySize  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemorySize
//#define _PCD_SET_MODE_64_PcdTrustZoneSharedMemorySize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTpm2AcpiBufferBase  58U
#define _PCD_SIZE_PcdTpm2AcpiBufferBase 8
#define _PCD_GET_MODE_SIZE_PcdTpm2AcpiBufferBase  _PCD_SIZE_PcdTpm2AcpiBufferBase 
#define _PCD_VALUE_PcdTpm2AcpiBufferBase  0x407EA000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferBase;
#define _PCD_GET_MODE_64_PcdTpm2AcpiBufferBase  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferBase
//#define _PCD_SET_MODE_64_PcdTpm2AcpiBufferBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTpm2AcpiBufferSize  59U
#define _PCD_SIZE_PcdTpm2AcpiBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdTpm2AcpiBufferSize  _PCD_SIZE_PcdTpm2AcpiBufferSize 
#define _PCD_VALUE_PcdTpm2AcpiBufferSize  0x3000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferSize;
#define _PCD_GET_MODE_32_PcdTpm2AcpiBufferSize  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferSize
//#define _PCD_SET_MODE_32_PcdTpm2AcpiBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
