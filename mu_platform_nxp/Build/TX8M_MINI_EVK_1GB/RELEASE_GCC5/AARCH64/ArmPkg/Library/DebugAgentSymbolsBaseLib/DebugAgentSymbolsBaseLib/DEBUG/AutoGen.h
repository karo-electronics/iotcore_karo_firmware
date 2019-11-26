/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_9055e2e0_9b33_11e0_a7d7_0002a5d5c51b
#define _AUTOGENH_9055e2e0_9b33_11e0_a7d7_0002a5d5c51b

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gArmTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdSecureFvBaseAddress  60U
extern const UINT64 _gPcd_FixedAtBuild_PcdSecureFvBaseAddress;
#define _PCD_GET_MODE_64_PcdSecureFvBaseAddress  _gPcd_FixedAtBuild_PcdSecureFvBaseAddress
//#define _PCD_SET_MODE_64_PcdSecureFvBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSecureFvBaseAddress 0x0
#define _PCD_SIZE_PcdSecureFvBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdSecureFvBaseAddress _PCD_SIZE_PcdSecureFvBaseAddress
#define _PCD_TOKEN_PcdFvBaseAddress  8U
extern const UINT64 _gPcd_FixedAtBuild_PcdFvBaseAddress;
#define _PCD_GET_MODE_64_PcdFvBaseAddress  _gPcd_FixedAtBuild_PcdFvBaseAddress
//#define _PCD_SET_MODE_64_PcdFvBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFvBaseAddress 0x50004000
#define _PCD_SIZE_PcdFvBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdFvBaseAddress _PCD_SIZE_PcdFvBaseAddress


#ifdef __cplusplus
}
#endif

#endif
