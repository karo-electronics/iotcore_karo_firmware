/** @file
  Debug Library based on report status code library.

  Note that if the debug message length is larger than the maximum allowable
  record length, then the debug message will be ignored directly.

  Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiPei.h>

#include <Guid/StatusCodeDataTypeId.h>
#include <Guid/StatusCodeDataTypeDebug.h>

#include <Library/DebugLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/ReportStatusCodeLib.h>
#include <Library/PcdLib.h>
#include <Library/DebugPrintErrorLevelLib.h>

/**
  MS_CHANGE_?
  MSCHANGE - To split the DebugPrint into two one taking va_list and one with var args
  Prints a debug message to the debug output device if the specified error level is enabled.

  If any bit in ErrorLevel is also set in DebugPrintErrorLevelLib function
  GetDebugPrintErrorLevel (), then print the message specified by Format and the
  associated variable argument list to the debug output device.

  If Format is NULL, then ASSERT().

  If the length of the message string specificed by Format is larger than the maximum allowable
  record length, then directly return and not print it.

  @param  ErrorLevel  The error level of the debug message.
  @param  Format      Format string for the debug message to print.
  @param  ...         Variable argument list whose contents are accessed
                      based on the format string specified by Format.

**/
VOID
EFIAPI
DebugPrint (
  IN  UINTN        ErrorLevel,
  IN  CONST CHAR8  *Format,
  ...
  )
{
  //MS_CHANGE - START
  VA_LIST         Marker;

  ASSERT(Format != NULL);

  VA_START(Marker, Format);
  DebugPrintValist(ErrorLevel, Format, Marker);
  VA_END(Marker);
  //MS_CHANGE - END

}

