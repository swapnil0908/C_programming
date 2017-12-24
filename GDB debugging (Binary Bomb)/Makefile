all: defuseTheBomb checkmem clean

defuseTheBomb : hidden.o defuseMe.o bomb.o
	gcc -g -o defuseTheBomb hidden.o defuseMe.o bomb.o
defuseMe.o : defuseMe.c
	gcc -c defuseMe.c
bomb.o : bomb.c
	gcc -c  bomb.c

checkmem : program3B
	valgrind ./program3B

checkmem.exe : program3B.o
	gcc -g program3B.o -o checkmem 

checkmem.o : program3B.c 
	gcc -g -c program3B.c -o program3B.o


clean :	
	./trash.sh defuseMe.o bomb.o program3B.o defuseTheBomb checkmem.exe

