# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
CC = g++
 
# ****************************************************
# Targets needed to bring the executable up to date
main: Test.o
	$(CC) -o main Test.o
 
# The main.o target can be written more simply
 
Test.o: Test.cpp MyRand.h Node.h Stack.h StackInterface.h
	$(CC) -c Test.cpp

clean:
	rm -vf *.o *.exe *.obj *.pdb *.ilk