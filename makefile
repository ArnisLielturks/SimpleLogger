#Compiler to use
CC=g++

all:
	$(CC) **/*.cpp -o main.o
clean:
	rm *.o
