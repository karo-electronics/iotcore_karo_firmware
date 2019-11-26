Production Grade SECO FW v2.3.0

Targets: i.MX8 QM B0
         i.MX8 QXP B0

Commit: 92ef114343216566371eeedf36e836d60cdbb32a

i.MX8 QM B0
    File:   mx8qm-ahab-container.img
    Tag:    SECO_FW_MX8QMB0_V2.3.0
    Build:  Bamboo QM B0 FW build #502
            https://bamboo1.sw.nxp.com/browse/IM-AHABDEV-502

i.MX8 QXP B0
    File:   mx8qx-ahab-container.img
    Tag:    SECO_FW_MX8QXPB0_V2.3.0
    Build:  Bamboo QXP B0 FW build #265
            https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-265

List of improvements & new features:
    - AHAB-472: clear only HDMI DRAM during HDMI open
    - AHAB-474: clear HDMI RAM before enabling HDMI debug
    - AHAB-476: Clear the pwr off IRQ on SNVS clear IRQ request
    - AHAB-477: refine SCU ROM patch update mechanism
    - AHAB-479: workaround compensating usb_sdp_fix patch

List of bug fixes:
    - AHAB-408: fix manufacturig protection msgrep size
    - Revert AHAB-450: stop 300ms WDT after SCFW authentication

================================================================================

Engineering SECO FW v0.3.0

Targets: i.MX8 QM B0
         i.MX8 QXP B0

Commit: c121d4a48a5fdfd1712041b10096bd37bfa0e3e9

i.MX8 QM B0
    File:   mx8qm-ahab-container.img
    Tag:    SECO_FW_MX8QMB0_V0.3.0
    Build:  Bamboo QM B0 FW build #478
            https://bamboo1.sw.nxp.com/browse/IM-AHABDEV-478

i.MX8 QXP B0
    File:   mx8qx-ahab-container.img
    Tag:    SECO_FW_MX8QXPB0_V0.3.0
    Build:  Bamboo QXP B0 FW build #239
            https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-239

List of improvements & new features:
    - HDMI: HDMI FW authentication and HDCP Tx keys setup
    - AHAB-445: SCU ROM patch update with double signed message
    - AHAB-451: VPU key handling
    - AHAB-450: stop 300ms WDT after SCFW authentication

List of bug fixes:
    - AHAB-449: key id had no effect

================================================================================

Engineering QXP B0 SECO FW v0.2.1

File:    mx8qx-ahab-container.img
Tag:     SECO_FW_MX8QXPB0_V0.2.1
Commit:  46e7397f6f84f60f212925f59b66f84fc5c76cef
Version: 0.2.1
Build:   Bamboo QXP B0 FW build #228
         https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-228

List of improvements & new features:
    - AHAB-444: improve SNVS accessibility

List of bug fixes:
    - AHAB-438: fix the RNG instantiation to load the KEK values and add PS

================================================================================

Engineering QXP B0 SECO FW v0.2.0

File:    mx8qx-ahab-container.img
Tag:     SECO_FW_MX8QXPB0_V0.2.0
Commit:  14b4e257c5ab40b81e0f1fcdcc828073747d1928
Version: 0.2.0
Build:   Bamboo QXP B0 FW build #214
         https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-214

List of improvements & new features:
    - AHAB-169 AHAB-268 AHAB-271: Blob handling
    - AHAB-385: Add OTPMK, DUSK and corresponding CRCs to the reserved fuses
    - AHAB-396: MessagingUnit/DID assignment
    - AHAB-408: Manufacturing protection public key and signature generation
    - AHAB-430: encrypted boot
    - AHAB-431: manage SNVS API
    - AHAB-435: IEE key handling

List of bug fixes:
    - AHAB-363: fix 50us delay issue
    - AHAB-404: API for SNVS wake up it
    - AHAB-410: add crc in dump debug rsp
    - AHAB-415: no events if PING or DUMP DEBUG
    - AHAB-416: invalid images generate events
    - AHAB-423: MISRA fixes for SECO FW build
    - AHAB-424: RNG init cleaning
    - AHAB-429: event buffer is not circular and reported in full

================================================================================

Production grade QM B0 SECO FW
SECO_FW_MX8QMB0_V1.1.0

commit 5ea797336509378b712c8405934062ff89921927
Version 1.1.0

- Build: Bamboo QM FW build #422 https://bamboo1.sw.nxp.com/browse/IM-AHABDEV-422
	mx8qm-ahab-container.img

