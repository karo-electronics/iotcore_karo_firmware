;------------------------------------------------------------------------------
;
; Copyright (c) 2006, Intel Corporation. All rights reserved.<BR>
; This program and the accompanying materials
; are licensed and made available under the terms and conditions of the BSD License
; which accompanies this distribution.  The full text of the license may be found at
; http://opensource.org/licenses/bsd-license.php.
;
; THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
; WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
;
; Module Name:
;
;   EnableInterrupts.Asm
;
; Abstract:
;
;   EnableInterrupts function
;
; Notes:
;
;------------------------------------------------------------------------------

    DEFAULT REL
    SECTION .text

;------------------------------------------------------------------------------
; VOID
; EFIAPI
; EnableInterrupts (
;   VOID
;   );
;------------------------------------------------------------------------------
global ASM_PFX(EnableInterrupts)
ASM_PFX(EnableInterrupts):
    sti
    ret

; MS_CHANGE - START
;------------------------------------------------------------------------------
; VOID
; EFIAPI
; EnableInterruptsAndSleep (
;   VOID
;   );
;------------------------------------------------------------------------------
global ASM_PFX(EnableInterruptsAndSleep)
ASM_PFX(EnableInterruptsAndSleep):
    sti
    hlt
    ret
; MS_CHANGE - END