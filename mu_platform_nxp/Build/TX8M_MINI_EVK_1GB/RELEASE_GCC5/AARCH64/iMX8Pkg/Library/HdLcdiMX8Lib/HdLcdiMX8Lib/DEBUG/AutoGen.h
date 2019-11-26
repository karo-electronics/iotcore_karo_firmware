/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_CBF88FAD_4797_AF2D_EBE7_2890BFD2AD8F
#define _AUTOGENH_CBF88FAD_4797_AF2D_EBE7_2890BFD2AD8F

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gArmPlatformTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
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


#ifdef __cplusplus
}
#endif

#endif
