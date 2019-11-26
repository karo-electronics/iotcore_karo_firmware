/** @file
DfciSettings.c

Library Instance for DXE to support getting, setting, defaults, and support Dfci settings.

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

#include <Uefi.h>

#include <DfciSystemSettingTypes.h>

#include <Guid/DfciSettingsGuid.h>

#include <Protocol/DfciSettingsProvider.h>

#include <Library/BaseMemoryLib.h>
#include <Library/DfciSettingsLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>

#include <Settings/DfciSettings.h>

EFI_EVENT  mDfciSettingsProviderSupportInstallEvent;
VOID      *mDfciSettingsProviderSupportInstallEventRegistration = NULL;

typedef enum {
    ID_IS_BAD,
    ID_IS_URL,
    ID_IS_HWID,
    ID_IS_FRIENDLY_NAME,
    ID_IS_TENANT_NAME,
}  ID_IS;

// Forward declarations needed
/**
 * Settings Provider GetDefault routine
 *
 * @param This
 * @param ValueSize
 * @param Value
 *
 * @return EFI_STATUS EFIAPI
 */
EFI_STATUS
EFIAPI
DfciSettingsGetDefault (
    IN  CONST DFCI_SETTING_PROVIDER     *This,
    IN  OUT   UINTN                     *ValueSize,
    OUT       VOID                      *Value
  );

/**
 * Settings Provider Get routine
 *
 * @param This
 * @param ValueSize
 * @param Value
 *
 * @return EFI_STATUS EFIAPI
 */
EFI_STATUS
EFIAPI
DfciSettingsGet (
  IN  CONST DFCI_SETTING_PROVIDER  *This,
  IN  OUT   UINTN                  *ValueSize,
  OUT       VOID                   *Value
  );

/**
@param Id - Setting ID to check for support status
@retval TRUE - Supported
@retval FALSE - Not supported
**/
STATIC
ID_IS
IsIdSupported (DFCI_SETTING_ID_STRING Id)
{

    if (0 == AsciiStrnCmp (Id, DFCI_SETTING_ID__DFCI_URL, DFCI_MAX_ID_LEN)) {
        return ID_IS_URL;
    } else if (0 == AsciiStrnCmp (Id, DFCI_SETTING_ID__DFCI_HWID, DFCI_MAX_ID_LEN)) {
        return ID_IS_HWID;
    } else if (0 == AsciiStrnCmp (Id, DFCI_SETTING_ID__MDM_FRIENDLY_NAME, DFCI_MAX_ID_LEN)) {
        return ID_IS_FRIENDLY_NAME;
    } else if (0 == AsciiStrnCmp (Id, DFCI_SETTING_ID__MDM_TENANT_NAME, DFCI_MAX_ID_LEN)) {
        return ID_IS_TENANT_NAME;
    } else {
        DEBUG((DEBUG_ERROR, "%a: Called with Invalid ID (%a)\n", __FUNCTION__, Id));
    }

    return ID_IS_BAD;
}

/**
 * Validate Nv Variable
 *
 * @param VariableName
 *
 * @return STATIC EFI_STATUS
 */
STATIC
EFI_STATUS
ValidateNvVariable (
    CHAR16 *VariableName
  )
{
    EFI_STATUS  Status;
    UINT32      Attributes = 0;
    UINTN       ValueSize = 0;


    Status = gRT->GetVariable (VariableName,
                              &gDfciSettingsGuid,
                              &Attributes,
                              &ValueSize,
                               NULL );
    if (!EFI_ERROR(Status)) {                          // We have a variable
        if (DFCI_SETTINGS_ATTRIBUTES != Attributes) {  // Check if Attributes are wrong
            // Delete invalid URL variable
            Status = gRT->SetVariable (VariableName,
                                      &gDfciSettingsGuid,
                                       0,
                                       0,
                                       NULL);
            if (EFI_ERROR(Status)) {                   // What???
                DEBUG((DEBUG_ERROR, "%a: Unable to delete invalid variable %s\n", __FUNCTION__, VariableName));
            }
        }
    }

    return Status;
}

/**
 * Internal function used to initialize the non volatile variables.
 *
 * @param
 *
 * @return STATIC EFI_STATUS
 */
