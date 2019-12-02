/*
 * Copyright (c) 2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __SQ_MHU_H__
#define __SQ_MHU_H__

#include <stdint.h>

void mhu_secure_message_start(unsigned int slot_id);
void mhu_secure_message_send(unsigned int slot_id);
uint32_t mhu_secure_message_wait(void);
void mhu_secure_message_end(unsigned int slot_id);

void mhu_secure_init(void);

#endif	/* __SQ_MHU_H__ */
