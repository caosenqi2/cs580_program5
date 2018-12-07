FLAG= -g
all: a.out
run: ./a.out
a.out: vector.o list.o stack.o queue.o t.o
	gcc $(FLAG) vector.o list.o stack.o queue.o program5.o -o a.out
memcheck: 
	valgrind ./a.out
program5.o: program5.c profile.c queue.h vector.h list.h data.h
	gcc $(FLAG) -c program5.c profile.c -o program5.o
t.o: t.c vector.h list.h stack.h queue.h
	gcc $(FLAG) -c t.c -o t.o
queue.o: queue.c queue.h vector.h list.h data.h
	gcc $(FLAG) -c queue.c -o queue.o
stack.o: stack.c stack.h vector.h list.h data.h
	gcc $(FLAG) -c stack.c -o stack.o	
vector.o: vector.c vector.h data.h
	gcc $(FLAG) -c vector.c -o vector.o
list.o: list.c list.h data.h
	gcc $(FLAG) -c list.c -o list.o
clean:
	rm -rf *.o
