/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A9945BAB_78C9_43C9_9175_F576CA189870
#define _AUTOGENH_A9945BAB_78C9_43C9_9175_F576CA189870

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xA9945BAB, 0x78C9, 0x43C9, {0x91, 0x75, 0xF5, 0x76, 0xCA, 0x18, 0x98, 0x70}}

// Guids
extern EFI_GUID giMXPlatformTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gArmTokenSpaceGuid;
extern EFI_GUID gEfiVTUTF8Guid;
extern EFI_GUID gEfiVT100Guid;
extern EFI_GUID gEfiVT100PlusGuid;
extern EFI_GUID gEfiPcAnsiGuid;
extern EFI_GUID gEfiUartDevicePathGuid;
extern EFI_GUID gEfiSasDevicePathGuid;
extern EFI_GUID gEfiVirtualDiskGuid;
extern EFI_GUID gEfiVirtualCdGuid;
extern EFI_GUID gEfiPersistentVirtualDiskGuid;
extern EFI_GUID gEfiPersistentVirtualCdGuid;
extern EFI_GUID gEfiEventReadyToBootGuid;
extern EFI_GUID gEfiEventLegacyBootGuid;
extern EFI_GUID gEfiGlobalVariableGuid;
extern EFI_GUID gEfiAcpi20TableGuid;
extern EFI_GUID gEfiAcpi10TableGuid;