STATIC
EFI_STATUS
InitializeNvVariables (
    VOID
  )
{
    EFI_STATUS  Status;

    Status  = ValidateNvVariable (DFCI_SETTINGS_URL_NAME);
    Status |= ValidateNvVariable (DFCI_SETTINGS_HWID_NAME);
    Status |= ValidateNvVariable (DFCI_SETTINGS_FRIENDLY_NAME);
    Status |= ValidateNvVariable (DFCI_SETTINGS_TENANT_NAME);

    return Status;
}

/////---------------------Interface for Settings Provider ---------------------//////

/**
 * Settings Provider Set Routine
 *
 * @param This
 * @param ValueSize
 * @param Value
 * @param Flags
 *
 * @return EFI_STATUS EFIAPI
 */
EFI_STATUS
EFIAPI
DfciSettingsSet (
    IN  CONST DFCI_SETTING_PROVIDER    *This,
    IN        UINTN                     ValueSize,
    IN  CONST VOID                     *Value,
    OUT       DFCI_SETTING_FLAGS       *Flags
  )
{
    VOID           *Buffer = NULL;
    UINTN           BufferSize;
    EFI_STATUS      Status;
    CHAR16         *VariableName;
    ID_IS           Id;

    if ((This == NULL) || (This->Id == NULL) || (Value == NULL) || (Flags == NULL) || (ValueSize > DFCI_SETTING_MAXIMUM_SIZE)) {
        DEBUG((DEBUG_ERROR, "%a: Invalid parameter.\n", __FUNCTION__));
        return EFI_INVALID_PARAMETER;
    }

    Id = IsIdSupported(This->Id);
    switch (Id) {
        case ID_IS_URL:
            VariableName = DFCI_SETTINGS_URL_NAME;
            break;

        case ID_IS_HWID:
            VariableName = DFCI_SETTINGS_HWID_NAME;
            break;

        case ID_IS_FRIENDLY_NAME:
            VariableName = DFCI_SETTINGS_FRIENDLY_NAME;
            break
            ;
        case ID_IS_TENANT_NAME:
            VariableName = DFCI_SETTINGS_TENANT_NAME;
            break;

        default:
            DEBUG((DEBUG_ERROR, "%a: Invalid id(%s).\n", __FUNCTION__, This->Id));
            return EFI_UNSUPPORTED;
            break;
    }

    BufferSize = 0;
    Status = DfciSettingsGet (This, &BufferSize, NULL);

    if (Status != EFI_NOT_FOUND) {
        if (EFI_ERROR(Status) && (EFI_BUFFER_TOO_SMALL != Status)) {
            DEBUG((DEBUG_ERROR, "%a: Error getting %s. Code=%r\n", __FUNCTION__, VariableName, Status));
            return Status;
        }

        if ((BufferSize == 0) && (ValueSize == 0)) {
            *Flags |= DFCI_SETTING_FLAGS_OUT_ALREADY_SET;
            DEBUG((DEBUG_INFO, "Setting %s ignored, sizes are 0\n", VariableName));
            return EFI_SUCCESS;
        }

        if ((ValueSize != 0) && (BufferSize == ValueSize)) {
            Buffer = AllocatePool (BufferSize);
            if (NULL == Buffer) {
                DEBUG((DEBUG_ERROR, "%a: Cannot allocate %d bytes.%r\n", __FUNCTION__, BufferSize));
                return EFI_OUT_OF_RESOURCES;
            }

            Status = gRT->GetVariable (VariableName,
                                      &gDfciSettingsGuid,
                                       NULL,
                                      &BufferSize,
                                       Buffer );
            if (EFI_ERROR(Status)) {
                FreePool (Buffer);
                DEBUG((DEBUG_ERROR, "%a: Error getting variable %s. Code=%r\n", __FUNCTION__, VariableName, Status));
                return Status;
            }

            if (0 == CompareMem(Buffer, Value, BufferSize)) {
                FreePool (Buffer);
                *Flags |= DFCI_SETTING_FLAGS_OUT_ALREADY_SET;
                DEBUG((DEBUG_INFO, "Setting %s ignored, value didn't change\n", VariableName));
                return EFI_SUCCESS;
            }
            FreePool (Buffer);
        }
    }

    Status = gRT->SetVariable (VariableName,
                              &gDfciSettingsGuid,
                               DFCI_SETTINGS_ATTRIBUTES,
                               ValueSize,
                               (VOID *) Value);  // SetVariable should not touch *Value
    if (EFI_ERROR(Status)) {
        DEBUG((DEBUG_ERROR, "Error setting variable %s.  Code = %r\n", VariableName, Status));
    } else {
        DEBUG((DEBUG_INFO, "Variable %s set.\n", VariableName));
    }

    return Status;
}

