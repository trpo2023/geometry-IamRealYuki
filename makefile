cflags = -Wall -Werror
compflags = -MMD

all: myprog
myprog: main.c
	gcc cflags -o myprog main.c	

run:	
	./myprog




