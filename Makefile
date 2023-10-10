timer: main.c Itoa/itoa.o print/printv.o
	$(CC) -Wall -o timer $^

print/printv.o:
	make -C print

Itoa/itoa.o:
	make -C Itoa

clean:
	rm -rf *.o timer timer.wasm
