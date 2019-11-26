/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_6E261F6C_4CF8_DF84_9226_17A360B03D84
#define _AUTOGENH_6E261F6C_4CF8_DF84_9226_17A360B03D84

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x6E261F6C, 0x4CF8, 0xDF84, {0x92, 0x26, 0x17, 0xA3, 0x60, 0xB0, 0x3D, 0x84}}

// Guids
extern EFI_GUID gEfiEndOfDxeEventGroupGuid;
extern EFI_GUID gEfiFileInfoGuid;
extern EFI_GUID gArmTokenSpaceGuid;
extern EFI_GUID giMX8TokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID giMXPlatformTokenSpaceGuid;
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
extern EFI_GUID gEdkiiIfrBitVarstoreGuid;
extern EFI_GUID gEfiShellEnvironment2ExtGuid;
extern EFI_GUID gEfiShellPkgTokenSpaceGuid;
extern EFI_GUID gArmBootMonFsFileInfoGuid;
extern EFI_GUID gEfiDxeServicesTableGuid;
extern EFI_GUID gEdkiiNonDiscoverableAhciDeviceGuid;
extern EFI_GUID gEdkiiNonDiscoverableAmbaDeviceGuid;
extern EFI_GUID gEdkiiNonDiscoverableEhciDeviceGuid;
extern EFI_GUID gEdkiiNonDiscoverableNvmeDeviceGuid;
extern EFI_GUID gEdkiiNonDiscoverableOhciDeviceGuid;
extern EFI_GUID gEdkiiNonDiscoverableSdhciDeviceGuid;
extern EFI_GUID gEdkiiNonDiscoverableUfsDeviceGuid;
extern EFI_GUID gEdkiiNonDiscoverableUhciDeviceGuid;
extern EFI_GUID gEdkiiNonDiscoverableXhciDeviceGuid;

// Protocols
extern EFI_GUID gEfiBlockIoProtocolGuid;
extern EFI_GUID gEfiDevicePathFromTextProtocolGuid;
extern EFI_GUID gEfiSimpleFileSystemProtocolGuid;
extern EFI_GUID gPcdProtocolGuid;
extern EFI_GUID gEfiPcdProtocolGuid;
extern EFI_GUID gGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiCpuArchProtocolGuid;
extern EFI_GUID gEfiDevicePathProtocolGuid;
extern EFI_GUID gEfiDebugPortProtocolGuid;
extern EFI_GUID gEfiHiiFontProtocolGuid;
extern EFI_GUID gEfiHiiStringProtocolGuid;
extern EFI_GUID gEfiHiiImageProtocolGuid;
extern EFI_GUID gEfiHiiDatabaseProtocolGuid;
extern EFI_GUID gEfiHiiConfigRoutingProtocolGuid;
extern EFI_GUID gEfiDriverBindingProtocolGuid;
extern EFI_GUID gEfiSimpleTextOutProtocolGuid;
extern EFI_GUID gEfiGraphicsOutputProtocolGuid;
extern EFI_GUID gEfiUgaDrawProtocolGuid;
extern EFI_GUID gEfiComponentNameProtocolGuid;
extern EFI_GUID gEfiComponentName2ProtocolGuid;
extern EFI_GUID gEfiDriverConfigurationProtocolGuid;
extern EFI_GUID gEfiDriverConfiguration2ProtocolGuid;
extern EFI_GUID gEfiDriverDiagnosticsProtocolGuid;
extern EFI_GUID gEfiDriverDiagnostics2ProtocolGuid;
extern EFI_GUID gEfiUnicodeCollation2ProtocolGuid;
extern EFI_GUID gEfiFormBrowser2ProtocolGuid;
extern EFI_GUID gEfiShellProtocolGuid;
extern EFI_GUID gEfiShellParametersProtocolGuid;
extern EFI_GUID gEfiShellEnvironment2Guid;
extern EFI_GUID gEfiShellInterfaceGuid;
extern EFI_GUID gEfiShellDynamicCommandProtocolGuid;
extern EFI_GUID gEdkiiNonDiscoverableDeviceProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdSystemMemoryBase  27U
#define _PCD_SIZE_PcdSystemMemoryBase 8
#define _PCD_GET_MODE_SIZE_PcdSystemMemoryBase  _PCD_SIZE_PcdSystemMemoryBase 
#define _PCD_VALUE_PcdSystemMemoryBase  0x40000000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdSystemMemoryBase;
#define _PCD_GET_MODE_64_PcdSystemMemoryBase  _gPcd_FixedAtBuild_PcdSystemMemoryBase
//#define _PCD_SET_MODE_64_PcdSystemMemoryBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSystemMemorySize  28U
#define _PCD_SIZE_PcdSystemMemorySize 8
#define _PCD_GET_MODE_SIZE_PcdSystemMemorySize  _PCD_SIZE_PcdSystemMemorySize 
#define _PCD_VALUE_PcdSystemMemorySize  0x3E000000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdSystemMemorySize;
#define _PCD_GET_MODE_64_PcdSystemMemorySize  _gPcd_FixedAtBuild_PcdSystemMemorySize
//#define _PCD_SET_MODE_64_PcdSystemMemorySize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHypFvBaseAddress  155U
#define _PCD_SIZE_PcdHypFvBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdHypFvBaseAddress  _PCD_SIZE_PcdHypFvBaseAddress 
#define _PCD_VALUE_PcdHypFvBaseAddress  0U
extern const  UINT32  _gPcd_FixedAtBuild_PcdHypFvBaseAddress;
#define _PCD_GET_MODE_32_PcdHypFvBaseAddress  _gPcd_FixedAtBuild_PcdHypFvBaseAddress
//#define _PCD_SET_MODE_32_PcdHypFvBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHypFvSize  156U
#define _PCD_SIZE_PcdHypFvSize 4
#define _PCD_GET_MODE_SIZE_PcdHypFvSize  _PCD_SIZE_PcdHypFvSize 
#define _PCD_VALUE_PcdHypFvSize  0U
extern const  UINT32  _gPcd_FixedAtBuild_PcdHypFvSize;
#define _PCD_GET_MODE_32_PcdHypFvSize  _gPcd_FixedAtBuild_PcdHypFvSize
//#define _PCD_SET_MODE_32_PcdHypFvSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUsb1XhciBaseAddress  157U
#define _PCD_SIZE_PcdUsb1XhciBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdUsb1XhciBaseAddress  _PCD_SIZE_PcdUsb1XhciBaseAddress 
#define _PCD_VALUE_PcdUsb1XhciBaseAddress  0x38100000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdUsb1XhciBaseAddress;
#define _PCD_GET_MODE_64_PcdUsb1XhciBaseAddress  _gPcd_FixedAtBuild_PcdUsb1XhciBaseAddress
//#define _PCD_SET_MODE_64_PcdUsb1XhciBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUsb2XhciBaseAddress  158U
#define _PCD_SIZE_PcdUsb2XhciBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdUsb2XhciBaseAddress  _PCD_SIZE_PcdUsb2XhciBaseAddress 
#define _PCD_VALUE_PcdUsb2XhciBaseAddress  0x38200000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdUsb2XhciBaseAddress;
#define _PCD_GET_MODE_64_PcdUsb2XhciBaseAddress  _gPcd_FixedAtBuild_PcdUsb2XhciBaseAddress
//#define _PCD_SET_MODE_64_PcdUsb2XhciBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
iMX8EntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
