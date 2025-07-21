q1: q1.o
	gcc q1.o -lpthread -o q1

q1.o: q1.c
	gcc -lpthread -c q1.c
