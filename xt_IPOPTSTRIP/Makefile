DEBUG=0

MODULES_DIR	:= /lib/modules/$(shell uname -r)
KERNEL_DIR	:= ${MODULES_DIR}/build

ifeq ($(DEBUG),1)
	ccflags-y	:= -DDEBUG
endif

obj-m += xt_IPOPTSTRIP.o

all:
	make -C ${KERNEL_DIR} M=$$PWD;
modules:
	make -C ${KERNEL_DIR} M=$$PWD $@;
modules_install:
	make -C ${KERNEL_DIR} M=$$PWD $@;
clean:
	make -C ${KERNEL_DIR} M=$$PWD $@;
