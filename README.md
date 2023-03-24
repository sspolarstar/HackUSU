# Test-SFML

Test/scratch world in SFML preperations for the hackathon

------|   c++/general  |--------------------------------
C:\Users\scott\Documents\code\Cpp\Libraries\SFML-2.5.1\SFML-2.5.1\include

------|  C++ preprocessor DEFF |--------------------------
SFML_STATIC

------|  linker General additional lib dir |------------------------
C:\Users\scott\Documents\code\Cpp\Libraries\SFML-2.5.1\SFML-2.5.1\lib

------|  linker input additional depp  |-----------------
sfml-graphics-s-d.lib
sfml-window-s-d.lib
sfml-system-s-d.lib
sfml-main-d.lib
opengl32.lib
freetype.lib
winmm.lib
gdi32.lib

compile on wsl1 with
export LIBGL_ALWAYS_INDIRECT=0
export DISPLAY=:0
run an xserver
g++ *.cpp  -lsfml-graphics -lsfml-window -lsfml-system -o maze
./maze

-SS March 22 2023
