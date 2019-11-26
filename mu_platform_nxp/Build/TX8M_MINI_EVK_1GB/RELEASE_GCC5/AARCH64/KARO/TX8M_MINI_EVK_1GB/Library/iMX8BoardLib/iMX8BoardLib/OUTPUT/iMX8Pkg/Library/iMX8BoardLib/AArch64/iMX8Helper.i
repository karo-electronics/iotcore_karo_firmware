# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/NXP/iMX8Pkg/Library/iMX8BoardLib/AArch64/iMX8Helper.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/home/uwe/gcc-linaro-7.2.1-2017.11-x86_64_aarch64-linux-gnu/aarch64-linux-gnu/libc/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Build/TX8M_MINI_EVK_1GB/RELEASE_GCC5/AARCH64/KARO/TX8M_MINI_EVK_1GB/Library/iMX8BoardLib/iMX8BoardLib/DEBUG/AutoGen.h" 1
# 16 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Build/TX8M_MINI_EVK_1GB/RELEASE_GCC5/AARCH64/KARO/TX8M_MINI_EVK_1GB/Library/iMX8BoardLib/iMX8BoardLib/DEBUG/AutoGen.h"
# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h" 1
# 28 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h"
# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/AArch64/ProcessorBind.h" 1
# 100 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/AArch64/ProcessorBind.h"
  typedef unsigned long long UINT64;
  typedef long long INT64;
  typedef unsigned int UINT32;
  typedef int INT32;
  typedef unsigned short UINT16;
  typedef unsigned short CHAR16;
  typedef short INT16;
  typedef unsigned char BOOLEAN;
  typedef unsigned char UINT8;
  typedef char CHAR8;
  typedef signed char INT8;







typedef UINT64 UINTN;





typedef INT64 INTN;
# 29 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h" 2
# 54 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h"
extern UINT8 _VerifySizeofBOOLEAN[(sizeof(BOOLEAN) == (1)) / (sizeof(BOOLEAN) == (1))];
extern UINT8 _VerifySizeofINT8[(sizeof(INT8) == (1)) / (sizeof(INT8) == (1))];
extern UINT8 _VerifySizeofUINT8[(sizeof(UINT8) == (1)) / (sizeof(UINT8) == (1))];
extern UINT8 _VerifySizeofINT16[(sizeof(INT16) == (2)) / (sizeof(INT16) == (2))];
extern UINT8 _VerifySizeofUINT16[(sizeof(UINT16) == (2)) / (sizeof(UINT16) == (2))];
extern UINT8 _VerifySizeofINT32[(sizeof(INT32) == (4)) / (sizeof(INT32) == (4))];
extern UINT8 _VerifySizeofUINT32[(sizeof(UINT32) == (4)) / (sizeof(UINT32) == (4))];
extern UINT8 _VerifySizeofINT64[(sizeof(INT64) == (8)) / (sizeof(INT64) == (8))];
extern UINT8 _VerifySizeofUINT64[(sizeof(UINT64) == (8)) / (sizeof(UINT64) == (8))];
extern UINT8 _VerifySizeofCHAR8[(sizeof(CHAR8) == (1)) / (sizeof(CHAR8) == (1))];
extern UINT8 _VerifySizeofCHAR16[(sizeof(CHAR16) == (2)) / (sizeof(CHAR16) == (2))];
# 73 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h"
typedef enum {
  __VerifyUint8EnumValue = 0xff
} __VERIFY_UINT8_ENUM_SIZE;

typedef enum {
  __VerifyUint16EnumValue = 0xffff
} __VERIFY_UINT16_ENUM_SIZE;

typedef enum {
  __VerifyUint32EnumValue = 0xffffffff
} __VERIFY_UINT32_ENUM_SIZE;

