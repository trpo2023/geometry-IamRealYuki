all: myprog
myprog: main.c
	gcc -Wall -Werror -o myprog main.c

run:	
	./myprog




