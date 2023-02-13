deps_config := \
	src/device/Kconfig \
	src/memory/Kconfig \
	/home/yanyusong/OneStudentOneChip/pa1/nemu/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