// Protocols
extern EFI_GUID gEfiSdhcProtocolGuid;
extern EFI_GUID gPcdProtocolGuid;
extern EFI_GUID gEfiPcdProtocolGuid;
extern EFI_GUID gGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiCpuArchProtocolGuid;
extern EFI_GUID gEfiDevicePathProtocolGuid;
extern EFI_GUID gEfiDebugPortProtocolGuid;
extern EFI_GUID gEfiDriverBindingProtocolGuid;
extern EFI_GUID gEfiSimpleTextOutProtocolGuid;
extern EFI_GUID gEfiGraphicsOutputProtocolGuid;
extern EFI_GUID gEfiHiiFontProtocolGuid;
extern EFI_GUID gEfiSimpleFileSystemProtocolGuid;
extern EFI_GUID gEfiUgaDrawProtocolGuid;
extern EFI_GUID gEfiComponentNameProtocolGuid;
extern EFI_GUID gEfiComponentName2ProtocolGuid;
extern EFI_GUID gEfiDriverConfigurationProtocolGuid;
extern EFI_GUID gEfiDriverConfiguration2ProtocolGuid;
extern EFI_GUID gEfiDriverDiagnosticsProtocolGuid;
extern EFI_GUID gEfiDriverDiagnostics2ProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdGpioBankMemoryRange  45U
#define _PCD_SIZE_PcdGpioBankMemoryRange 4
#define _PCD_GET_MODE_SIZE_PcdGpioBankMemoryRange  _PCD_SIZE_PcdGpioBankMemoryRange 
#define _PCD_VALUE_PcdGpioBankMemoryRange  16384U
extern const  UINT32  _gPcd_FixedAtBuild_PcdGpioBankMemoryRange;
#define _PCD_GET_MODE_32_PcdGpioBankMemoryRange  _gPcd_FixedAtBuild_PcdGpioBankMemoryRange
//#define _PCD_SET_MODE_32_PcdGpioBankMemoryRange  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc1Base  162U
#define _PCD_SIZE_PcdSdhc1Base 4
#define _PCD_GET_MODE_SIZE_PcdSdhc1Base  _PCD_SIZE_PcdSdhc1Base 
#define _PCD_VALUE_PcdSdhc1Base  0x30B40000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdSdhc1Base;
#define _PCD_GET_MODE_32_PcdSdhc1Base  _gPcd_FixedAtBuild_PcdSdhc1Base
//#define _PCD_SET_MODE_32_PcdSdhc1Base  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc1CardDetectSignal  163U
#define _PCD_SIZE_PcdSdhc1CardDetectSignal 2
#define _PCD_GET_MODE_SIZE_PcdSdhc1CardDetectSignal  _PCD_SIZE_PcdSdhc1CardDetectSignal 
#define _PCD_VALUE_PcdSdhc1CardDetectSignal  0xFF00U
extern const  UINT16  _gPcd_FixedAtBuild_PcdSdhc1CardDetectSignal;
#define _PCD_GET_MODE_16_PcdSdhc1CardDetectSignal  _gPcd_FixedAtBuild_PcdSdhc1CardDetectSignal
//#define _PCD_SET_MODE_16_PcdSdhc1CardDetectSignal  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc1Enable  164U
#define _PCD_SIZE_PcdSdhc1Enable 1
#define _PCD_GET_MODE_SIZE_PcdSdhc1Enable  _PCD_SIZE_PcdSdhc1Enable 
#define _PCD_VALUE_PcdSdhc1Enable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSdhc1Enable;
#define _PCD_GET_MODE_BOOL_PcdSdhc1Enable  _gPcd_FixedAtBuild_PcdSdhc1Enable
//#define _PCD_SET_MODE_BOOL_PcdSdhc1Enable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc1WriteProtectSignal  165U
#define _PCD_SIZE_PcdSdhc1WriteProtectSignal 2
#define _PCD_GET_MODE_SIZE_PcdSdhc1WriteProtectSignal  _PCD_SIZE_PcdSdhc1WriteProtectSignal 
#define _PCD_VALUE_PcdSdhc1WriteProtectSignal  0xFF00U
extern const  UINT16  _gPcd_FixedAtBuild_PcdSdhc1WriteProtectSignal;
#define _PCD_GET_MODE_16_PcdSdhc1WriteProtectSignal  _gPcd_FixedAtBuild_PcdSdhc1WriteProtectSignal
//#define _PCD_SET_MODE_16_PcdSdhc1WriteProtectSignal  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc2Base  166U
#define _PCD_SIZE_PcdSdhc2Base 4
#define _PCD_GET_MODE_SIZE_PcdSdhc2Base  _PCD_SIZE_PcdSdhc2Base 
#define _PCD_VALUE_PcdSdhc2Base  0x30B50000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdSdhc2Base;
#define _PCD_GET_MODE_32_PcdSdhc2Base  _gPcd_FixedAtBuild_PcdSdhc2Base
//#define _PCD_SET_MODE_32_PcdSdhc2Base  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc2CardDetectSignal  167U
#define _PCD_SIZE_PcdSdhc2CardDetectSignal 2
#define _PCD_GET_MODE_SIZE_PcdSdhc2CardDetectSignal  _PCD_SIZE_PcdSdhc2CardDetectSignal 
#define _PCD_VALUE_PcdSdhc2CardDetectSignal  0xFF00U
extern const  UINT16  _gPcd_FixedAtBuild_PcdSdhc2CardDetectSignal;
#define _PCD_GET_MODE_16_PcdSdhc2CardDetectSignal  _gPcd_FixedAtBuild_PcdSdhc2CardDetectSignal
//#define _PCD_SET_MODE_16_PcdSdhc2CardDetectSignal  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc2Enable  168U
#define _PCD_SIZE_PcdSdhc2Enable 1
#define _PCD_GET_MODE_SIZE_PcdSdhc2Enable  _PCD_SIZE_PcdSdhc2Enable 
#define _PCD_VALUE_PcdSdhc2Enable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSdhc2Enable;
#define _PCD_GET_MODE_BOOL_PcdSdhc2Enable  _gPcd_FixedAtBuild_PcdSdhc2Enable
//#define _PCD_SET_MODE_BOOL_PcdSdhc2Enable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc2WriteProtectSignal  169U
#define _PCD_SIZE_PcdSdhc2WriteProtectSignal 2
#define _PCD_GET_MODE_SIZE_PcdSdhc2WriteProtectSignal  _PCD_SIZE_PcdSdhc2WriteProtectSignal 
#define _PCD_VALUE_PcdSdhc2WriteProtectSignal  0xFF00U
extern const  UINT16  _gPcd_FixedAtBuild_PcdSdhc2WriteProtectSignal;
#define _PCD_GET_MODE_16_PcdSdhc2WriteProtectSignal  _gPcd_FixedAtBuild_PcdSdhc2WriteProtectSignal
//#define _PCD_SET_MODE_16_PcdSdhc2WriteProtectSignal  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc3Base  170U
#define _PCD_SIZE_PcdSdhc3Base 4
#define _PCD_GET_MODE_SIZE_PcdSdhc3Base  _PCD_SIZE_PcdSdhc3Base 
#define _PCD_VALUE_PcdSdhc3Base  0x30B60000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdSdhc3Base;
#define _PCD_GET_MODE_32_PcdSdhc3Base  _gPcd_FixedAtBuild_PcdSdhc3Base
//#define _PCD_SET_MODE_32_PcdSdhc3Base  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc3CardDetectSignal  171U
#define _PCD_SIZE_PcdSdhc3CardDetectSignal 2
#define _PCD_GET_MODE_SIZE_PcdSdhc3CardDetectSignal  _PCD_SIZE_PcdSdhc3CardDetectSignal 
#define _PCD_VALUE_PcdSdhc3CardDetectSignal  0xFFFFU
extern const  UINT16  _gPcd_FixedAtBuild_PcdSdhc3CardDetectSignal;
#define _PCD_GET_MODE_16_PcdSdhc3CardDetectSignal  _gPcd_FixedAtBuild_PcdSdhc3CardDetectSignal
//#define _PCD_SET_MODE_16_PcdSdhc3CardDetectSignal  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc3Enable  172U
#define _PCD_SIZE_PcdSdhc3Enable 1
#define _PCD_GET_MODE_SIZE_PcdSdhc3Enable  _PCD_SIZE_PcdSdhc3Enable 
#define _PCD_VALUE_PcdSdhc3Enable  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSdhc3Enable;
#define _PCD_GET_MODE_BOOL_PcdSdhc3Enable  _gPcd_FixedAtBuild_PcdSdhc3Enable
//#define _PCD_SET_MODE_BOOL_PcdSdhc3Enable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc3WriteProtectSignal  173U
#define _PCD_SIZE_PcdSdhc3WriteProtectSignal 2
#define _PCD_GET_MODE_SIZE_PcdSdhc3WriteProtectSignal  _PCD_SIZE_PcdSdhc3WriteProtectSignal 
#define _PCD_VALUE_PcdSdhc3WriteProtectSignal  0xFF00U
extern const  UINT16  _gPcd_FixedAtBuild_PcdSdhc3WriteProtectSignal;
#define _PCD_GET_MODE_16_PcdSdhc3WriteProtectSignal  _gPcd_FixedAtBuild_PcdSdhc3WriteProtectSignal
//#define _PCD_SET_MODE_16_PcdSdhc3WriteProtectSignal  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc4Base  174U
#define _PCD_SIZE_PcdSdhc4Base 4
#define _PCD_GET_MODE_SIZE_PcdSdhc4Base  _PCD_SIZE_PcdSdhc4Base 
#define _PCD_VALUE_PcdSdhc4Base  0x00000000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdSdhc4Base;
#define _PCD_GET_MODE_32_PcdSdhc4Base  _gPcd_FixedAtBuild_PcdSdhc4Base
//#define _PCD_SET_MODE_32_PcdSdhc4Base  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc4CardDetectSignal  175U
#define _PCD_SIZE_PcdSdhc4CardDetectSignal 2
#define _PCD_GET_MODE_SIZE_PcdSdhc4CardDetectSignal  _PCD_SIZE_PcdSdhc4CardDetectSignal 
#define _PCD_VALUE_PcdSdhc4CardDetectSignal  0xFF00U
extern const  UINT16  _gPcd_FixedAtBuild_PcdSdhc4CardDetectSignal;
#define _PCD_GET_MODE_16_PcdSdhc4CardDetectSignal  _gPcd_FixedAtBuild_PcdSdhc4CardDetectSignal
//#define _PCD_SET_MODE_16_PcdSdhc4CardDetectSignal  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc4Enable  176U
#define _PCD_SIZE_PcdSdhc4Enable 1
#define _PCD_GET_MODE_SIZE_PcdSdhc4Enable  _PCD_SIZE_PcdSdhc4Enable 
#define _PCD_VALUE_PcdSdhc4Enable  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSdhc4Enable;
#define _PCD_GET_MODE_BOOL_PcdSdhc4Enable  _gPcd_FixedAtBuild_PcdSdhc4Enable
//#define _PCD_SET_MODE_BOOL_PcdSdhc4Enable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSdhc4WriteProtectSignal  177U
#define _PCD_SIZE_PcdSdhc4WriteProtectSignal 2
#define _PCD_GET_MODE_SIZE_PcdSdhc4WriteProtectSignal  _PCD_SIZE_PcdSdhc4WriteProtectSignal 
#define _PCD_VALUE_PcdSdhc4WriteProtectSignal  0xFF01U
extern const  UINT16  _gPcd_FixedAtBuild_PcdSdhc4WriteProtectSignal;
#define _PCD_GET_MODE_16_PcdSdhc4WriteProtectSignal  _gPcd_FixedAtBuild_PcdSdhc4WriteProtectSignal
//#define _PCD_SET_MODE_16_PcdSdhc4WriteProtectSignal  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
SdhcInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
