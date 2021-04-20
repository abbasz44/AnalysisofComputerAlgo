all: add

add:p11.c p12.c p21.c p22.c main.c
	gcc -g -Wall p11.c -o p11.o -c
	gcc -g -Wall p12.c -o p12.o -c
	gcc -g -Wall p21.c -o p21.o -c
	gcc -g -Wall p22.c -o p22.o -c
	gcc -g -Wall main.c -o main.o -c
	gcc -g -o test p11.o p12.o p21.o p22.o main.o
clean:
	rm *.o
	rm test
