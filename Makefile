# Author: Viraj R Chitnis
# Date: 02/12/18
# Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.

# set the compiler and compiler flags
CXX=g++
CXXFLAGS=-Wall -pedantic -g -std=c++17
CC=$(CXX)
CFLAGS=$(CXXFLAGS)
EXECUTABLE=binary-tree

# Compile the entire project
all: $(EXECUTABLE)

# Compile and run the entire project
run: all
	./$(EXECUTABLE)

$(EXECUTABLE): binary-tree.o Node.o BinaryTree.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) binary-tree.o Node.o BinaryTree.o

binary-tree.o: binary-tree.cpp
	$(CC) $(CFLAGS) -c binary-tree.cpp

Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp

BinaryTree.o: BinaryTree.h BinaryTree.cpp
	$(CC) $(CFLAGS) -c BinaryTree.cpp

# Clean up the source code directory
clean:
	-rm *.o
	-rm $(EXECUTABLE)
	-rm -r *.dSYM
