#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <array>
//static float Time_Remaining = 900000.0 ;


constexpr unsigned char LEFT  = 0;
constexpr unsigned char RIGHT = 1;
constexpr unsigned char UP    = 2;
constexpr unsigned char DOWN  = 3;

constexpr unsigned short VIEW_HIGHT = 400;
constexpr unsigned short VIEW_WIDTH = 400;

constexpr unsigned short MAX_MAP_HEIGHT = 300;
constexpr unsigned short MAX_MAP_WIDTH = 300;
constexpr unsigned char CELL_SIZE = 16;
//constexpr unsigned char
enum class Cell {
    empty,
    wall,
    stair,
    grass,
    Left_rail,
    Right_rail,
    concrete,
    flower,
    bush,

};


struct Collided {
	bool wall[4] = { 0,0,0,0 };
	bool enemy[4] = { 0,0,0,0 };
	bool nextArea[4] = { 0,0,0,0 };

};


struct Map{
    int level;
    std::array<std::array<Cell, MAX_MAP_HEIGHT>, MAX_MAP_WIDTH> map;

    Map(std::array<std::array<Cell, MAX_MAP_HEIGHT>, MAX_MAP_WIDTH> map, int level){
        this->level = level;
        this->map = map;
    }
    Map(){
        
    }
};



struct Position{
    
    float x, y;

    Position(float x, float y){
        this->x = x;
        this->y = y;
    }
    Position(){
        this->x=0.0;
        this->y=0.0;
    }
    void setPosition(float x, float y){
        setPosition({x,y});
    }
    void setPosition(Position position){
        this->x = position.x;
        this->y = position.y;
    }

    Position operator+(Position &pos){
        Position position;
        position.x += pos.x;
        position.y += pos.y;
        return position;
    }

};