q3: q3.o
	gcc q3.o -lpthread -o q3 

q3.o: q3.c
	gcc -lpthread -c q3.c
