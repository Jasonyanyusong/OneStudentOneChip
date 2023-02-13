deps_config := \
	src/device/Kconfig \
	src/memory/Kconfig \
	/home/parallels/OneStudentOneChip/pa1/nemu/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