/**
  MS_CHANGE_?
  MSCHANGE - To split the DebugPrint into two one taking va_list and one with var args
  Prints a debug message to the debug output device if the specified error level is enabled.

  If any bit in ErrorLevel is also set in DebugPrintErrorLevelLib function 
  GetDebugPrintErrorLevel (), then print the message specified by Format and the 
  associated variable argument list to the debug output device.

  If Format is NULL, then ASSERT().

  If the length of the message string specificed by Format is larger than the maximum allowable
  record length, then directly return and not print it.

  @param  ErrorLevel    The error level of the debug message.
  @param  Format        Format string for the debug message to print.
  @param  VaListMarker  VA_LIST marker for the variable argument list.

**/
VOID
EFIAPI
DebugPrintValist (
  IN  UINTN        ErrorLevel,
  IN  CONST CHAR8  *Format,
  VA_LIST          VaListMarker
  )
{
  UINT64          Buffer[(EFI_STATUS_CODE_DATA_MAX_SIZE / sizeof (UINT64)) + 1];
  EFI_DEBUG_INFO  *DebugInfo;
  UINTN           TotalSize;
  //MSCHANGE - To split the DebugPrint into two one taking va_list and one with var args
  //VA_LIST         VaListMarker;    // MS_CHANGE_?
  BASE_LIST       BaseListMarker;
  CHAR8           *FormatString;
  BOOLEAN         Long;

  //
  // If Format is NULL, then ASSERT().
  //
  ASSERT (Format != NULL);

  //
  // Check driver Debug Level value and global debug level
  //
  if ((ErrorLevel & GetDebugPrintErrorLevel ()) == 0) {
    return;
  }

  //
  // Compute the total size of the record.
  // Note that the passing-in format string and variable parameters will be constructed to
  // the following layout:
  //
  //         Buffer->|------------------------|
  //                 |         Padding        | 4 bytes
  //      DebugInfo->|------------------------|
  //                 |      EFI_DEBUG_INFO    | sizeof(EFI_DEBUG_INFO)
  // BaseListMarker->|------------------------|
  //                 |           ...          |
  //                 |   variable arguments   | 12 * sizeof (UINT64)
  //                 |           ...          |
  //                 |------------------------|
  //                 |       Format String    |
  //                 |------------------------|<- (UINT8 *)Buffer + sizeof(Buffer)
  //
  TotalSize = 4 + sizeof (EFI_DEBUG_INFO) + 12 * sizeof (UINT64) + AsciiStrSize (Format);

  //
  // If the TotalSize is larger than the maximum record size, then return
  //
  if (TotalSize > sizeof (Buffer)) {
    TotalSize = sizeof (Buffer);
  }

  //
  // Fill in EFI_DEBUG_INFO
  //
  // Here we skip the first 4 bytes of Buffer, because we must ensure BaseListMarker is
  // 64-bit aligned, otherwise retrieving 64-bit parameter from BaseListMarker will cause
  // exception on IPF. Buffer starts at 64-bit aligned address, so skipping 4 types (sizeof(EFI_DEBUG_INFO))
  // just makes address of BaseListMarker, which follows DebugInfo, 64-bit aligned.
  //
  DebugInfo             = (EFI_DEBUG_INFO *)(Buffer) + 1;
  DebugInfo->ErrorLevel = (UINT32)ErrorLevel;
  BaseListMarker        = (BASE_LIST)(DebugInfo + 1);
  FormatString          = (CHAR8 *)((UINT64 *)(DebugInfo + 1) + 12);

  //
  // Copy the Format string into the record. It will be truncated if it's too long.
  //
  AsciiStrnCpyS (
    FormatString, sizeof(Buffer) - (4 + sizeof(EFI_DEBUG_INFO) + 12 * sizeof(UINT64)),
    Format,       sizeof(Buffer) - (4 + sizeof(EFI_DEBUG_INFO) + 12 * sizeof(UINT64)) - 1
    );

  //
  // The first 12 * sizeof (UINT64) bytes following EFI_DEBUG_INFO are for variable arguments
  // of format in DEBUG string, which is followed by the DEBUG format string.
  // Here we will process the variable arguments and pack them in this area.
  //
  //MSCHANGE - To split the DebugPrint into two one taking va_list and one with var args
  //VA_START (VaListMarker, Format);   // MS_CHANGE_?

  //
  // Use the actual format string.
  //
  Format = FormatString;
  for (; *Format != '\0'; Format++) {
    //
    // Only format with prefix % is processed.
    //
    if (*Format != '%') {
      continue;
    }
    Long = FALSE;
    //
    // Parse Flags and Width
    //
    for (Format++; TRUE; Format++) {
      if (*Format == '.' || *Format == '-' || *Format == '+' || *Format == ' ') {
        //
        // These characters in format field are omitted.
        //
        continue;
      }
      if (*Format >= '0' && *Format <= '9') {
        //
        // These characters in format field are omitted.
        //
        continue;
      }
      if (*Format == 'L' || *Format == 'l') {
        //
        // 'L" or "l" in format field means the number being printed is a UINT64
        //
        Long = TRUE;
        continue;
      }
      if (*Format == '*') {
        //
        // '*' in format field means the precision of the field is specified by
        // a UINTN argument in the argument list.
        //
        BASE_ARG (BaseListMarker, UINTN) = VA_ARG (VaListMarker, UINTN);
        continue;
      }
      if (*Format == '\0') {
        //
        // Make no output if Format string terminates unexpectedly when
        // looking up for flag, width, precision and type.
        //
        Format--;
      }
      //
      // When valid argument type detected or format string terminates unexpectedly,
      // the inner loop is done.
      //
      break;
    }

    //
    // Pack variable arguments into the storage area following EFI_DEBUG_INFO.
    //
    if ((*Format == 'p') && (sizeof (VOID *) > 4)) {
      Long = TRUE;
    }
    if (*Format == 'p' || *Format == 'X' || *Format == 'x' || *Format == 'd' || *Format == 'u') {
      if (Long) {
        BASE_ARG (BaseListMarker, INT64) = VA_ARG (VaListMarker, INT64);
      } else {
        BASE_ARG (BaseListMarker, int) = VA_ARG (VaListMarker, int);
      }
    } else if (*Format == 's' || *Format == 'S' || *Format == 'a' || *Format == 'g' || *Format == 't') {
      BASE_ARG (BaseListMarker, VOID *) = VA_ARG (VaListMarker, VOID *);
    } else if (*Format == 'c') {
      BASE_ARG (BaseListMarker, UINTN) = VA_ARG (VaListMarker, UINTN);
    } else if (*Format == 'r') {
      BASE_ARG (BaseListMarker, RETURN_STATUS) = VA_ARG (VaListMarker, RETURN_STATUS);
    }

    //
    // If the converted BASE_LIST is larger than the 12 * sizeof (UINT64) allocated bytes, then ASSERT()
    // This indicates that the DEBUG() macro is passing in more argument than can be handled by
    // the EFI_DEBUG_INFO record
    //
    ASSERT ((CHAR8 *)BaseListMarker <= FormatString);

    //
    // If the converted BASE_LIST is larger than the 12 * sizeof (UINT64) allocated bytes, then return
    //
    if ((CHAR8 *)BaseListMarker > FormatString) {
      // VA_END (VaListMarker); // MS_CHANGE_?
      return;
    }
  }
  //MSCHANGE - To split the DebugPrint into two one taking va_list and one with var args
  // VA_END (VaListMarker);      // MS_CHANGE_?

  //
  // Send the DebugInfo record
  //
  REPORT_STATUS_CODE_EX (
    EFI_DEBUG_CODE,
    (EFI_SOFTWARE_DXE_BS_DRIVER | EFI_DC_UNSPECIFIED),
    0,
    NULL,
    &gEfiStatusCodeDataTypeDebugGuid,
    DebugInfo,
    TotalSize
    );
}