/**
 * Settings Provider Get routine
 *
 * @param This
 * @param ValueSize
 * @param Value
 *
 * @return EFI_STATUS EFIAPI
 */
EFI_STATUS
EFIAPI
DfciSettingsGet (
    IN  CONST DFCI_SETTING_PROVIDER    *This,
    IN  OUT   UINTN                    *ValueSize,
    OUT       VOID                     *Value
  )
{
    ID_IS               Id;
    EFI_STATUS          Status;
    CHAR16             *VariableName;

    if ((This == NULL) || (This->Id == NULL) || (ValueSize == NULL) || ((Value == NULL) && (*ValueSize != 0))) {
        DEBUG((DEBUG_ERROR, "%a: Invalid parameter.\n", __FUNCTION__));
        return EFI_INVALID_PARAMETER;
    }

    Id = IsIdSupported(This->Id);
    switch (Id) {
        case ID_IS_URL:
            VariableName = DFCI_SETTINGS_URL_NAME;
            break;

        case ID_IS_HWID:
            VariableName = DFCI_SETTINGS_HWID_NAME;
            break;

        case ID_IS_FRIENDLY_NAME:
            VariableName = DFCI_SETTINGS_FRIENDLY_NAME;
            break
            ;
        case ID_IS_TENANT_NAME:
            VariableName = DFCI_SETTINGS_TENANT_NAME;
            break;

        default:
            DEBUG((DEBUG_ERROR, "%a: Invalid id(%s).\n", __FUNCTION__, This->Id));
            return EFI_UNSUPPORTED;
            break;
    }


    Status = gRT->GetVariable (VariableName,
                              &gDfciSettingsGuid,
                               NULL,
                               ValueSize,
                               Value );
    if (EFI_NOT_FOUND == Status) {
        DEBUG((DEBUG_INFO, "%a - Variable %s not found. Getting default value.\n", __FUNCTION__, VariableName));
        Status = DfciSettingsGetDefault (This, ValueSize, Value);
    }

    if (EFI_ERROR(Status)) {
        DEBUG((DEBUG_ERROR, "%a - Error retrieving setting %s. Code=%r\n", __FUNCTION__, VariableName, Status));
    } else {
        DEBUG((DEBUG_INFO, "%a - Setting %s retrieved.\n",__FUNCTION__ , VariableName));
    }

    return Status;
}

/**
 * Settings Provider GetDefault routine
 *
 * @param This
 * @param ValueSize
 * @param Value
 *
 * @return EFI_STATUS EFIAPI
 */
EFI_STATUS
EFIAPI
DfciSettingsGetDefault (
    IN  CONST DFCI_SETTING_PROVIDER     *This,
    IN  OUT   UINTN                     *ValueSize,
    OUT       VOID                      *Value
  )
{
    ID_IS    Id;

    if ((This == NULL) || (This->Id == NULL) || (ValueSize == NULL) || ((Value == NULL) && (*ValueSize != 0))) {
        DEBUG((DEBUG_ERROR, "%a: Invalid parameter.\n", __FUNCTION__));
        return EFI_INVALID_PARAMETER;
    }

    Id = IsIdSupported(This->Id);
    if (Id == ID_IS_BAD) {
        return EFI_UNSUPPORTED;
    }

    if (This->Type == DFCI_SETTING_TYPE_CERT) {
        *ValueSize = 0;  // Indicate no default
    } else {
        if (*ValueSize < sizeof(CHAR8)) {
            *ValueSize = sizeof(CHAR8);
            return EFI_BUFFER_TOO_SMALL;
        }
        *ValueSize = sizeof(CHAR8);
        *((CHAR8 *)Value) = '\0';
    }
    // DFCI Strings default to "", and CERTs default to not present.

    return EFI_SUCCESS;
}

