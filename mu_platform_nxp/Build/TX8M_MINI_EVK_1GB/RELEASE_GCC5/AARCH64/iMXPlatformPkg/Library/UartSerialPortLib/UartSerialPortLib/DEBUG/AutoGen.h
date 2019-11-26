/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_C22D85E6_8B3E_4c05_AA5B_5732F3ACD055
#define _AUTOGENH_C22D85E6_8B3E_4c05_AA5B_5732F3ACD055

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID giMXPlatformTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdSerialRegisterBase  35U
extern const UINT32 _gPcd_FixedAtBuild_PcdSerialRegisterBase;
#define _PCD_GET_MODE_32_PcdSerialRegisterBase  _gPcd_FixedAtBuild_PcdSerialRegisterBase
//#define _PCD_SET_MODE_32_PcdSerialRegisterBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSerialRegisterBase 0x30860000
#define _PCD_SIZE_PcdSerialRegisterBase 4
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterBase _PCD_SIZE_PcdSerialRegisterBase


#ifdef __cplusplus
}
#endif

#endif
