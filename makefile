all: client.o control.o 
	gcc -o client client.o
	gcc -o control control.o	

client.o: client.c
	gcc -c client.c

control.o: control.c
	gcc -c control.c

clean:
	rm -rf *.o *~ client.o
	rm -rf *.0 *~ control.o
