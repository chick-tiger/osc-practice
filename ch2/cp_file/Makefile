obj-m += cp_file.c
all:
	make -C /lib/modules/$(shell uname -r)/build -I/usr/src/linux-headers-$(shell uname -r)/include M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