extern UINT8 _VerifySizeof__VERIFY_UINT8_ENUM_SIZE[(sizeof(__VERIFY_UINT8_ENUM_SIZE) == (4)) / (sizeof(__VERIFY_UINT8_ENUM_SIZE) == (4))];
extern UINT8 _VerifySizeof__VERIFY_UINT16_ENUM_SIZE[(sizeof(__VERIFY_UINT16_ENUM_SIZE) == (4)) / (sizeof(__VERIFY_UINT16_ENUM_SIZE) == (4))];
extern UINT8 _VerifySizeof__VERIFY_UINT32_ENUM_SIZE[(sizeof(__VERIFY_UINT32_ENUM_SIZE) == (4)) / (sizeof(__VERIFY_UINT32_ENUM_SIZE) == (4))];
# 280 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h"
typedef struct {
  UINT32 Data1;
  UINT16 Data2;
  UINT16 Data3;
  UINT8 Data4[8];
} GUID;




typedef struct {
  UINT8 Addr[4];
} IPv4_ADDRESS;




typedef struct {
  UINT8 Addr[16];
} IPv6_ADDRESS;




typedef UINT64 PHYSICAL_ADDRESS;




typedef struct _LIST_ENTRY LIST_ENTRY;




struct _LIST_ENTRY {
  LIST_ENTRY *ForwardLink;
  LIST_ENTRY *BackLink;
};
# 715 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h"
typedef __builtin_va_list VA_LIST;
# 866 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h"
typedef UINTN *BASE_LIST;
# 1030 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h"
typedef UINTN RETURN_STATUS;
# 1346 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Base.h"
  void * __builtin_return_address (unsigned int level);
# 17 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Build/TX8M_MINI_EVK_1GB/RELEASE_GCC5/AARCH64/KARO/TX8M_MINI_EVK_1GB/Library/iMX8BoardLib/iMX8BoardLib/DEBUG/AutoGen.h" 2
# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h" 1
# 1082 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINTN

LibPcdSetSku (
  UINTN SkuId
  );
# 1099 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT8

LibPcdGet8 (
  UINTN TokenNumber
  );
# 1116 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT16

LibPcdGet16 (
  UINTN TokenNumber
  );
# 1133 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT32

LibPcdGet32 (
  UINTN TokenNumber
  );
# 1150 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT64

LibPcdGet64 (
  UINTN TokenNumber
  );
# 1167 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void *

LibPcdGetPtr (
  UINTN TokenNumber
  );
# 1184 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
BOOLEAN

LibPcdGetBool (
  UINTN TokenNumber
  );
# 1199 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINTN

LibPcdGetSize (
  UINTN TokenNumber
  );
# 1220 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT8

LibPcdGetEx8 (
  const GUID *Guid,
  UINTN TokenNumber
  );
# 1242 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT16

LibPcdGetEx16 (
  const GUID *Guid,
  UINTN TokenNumber
  );
# 1261 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT32

LibPcdGetEx32 (
  const GUID *Guid,
  UINTN TokenNumber
  );
# 1283 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT64

LibPcdGetEx64 (
  const GUID *Guid,
  UINTN TokenNumber
  );
# 1305 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void *

LibPcdGetExPtr (
  const GUID *Guid,
  UINTN TokenNumber
  );
# 1327 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
BOOLEAN

LibPcdGetExBool (
  const GUID *Guid,
  UINTN TokenNumber
  );
# 1349 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINTN

LibPcdGetExSize (
  const GUID *Guid,
  UINTN TokenNumber
  );
# 1370 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT8

LibPcdSet8 (
  UINTN TokenNumber,
  UINT8 Value
  );
# 1390 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT16

LibPcdSet16 (
  UINTN TokenNumber,
  UINT16 Value
  );
# 1410 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT32

LibPcdSet32 (
  UINTN TokenNumber,
  UINT32 Value
  );
# 1430 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT64

LibPcdSet64 (
  UINTN TokenNumber,
  UINT64 Value
  );
# 1460 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void *

LibPcdSetPtr (
  UINTN TokenNumber,
  UINTN *SizeOfBuffer,
  const void *Buffer
  );
# 1481 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
BOOLEAN

LibPcdSetBool (
  UINTN TokenNumber,
  BOOLEAN Value
  );
# 1505 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT8

LibPcdSetEx8 (
  const GUID *Guid,
  UINTN TokenNumber,
  UINT8 Value
  );
# 1530 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT16