/**
// MS_CHANGE_?
// MSCHANGE Added DebugDumpMemory
  Dumps memory formatted.

  Dumps the memory as hex bytes.  Other additional options 
  are controled with the Flags parameter.


  @param  Address      The address of the memory to dump.
  @param  Length       The length of the region to dump.
  @param  Flags        PrintAddress, PrintOffset etc

**/

VOID
EFIAPI
DebugDumpMemory (
  IN  UINTN         ErrorLevel,
  IN  CONST VOID   *Address,
  IN  UINTN         Length,
  IN  UINT32        Flags
  ) 
{
  UINTN       Indx;
  UINT8      *p;
  CHAR8       Txt[17]; // 16 characters, and a NULL

  p = (UINT8 *) Address;

  Txt[16] = '\0';
  Indx = 0;
  while(Indx < Length)
  {
    UINTN LoopLen = ((Length - Indx) >= 16) ? 16 : (Length - Indx);
    if (0 == (Indx % 16))  // first time and every 16 bytes thereafter
    {
      if (Flags & DEBUG_DM_PRINT_ADDRESS)
      {
        DebugPrint(ErrorLevel, "\n0x%16.16X:  ", p);
      }
      else if (Flags & DEBUG_DM_PRINT_OFFSET)
      {
        DebugPrint(ErrorLevel, "\n0x%8.8X:  ", (p - (UINT8 *)Address));
      }
      else
      {
        DebugPrint(ErrorLevel, "\n");
      }

      //Get all Ascii Chars if Ascii flag for the next 16 or less
      if (Flags & DEBUG_DM_PRINT_ASCII)
      {
        SetMem(Txt, sizeof(Txt) - 1, ' ');
        for (UINTN I = (Indx % 16); I < LoopLen; I++)
        {
          CHAR8* c = (CHAR8*) (p + I);
          Txt[I] = ((*c >= 0x20) && (*c <= 0x7e)) ? *c : '.';
        }
      }
    }  //first pass -- done only at (index % 16 == 0)

    if (LoopLen == 16)
    {
      DebugPrint(ErrorLevel, "%02X %02X %02X %02X %02X %02X %02X %02X - ", *(p), *(p + 1), *(p + 2), *(p + 3), *(p + 4), *(p + 5), *(p + 6), *(p + 7));
      DebugPrint(ErrorLevel, "%02X %02X %02X %02X %02X %02X %02X %02X ", *(p + 8), *(p + 9), *(p + 10), *(p + 11), *(p + 12), *(p + 13), *(p + 14), *(p + 15));
      Indx += 16;
      p += 16;
    } 
    else
    {
      if ((Indx % 16) == 7)
      {
        DebugPrint(ErrorLevel, "%02X - ", *(p));
      }
      else
      {
        DebugPrint(ErrorLevel, "%02X ", *(p));
      }
      Indx++;
      p++;
    }
      
    //end of line and/or end of buffer
    if (((Indx % 16) == 0) || (Indx == Length))
    {

      //special case where we need to print out a few blank spaces because our length
      //was not evenly divisible by 16
      if (Flags & DEBUG_DM_PRINT_ASCII)
      {
        if ((Indx % 16) != 0)
        {
          //figure out how many spaces to print
          CHAR8 empty[48]; //(15 bytes * 3 chars) + 2 (for -) + 1 (\0)
          UINTN endchar = ((16 - (Indx % 16)) * 3);
          SetMem(empty, 47, ' ');
          if ((Indx % 16) <= 8)
          {
            endchar += 2;
          }
          empty[endchar] = '\0';  //null terminate
          DebugPrint(ErrorLevel, "%a", empty);
        }
        DebugPrint(ErrorLevel, "  *%a*", Txt);   // print the txt
      }
    }
  }  //End while loop
  DebugPrint(ErrorLevel, "\n");
}

