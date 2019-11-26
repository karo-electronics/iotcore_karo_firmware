#
# Copyright 2019 Lothar Waßmann <LW@KARO-electronics.de>
#
# SPDX-License-Identifier:      GPL-2.0+
#

ifdef CONFIG_SPL_BUILD
obj-y += helper.o wait_ddrphy_training_complete.o
obj-$(CONFIG_TARGET_KARO_TX8MM_EVK) += ddrphy_train.o ddr_init.o
endif
