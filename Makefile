PROJECTS = firmware

.PHONY = libopencm3 clean

all: 	make -C libopencm3
		make -C src
clean:	$(MAKE) -C libopencm3 clean
		$(MAKE) -C src clean
