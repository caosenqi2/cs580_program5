FLAG= -g
all: a
run: 
	gcc $(FLAG) vector.o list.o stack.o queue.o profile.o program5.o -o a
	./a
a: vector.o list.o stack.o queue.o program5.o profile.o
	gcc $(FLAG) vector.o list.o stack.o queue.o profile.o program5.o -o a
memcheck: 
	valgrind ./a
program5.o: program5.c queue.h vector.h list.h stack.h data.h
	gcc $(FLAG) -c program5.c -o program5.o
profile.o: profile.c queue.h vector.h list.h data.h
	gcc $(FLAG) -c profile.c -o profile.o	
queue.o: queue.c queue.h vector.h list.h data.h
	gcc $(FLAG) -c queue.c -o queue.o
stack.o: stack.c stack.h vector.h list.h data.h
	gcc $(FLAG) -c stack.c -o stack.o	
vector.o: vector.c vector.h data.h
	gcc $(FLAG) -c vector.c -o vector.o
list.o: list.c list.h data.h
	gcc $(FLAG) -c list.c -o list.o
clean:
	rm -rf *.o a