LibPcdSetEx16 (
  const GUID *Guid,
  UINTN TokenNumber,
  UINT16 Value
  );
# 1555 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT32

LibPcdSetEx32 (
  const GUID *Guid,
  UINTN TokenNumber,
  UINT32 Value
  );
# 1580 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINT64

LibPcdSetEx64 (
  const GUID *Guid,
  UINTN TokenNumber,
  UINT64 Value
  );
# 1611 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void *

LibPcdSetExPtr (
  const GUID *Guid,
  UINTN TokenNumber,
  UINTN *SizeOfBuffer,
  void *Buffer
  );
# 1637 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
BOOLEAN

LibPcdSetExBool (
  const GUID *Guid,
  UINTN TokenNumber,
  BOOLEAN Value
  );
# 1658 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSet8S (
  UINTN TokenNumber,
  UINT8 Value
  );
# 1677 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSet16S (
  UINTN TokenNumber,
  UINT16 Value
  );
# 1696 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSet32S (
  UINTN TokenNumber,
  UINT32 Value
  );
# 1715 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSet64S (
  UINTN TokenNumber,
  UINT64 Value
  );
# 1744 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSetPtrS (
  UINTN TokenNumber,
  UINTN *SizeOfBuffer,
  const void *Buffer
  );
# 1764 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSetBoolS (
  UINTN TokenNumber,
  BOOLEAN Value
  );
# 1787 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSetEx8S (
  const GUID *Guid,
  UINTN TokenNumber,
  UINT8 Value
  );
# 1811 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSetEx16S (
  const GUID *Guid,
  UINTN TokenNumber,
  UINT16 Value
  );
# 1835 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSetEx32S (
  const GUID *Guid,
  UINTN TokenNumber,
  UINT32 Value
  );
# 1859 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSetEx64S (
  const GUID *Guid,
  UINTN TokenNumber,
  UINT64 Value
  );
# 1889 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSetExPtrS (
  const GUID *Guid,
  UINTN TokenNumber,
  UINTN *SizeOfBuffer,
  void *Buffer
  );
# 1914 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPcdSetExBoolS (
  const GUID *Guid,
  UINTN TokenNumber,
  BOOLEAN Value
  );
# 1938 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
typedef
void
( *PCD_CALLBACK)(
  const GUID *CallBackGuid,
  UINTN CallBackToken,
  void *TokenData,
  UINTN TokenDataSize
  );
# 1964 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void

LibPcdCallbackOnSet (
  const GUID *Guid,
  UINTN TokenNumber,
  PCD_CALLBACK NotificationFunction
  );
# 1986 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void

LibPcdCancelCallback (
  const GUID *Guid,
  UINTN TokenNumber,
  PCD_CALLBACK NotificationFunction
  );
# 2014 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINTN

LibPcdGetNextToken (
  const GUID *Guid,
  UINTN TokenNumber
  );
# 2036 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
GUID *

LibPcdGetNextTokenSpace (
  const GUID *TokenSpaceGuid
  );
# 2066 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void *

LibPatchPcdSetPtr (
  void *PatchVariable,
  UINTN MaximumDatumSize,
  UINTN *SizeOfBuffer,
  const void *Buffer
  );
# 2098 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPatchPcdSetPtrS (
  void *PatchVariable,
  UINTN MaximumDatumSize,
  UINTN *SizeOfBuffer,
  const void *Buffer
  );
# 2132 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void *

LibPatchPcdSetPtrAndSize (
  void *PatchVariable,
  UINTN *SizeOfPatchVariable,
  UINTN MaximumDatumSize,
  UINTN *SizeOfBuffer,
  const void *Buffer
  );
# 2167 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
RETURN_STATUS

LibPatchPcdSetPtrAndSizeS (
  void *PatchVariable,
  UINTN *SizeOfPatchVariable,
  UINTN MaximumDatumSize,
  UINTN *SizeOfBuffer,
  const void *Buffer
  );

typedef enum {
  PCD_TYPE_8,
  PCD_TYPE_16,
  PCD_TYPE_32,
  PCD_TYPE_64,
  PCD_TYPE_BOOL,
  PCD_TYPE_PTR
} PCD_TYPE;

