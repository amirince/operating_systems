# list/Makefile
#
# Makefile for list implementation and test file.
#
# Amir Ince

list: list.c main.c 
	gcc list.c main.c -o list.exe
