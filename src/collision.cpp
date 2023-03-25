#include "headers/collision.hpp"
#include <cmath>

Collided map_collision(Position pos, MapManager& mapRef){
    Collided output;
    Map map = mapRef.getMap();
	
    //MakeSure the character is in the array!   
    int x = 0, y = 0;
    pos.y += CELL_SIZE;
   
	if (0 <= pos.x/CELL_SIZE && 0 <= pos.y/CELL_SIZE && MAX_MAP_HEIGHT >= pos.y/CELL_SIZE && MAX_MAP_WIDTH >= pos.x/CELL_SIZE) {	
        for (int a = 0; a < 4; a++) {
			switch (a) {
			case LEFT: 
				x = static_cast<int>((pos.x - 3) / CELL_SIZE);
				y = static_cast<int>((pos.y) / CELL_SIZE);
				break;
			case RIGHT:
				x = static_cast<int>((pos.x + 3 + CELL_SIZE) / CELL_SIZE);
				y = static_cast<int>(pos.y / CELL_SIZE);
				break;
			case UP:
				x = static_cast<int>((pos.x -2) / CELL_SIZE);
				y = static_cast<int>((pos.y - 4 ) / CELL_SIZE);
				break;
			case DOWN:
                x = static_cast<int>((pos.x -2)/CELL_SIZE);
				y = static_cast<int>(((pos.y + CELL_SIZE + 3) / CELL_SIZE));
				if(pos.y + 20 >= 0 && pos.y < 0){
					y = 0;
				}
				break;
			}
			output.wall[a] = Cell::wall == map.map[y][x] || Cell::bush == map.map[y][x] || Cell::flower == map.map[y][x] || Cell::grass == map.map[y][x];

			//output.nextArea[a] = Cell::stair == map.map[y][x];
		}

	}	
	return output;
}