typedef struct {




  PCD_TYPE PcdType;




  UINTN PcdSize;






  CHAR8 *PcdName;
} PCD_INFO;
# 2219 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void

LibPcdGetInfo (
  UINTN TokenNumber,
  PCD_INFO *PcdInfo
  );
# 2239 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
void

LibPcdGetInfoEx (
  const GUID *Guid,
  UINTN TokenNumber,
  PCD_INFO *PcdInfo
  );
# 2254 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Library/PcdLib.h"
UINTN

LibPcdGetSku (
  void
  );
# 18 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Build/TX8M_MINI_EVK_1GB/RELEASE_GCC5/AARCH64/KARO/TX8M_MINI_EVK_1GB/Library/iMX8BoardLib/iMX8BoardLib/DEBUG/AutoGen.h" 2

extern GUID gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;



extern GUID gArmTokenSpaceGuid;
extern GUID giMX8TokenSpaceGuid;
extern GUID giMXPlatformTokenSpaceGuid;
extern GUID gArmPlatformTokenSpaceGuid;
extern GUID gOpteeClientPkgTokenSpaceGuid;


extern GUID gArmMpCoreInfoPpiGuid;


extern UINT64 _gPcd_SkuId_Array[];



extern const UINT64 _gPcd_FixedAtBuild_PcdSystemMemoryBase;






extern const UINT64 _gPcd_FixedAtBuild_PcdSystemMemorySize;






extern const UINT64 _gPcd_FixedAtBuild_PcdFvBaseAddress;






extern const UINT32 _gPcd_FixedAtBuild_PcdArmPrimaryCoreMask;






extern const UINT64 _gPcd_FixedAtBuild_PcdPcieControlBaseAddress;






extern const UINT64 _gPcd_FixedAtBuild_PcdPciConfigurationSpaceBaseAddress;






extern const UINT64 _gPcd_FixedAtBuild_PcdPciConfigurationSpaceSize;






extern const UINT32 _gPcd_FixedAtBuild_PcdGlobalDataBaseAddress;






extern const UINT32 _gPcd_FixedAtBuild_PcdGlobalDataSize;






extern const UINT32 _gPcd_FixedAtBuild_PcdGpioBankMemoryRange;






extern const UINT64 _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferBase;






extern const UINT32 _gPcd_FixedAtBuild_PcdArmLcdDdrFrameBufferSize;






extern const UINT32 _gPcd_FixedAtBuild_PcdCoreCount;






extern const UINT64 _gPcd_FixedAtBuild_PcdTrustZonePrivateMemoryBase;






extern const UINT64 _gPcd_FixedAtBuild_PcdTrustZonePrivateMemorySize;






extern const UINT64 _gPcd_FixedAtBuild_PcdTrustZoneSharedMemoryBase;






extern const UINT64 _gPcd_FixedAtBuild_PcdTrustZoneSharedMemorySize;






extern const UINT64 _gPcd_FixedAtBuild_PcdTpm2AcpiBufferBase;






extern const UINT32 _gPcd_FixedAtBuild_PcdTpm2AcpiBufferSize;
# 32 "<command-line>" 2
# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/NXP/iMX8Pkg/Library/iMX8BoardLib/AArch64/iMX8Helper.S"
# 16 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/NXP/iMX8Pkg/Library/iMX8BoardLib/AArch64/iMX8Helper.S"
# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/AsmMacroIoLibV8.h" 1
# 17 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/NXP/iMX8Pkg/Library/iMX8BoardLib/AArch64/iMX8Helper.S" 2
# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Library/ArmLib.h" 1
# 19 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Library/ArmLib.h"
# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Uefi/UefiBaseType.h" 1
# 29 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Uefi/UefiBaseType.h"
typedef GUID EFI_GUID;



typedef RETURN_STATUS EFI_STATUS;



typedef void *EFI_HANDLE;



typedef void *EFI_EVENT;



typedef UINTN EFI_TPL;



typedef UINT64 EFI_LBA;




