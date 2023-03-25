#pragma once
#include "../../headers/global.hpp"

            std::array<std::string, MAX_MAP_HEIGHT> firstMap = {
                " SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS ",
                " SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS ",
                " SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS ",
                " SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS ",
                " SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS ",
                " SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS ",
                " SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSISSSSSSSSSSSSSSSSSSSSSSSSS ",
                " KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK ",
                " WKWKWKWKWKWKWKWKWKWKWKWKWKWKWKKKKKWKWKWKWKWKWKWKWKWKWKWKWK ",
                " KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK ",
                " WKWKWKWKWKWKWKWKWKWKWKWKWKWKKKKKKKKKWKWKWKWKWKWKWKWKWKWKWK ",
                " KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK ",
                " GGGGGGGGGGGGGGGGGGG#CCCCBCCCCCCCCCCCCCBCCCC#GGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGG#CCCCBCCCCCCCCCCCCCBCCCC#GGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGG#CCCCBCCCCCCCCCCCCCBCCCC#GGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGG#CCCCBCCCCCCCCCCCCCBCCCC#GGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGG#####CCCCCCCCCCCCC#####GGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGG6GGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGG123GGGG456GGGG*L000000000R*GGGG456GG123GGGGGGGG ",
                " GGGGGGGGGGG456GGG123GGGG#CCCCCCCCCCCCC#GGGG123G456GGGGGGGG ",
                " GGGGGGGGGGGGGGGGG456GGG#CCCCCCCCCCCCCCC#GGG456GGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123G#CCCCCCCCCCCCCCCCC#G123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGG123GGG456G#CCCCCCCCCCCCCCCCC#G456GGG123GGGGGGG ",
                " GGGGGGGGGGGG456GGGGGGG#CCCCCCCCCCCCCCCCC#GGGGGGG456GGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GG#CCCCCCCCCCCCCCC#GG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGG#CCCCCCCCCCCCC#GGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGG6GGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGG123GGGG456GGGG*L000000000R*GGGG456GG123GGGGGGGG ",
                " GGGGGGGGGGG456GGG123GGGG#CCCCCCCCCCCCC#GGGG123G456GGGGGGGG ",
                " GGGGGGGGGGGGGGGGG456GGG#CCCCCCCCCCCCCCC#GGG456GGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123G#CCCCCCCCCCCCCCCCC#G123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGG123GGG456G#CCCCCCCCCCCCCCCCC#G456GGG123GGGGGGG ",
                " GGGGGGGGGGGG456GGGGGGG#CCCCCCCCCCCCCCCCC#GGGGGGG456GGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GG#CCCCCCCCCCCCCCC#GG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGG#CCCCCCCCCCCCC#GGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG123GGG#########GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG456GG#DDDDDDDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDDDD#GGGGGGGGGGGGG#########################GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDDDDDD#G123GGGGGGGG#DDDDDDDDDDDDDDDDDDDDDDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDDDDDD#G456GGGGGGGG#DDDDDDDDDDDDDDDDDDDDDDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDDDDDD#GGGGGGGGGGGG#DDDDDDTTTTTTTTTTTTTTTDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGG123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDDDDDD#GGGGGGGGGGGG#DDDDDDTDDDTDDDDDDDDDTDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123G456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG123G#DDDDDDDDDDDDDDD#GGGGGGGGGGGG#######TTDDDDDDDDDDDDTDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG456G#DDDDDDDDDDDDDDD#GGGGGGGGGGGGGGGGGGG#TTTTDDDDDTDDDTDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDDDDDD#GGGGGGGGGGGGGGGGGGG#DDDTDTDDDTDDDTDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDDDDDD#GGGGGGGGGGGGGGGGGGG#DDDTDTDDDTDDDTDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDDDD#GGGGGGGGGGGGGGGGGGGG#DDDTTTDDDTTTTTDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDD#GGGGGGGGGGGGGGGGGGGGG#DDDDDDDDDDDDDDDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG123GGGGGGG#DDDDDDDDD#GGGGG123GGGGGGGGGGGGGG#DDDDDDDDDDDDDDDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG456GGGGGGGG#DDDDDDD#GGGGGG456GGGGGGGGGGGGGGG###TTTDDDTTT#####GGGGGGGGGGGGGGGGGGGGGGGG###############GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG123GGGG#L000000000R#GGGG123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#VVVVVVV#GGGGGGGGGGGGGGGGGGGGGGGGGG#DDDDDDDDD#GGGGGGGGGGGGGGGGGGGGGGGGGGG#CCBCBCBCBCBCCCC#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGG456GGGG*L000000000R*GGGG456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#CCCCCCC#GGGGGGGGGGGGGGGGGGGGGGGGGG#VVVVVVVVV############################CCCCCCCCCCCCCCCCC#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG123G#L000000000R#G123GGGGGGGGGG123GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#CCCCCCC#GGGGGGGGGGGGGGGGGGGGGGGGGG#CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCBCBCBCBCBCCCCC#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGG456G*L000000000R*G456GGGGGGGGGG456GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#CCCCCCC#GGGGGGGGGGGGGGGGGGGGGGGGGG#CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCPCC#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGG#L000000000R#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#CCCCCCC###########################CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCPCC#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGG*L000000000R*########################################################CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCBCBCBCBCBCCCCC#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGG123GG#CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC###############################CCCCCCCCCCCCCCCCC#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGG456GG#CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC##GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#CCBCBCBCBCBCCCC#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGG#CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC##GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG###############GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGG#CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC###############################GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGG##############################CCCCCCCCC###################################GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#CCCpCCC#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
            }; 


            std::array<std::string, MAX_MAP_HEIGHT> secondMap = {  
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGnGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
                " GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGpGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG ",
            };
 