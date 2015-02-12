CFLAGS=-Wall -Werror -fPIC -O2

everybody-root.so: everybody-root.o
	$(CC) -shared -o everybody-root.so everybody-root.o -ldl

clean:
	rm -f *.o *.so
