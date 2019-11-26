/** @file
JsonLiteParser.h

Library for limited parsing of JSON files

Copyright (c) 2018, Microsoft Corporation

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**/

#ifndef __JSON_LITE_H__
#define __JSON_LITE_H__

//
// The limited format Json string is in the format:
//
//    { "ASCII-127-Identifier",  "ASCII-127-Value",
//      "ASCII-127-Identifier1", "ASCII-127-Value",
//      "ASCII-127-Identifier3", "ASCII-127-Value",
//      "ASCII-127-Identifier4", "ASCII-127-Value" }
//
// where ASCII-127 includes all characters 0x01-0x7F excluding 0x22 (the double quote "). 0x00
// is the NULL terminator.  ASCII-127 is not validated, but should not have an effect on parsing.
// An embedded NULL in the string will only stop parsing the string.

typedef struct {
    CHAR8    *FieldName;
    UINTN     FieldSize;
    CHAR8    *Value;
    UINTN     ValueSize;
} JSON_REQUEST_ELEMENT;

/**
 *  Function to process a Json Element
 *
 * @param[in]  Json Request Element   Element Being Processed
 *
 * @retval EFI_SUCCESS -       Packet processed normally
 * @retval Error -             Error processing packet
 */
typedef
EFI_STATUS
(EFIAPI *JSON_PROCESS_ELEMENT) (
    IN  JSON_REQUEST_ELEMENT *JsonElement
);

/**
 * EncodeJson
 *
 * @param[in]  Request Array
 * @param[in]  Request Count    - Number of entries in the array
 * @param[out] Json String      - Where to store pointer to Json String
 * @param[out] Json String Size - Where to store Json String Size
 *
 * Don't confuse this routine for a real Json Encoder.  This code is for the
 * expected Dfci request packets. Strict formatting is required, and
 * comments are not allowed.
 *
 * The caller is responsible for freeing the returned Json String;
 *
 **/
EFI_STATUS
EFIAPI
JsonLibEncode (
    IN  JSON_REQUEST_ELEMENT *Request,
    IN  UINTN                 RequestCount,
    OUT CHAR8               **JsonString,
    OUT UINTN                *JsonStringSize);

/**
 * ParseJson
 *
 * @param[in]      JsonString       - Json String
 * @param[in]      JsonStringLength   Number of characters in the string
 * @param[in]      ApplyFunction    - Function to process a Json Element
 *
 * Don't confuse this routine for a real Json Parser.  This code is for the
 * expected Dfci request packets.
 *
 * JsonString will be modified by the parse action.  The trailing quotes will
 * be converted to NULL characters.
 *
 **/
EFI_STATUS
EFIAPI
JsonLibParse (
    IN  CHAR8                  *JsonString,
    IN  UINTN                   JsonStringSize,
    IN  JSON_PROCESS_ELEMENT     ApplyFunction
);

#endif // __JSON_LITE_H__