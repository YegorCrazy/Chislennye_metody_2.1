.PHONY: all clean again

all: main

main.o: main.c
	gcc -Wall -g -fsanitize=address -fsanitize=undefined -fsanitize=leak -c main.c -o main.o -lm

diff_eq.o: diff_eq.c
	gcc -Wall -g -fsanitize=address -fsanitize=undefined -fsanitize=leak -c diff_eq.c -o diff_eq.o -lm

main: main.o diff_eq.o
	gcc -Wall -g -fsanitize=address -fsanitize=undefined -fsanitize=leak diff_eq.o main.o -o main -lm

clean:
	rm -rf main *.o

again:
	make clean
	make all
