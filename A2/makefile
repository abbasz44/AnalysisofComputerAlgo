all: add

add:P11.c P12.c P21.c P22.c P23.c main.c
	gcc -g -Wall P11.c -o P11.o -c
	gcc -g -Wall P12.c -o P12.o -c
	gcc -g -Wall P21.c -o P21.o -c
	gcc -g -Wall P22.c -o P22.o -c
	gcc -g -Wall P23.c -o P23.o -c
	gcc -g -Wall main.c -o main.o -c
	gcc -g -o test P11.o P12.o P21.o P22.o P23.o main.o
clean:
	rm *.o
	rm test