New in version 1.1.0:
List of improvements & new features:
- AHAB-390: add reload shadow in write secure fuse
- AHAB-372: commit only if no events
- AHAB-357: refined cond + new fail status for closing LC
- AHAB-391: support SHA256 & SHA512 for images integrity
- AHAB-388: attest verifier mode controlled through a fuse

List of bug fixes:
- AHAB-393: fixes severe and medium coverity issues
- AHAB-397: CAAM JR timeout increased in FW and timeout function fixed
- AHAB-378 AHAB-379: attestation context do not survive any command
- AHAB-384: release memory allocated for auth req
- AHAB-348: fix seco debug
- AHAB-402: 2nd call to AHAB_OPEN_HDMI_X_REQ causes error while loading HDMI firmware

================================================================================

Production grade QXP B0 SECO FW
SECO_FW_MX8QXPB0_V1.1.0

commit 9d71fd5becad5ecb75d52af529e9fff5c62d2d25
Version 1.1.0

- Build: Bamboo QXP FW build #166 https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-166
	mx8qx-ahab-container.img

New in version 1.1.0:
List of improvements & new features:
- AHAB-390: add reload shadow in write secure fuse
- AHAB-372: commit only if no events
- AHAB-357: refined cond + new fail status for closing LC
- AHAB-391: support SHA256 & SHA512 for images integrity
- AHAB-388: attest verifier mode controlled through a fuse

List of bug fixes:
- AHAB-393: fixes severe and medium coverity issues
- AHAB-397: CAAM JR timeout increased in FW and timeout function fixed
- AHAB-378 AHAB-379: attestation context do not survive any command
- AHAB-384: release memory allocated for auth req
- AHAB-348: fix seco debug

================================================================================

Tag SECO_FW_MX8QMB0_V0.1.0  
    SECO_FW_MX8QXPB0_V0.1.0

commit: 31fabbffb180f5ed54af8ef89560ff0453c00cee
version 0.1.0

- Build: Bamboo QX FW build #134 https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-134
	mx8qm-ahab-container.img
- Build: Bamboo QM FW build #381 https://bamboo1.sw.nxp.com/browse/IM-AHABDEV-381
	mx8qx-ahab-container.img

New in version 0.1.0:
- Power request (lpm) fully implemented
- Attestation (prover & verifier modes)
- SRK revocation - Version handling
- SNVS message to configure button time parameters
- CRC on SECO ROM fuse patch
- Moving to closed LC is possible only if event queue is empty

================================================================================

Tags SECO_FW_MX8QMB0_V007 & SECO_FW_MX8QXPB0_V007

Container named respectively:
- mx8qm-ahab-container.img for qm
- mx8qx-ahab-container.img for qx

Tag SECO_FW_QMB0_V007

commit: 327152369c95bae5df480d399e31c21dba4cf054
version 007

- AHAB tree version: tag SECO_FW_QMB0_V007, https://bitbucket.sw.nxp.com/projects/MCUSEC/repos/ahab/browse?at=refs%2Ftags%2FSECO_FW_QMB0_V007
- Build: Bamboo QX FW build #348 https://bamboo1.sw.nxp.com/browse/IM-AHABDEV-348

Signing request:

- Signing certificate = ./imx8qm/crts/OEF_A0F6/IM8QMAX0101.pem
- Data to be signed   = container-201807201413-daa224bf6060fef85dfe79265c8203b0f86334ff.bin


Tag SECO_FW_QXPB0_V007

commit: 327152369c95bae5df480d399e31c21dba4cf054
version 007

- AHAB tree version: https://bitbucket.sw.nxp.com/projects/MCUSEC/repos/ahab/browse?at=refs%2Ftags%2FSECO_FW_QXPB0_V007
- Build: Bamboo QX FW build #110 https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-110

Signing request:

- Signing certificate = ./imx8x/crts/IMXQXP0101.pem
- Data to be signed   = container-201807201404-d2619593f404f9d96fca87c93a5ee05af54d6d86.bin


New in version 007:
 - Fix the issue found on secure RTC:
    . The secure RTC must not be initialized during SNVS initialization
    . Unlike the RTC, the Secure RTC counts in seconds

 - The CAAM TRNG initialization is not handled automatically by the SECO anymore to avoid any impact on the boot time
   Instead the SCFW can control the initialization with the message "start RNG request".

 - Only the first 8 pages of CAAM Secure memory are owned by the SECO instead of 16 pages in the previous versions. Pages 0 & 1 are r/w for the system.

JIRAs:
- AHAB-344: Update FW version to 007
- AHAB-342: CAAM RNG initialization
- AHAB-349: SNVS: fix secure RTC
- AHAB-351: SECO Secure memory handling

================================================================================

Tag SECO_FW_QXPB0_V06

