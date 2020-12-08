all: main.o
	gcc -o main main.c

main.o: main.c
	gcc -c main.c

.PHONY: all run clean

run:
	./main

clean:
	rm *.o
	rm main