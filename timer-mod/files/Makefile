obj-m := timer.o
SRC := $(shell pwd)
all:
[tab][tab]$(MAKE) -C $(KERNEL_SRC) M=$(SRC)
modules_install:
[tab][tab]$(MAKE) -C $(KERNEL_SRC) M=$(SRC) modules_install
clean:
[tab][tab]rm -f *.o *~ core .depend .*.cmd *.ko *.mod.c
[tab][tab]rm -f Module.markers Module.symvers modules.order
[tab][tab]rm -rf .tmp_versions Modules.symvers