/**
  Prints an assert message containing a filename, line number, and description.
  This may be followed by a breakpoint or a dead loop.

  Print a message of the form "ASSERT <FileName>(<LineNumber>): <Description>\n"
  to the debug output device.  If DEBUG_PROPERTY_ASSERT_BREAKPOINT_ENABLED bit of
  PcdDebugProperyMask is set then CpuBreakpoint() is called. Otherwise, if
  DEBUG_PROPERTY_ASSERT_DEADLOOP_ENABLED bit of PcdDebugProperyMask is set then
  CpuDeadLoop() is called.  If neither of these bits are set, then this function
  returns immediately after the message is printed to the debug output device.
  DebugAssert() must actively prevent recursion.  If DebugAssert() is called while
  processing another DebugAssert(), then DebugAssert() must return immediately.

  If FileName is NULL, then a <FileName> string of "(NULL) Filename" is printed.
  If Description is NULL, then a <Description> string of "(NULL) Description" is printed.

  @param  FileName     Pointer to the name of the source file that generated the assert condition.
  @param  LineNumber   The line number in the source file that generated the assert condition
  @param  Description  Pointer to the description of the assert condition.

**/
VOID
EFIAPI
DebugAssert (
  IN CONST CHAR8  *FileName,
  IN UINTN        LineNumber,
  IN CONST CHAR8  *Description
  )
{
  UINT64                 Buffer[EFI_STATUS_CODE_DATA_MAX_SIZE / sizeof(UINT64)];
  EFI_DEBUG_ASSERT_DATA  *AssertData;
  UINTN                  HeaderSize;
  UINTN                  TotalSize;
  CHAR8                  *Temp;
  UINTN                  ModuleNameSize;
  UINTN                  FileNameSize;
  UINTN                  DescriptionSize;

  //
  // Get string size
  //
  HeaderSize       = sizeof (EFI_DEBUG_ASSERT_DATA);
  //
  // Compute string size of module name enclosed by []
  //
  ModuleNameSize   = 2 + AsciiStrSize (gEfiCallerBaseName);
  FileNameSize     = AsciiStrSize (FileName);
  DescriptionSize  = AsciiStrSize (Description);

  //
  // Make sure it will all fit in the passed in buffer.
  //
  if (HeaderSize + ModuleNameSize + FileNameSize + DescriptionSize > sizeof (Buffer)) {
    //
    // remove module name if it's too long to be filled into buffer
    //
    ModuleNameSize = 0;
    if (HeaderSize + FileNameSize + DescriptionSize > sizeof (Buffer)) {
      //
      // FileName + Description is too long to be filled into buffer.
      //
      if (HeaderSize + FileNameSize < sizeof (Buffer)) {
        //
        // Description has enough buffer to be truncated.
        //
        DescriptionSize = sizeof (Buffer) - HeaderSize - FileNameSize;
      } else {
        //
        // FileName is too long to be filled into buffer.
        // FileName will be truncated. Reserved one byte for Description NULL terminator.
        //
        DescriptionSize = 1;
        FileNameSize    = sizeof (Buffer) - HeaderSize - DescriptionSize;
      }
    }
  }
  //
  // Fill in EFI_DEBUG_ASSERT_DATA
  //
  AssertData = (EFI_DEBUG_ASSERT_DATA *)Buffer;
  AssertData->LineNumber = (UINT32)LineNumber;
  TotalSize  = sizeof (EFI_DEBUG_ASSERT_DATA);

  Temp = (CHAR8 *)(AssertData + 1);

  //
  // Copy Ascii [ModuleName].
  //
  if (ModuleNameSize != 0) {
    CopyMem(Temp, "[", 1);
    CopyMem(Temp + 1, gEfiCallerBaseName, ModuleNameSize - 3);
    CopyMem(Temp + ModuleNameSize - 2, "] ", 2);
  }

  //
  // Copy Ascii FileName including NULL terminator.
  //
  Temp = CopyMem (Temp + ModuleNameSize, FileName, FileNameSize);
  Temp[FileNameSize - 1] = 0;
  TotalSize += (ModuleNameSize + FileNameSize);

  //
  // Copy Ascii Description include NULL terminator.
  //
  Temp = CopyMem (Temp + FileNameSize, Description, DescriptionSize);
  Temp[DescriptionSize - 1] = 0;
  TotalSize += DescriptionSize;

  REPORT_STATUS_CODE_EX (
    (EFI_ERROR_CODE | EFI_ERROR_UNRECOVERED),
    (EFI_SOFTWARE_DXE_BS_DRIVER | EFI_SW_EC_ILLEGAL_SOFTWARE_STATE),
    0,
    NULL,
    NULL,
    AssertData,
    TotalSize
    );

  //
  // Generate a Breakpoint, DeadLoop, or NOP based on PCD settings
  //
  if ((PcdGet8 (PcdDebugPropertyMask) & DEBUG_PROPERTY_ASSERT_BREAKPOINT_ENABLED) != 0) {
    CpuBreakpoint ();
  } else if ((PcdGet8 (PcdDebugPropertyMask) & DEBUG_PROPERTY_ASSERT_DEADLOOP_ENABLED) != 0) {
    CpuDeadLoop ();
  }
}