/**
 * Settings Provider Set Default routine
 *
 * @param This
 *
 * @return EFI_STATUS EFIAPI
 */
EFI_STATUS
EFIAPI
DfciSettingsSetDefault (
    IN  CONST DFCI_SETTING_PROVIDER     *This
  )
{
    DFCI_SETTING_FLAGS Flags = 0;
    EFI_STATUS         Status;
    CHAR8              Value;
    UINTN              ValueSize;

    if (This == NULL) {
        return EFI_INVALID_PARAMETER;
    }

    ValueSize = sizeof(ValueSize);
    Status = DfciSettingsGetDefault (This, &ValueSize, &Value);
    if (EFI_ERROR(Status)) {
        return Status;
    }

    return DfciSettingsSet (This, ValueSize, &Value, &Flags);
}

//
// Since ProviderSupport Registration copies the provider to its own
// allocated memory this code can use a single "template" and just change
// the id, type, and flags field as needed for registration.
//
DFCI_SETTING_PROVIDER mDfciSettingsProviderTemplate = {
  0,
  0,
  0,
  DfciSettingsSet,
  DfciSettingsGet,
  DfciSettingsGetDefault,
  DfciSettingsSetDefault
};

/////---------------------Interface for Library  ---------------------//////

/**
Function to Get a Dfci Setting.
If the setting has not be previously set this function will return the default.  However it will
not cause the default to be set.

@param Id:          The DFCI_SETTING_ID_ENUM of the Dfci
@param ValueSize:   IN=Size Of Buffer or 0 to get size, OUT=Size of returned Value
@param Value:       Ptr to a buffer for the setting to be returned.


@retval: Success - Setting was returned in Value
@retval: EFI_ERROR.  Settings was not returned in Value.
**/
EFI_STATUS
EFIAPI
GetDfciSetting (
  IN      DFCI_SETTING_ID_STRING   Id,
  IN  OUT UINTN                   *ValueSize,
  OUT     VOID                    *Value
) {
    EFI_STATUS      Status;

    mDfciSettingsProviderTemplate.Id = Id;
    Status = DfciSettingsGet (&mDfciSettingsProviderTemplate, ValueSize, Value);
    if (EFI_ERROR(Status) && (EFI_BUFFER_TOO_SMALL != Status)) {
        Status = DfciSettingsGetDefault (&mDfciSettingsProviderTemplate, ValueSize, Value);
    }
    return Status;
}

/**
 * Library design is such that a dependency on gDfciSettingsProviderSupportProtocolGuid
 * is not desired.  So to resolve that a ProtocolNotify is used.
 *
 * This function gets triggered once on install and 2nd time when the Protocol gets installed.
 *
 * When the gDfciSettingsProviderSupportProtocolGuid protocol is available the function will
 * loop thru all the Dfci settings (using PCD) and install the settings
 *
 * Context is NULL.
 *
 *
 * @param Event
 * @param Context
 *
 * @return VOID EFIAPI
 */
