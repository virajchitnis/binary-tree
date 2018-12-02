# Author: Viraj R Chitnis
# Date: 02/12/18
# Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.

# set the compiler and compiler flags
CXX=g++
CXXFLAGS=-Wall -pedantic -g -std=c++17
CC=$(CXX)
CFLAGS=$(CXXFLAGS)

all: Node.o

Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp

# Clean up the source code directory
clean:
	-rm *.o
	-rm simplified-phonebook
	-rm -r *.dSYM
