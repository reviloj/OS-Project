
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "shapes.h"


// uint32_t charSize = 20;

void shapes_init(void){


	for(uint8_t i = 0; i < MAX_BULLETS; i++) {
		bulletArr[i] = (Object){{0, -10},Bullet};
	}

	for(uint8_t i = 0; i < MAX_ENEMIES; i++) {
		enemyArr[i] = (Object){{0, -10},Enemy};
	}



	enemyArr[MAX_ENEMIES-1] = (Object){{200, 300},Enemy};
	enemyArr[MAX_ENEMIES-2] = (Object){{300, 400},Enemy};
	curEnemyArr[0] = MAX_ENEMIES-1;
	for(uint8_t i = 0; i < MAX_ENEMIES; i++) {
		if(enemyArr[i].origin.y != -10) {
			addEnemy(i);
		}
	}

}

void addEnemy(uint8_t index) {
	curEnemyArr[curEnemy] = index;
	curEnemy += 1;
}

void delEnemy(uint8_t index) {
	curEnemy -= 1;
	curEnemyArr[index] = curEnemyArr[curEnemy];

}

// Shape ship = (Shape){
// 	{
// 	{{0, -3}, 0x000000FF},
// 	{{0, -2}, 0x000000FF},
// 	{{-1, -1}, 0x000000FF}, {{0, -1}, 0x000000FF}, {{1, -1}, 0x000000FF},
// 	{{-1, 0}, 0x000000FF}, {{0, 0}, 0x000000FF}, {{1, 0}, 0x000000FF},
// 	{{-2, 1}, 0x000000FF}, {{-1, 1}, 0x000000FF}, {{0, 1}, 0x000000FF}, {{1, 1}, 0x000000FF}, {{2, 1}, 0x000000FF},
// 	{{-2, 2}, 0x000000FF}, {{-1, 2}, 0x000000FF}, {{0, 2}, 0x000000FF}, {{1, 2}, 0x000000FF}, {{2, 2}, 0x000000FF}
// 	}, 18
	
// };

Object ship = (Object){
	{500, 600},
	Ship
};

// Object enemy = (Object){
// 	{200, 300},
// 	Enemy
// };

Shape objectShapes[3] = { 
	(Shape){{
	{{-4, 4}, 0x000000FF},{{4, 4}, 0x000000FF},
	{{-4, 3}, 0x000000FF},{{4, 3}, 0x000000FF}, {{-1, 3}, 0x00FF0000},{{1, 3}, 0x00FF0000},
	{{-4, 2}, 0x000000FF},{{4, 2}, 0x000000FF}, {{-1, 2}, 0x000000FF},{{1, 2}, 0x000000FF},{{-2, 2}, 0xFFFFFFFF},{{0, 2}, 0xFFFFFFFF},{{2, 2}, 0xFFFFFFFF},
	{{-4, 1}, 0x000000FF},{{4, 1}, 0x000000FF}, {{-1, 1}, 0xFFFFFFFF},{{1, 1}, 0xFFFFFFFF},{{-2, 1}, 0xFFFFFFFF},{{0, 1}, 0xFFFFFFFF},{{2, 1}, 0xFFFFFFFF},
	{{-4, 0}, 0x000000FF},{{4, 0}, 0x000000FF}, {{-1, 0}, 0xFFFFFFFF},{{1, 0}, 0xFFFFFFFF},{{-2, 0}, 0x000000FF},{{0, 0}, 0xFFFFFFFF},{{2, 0}, 0x000000FF},{{-3, 0}, 0x000000FF},{{3, 0}, 0x000000FF},
	{{-1, -1}, 0x00FF0000},{{1, -1}, 0x00FF0000},{{-2, -1}, 0x000000FF},{{0, -1}, 0x00FF0000},{{2, -1}, 0x000000FF},{{-3, -1}, 0x000000FF},{{3, -1}, 0x000000FF},
	{{-4, -2}, 0x000000FF},{{4, -2}, 0x000000FF}, {{-1, -2}, 0xFFFFFFFF},{{1, -2}, 0xFFFFFFFF},{{-2, -2}, 0x000000FF},{{0, -2}, 0xFFFFFFFF},{{2, -2}, 0x000000FF},{{-3, -2}, 0x000000FF},{{3, -2}, 0x000000FF},
	{{-4, -3}, 0x000000FF},{{4, -3}, 0x000000FF}, {{-1, -3}, 0x00FF0000},{{1, -3}, 0x00FF0000},{{0, -3}, 0x00FF0000}, {{-3, -3}, 0x000000FF}, {{3, -3}, 0x000000FF},
	{{-4,-4}, 0x000000FF},{{4,-4}, 0x000000FF}, {{0,-4}, 0x00FF0000},{{-3, -4}, 0x000000FF},{{3, -4}, 0x000000FF},
	}, 57},
	(Shape){{
		{{0, -3}, 0x000000FF},
		{{0, -2}, 0x000000FF},
		{{-1, -1}, 0x000000FF}, {{0, -1}, 0x000000FF}, {{1, -1}, 0x000000FF},
		{{-1, 0}, 0x000000FF}, {{0, 0}, 0x000000FF}, {{1, 0}, 0x000000FF},
		{{-2, 1}, 0x000000FF}, {{-1, 1}, 0x000000FF}, {{0, 1}, 0x000000FF}, {{1, 1}, 0x000000FF}, {{2, 1}, 0x000000FF},
		{{-2, 2}, 0x000000FF}, {{-1, 2}, 0x000000FF}, {{0, 2}, 0x000000FF}, {{1, 2}, 0x000000FF}, {{2, 2}, 0x000000FF}
		}, 18	
	},
	(Shape){
		{{{0, 0}, 0x000000FF}}, 1}
};

// {
// 	{{0, -3}, 0x000000FF},
// 	{{0, -2}, 0x000000FF},
// 	{{-1, -1}, 0x000000FF}, {{0, -1}, 0x000000FF}, {{1, -1}, 0x000000FF},
// 	{{-1, 0}, 0x000000FF}, {{0, 0}, 0x000000FF}, {{1, 0}, 0x000000FF},
// 	{{-2, 1}, 0x000000FF}, {{-1, 1}, 0x000000FF}, {{0, 1}, 0x000000FF}, {{1, 1}, 0x000000FF}, {{2, 1}, 0x000000FF},
// 	{{-2, 2}, 0x000000FF}, {{-1, 2}, 0x000000FF}, {{0, 2}, 0x000000FF}, {{1, 2}, 0x000000FF}, {{2, 2}, 0x000000FF}
// 	}	
// }
