all: program5

program5: program5.o vector.o list.o profile.o
	gcc -Wall -g program5.o vector.o list.o profile.o -o program5

program5.o: program5.c vector.h list.h profile.h data.h
	gcc -Wall -g -c program5.c -o program5.o

vector.o: vector.c vector.h
	gcc -Wall -g -c vector.c -o vector.o

list.o: list.c list.h
	gcc -Wall -g -c list.c -o list.o

profile.o:profile.c profile.h
	gcc -Wall -g -c profile.c -o profile.o 

run: all
	./program5

checkmem: all
	valgrind -v ./program5

clean: 
	rm *.o program5


