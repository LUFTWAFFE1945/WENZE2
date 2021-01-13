all:
	cc main.c wenze.c -o snake -Wall --pedantic

test: all
	./snake

memory: all
	valgrind ./snake