VOID
EFIAPI
DfciSettingsProviderSupportProtocolNotify (
    IN  EFI_EVENT       Event,
    IN  VOID            *Context
  )
{
    STATIC UINT8                            CallCount = 0;
    DFCI_SETTING_PROVIDER_SUPPORT_PROTOCOL *sp;
    EFI_STATUS                              Status;

    //locate protocol
    Status = gBS->LocateProtocol (&gDfciSettingsProviderSupportProtocolGuid, NULL, (VOID**)&sp);
    if (EFI_ERROR(Status)) {
      if ((CallCount++ != 0) || (Status != EFI_NOT_FOUND)) {
        DEBUG((DEBUG_ERROR, "%a() - Failed to locate gDfciSettingsProviderSupportProtocolGuid in notify.  Status = %r\n", __FUNCTION__, Status));
      }
      return;
    }

    //
    // Register items that are NOT in the PREBOOT_UI
    //
    mDfciSettingsProviderTemplate.Id = DFCI_SETTING_ID__DFCI_URL;
    mDfciSettingsProviderTemplate.Type = DFCI_SETTING_TYPE_STRING;
    mDfciSettingsProviderTemplate.Flags = DFCI_SETTING_FLAGS_NO_PREBOOT_UI;
    Status = sp->RegisterProvider (sp, &mDfciSettingsProviderTemplate);
    if (EFI_ERROR(Status)) {
        DEBUG((DEBUG_ERROR, "Failed to Register DFCI_URL.  Status = %r\n", Status));
    }

    mDfciSettingsProviderTemplate.Id = DFCI_SETTING_ID__DFCI_HWID;
    mDfciSettingsProviderTemplate.Type = DFCI_SETTING_TYPE_STRING;
    mDfciSettingsProviderTemplate.Flags = DFCI_SETTING_FLAGS_NO_PREBOOT_UI;
    Status = sp->RegisterProvider(sp, &mDfciSettingsProviderTemplate);
    if (EFI_ERROR(Status)) {
        DEBUG((DEBUG_ERROR, "Failed to Register DFCI_HWID.  Status = %r\n", Status));
    }

    mDfciSettingsProviderTemplate.Id = DFCI_SETTING_ID__MDM_FRIENDLY_NAME;
    mDfciSettingsProviderTemplate.Type = DFCI_SETTING_TYPE_STRING;
    mDfciSettingsProviderTemplate.Flags = DFCI_SETTING_FLAGS_NO_PREBOOT_UI;
    Status = sp->RegisterProvider(sp, &mDfciSettingsProviderTemplate);
    if (EFI_ERROR(Status)) {
        DEBUG((DEBUG_ERROR, "Failed to Register DFCI_MDM_FRIENDLY_NAME.  Status = %r\n", Status));
    }

    mDfciSettingsProviderTemplate.Id = DFCI_SETTING_ID__MDM_TENANT_NAME;
    mDfciSettingsProviderTemplate.Type = DFCI_SETTING_TYPE_STRING;
    mDfciSettingsProviderTemplate.Flags = DFCI_SETTING_FLAGS_NO_PREBOOT_UI;
    Status = sp->RegisterProvider(sp, &mDfciSettingsProviderTemplate);
    if (EFI_ERROR(Status)) {
        DEBUG((DEBUG_ERROR, "Failed to Register DFCI_MDM_TENANT_NAME.  Status = %r\n", Status));
    }

    //We got here, this means all protocols were installed and we didn't exit early.
    //close the event as we dont' need to be signaled again. (shouldn't happen anyway)
    gBS->CloseEvent(Event);
}

/**
 * The constructor function initializes the Lib for Dxe.
 *
 * This constructor is only needed for DfciSettingsManager support.
 * The design is to have the PCD false for all modules except the 1 anonymously liked to the DfciettingsManager.
 *
 * @param  ImageHandle   The firmware allocated handle for the EFI image.
 * @param  SystemTable   A pointer to the EFI System Table.
 *
 * @retval EFI_SUCCESS   The constructor always returns EFI_SUCCESS.
 *
 **/
EFI_STATUS
EFIAPI
DfciSettingsConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
    EFI_STATUS Status;

    if (FeaturePcdGet (PcdSettingsManagerInstallProvider)) {
        //Install callback on the SettingsManager gMsSystemSettingsProviderSupportProtocolGuid protocol
        mDfciSettingsProviderSupportInstallEvent = EfiCreateProtocolNotifyEvent (
            &gDfciSettingsProviderSupportProtocolGuid,
             TPL_CALLBACK,
             DfciSettingsProviderSupportProtocolNotify,
             NULL,
            &mDfciSettingsProviderSupportInstallEventRegistration
            );

        DEBUG((DEBUG_INFO, "%a: Event Registered.\n", __FUNCTION__));

        //Init nv var
        Status = InitializeNvVariables ();
        if (EFI_ERROR(Status)) {
            DEBUG((DEBUG_ERROR, "%a: Initialize Nv Var failed. %r.\n", __FUNCTION__, Status));
        }
    }
    return EFI_SUCCESS;
}

