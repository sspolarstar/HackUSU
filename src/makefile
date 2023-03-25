all: compile link

compile:
	g++	-Isrc/include -c *.cpp -Wall -Wextra

link:
	g++ *.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
