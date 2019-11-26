/* Microsoft Reference Implementation for TPM 2.0
 *
 *  The copyright in this software is being made available under the BSD License,
 *  included below. This software may be subject to other third party and
 *  contributor rights, including patent rights, and no such rights are granted
 *  under this license.
 *
 *  Copyright (c) Microsoft Corporation
 *
 *  All rights reserved.
 *
 *  BSD License
 *
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *
 *  Redistributions of source code must retain the above copyright notice, this list
 *  of conditions and the following disclaimer.
 *
 *  Redistributions in binary form must reproduce the above copyright notice, this
 *  list of conditions and the following disclaimer in the documentation and/or other
 *  materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ""AS IS""
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//** Introduction
// This header defines the interface between the hashing code and the LIbTomCrypt
// hash functions.

#ifndef _TPM_TO_LTC_HASH_H_
#define _TPM_TO_LTC_HASH_H_

#if HASH_LIB == LTC

// Avoid pulling in the MPA math if not doing asymmetric with LTC
#if MATH_LIB != LTC
#  define LTC_NO_ASYMMETRIC
#endif

#include "LtcSettings.h"

//***************************************************************
//******** Linking to the TomCrypt HASH code ********************
//***************************************************************
// These defines need to be known in all parts of the TPM so that the structure
// sizes can be properly computed when needed.
#define tpmHashStateSHA1_t            struct sha1_state
#define tpmHashStateSHA256_t          struct sha256_state
#define tpmHashStateSHA512_t          struct sha512_state
#define tpmHashStateSHA384_t          struct sha512_state


// The following defines are only needed by CryptHash.c
#ifdef _CRYPT_HASH_C_

// Define the interface between CryptHash.c to the functions provided by the 
// library. For each method, define the calling parameters of the method and then 
// define how the method is invoked in CryptHash.c.
//
// All hashes are required to have the same calling sequence. If they don't, create
// a simple adaptation function that converts from the "standard" form of the call
// to the form used by the specific hash (and then send a nasty letter to the
// person who wrote the hash function for the library). 
// 
// The macro that calls the method also defines how the
// parameters get swizzled between the default form (in CryptHash.c)and the 
// library form.
//
// Initialize the hash context
#define HASH_START_METHOD_DEF                                                   \
                void (HASH_START_METHOD)(PANY_HASH_STATE state)
#define HASH_START(hashState)                                                   \
                ((hashState)->def->method.start)(&(hashState)->state)

// Add data to the hash
#define HASH_DATA_METHOD_DEF                                                    \
                void (HASH_DATA_METHOD)(PANY_HASH_STATE state,                  \
                                        const BYTE *buffer,                     \
                                        size_t size)
#define HASH_DATA(hashState, dInSize, dIn)                                      \
                ((hashState)->def->method.data)(&(hashState)->state, dIn, dInSize)

// Finalize the hash and get the digest
#define HASH_END_METHOD_DEF                                                     \
                void (HASH_END_METHOD)(PANY_HASH_STATE                          \
                                       state,                                   \
                                       BYTE *buffer)
#define HASH_END(hashState, buffer)                                             \
                ((hashState)->def->method.end)(&(hashState)->state, buffer)

// Copy the hash context
// Note: For import, export, and copy, memcpy() is used since there is no
// reformatting necessary between the internal and external forms
#define HASH_STATE_COPY_METHOD_DEF                                              \
                void (HASH_STATE_COPY_METHOD)(PANY_HASH_STATE to,               \
                                              PCANY_HASH_STATE from,            \
                                              size_t size)
#define  HASH_STATE_COPY(hashStateOut, hashStateIn)                             \
                ((hashStateIn)->def->method.copy)                               \
                        (&(hashStateOut)->state,                                \
                         &(hashStateIn)->state,                                 \
                         (hashStateIn)->def->contextSize)

// Copy (with reformatting when necessary) an internal hash structure to an 
// external blob
#define  HASH_STATE_EXPORT_METHOD_DEF                                           \
                void (HASH_STATE_EXPORT_METHOD)(BYTE *to,                       \
                                                PANY_HASH_STATE from,           \
                                                size_t size)
#define HASH_STATE_EXPORT(to, hashStateFrom)                                    \
                ((hashStateFrom)->def->method.copyOut)                          \
                        (&(((BYTE *)(to))[offsetof(HASH_STATE, state)]),        \
                         &(hashStateFrom)->state,                               \
                         (hashStateFrom)->def->contextSize)

// Copy from an external blob to an internal formate (with reformatting when 
// necessary
#define  HASH_STATE_IMPORT_METHOD_DEF                                           \
                void (HASH_STATE_IMPORT_METHOD)(PANY_HASH_STATE to,             \
                                                 const BYTE *from,              \
                                                 size_t size)
#define  HASH_STATE_IMPORT(hashStateTo, from)                                   \
                ((hashStateTo)->def->method.copyIn)                             \
                        (&(hashStateTo)->state,                                 \
                         &(((const BYTE *)(from))[offsetof(HASH_STATE, state)]),\
                         (hashStateTo)->def->contextSize)

//          Internal                    External
//          Designation                 Designation
#define tpmHashStart_SHA1           sha1_init
#define tpmHashData_SHA1            sha1_process
#define tpmHashEnd_SHA1             sha1_done
#define tpmHashStateCopy_SHA1       memcpy 
#define tpmHashStateExport_SHA1     memcpy 
#define tpmHashStateImport_SHA1     memcpy
#define tpmHashStart_SHA256         sha256_init
#define tpmHashData_SHA256          sha256_process
#define tpmHashEnd_SHA256           sha256_done
#define tpmHashStateCopy_SHA256     memcpy 
#define tpmHashStateExport_SHA256   memcpy
#define tpmHashStateImport_SHA256   memcpy 
#define tpmHashStart_SHA384         sha384_init
#define tpmHashData_SHA384          sha384_process
#define tpmHashEnd_SHA384           sha384_done
#define tpmHashStateCopy_SHA384     memcpy 
#define tpmHashStateExport_SHA384   memcpy 
#define tpmHashStateImport_SHA384   memcpy 
#define tpmHashStart_SHA512         sha512_init
#define tpmHashData_SHA512          sha512_process
#define tpmHashEnd_SHA512           sha512_done
#define tpmHashStateCopy_SHA512     memcpy 
#define tpmHashStateExport_SHA512   memcpy 
#define tpmHashStateImport_SHA512   memcpy

#endif // _CRYPT_HASH_C_


// No special processing to initialize the LTC hash library
#define LibHashInit()

// No special processing at the end of the simulation (i.e., no statistics to print)
#define HashLibSimulationEnd()


#endif // HASH_LIB == LTC

#endif //
