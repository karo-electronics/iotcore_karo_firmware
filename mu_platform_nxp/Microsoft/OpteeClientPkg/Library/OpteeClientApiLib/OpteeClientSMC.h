/** @file
  The OP-TEE SMC Interface that packs the SMC parameters and sends the SMC to
  secure world for handling.

  Copyright (c) 2015, Microsoft Corporation.
  Portions Copyright (c) 2014, STMicroelectronics International N.V.
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  
  1. Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
  
  2. Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef __OPTEE_CLIENT_SMC_H__
#define __OPTEE_CLIENT_SMC_H__

TEEC_Result
TEEC_SMC_OpenSession (
  IN TEEC_Context     *Context,
  IN TEEC_Session     *Session,
  IN const TEEC_UUID  *Destination,
  IN TEEC_Operation   *Operation,
  OUT uint32_t        *ReturnOrigin
  );

TEEC_Result
TEEC_SMC_CloseSession (
  IN TEEC_Session   *Session,
  OUT uint32_t      *ReturnOrigin
  );

TEEC_Result
TEEC_SMC_InvokeCommand (
  IN TEEC_Session     *Session,
  IN uint32_t         CommandId,
  IN TEEC_Operation   *Operation,
  OUT uint32_t        *ReturnOrigin
  );

#endif // __OPTEE_CLIENT_SMC_H__
