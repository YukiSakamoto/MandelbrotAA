CC=gcc
CFLAGS=-O3

all : main.c
	$(CC) $(CFLAGS) main.c -o main.x

run:
	./main.x

make_readme: main.x
	echo "AA Mandelbrot set" > README.txt
	echo "==================================================" >> README.txt
	./main.x >> README.txt

