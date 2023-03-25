# HackUSU
You will need the SFML to compile.
the easiest way will be with linux, run 

sudo apt-get install libsfml-dev 

compile on wsl1 with
export LIBGL_ALWAYS_INDIRECT=0
export DISPLAY=:0
run an xserver
g++ *.cpp  -lsfml-graphics -lsfml-window -lsfml-system -o main
./main

-SS March 22 2023
