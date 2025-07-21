q2: q2.o
	gcc q2.o -lpthread -o q2

q2.o: q2.c
	gcc -lpthread -c q2.c
