/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_1E27D461_78F3_4F7D_B1C2_F72384F13A6E
#define _AUTOGENH_1E27D461_78F3_4F7D_B1C2_F72384F13A6E

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
#define _PCD_TOKEN_PcdArmArchTimerFreqInHz  39U
extern const UINT32 _gPcd_FixedAtBuild_PcdArmArchTimerFreqInHz;
#define _PCD_GET_MODE_32_PcdArmArchTimerFreqInHz  _gPcd_FixedAtBuild_PcdArmArchTimerFreqInHz
//#define _PCD_SET_MODE_32_PcdArmArchTimerFreqInHz  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdArmArchTimerFreqInHz 0
#define _PCD_SIZE_PcdArmArchTimerFreqInHz 4
#define _PCD_GET_MODE_SIZE_PcdArmArchTimerFreqInHz _PCD_SIZE_PcdArmArchTimerFreqInHz


#ifdef __cplusplus
}
#endif

#endif
