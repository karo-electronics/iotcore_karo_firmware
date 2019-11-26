/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_F635FE9D_6678_40E3_AC3D_4CBA5FC47B48
#define _AUTOGENH_F635FE9D_6678_40E3_AC3D_4CBA5FC47B48

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern EFI_GUID gOpteeClientPkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiRpmbIoProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
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


#ifdef __cplusplus
}
#endif

#endif
