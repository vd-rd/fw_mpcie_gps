PROJECTS = firmware

.PHONY = libopencm3 clean

all: 	$(MAKE) -C libopencm3
		$(MAKE) -C src
clean:	$(MAKE) -C libopencm3 clean
		$(MAKE) -C src clean
