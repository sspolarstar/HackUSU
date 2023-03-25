all: compile link

compile:
	g++	-Isrc/include -c *.cpp -Ofast -march=native

link:
	g++ *.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
