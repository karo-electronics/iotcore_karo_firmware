/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.c
  Abstract:       Auto-generated AutoGen.c for building module or library.
**/
#include <PiPei.h>
#include <Library/DebugLib.h>

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEfiCallerIdGuid = {0xd959e387, 0x7b91, 0x452c, {0x90, 0xe0, 0xa1, 0xdb, 0xac, 0x90, 0xdd, 0xb8}};

GLOBAL_REMOVE_IF_UNREFERENCED CHAR8 *gEfiCallerBaseName = "ArmPlatformPrePiUniCore";

// Guids
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gArmMpCoreInfoGuid = { 0xa4ee0728, 0xe5d7, 0x4ac5,  {0xb2, 0x1e, 0x65, 0x8e, 0xd8, 0x57, 0xe8, 0x34} };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiFirmwarePerformanceGuid = { 0xc095791a, 0x3001, 0x47b2, { 0x80, 0xc9, 0xea, 0xc7, 0x31, 0x9f, 0x2f, 0xa4 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gArmTokenSpaceGuid = { 0xBB11ECFE, 0x820F, 0x4968, { 0xBB, 0xA6, 0xF7, 0x6A, 0xFE, 0x30, 0x25, 0x96 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gArmPlatformTokenSpaceGuid = { 0x9c0aaed4, 0x74c5, 0x4043, { 0xb4, 0x17, 0xa3, 0x22, 0x38, 0x14, 0xce, 0x76 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEmbeddedTokenSpaceGuid = { 0xe0d8ca17, 0x4276, 0x4386, { 0xbb, 0x79, 0x48, 0xcb, 0x81, 0x3d, 0x3c, 0x4f }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMdeModulePkgTokenSpaceGuid = { 0xA1AFF049, 0xFDEB, 0x442a, { 0xB3, 0x20, 0x13, 0xAB, 0x4C, 0xB7, 0x2B, 0xBC }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMdePkgTokenSpaceGuid = { 0x914AEBE7, 0x4635, 0x459b, { 0xAA, 0x1C, 0x11, 0xE2, 0x19, 0xB0, 0x3A, 0x10 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID giMXPlatformTokenSpaceGuid = { 0x24b09abe, 0x4e47, 0x481c, { 0xa9, 0xad, 0xce, 0xf1, 0x2c, 0x39, 0x23, 0x27} };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHobMemoryAllocModuleGuid = { 0xF8E21975, 0x0899, 0x4F58, { 0xA4, 0xBE, 0x55, 0x25, 0xA9, 0xC6, 0xD7, 0x7A }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHobMemoryAllocStackGuid = { 0x4ED4BF27, 0x4092, 0x42E9, { 0x80, 0x7D, 0x52, 0x7B, 0x1D, 0x00, 0xC9, 0xBD }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid = { 0x3b387bfd, 0x7abc, 0x4cf2, { 0xa0, 0xca, 0xb6, 0xa1, 0x6c, 0x1b, 0x1b, 0x25 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiStatusCodeSpecificDataGuid = { 0x335984BD, 0xE805, 0x409A, { 0xB8, 0xF8, 0xD2, 0x7E, 0xCE, 0x5F, 0xF7, 0xA6 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMemoryTypeInformationGuid = { 0x4C19049F, 0x4137, 0x4DD3, { 0x9C, 0x10, 0x8B, 0x97, 0xA8, 0x3F, 0xFD, 0xFA }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiStatusCodeDataTypeDebugGuid = { 0x9A4E9246, 0xD553, 0x11D5, { 0x87, 0xE2, 0x00, 0x06, 0x29, 0x45, 0xC3, 0xB9 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID giMX8TokenSpaceGuid = { 0x4F3BDBA2, 0x496B, 0x64BB, { 0xFA, 0xB3, 0x19, 0x9D, 0x81, 0xAA, 0xE5, 0xA2 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gOpteeClientPkgTokenSpaceGuid = { 0x04ad34ca, 0xdd25, 0x4156, { 0x90, 0xf5, 0x16, 0xf9, 0x40, 0xd0, 0x49, 0xe3 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLzmaCustomDecompressGuid = { 0xEE4E5898, 0x3914, 0x4259, { 0x9D, 0x6E, 0xDC, 0x7B, 0xD7, 0x94, 0x03, 0xCF }};

// Protocols
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiCpuArchProtocolGuid = { 0x26BACCB1, 0x6F42, 0x11D4, { 0xBC, 0xE7, 0x00, 0x80, 0xC7, 0x3C, 0x88, 0x81 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiStatusCodeRuntimeProtocolGuid = { 0xD2B2B828, 0x0826, 0x48A7, { 0xB3, 0xDF, 0x98, 0x3C, 0x00, 0x60, 0x24, 0xF0 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPeCoffLoaderProtocolGuid = { 0xB323179B, 0x97FB, 0x477E, { 0xB0, 0xFE, 0xD8, 0x85, 0x91, 0xFA, 0x11, 0xAB } };

// PPIs
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gArmMpCoreInfoPpiGuid = { 0x6847cc74, 0xe9ec, 0x4f8f, {0xa2, 0x9d, 0xab, 0x44, 0xe7, 0x54, 0xa8, 0xfc} };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiPeiMasterBootModePpiGuid = { 0x7408d748, 0xfc8c, 0x4ee6, {0x92, 0x88, 0xc4, 0xbe, 0xc0, 0x92, 0xa4, 0x10 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiPeiBootInRecoveryModePpiGuid = { 0x17ee496a, 0xd8e4, 0x4b9a, {0x94, 0xd1, 0xce, 0x82, 0x72, 0x30, 0x8, 0x50 } };

// Definition of SkuId Array
GLOBAL_REMOVE_IF_UNREFERENCED UINT64 _gPcd_SkuId_Array[] = {0x0};

// Definition of PCDs used in this module
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdVFPEnabled = _PCD_VALUE_PcdVFPEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdFdBaseAddress = _PCD_VALUE_PcdFdBaseAddress;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFdSize = _PCD_VALUE_PcdFdSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdFvBaseAddress = _PCD_VALUE_PcdFvBaseAddress;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFvSize = _PCD_VALUE_PcdFvSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCPUCorePrimaryStackSize = _PCD_VALUE_PcdCPUCorePrimaryStackSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCPUCoreSecondaryStackSize = _PCD_VALUE_PcdCPUCoreSecondaryStackSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSystemMemoryUefiRegionSize = _PCD_VALUE_PcdSystemMemoryUefiRegionSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCoreCount = _PCD_VALUE_PcdCoreCount;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdPrePiCpuIoSize = _PCD_VALUE_PcdPrePiCpuIoSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiACPIReclaimMemory = _PCD_VALUE_PcdMemoryTypeEfiACPIReclaimMemory;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiACPIMemoryNVS = _PCD_VALUE_PcdMemoryTypeEfiACPIMemoryNVS;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiReservedMemoryType = _PCD_VALUE_PcdMemoryTypeEfiReservedMemoryType;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiRuntimeServicesData = _PCD_VALUE_PcdMemoryTypeEfiRuntimeServicesData;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiRuntimeServicesCode = _PCD_VALUE_PcdMemoryTypeEfiRuntimeServicesCode;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiBootServicesCode = _PCD_VALUE_PcdMemoryTypeEfiBootServicesCode;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiBootServicesData = _PCD_VALUE_PcdMemoryTypeEfiBootServicesData;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiLoaderCode = _PCD_VALUE_PcdMemoryTypeEfiLoaderCode;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiLoaderData = _PCD_VALUE_PcdMemoryTypeEfiLoaderData;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdPrePiProduceMemoryTypeInformationHob = _PCD_VALUE_PcdPrePiProduceMemoryTypeInformationHob;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdSendSgiToBringUpSecondaryCores = _PCD_VALUE_PcdSendSgiToBringUpSecondaryCores;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT16 _gPcd_FixedAtBuild_PcdFirmwareVersionString[1] = {0 };
GLOBAL_REMOVE_IF_UNREFERENCED const UINTN _gPcd_FixedAtBuild_Size_PcdFirmwareVersionString = 2;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdSystemMemoryBase = _PCD_VALUE_PcdSystemMemoryBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdSystemMemorySize = _PCD_VALUE_PcdSystemMemorySize;

// Definition of PCDs used in libraries

#define _PCD_TOKEN_PcdVerifyNodeInList  29U
#define _PCD_SIZE_PcdVerifyNodeInList 1
#define _PCD_GET_MODE_SIZE_PcdVerifyNodeInList  _PCD_SIZE_PcdVerifyNodeInList 
#define _PCD_VALUE_PcdVerifyNodeInList  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVerifyNodeInList = _PCD_VALUE_PcdVerifyNodeInList;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifyNodeInList;
#define _PCD_GET_MODE_BOOL_PcdVerifyNodeInList  _gPcd_FixedAtBuild_PcdVerifyNodeInList
//#define _PCD_SET_MODE_BOOL_PcdVerifyNodeInList  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumLinkedListLength  30U
#define _PCD_SIZE_PcdMaximumLinkedListLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumLinkedListLength  _PCD_SIZE_PcdMaximumLinkedListLength 
#define _PCD_VALUE_PcdMaximumLinkedListLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumLinkedListLength = _PCD_VALUE_PcdMaximumLinkedListLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength;
#define _PCD_GET_MODE_32_PcdMaximumLinkedListLength  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength
//#define _PCD_SET_MODE_32_PcdMaximumLinkedListLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumAsciiStringLength  31U
#define _PCD_SIZE_PcdMaximumAsciiStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumAsciiStringLength  _PCD_SIZE_PcdMaximumAsciiStringLength 
#define _PCD_VALUE_PcdMaximumAsciiStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength = _PCD_VALUE_PcdMaximumAsciiStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength;
#define _PCD_GET_MODE_32_PcdMaximumAsciiStringLength  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength
//#define _PCD_SET_MODE_32_PcdMaximumAsciiStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumUnicodeStringLength  32U
#define _PCD_SIZE_PcdMaximumUnicodeStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumUnicodeStringLength  _PCD_SIZE_PcdMaximumUnicodeStringLength 
#define _PCD_VALUE_PcdMaximumUnicodeStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength = _PCD_VALUE_PcdMaximumUnicodeStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength;
#define _PCD_GET_MODE_32_PcdMaximumUnicodeStringLength  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength
//#define _PCD_SET_MODE_32_PcdMaximumUnicodeStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdControlFlowEnforcementPropertyMask  33U
#define _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 4
#define _PCD_GET_MODE_SIZE_PcdControlFlowEnforcementPropertyMask  _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 
#define _PCD_VALUE_PcdControlFlowEnforcementPropertyMask  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask = _PCD_VALUE_PcdControlFlowEnforcementPropertyMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask;
#define _PCD_GET_MODE_32_PcdControlFlowEnforcementPropertyMask  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask
//#define _PCD_SET_MODE_32_PcdControlFlowEnforcementPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPrintErrorLevel  34U
#define _PCD_SIZE_PcdDebugPrintErrorLevel 4
#define _PCD_GET_MODE_SIZE_PcdDebugPrintErrorLevel  _PCD_SIZE_PcdDebugPrintErrorLevel 
#define _PCD_VALUE_PcdDebugPrintErrorLevel  0x80080206U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdDebugPrintErrorLevel = _PCD_VALUE_PcdDebugPrintErrorLevel;
extern const  UINT32  _gPcd_FixedAtBuild_PcdDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdDebugPrintErrorLevel  _gPcd_FixedAtBuild_PcdDebugPrintErrorLevel
//#define _PCD_SET_MODE_32_PcdDebugPrintErrorLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSerialRegisterBase  35U
#define _PCD_SIZE_PcdSerialRegisterBase 4
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterBase  _PCD_SIZE_PcdSerialRegisterBase 
#define _PCD_VALUE_PcdSerialRegisterBase  0x30860000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSerialRegisterBase = _PCD_VALUE_PcdSerialRegisterBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSerialRegisterBase;
#define _PCD_GET_MODE_32_PcdSerialRegisterBase  _gPcd_FixedAtBuild_PcdSerialRegisterBase
//#define _PCD_SET_MODE_32_PcdSerialRegisterBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugClearMemoryValue  36U
#define _PCD_SIZE_PcdDebugClearMemoryValue 1
#define _PCD_GET_MODE_SIZE_PcdDebugClearMemoryValue  _PCD_SIZE_PcdDebugClearMemoryValue 
#define _PCD_VALUE_PcdDebugClearMemoryValue  0xAFU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugClearMemoryValue = _PCD_VALUE_PcdDebugClearMemoryValue;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue;
#define _PCD_GET_MODE_8_PcdDebugClearMemoryValue  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue
//#define _PCD_SET_MODE_8_PcdDebugClearMemoryValue  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPropertyMask  37U
#define _PCD_SIZE_PcdDebugPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdDebugPropertyMask  _PCD_SIZE_PcdDebugPropertyMask 
#define _PCD_VALUE_PcdDebugPropertyMask  0x6FU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugPropertyMask = _PCD_VALUE_PcdDebugPropertyMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugPropertyMask;
#define _PCD_GET_MODE_8_PcdDebugPropertyMask  _gPcd_FixedAtBuild_PcdDebugPropertyMask
//#define _PCD_SET_MODE_8_PcdDebugPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFixedDebugPrintErrorLevel  38U
#define _PCD_SIZE_PcdFixedDebugPrintErrorLevel 4
#define _PCD_GET_MODE_SIZE_PcdFixedDebugPrintErrorLevel  _PCD_SIZE_PcdFixedDebugPrintErrorLevel 
#define _PCD_VALUE_PcdFixedDebugPrintErrorLevel  0x80480246U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel = _PCD_VALUE_PcdFixedDebugPrintErrorLevel;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdFixedDebugPrintErrorLevel  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel
//#define _PCD_SET_MODE_32_PcdFixedDebugPrintErrorLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArmArchTimerFreqInHz  39U
#define _PCD_SIZE_PcdArmArchTimerFreqInHz 4
#define _PCD_GET_MODE_SIZE_PcdArmArchTimerFreqInHz  _PCD_SIZE_PcdArmArchTimerFreqInHz 
#define _PCD_VALUE_PcdArmArchTimerFreqInHz  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdArmArchTimerFreqInHz = _PCD_VALUE_PcdArmArchTimerFreqInHz;
extern const  UINT32  _gPcd_FixedAtBuild_PcdArmArchTimerFreqInHz;
#define _PCD_GET_MODE_32_PcdArmArchTimerFreqInHz  _gPcd_FixedAtBuild_PcdArmArchTimerFreqInHz
//#define _PCD_SET_MODE_32_PcdArmArchTimerFreqInHz  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaxPeiPerformanceLogEntries  40U
#define _PCD_SIZE_PcdMaxPeiPerformanceLogEntries 1
#define _PCD_GET_MODE_SIZE_PcdMaxPeiPerformanceLogEntries  _PCD_SIZE_PcdMaxPeiPerformanceLogEntries 
#define _PCD_VALUE_PcdMaxPeiPerformanceLogEntries  40U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdMaxPeiPerformanceLogEntries = _PCD_VALUE_PcdMaxPeiPerformanceLogEntries;
extern const  UINT8  _gPcd_FixedAtBuild_PcdMaxPeiPerformanceLogEntries;
#define _PCD_GET_MODE_8_PcdMaxPeiPerformanceLogEntries  _gPcd_FixedAtBuild_PcdMaxPeiPerformanceLogEntries
//#define _PCD_SET_MODE_8_PcdMaxPeiPerformanceLogEntries  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaxPeiPerformanceLogEntries16  41U
#define _PCD_SIZE_PcdMaxPeiPerformanceLogEntries16 2
#define _PCD_GET_MODE_SIZE_PcdMaxPeiPerformanceLogEntries16  _PCD_SIZE_PcdMaxPeiPerformanceLogEntries16 
#define _PCD_VALUE_PcdMaxPeiPerformanceLogEntries16  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT16 _gPcd_FixedAtBuild_PcdMaxPeiPerformanceLogEntries16 = _PCD_VALUE_PcdMaxPeiPerformanceLogEntries16;
extern const  UINT16  _gPcd_FixedAtBuild_PcdMaxPeiPerformanceLogEntries16;
#define _PCD_GET_MODE_16_PcdMaxPeiPerformanceLogEntries16  _gPcd_FixedAtBuild_PcdMaxPeiPerformanceLogEntries16
//#define _PCD_SET_MODE_16_PcdMaxPeiPerformanceLogEntries16  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPerformanceLibraryPropertyMask  42U
#define _PCD_SIZE_PcdPerformanceLibraryPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdPerformanceLibraryPropertyMask  _PCD_SIZE_PcdPerformanceLibraryPropertyMask 
#define _PCD_VALUE_PcdPerformanceLibraryPropertyMask  1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdPerformanceLibraryPropertyMask = _PCD_VALUE_PcdPerformanceLibraryPropertyMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdPerformanceLibraryPropertyMask;
#define _PCD_GET_MODE_8_PcdPerformanceLibraryPropertyMask  _gPcd_FixedAtBuild_PcdPerformanceLibraryPropertyMask
//#define _PCD_SET_MODE_8_PcdPerformanceLibraryPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdEdkiiFpdtStringRecordEnableOnly  43U
#define _PCD_SIZE_PcdEdkiiFpdtStringRecordEnableOnly 1
#define _PCD_GET_MODE_SIZE_PcdEdkiiFpdtStringRecordEnableOnly  _PCD_SIZE_PcdEdkiiFpdtStringRecordEnableOnly 
#define _PCD_VALUE_PcdEdkiiFpdtStringRecordEnableOnly  0U
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdEdkiiFpdtStringRecordEnableOnly = _PCD_VALUE_PcdEdkiiFpdtStringRecordEnableOnly;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdEdkiiFpdtStringRecordEnableOnly;
#define _PCD_GET_MODE_BOOL_PcdEdkiiFpdtStringRecordEnableOnly  _gPcd_FixedAtBuild_PcdEdkiiFpdtStringRecordEnableOnly
//#define _PCD_SET_MODE_BOOL_PcdEdkiiFpdtStringRecordEnableOnly  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumGuidedExtractHandler  44U
#define _PCD_SIZE_PcdMaximumGuidedExtractHandler 4
#define _PCD_GET_MODE_SIZE_PcdMaximumGuidedExtractHandler  _PCD_SIZE_PcdMaximumGuidedExtractHandler 
#define _PCD_VALUE_PcdMaximumGuidedExtractHandler  0x10U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumGuidedExtractHandler = _PCD_VALUE_PcdMaximumGuidedExtractHandler;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumGuidedExtractHandler;
#define _PCD_GET_MODE_32_PcdMaximumGuidedExtractHandler  _gPcd_FixedAtBuild_PcdMaximumGuidedExtractHandler
//#define _PCD_SET_MODE_32_PcdMaximumGuidedExtractHandler  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGpioBankMemoryRange  45U
#define _PCD_SIZE_PcdGpioBankMemoryRange 4
#define _PCD_GET_MODE_SIZE_PcdGpioBankMemoryRange  _PCD_SIZE_PcdGpioBankMemoryRange 
#define _PCD_VALUE_PcdGpioBankMemoryRange  16384U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdGpioBankMemoryRange = _PCD_VALUE_PcdGpioBankMemoryRange;
extern const  UINT32  _gPcd_FixedAtBuild_PcdGpioBankMemoryRange;
#define _PCD_GET_MODE_32_PcdGpioBankMemoryRange  _gPcd_FixedAtBuild_PcdGpioBankMemoryRange
//#define _PCD_SET_MODE_32_PcdGpioBankMemoryRange  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArmPrimaryCoreMask  46U
#define _PCD_SIZE_PcdArmPrimaryCoreMask 4
#define _PCD_GET_MODE_SIZE_PcdArmPrimaryCoreMask  _PCD_SIZE_PcdArmPrimaryCoreMask 
#define _PCD_VALUE_PcdArmPrimaryCoreMask  0xF03U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdArmPrimaryCoreMask = _PCD_VALUE_PcdArmPrimaryCoreMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdArmPrimaryCoreMask;
#define _PCD_GET_MODE_32_PcdArmPrimaryCoreMask  _gPcd_FixedAtBuild_PcdArmPrimaryCoreMask
//#define _PCD_SET_MODE_32_PcdArmPrimaryCoreMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPcieControlBaseAddress  47U
#define _PCD_SIZE_PcdPcieControlBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdPcieControlBaseAddress  _PCD_SIZE_PcdPcieControlBaseAddress 
#define _PCD_VALUE_PcdPcieControlBaseAddress  0x33800000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdPcieControlBaseAddress = _PCD_VALUE_PcdPcieControlBaseAddress;
extern const  UINT64  _gPcd_FixedAtBuild_PcdPcieControlBaseAddress;
#define _PCD_GET_MODE_64_PcdPcieControlBaseAddress  _gPcd_FixedAtBuild_PcdPcieControlBaseAddress
//#define _PCD_SET_MODE_64_PcdPcieControlBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciConfigurationSpaceBaseAddress  48U
#define _PCD_SIZE_PcdPciConfigurationSpaceBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdPciConfigurationSpaceBaseAddress  _PCD_SIZE_PcdPciConfigurationSpaceBaseAddress 
#define _PCD_VALUE_PcdPciConfigurationSpaceBaseAddress  0x40000000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdPciConfigurationSpaceBaseAddress = _PCD_VALUE_PcdPciConfigurationSpaceBaseAddress;
extern const  UINT64  _gPcd_FixedAtBuild_PcdPciConfigurationSpaceBaseAddress;
#define _PCD_GET_MODE_64_PcdPciConfigurationSpaceBaseAddress  _gPcd_FixedAtBuild_PcdPciConfigurationSpaceBaseAddress
//#define _PCD_SET_MODE_64_PcdPciConfigurationSpaceBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciConfigurationSpaceSize  49U
#define _PCD_SIZE_PcdPciConfigurationSpaceSize 8
#define _PCD_GET_MODE_SIZE_PcdPciConfigurationSpaceSize  _PCD_SIZE_PcdPciConfigurationSpaceSize 
#define _PCD_VALUE_PcdPciConfigurationSpaceSize  0x10000000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdPciConfigurationSpaceSize = _PCD_VALUE_PcdPciConfigurationSpaceSize;
extern const  UINT64  _gPcd_FixedAtBuild_PcdPciConfigurationSpaceSize;
#define _PCD_GET_MODE_64_PcdPciConfigurationSpaceSize  _gPcd_FixedAtBuild_PcdPciConfigurationSpaceSize
//#define _PCD_SET_MODE_64_PcdPciConfigurationSpaceSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGlobalDataBaseAddress  50U
#define _PCD_SIZE_PcdGlobalDataBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdGlobalDataBaseAddress  _PCD_SIZE_PcdGlobalDataBaseAddress 
#define _PCD_VALUE_PcdGlobalDataBaseAddress  0x407E9000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdGlobalDataBaseAddress = _PCD_VALUE_PcdGlobalDataBaseAddress;
extern const  UINT32  _gPcd_FixedAtBuild_PcdGlobalDataBaseAddress;
#define _PCD_GET_MODE_32_PcdGlobalDataBaseAddress  _gPcd_FixedAtBuild_PcdGlobalDataBaseAddress
//#define _PCD_SET_MODE_32_PcdGlobalDataBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGlobalDataSize  51U
#define _PCD_SIZE_PcdGlobalDataSize 4
#define _PCD_GET_MODE_SIZE_PcdGlobalDataSize  _PCD_SIZE_PcdGlobalDataSize 
#define _PCD_VALUE_PcdGlobalDataSize  0x1000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdGlobalDataSize = _PCD_VALUE_PcdGlobalDataSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdGlobalDataSize;
#define _PCD_GET_MODE_32_PcdGlobalDataSize  _gPcd_FixedAtBuild_PcdGlobalDataSize
//#define _PCD_SET_MODE_32_PcdGlobalDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArmLcdDdrFrameBufferBase  52U
#define _PCD_SIZE_PcdArmLcdDdrFrameBufferBase 8
#define _PCD_GET_MODE_SIZE_PcdArmLcdDdrFrameBufferBase  _PCD_SIZE_PcdArmLcdDdrFrameBufferBase 
#define _PCD_VALUE_PcdArmLcdDdrFrameBufferBase  0x40000000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferBase = _PCD_VALUE_PcdArmLcdDdrFrameBufferBase;
extern const  UINT64  _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferBase;
#define _PCD_GET_MODE_64_PcdArmLcdDdrFrameBufferBase  _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferBase
//#define _PCD_SET_MODE_64_PcdArmLcdDdrFrameBufferBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArmLcdDdrFrameBufferSize  53U
#define _PCD_SIZE_PcdArmLcdDdrFrameBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdArmLcdDdrFrameBufferSize  _PCD_SIZE_PcdArmLcdDdrFrameBufferSize 
#define _PCD_VALUE_PcdArmLcdDdrFrameBufferSize  0x007E9000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferSize = _PCD_VALUE_PcdArmLcdDdrFrameBufferSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferSize;
#define _PCD_GET_MODE_32_PcdArmLcdDdrFrameBufferSize  _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferSize
//#define _PCD_SET_MODE_32_PcdArmLcdDdrFrameBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTrustZonePrivateMemoryBase  54U
#define _PCD_SIZE_PcdTrustZonePrivateMemoryBase 8
#define _PCD_GET_MODE_SIZE_PcdTrustZonePrivateMemoryBase  _PCD_SIZE_PcdTrustZonePrivateMemoryBase 
#define _PCD_VALUE_PcdTrustZonePrivateMemoryBase  0xBE000000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdTrustZonePrivateMemoryBase = _PCD_VALUE_PcdTrustZonePrivateMemoryBase;
extern const  UINT64  _gPcd_FixedAtBuild_PcdTrustZonePrivateMemoryBase;
#define _PCD_GET_MODE_64_PcdTrustZonePrivateMemoryBase  _gPcd_FixedAtBuild_PcdTrustZonePrivateMemoryBase
//#define _PCD_SET_MODE_64_PcdTrustZonePrivateMemoryBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTrustZonePrivateMemorySize  55U
#define _PCD_SIZE_PcdTrustZonePrivateMemorySize 8
#define _PCD_GET_MODE_SIZE_PcdTrustZonePrivateMemorySize  _PCD_SIZE_PcdTrustZonePrivateMemorySize 
#define _PCD_VALUE_PcdTrustZonePrivateMemorySize  0x01E00000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdTrustZonePrivateMemorySize = _PCD_VALUE_PcdTrustZonePrivateMemorySize;
extern const  UINT64  _gPcd_FixedAtBuild_PcdTrustZonePrivateMemorySize;
#define _PCD_GET_MODE_64_PcdTrustZonePrivateMemorySize  _gPcd_FixedAtBuild_PcdTrustZonePrivateMemorySize
//#define _PCD_SET_MODE_64_PcdTrustZonePrivateMemorySize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTrustZoneSharedMemoryBase  56U
#define _PCD_SIZE_PcdTrustZoneSharedMemoryBase 8
#define _PCD_GET_MODE_SIZE_PcdTrustZoneSharedMemoryBase  _PCD_SIZE_PcdTrustZoneSharedMemoryBase 
#define _PCD_VALUE_PcdTrustZoneSharedMemoryBase  0xBFE00000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdTrustZoneSharedMemoryBase = _PCD_VALUE_PcdTrustZoneSharedMemoryBase;
extern const  UINT64  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemoryBase;
#define _PCD_GET_MODE_64_PcdTrustZoneSharedMemoryBase  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemoryBase
//#define _PCD_SET_MODE_64_PcdTrustZoneSharedMemoryBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTrustZoneSharedMemorySize  57U
#define _PCD_SIZE_PcdTrustZoneSharedMemorySize 8
#define _PCD_GET_MODE_SIZE_PcdTrustZoneSharedMemorySize  _PCD_SIZE_PcdTrustZoneSharedMemorySize 
#define _PCD_VALUE_PcdTrustZoneSharedMemorySize  0x00200000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdTrustZoneSharedMemorySize = _PCD_VALUE_PcdTrustZoneSharedMemorySize;
extern const  UINT64  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemorySize;
#define _PCD_GET_MODE_64_PcdTrustZoneSharedMemorySize  _gPcd_FixedAtBuild_PcdTrustZoneSharedMemorySize
//#define _PCD_SET_MODE_64_PcdTrustZoneSharedMemorySize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTpm2AcpiBufferBase  58U
#define _PCD_SIZE_PcdTpm2AcpiBufferBase 8
#define _PCD_GET_MODE_SIZE_PcdTpm2AcpiBufferBase  _PCD_SIZE_PcdTpm2AcpiBufferBase 
#define _PCD_VALUE_PcdTpm2AcpiBufferBase  0x407EA000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdTpm2AcpiBufferBase = _PCD_VALUE_PcdTpm2AcpiBufferBase;
extern const  UINT64  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferBase;
#define _PCD_GET_MODE_64_PcdTpm2AcpiBufferBase  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferBase
//#define _PCD_SET_MODE_64_PcdTpm2AcpiBufferBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTpm2AcpiBufferSize  59U
#define _PCD_SIZE_PcdTpm2AcpiBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdTpm2AcpiBufferSize  _PCD_SIZE_PcdTpm2AcpiBufferSize 
#define _PCD_VALUE_PcdTpm2AcpiBufferSize  0x3000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdTpm2AcpiBufferSize = _PCD_VALUE_PcdTpm2AcpiBufferSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferSize;
#define _PCD_GET_MODE_32_PcdTpm2AcpiBufferSize  _gPcd_FixedAtBuild_PcdTpm2AcpiBufferSize
//#define _PCD_SET_MODE_32_PcdTpm2AcpiBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSecureFvBaseAddress  60U
#define _PCD_SIZE_PcdSecureFvBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdSecureFvBaseAddress  _PCD_SIZE_PcdSecureFvBaseAddress 
#define _PCD_VALUE_PcdSecureFvBaseAddress  0x0ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdSecureFvBaseAddress = _PCD_VALUE_PcdSecureFvBaseAddress;
extern const  UINT64  _gPcd_FixedAtBuild_PcdSecureFvBaseAddress;
#define _PCD_GET_MODE_64_PcdSecureFvBaseAddress  _gPcd_FixedAtBuild_PcdSecureFvBaseAddress
//#define _PCD_SET_MODE_64_PcdSecureFvBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


RETURN_STATUS
EFIAPI
BaseDebugLibSerialPortConstructor (
  VOID
  );

RETURN_STATUS
EFIAPI
TimerConstructor (
  VOID
  );

RETURN_STATUS
EFIAPI
ExtractGuidedSectionLibConstructor (
  VOID
  );

RETURN_STATUS
EFIAPI
ArmMmuBaseLibConstructor (
  VOID
  );

RETURN_STATUS
EFIAPI
LzmaDecompressLibConstructor (
  VOID
  );


VOID
EFIAPI
ProcessLibraryConstructorList (
  VOID
  )
{
  RETURN_STATUS  Status;

  Status = BaseDebugLibSerialPortConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = TimerConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = ExtractGuidedSectionLibConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = ArmMmuBaseLibConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = LzmaDecompressLibConstructor ();
  ASSERT_RETURN_ERROR (Status);

}



VOID
EFIAPI
ProcessLibraryDestructorList (
  VOID
  )
{

}
