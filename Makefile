build: timer

timer: main.c Itoa/itoa.o print/printv.o
	$(CC) -Wall -o timer $^

print/printv.o:
	make -C print

Itoa/itoa.o:
	make -C Itoa

clean:
	rm -rf *.o timer timer.wasm Itoa/*.o print/*.o

INSTALL_DIR ?= /usr/local/bin
install: build
	install timer $(INSTALL_DIR)

.PHONY: build clean install
