/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_FA41BEF0_0666_4C07_9EC3_47F61C36EDBE
#define _AUTOGENH_FA41BEF0_0666_4C07_9EC3_47F61C36EDBE

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
#define _PCD_TOKEN_PcdGpioBankMemoryRange  45U
extern const UINT32 _gPcd_FixedAtBuild_PcdGpioBankMemoryRange;
#define _PCD_GET_MODE_32_PcdGpioBankMemoryRange  _gPcd_FixedAtBuild_PcdGpioBankMemoryRange
//#define _PCD_SET_MODE_32_PcdGpioBankMemoryRange  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdGpioBankMemoryRange 16384
#define _PCD_SIZE_PcdGpioBankMemoryRange 4
#define _PCD_GET_MODE_SIZE_PcdGpioBankMemoryRange _PCD_SIZE_PcdGpioBankMemoryRange


#ifdef __cplusplus
}
#endif

#endif
