/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_814EA9F7_4DEE_4817_B0B9_224EBA8126E9
#define _AUTOGENH_814EA9F7_4DEE_4817_B0B9_224EBA8126E9

#ifdef __cplusplus
extern "C" {
#endif

#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x814EA9F7, 0x4DEE, 0x4817, {0xB0, 0xB9, 0x22, 0x4E, 0xBA, 0x81, 0x26, 0xE9}}

// Guids
extern EFI_GUID gOpteeHelloWorldTaGuid;
extern EFI_GUID gOpteeClientPkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID giMXPlatformTokenSpaceGuid;
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
extern EFI_GUID gEdkiiPerformanceMeasurementProtocolGuid;
extern EFI_GUID gEfiDxeServicesTableGuid;
extern EFI_GUID gEfiFileInfoGuid;

// Protocols
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
extern EFI_GUID gEfiFirmwareVolume2ProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;
extern EFI_GUID gEfiLoadFileProtocolGuid;
extern EFI_GUID gEfiLoadFile2ProtocolGuid;
extern EFI_GUID gEfiShellParametersProtocolGuid;
extern EFI_GUID gEfiShellInterfaceGuid;
extern EFI_GUID gEfiRpmbIoProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

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

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
