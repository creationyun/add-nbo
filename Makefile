all: add-nbo

add-nbo: add-nbo.o

add-nbo.o: add-nbo.c

clean:
	rm -f add-nbo *.o
