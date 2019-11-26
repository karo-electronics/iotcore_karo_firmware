/*
 * (C) Copyright 2019 Lothar Waßmann <LW@KARO-electronics.de>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <environment.h>
#include "karo.h"

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_UBOOT_IGNORE_ENV
void karo_env_cleanup(void)
{
	printf("Using default environment\n");
	set_default_env(NULL);
}
#else
static const char * const cleanup_vars[] = {
	"bootargs",
	"fileaddr",
	"filesize",
	"safeboot",
	"wdreset",
};

void karo_env_cleanup(void)
{
	size_t i;

	debug("%s@%d: Cleaning up environment\n", __func__, __LINE__);
	for (i = 0; i < ARRAY_SIZE(cleanup_vars); i++) {
		if (env_get(cleanup_vars[i]) != NULL)
			env_set(cleanup_vars[i], NULL);
	}
}
#endif