commit: eeb55e1e5747293335ea2974e59fb3189d74e9d4
version 0006

- AHAB tree version: https://bitbucket.sw.nxp.com/projects/MCUSEC/repos/ahab/browse?at=refs%2Ftags%2FSECO_FW_QXPB0_V06
- Build: Bamboo QX FW build #99 https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-99, all build artifacts attached to plan

Signing request

- Signing certificate = ./imx8x/crts/IMXQXP0101.pem
- Data to be signed   = container-201806261453-1d985170c41d31e53c63cd1f7cf254a57bd13d36.bin

New in version 0006:
 High level summary:
  main reason for this release is a fix for the JTAG match (message attach request)

 By the details:
- AHAB-344: Update FW version to 0006
- AHAB-337: use fetched ADM status1 value for attach req handling
- AHAB-228,AHAB-296: fix issue on QX index

================================================================================

Tag SECO_FW_QXPB0_V05

commit: 101e7c63a4f9cf1a86c5328eea4aead1d7a07e49
version 5

- AHAB tree version: https://bitbucket.sw.nxp.com/projects/MCUSEC/repos/ahab/browse?at=refs%2Ftags%2FAHAB_FW_QX_version_5
- Build: Bamboo QX FW build #96 https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-96, all build artifacts attached to plan

Signing request

- Signing certificate = ./imx8x/crts/IMXQXP0101.pem
- Data to be signed   = container-201806221354-4554ab7d9d7894e8fc5d4b151ca05e2f618984b2.bin

New in version 5:
- AHAB-344:  Update FW version to 5
- AHAB-342: RNG initialization
- AHAB-294: Support ENABLE DEBUG message
- AHAB-341: support of GET EVENT message
- AHAB-296 : support of WRITE SECURE FUSE message
- AHAB-331: FW container parser supports DEK image
- AHAB-337: support of ATTACH DEBUG message
- AHAB-335: SNVS power button handling
- AHAB-330: Message Assign JR Request
- AHAB-329: bit 31 of version log indicates a dirty build
- AHAB-327: support of GET CHIP INFO message
- AHAB-243: support RETURN LIFE CYCLE message

================================================================================

Tag AHAB_FW_QX_version_4 / SECO_FW_QXPB0_V04

commit: 063912b6cfdcd6bb79ddb942051a8b7264f9e3b7
version 4

-	AHAB tree version: https://bitbucket.sw.nxp.com/projects/MCUSEC/repos/ahab/browse?at=refs%2Ftags%2FAHAB_FW_QX_version_4
-	Build: Bamboo QX FW build #58 https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-58, all build artifacts attached to plan

New in version 4:

o AHAB-228: write_common_fuse - verify that fuse is not in InFieldSecurityFuses list
o AHAB-187: ADM active kick is self-clear. Fix 24h reset issue due to ADM kick not properly handled in SECO
o AHAB-223: add Certificate support
o AHAB-222: add P256 & P521 support

================================================================================

Tag AHAB_FW_QX_drop_3 / SECO_FW_QXPB0_V03

commit: 041c9f925c9bc00982eeffe1f1c77cbc2fc96899
version 3

Drop 3 below:
�	AHAB tree version: tag AHAB_FW_QX_drop_3, https://bitbucket.sw.nxp.com/projects/MCUSEC/repos/ahab/browse?at=refs%2Ftags%2FAHAB_FW_QX_drop_3
�	Build: Bamboo QX FW build #51 https://bamboo1.sw.nxp.com/browse/IM-AHABFDP-51  , all build artifacts attached to plan


New in this version:

o Get FW version request

o SECO kick request

o Low power request (limited implementaion clearing adm_lpm_inhibit only: SECO FW will not be able to recover if the security subsystem effectively goes into lpm)

o SNVS read/write for the following:
	1. AHAB_SNVS_ID_INIT
	2. AHAB_SNVS_ID_POWER_OFF
	3. AHAB_SNVS_ID_SRTC
	4. AHAB_SNVS_ID_SRTC_CALB
	5. AHAB_SNVS_ID_SRTC_ALRM
	6. AHAB_SNVS_ID_RTC
	7. AHAB_SNVS_ID_RTC_CALB
	8. AHAB_SNVS_ID_RTC_ALRM
	9. AHAB_SNVS_ID_BTN_CONFIG
	10. AHAB_SNVS_ID_BTN_MASK
	11. AHAB_SNVS_ID_BTN
	12. AHAB_SNVS_ID_BTN_CLEAR
	13. AHAB_SNVS_ID_SSM_STATE

o Support for RSA 2, 3 & 4k