/**
  Fills a target buffer with PcdDebugClearMemoryValue, and returns the target buffer.

  This function fills Length bytes of Buffer with the value specified by
  PcdDebugClearMemoryValue, and returns Buffer.

  If Buffer is NULL, then ASSERT().
  If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().

  @param   Buffer  Pointer to the target buffer to be filled with PcdDebugClearMemoryValue.
  @param   Length  Number of bytes in Buffer to fill with zeros PcdDebugClearMemoryValue.

  @return  Buffer  Pointer to the target buffer filled with PcdDebugClearMemoryValue.

**/
VOID *
EFIAPI
DebugClearMemory (
  OUT VOID  *Buffer,
  IN UINTN  Length
  )
{
  ASSERT (Buffer != NULL);

  return SetMem (Buffer, Length, PcdGet8 (PcdDebugClearMemoryValue));
}


/**
  Returns TRUE if ASSERT() macros are enabled.

  This function returns TRUE if the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit of
  PcdDebugProperyMask is set.  Otherwise FALSE is returned.

  @retval  TRUE    The DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit of PcdDebugProperyMask is set.
  @retval  FALSE   The DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED bit of PcdDebugProperyMask is clear.

**/
BOOLEAN
EFIAPI
DebugAssertEnabled (
  VOID
  )
{
  return (BOOLEAN) ((PcdGet8 (PcdDebugPropertyMask) & DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED) != 0);
}


/**
  Returns TRUE if DEBUG() macros are enabled.

  This function returns TRUE if the DEBUG_PROPERTY_DEBUG_PRINT_ENABLED bit of
  PcdDebugProperyMask is set.  Otherwise FALSE is returned.

  @retval  TRUE    The DEBUG_PROPERTY_DEBUG_PRINT_ENABLED bit of PcdDebugProperyMask is set.
  @retval  FALSE   The DEBUG_PROPERTY_DEBUG_PRINT_ENABLED bit of PcdDebugProperyMask is clear.

**/
BOOLEAN
EFIAPI
DebugPrintEnabled (
  VOID
  )
{
  return (BOOLEAN) ((PcdGet8 (PcdDebugPropertyMask) & DEBUG_PROPERTY_DEBUG_PRINT_ENABLED) != 0);
}


/**
  Returns TRUE if DEBUG_CODE() macros are enabled.

  This function returns TRUE if the DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of
  PcdDebugProperyMask is set.  Otherwise FALSE is returned.

  @retval  TRUE    The DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of PcdDebugProperyMask is set.
  @retval  FALSE   The DEBUG_PROPERTY_DEBUG_CODE_ENABLED bit of PcdDebugProperyMask is clear.

**/
BOOLEAN
EFIAPI
DebugCodeEnabled (
  VOID
  )
{
  return (BOOLEAN) ((PcdGet8 (PcdDebugPropertyMask) & DEBUG_PROPERTY_DEBUG_CODE_ENABLED) != 0);
}


/**
  Returns TRUE if DEBUG_CLEAR_MEMORY() macro is enabled.

  This function returns TRUE if the DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of
  PcdDebugProperyMask is set.  Otherwise FALSE is returned.

  @retval  TRUE    The DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of PcdDebugProperyMask is set.
  @retval  FALSE   The DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED bit of PcdDebugProperyMask is clear.

**/
BOOLEAN
EFIAPI
DebugClearMemoryEnabled (
  VOID
  )
{
  return (BOOLEAN) ((PcdGet8 (PcdDebugPropertyMask) & DEBUG_PROPERTY_CLEAR_MEMORY_ENABLED) != 0);
}

/**
  Returns TRUE if any one of the bit is set both in ErrorLevel and PcdFixedDebugPrintErrorLevel.

  This function compares the bit mask of ErrorLevel and PcdFixedDebugPrintErrorLevel.

  @retval  TRUE    Current ErrorLevel is supported.
  @retval  FALSE   Current ErrorLevel is not supported.

**/
BOOLEAN
EFIAPI
DebugPrintLevelEnabled (
  IN  CONST UINTN        ErrorLevel
  )
{
  return (BOOLEAN) ((ErrorLevel & PcdGet32(PcdFixedDebugPrintErrorLevel)) != 0);
}