typedef UINT64 EFI_PHYSICAL_ADDRESS;




typedef UINT64 EFI_VIRTUAL_ADDRESS;
# 72 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/MU_BASECORE/MdePkg/Include/Uefi/UefiBaseType.h"
typedef struct {
  UINT16 Year;
  UINT8 Month;
  UINT8 Day;
  UINT8 Hour;
  UINT8 Minute;
  UINT8 Second;
  UINT8 Pad1;
  UINT32 Nanosecond;
  INT16 TimeZone;
  UINT8 Daylight;
  UINT8 Pad2;
} EFI_TIME;





typedef IPv4_ADDRESS EFI_IPv4_ADDRESS;




typedef IPv6_ADDRESS EFI_IPv6_ADDRESS;




typedef struct {
  UINT8 Addr[32];
} EFI_MAC_ADDRESS;





typedef union {
  UINT32 Addr[4];
  EFI_IPv4_ADDRESS v4;
  EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;
# 20 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Library/ArmLib.h" 2




# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Chipset/AArch64.h" 1
# 19 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Chipset/AArch64.h"
# 1 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Chipset/AArch64Mmu.h" 1
# 20 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Chipset/AArch64.h" 2
# 154 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Chipset/AArch64.h"
void

ArmEnableSWPInstruction (
  void
  );

UINTN

ArmReadCbar (
  void
  );

UINTN

ArmReadTpidrurw (
  void
  );

void

ArmWriteTpidrurw (
  UINTN Value
  );

UINTN

ArmGetTCR (
  void
  );

void

ArmSetTCR (
  UINTN Value
  );

UINTN

ArmGetMAIR (
  void
  );

void

ArmSetMAIR (
  UINTN Value
  );

void

ArmDisableAlignmentCheck (
  void
  );

void

ArmEnableAlignmentCheck (
  void
  );

void

ArmDisableStackAlignmentCheck (
  void
  );

void

ArmEnableStackAlignmentCheck (
  void
  );

void

ArmDisableAllExceptions (
  void
  );

void
ArmWriteHcr (
  UINTN Hcr
  );

UINTN
ArmReadHcr (
  void
  );

UINTN
ArmReadCurrentEL (
  void
  );

UINT64
PageAttributeToGcdAttribute (
  UINT64 PageAttributes
  );

UINTN
ArmWriteCptr (
  UINT64 Cptr
  );

UINT32
ArmReadCntHctl (
  void
  );

void
ArmWriteCntHctl (
  UINT32 CntHctl
  );
# 25 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Library/ArmLib.h" 2
# 39 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Library/ArmLib.h"
typedef enum {
  ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED = 0,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_UNCACHED_UNBUFFERED,
  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_WRITE_BACK,





  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK_NONSHAREABLE,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_WRITE_BACK_NONSHAREABLE,

  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_WRITE_THROUGH,
  ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE
} ARM_MEMORY_REGION_ATTRIBUTES;



typedef struct {
  EFI_PHYSICAL_ADDRESS PhysicalBase;
  EFI_VIRTUAL_ADDRESS VirtualBase;
  UINT64 Length;
  ARM_MEMORY_REGION_ATTRIBUTES Attributes;
} ARM_MEMORY_REGION_DESCRIPTOR;

typedef void (*CACHE_OPERATION)(void);
typedef void (*LINE_OPERATION)(UINTN);




typedef enum {
  ARM_PROCESSOR_MODE_USER = 0x10,
  ARM_PROCESSOR_MODE_FIQ = 0x11,
  ARM_PROCESSOR_MODE_IRQ = 0x12,
  ARM_PROCESSOR_MODE_SUPERVISOR = 0x13,
  ARM_PROCESSOR_MODE_ABORT = 0x17,
  ARM_PROCESSOR_MODE_HYP = 0x1A,
  ARM_PROCESSOR_MODE_UNDEFINED = 0x1B,
  ARM_PROCESSOR_MODE_SYSTEM = 0x1F,
  ARM_PROCESSOR_MODE_MASK = 0x1F
} ARM_PROCESSOR_MODE;
# 117 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Library/ArmLib.h"
UINTN

ArmDataCacheLineLength (
  void
  );

UINTN

ArmInstructionCacheLineLength (
  void
  );

UINTN

ArmCacheWritebackGranule (
  void
  );

UINTN

ArmIsArchTimerImplemented (
  void
  );

UINTN

ArmReadIdPfr0 (
  void
  );

UINTN

ArmReadIdPfr1 (
  void
  );

UINTN

ArmCacheInfo (
  void
  );

BOOLEAN

ArmIsMpCore (
  void
  );

void

ArmInvalidateDataCache (
  void
  );


void

ArmCleanInvalidateDataCache (
  void
  );

void

ArmCleanDataCache (
  void
  );

void

ArmInvalidateInstructionCache (
  void
  );

void

ArmInvalidateDataCacheEntryByMVA (
  UINTN Address
  );

void

ArmCleanDataCacheEntryToPoUByMVA (
  UINTN Address
  );

void

ArmInvalidateInstructionCacheEntryToPoUByMVA (
  UINTN Address
  );

void

ArmCleanDataCacheEntryByMVA (
 UINTN Address
);

void

ArmCleanInvalidateDataCacheEntryByMVA (
  UINTN Address
  );

void

ArmInvalidateDataCacheEntryBySetWay (
  UINTN SetWayFormat
  );

void

ArmCleanDataCacheEntryBySetWay (
  UINTN SetWayFormat
  );

void

ArmCleanInvalidateDataCacheEntryBySetWay (
  UINTN SetWayFormat
  );

void

ArmEnableDataCache (
  void
  );

void

ArmDisableDataCache (
  void
  );

void

ArmEnableInstructionCache (
  void
  );

void

ArmDisableInstructionCache (
  void
  );

void

ArmEnableMmu (
  void
  );

void

ArmDisableMmu (
  void
  );

void

ArmEnableCachesAndMmu (
  void
  );

void

ArmDisableCachesAndMmu (
  void
  );

void

ArmEnableInterrupts (
  void
  );

UINTN

ArmDisableInterrupts (
  void
  );

BOOLEAN

ArmGetInterruptState (
  void
  );

void

ArmEnableAsynchronousAbort (
  void
  );

UINTN

ArmDisableAsynchronousAbort (
  void
  );

void

ArmEnableIrq (
  void
  );

UINTN

ArmDisableIrq (
  void
  );

void

ArmEnableFiq (
  void
  );

UINTN

ArmDisableFiq (
  void
  );

BOOLEAN

ArmGetFiqState (
  void
  );




void

ArmInvalidateTlb (
  void
  );

void

ArmUpdateTranslationTableEntry (
  void *TranslationTableEntry,
  void *Mva
  );

void

ArmSetDomainAccessControl (
  UINT32 Domain
  );

void

ArmSetTTBR0 (
  void *TranslationTableBase
  );

void

ArmSetTTBCR (
  UINT32 Bits
  );

void *

ArmGetTTBR0BaseAddress (
  void
  );

BOOLEAN

ArmMmuEnabled (
  void
  );

void

ArmEnableBranchPrediction (
  void
  );

void

ArmDisableBranchPrediction (
  void
  );

void

ArmSetLowVectors (
  void
  );

void

ArmSetHighVectors (
  void
  );

void

ArmDataMemoryBarrier (
  void
  );

void

ArmDataSynchronizationBarrier (
  void
  );

void

ArmInstructionSynchronizationBarrier (
  void
  );

void

ArmWriteVBar (
  UINTN VectorBase
  );

UINTN

ArmReadVBar (
  void
  );

void

ArmWriteAuxCr (
  UINT32 Bit
  );

UINT32

ArmReadAuxCr (
  void
  );

void

ArmSetAuxCrBit (
  UINT32 Bits
  );

void

ArmUnsetAuxCrBit (
  UINT32 Bits
  );

void

ArmCallSEV (
  void
  );

void

ArmCallWFE (
  void
  );

void

ArmCallWFI (

  void
  );

UINTN

ArmReadMpidr (
  void
  );

UINTN

ArmReadMidr (
  void
  );

UINT32

ArmReadCpacr (
  void
  );

void

ArmWriteCpacr (
  UINT32 Access
  );

void

ArmEnableVFP (
  void
  );







UINT32

ArmReadScr (
  void
  );







void

ArmWriteScr (
  UINT32 Value
  );

UINT32

ArmReadMVBar (
  void
  );

void

ArmWriteMVBar (
  UINT32 VectorMonitorBase
  );

UINT32

ArmReadSctlr (
  void
  );

void

ArmWriteSctlr (
  UINT32 Value
  );

UINTN

ArmReadHVBar (
  void
  );

void

ArmWriteHVBar (
  UINTN HypModeVectorBase
  );






UINTN

ArmReadCpuActlr (
  void
  );

void

ArmWriteCpuActlr (
  UINTN Val
  );

void

ArmSetCpuActlrBit (
  UINTN Bits
  );

void

ArmUnsetCpuActlrBit (
  UINTN Bits
  );
# 616 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/MU_TIANO/ArmPkg/Include/Library/ArmLib.h"
UINTN

ArmReadCntFrq (
  void
  );

void

ArmWriteCntFrq (
  UINTN FreqInHz
  );

UINT64

ArmReadCntPct (
  void
  );

UINTN

ArmReadCntkCtl (
  void
  );

void

ArmWriteCntkCtl (
  UINTN Val
  );

UINTN

ArmReadCntpTval (
  void
  );

void

ArmWriteCntpTval (
  UINTN Val
  );

UINTN

ArmReadCntpCtl (
  void
  );

void

ArmWriteCntpCtl (
  UINTN Val
  );

UINTN

ArmReadCntvTval (
  void
  );

void

ArmWriteCntvTval (
  UINTN Val
  );

UINTN

ArmReadCntvCtl (
  void
  );

void

ArmWriteCntvCtl (
  UINTN Val
  );

UINT64

ArmReadCntvCt (
  void
  );

UINT64

ArmReadCntpCval (
  void
  );

void

ArmWriteCntpCval (
  UINT64 Val
  );

UINT64

ArmReadCntvCval (
  void
  );

void

ArmWriteCntvCval (
  UINT64 Val
  );

UINT64

ArmReadCntvOff (
  void
  );

void

ArmWriteCntvOff (
  UINT64 Val
  );

UINTN

ArmGetPhysicalAddressBits (
  void
  );






UINTN

ArmReadIdMmfr0(
  void
  );
# 18 "/home/uwe/git/ms/iot_core_tx8mmini/mu_platform_nxp/Silicon/ARM/NXP/iMX8Pkg/Library/iMX8BoardLib/AArch64/iMX8Helper.S" 2






.global ArmPlatformGetCorePosition ; .section ".text.ArmPlatformGetCorePosition", "ax" ; .type ArmPlatformGetCorePosition, %function ; ArmPlatformGetCorePosition:
  and x1, x0, #0xFF
  and x0, x0, #(0xFF << 8)
  add x0, x1, x0, LSR #7
  ret





.global ArmPlatformGetPrimaryCoreMpId ; .section ".text.ArmPlatformGetPrimaryCoreMpId", "ax" ; .type ArmPlatformGetPrimaryCoreMpId, %function ; ArmPlatformGetPrimaryCoreMpId:
  ldr w0, PrimaryCoreMpid
  ret





.global ArmPlatformIsPrimaryCore ; .section ".text.ArmPlatformIsPrimaryCore", "ax" ; .type ArmPlatformIsPrimaryCore, %function ; ArmPlatformIsPrimaryCore:
  movz w1, (0xF03) >> 16, lsl #16 ; movk w1, (0xF03) & 0xffff
  and x0, x0, x1

  ldr w1, PrimaryCoreMpid

  cmp w0, w1
  cset x0, eq
  ret

.global ArmPlatformPeiBootAction ; .section ".text.ArmPlatformPeiBootAction", "ax" ; .type ArmPlatformPeiBootAction, %function ; ArmPlatformPeiBootAction:





  ret

PrimaryCoreMpid: .word 0x0
