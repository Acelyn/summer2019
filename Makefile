
obj-m += enable_ccr.o
 
all:
	make -C /lib/modules/4.19.42-v7+/build M=$(PWD) modules
	#make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
 
clean:
	make -C /lib/modules/4.19.42-v7+/build M=$(PWD) clean
	#make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
