
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "shapes.h"


uint32_t charSize = 20;

void fonts_init(void){
	characters[0] = (FontCharacter){{{{0, 20}, {10, 0}}, {{20, 20}, {10, 0}}, {{5, 12}, {15, 12}}}, 3};
	characters[1] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 0}, {17, 0}}, {{17, 0}, {20, 3}}, {{20, 3}, {20, 7}}, {{20, 7}, {17, 10}}, {{17, 10}, {0, 10}}, {{17, 10}, {20, 13}}, {{20, 13}, {20, 17}}, {{20, 17}, {17, 20}}, {{17, 20}, {0, 20}}}, 10};
	characters[2] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 0}, {20, 0}}, {{0, 20}, {20, 20}}}, 3};
	characters[3] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 0}, {17, 0}}, {{17, 0}, {20, 3}}, {{20, 3}, {20, 17}}, {{20, 17}, {17, 20}}, {{17, 20}, {0, 20}}}, 6};
	characters[4] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 0}, {20, 0}}, {{0, 20}, {20, 20}}, {{0, 10}, {20, 10}}}, 4};
	characters[5] = (FontCharacter){{{{0, 0}, {20, 0}}, {{0, 10}, {20, 10}}, {{0, 0}, {0, 20}}}, 3};
	characters[6] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 0}, {20, 0}}, {{0, 20}, {20, 20}}, {{20, 20}, {20, 13}}, {{13, 13}, {20, 13}}}, 5};
	characters[7] = (FontCharacter){{{{0, 0}, {0, 20}}, {{20, 0}, {20, 20}}, {{0, 10}, {20, 10}}}, 3};
	characters[8] = (FontCharacter){{{{10, 0}, {10, 20}}, {{0, 0}, {20, 0}}, {{0, 20}, {20, 20}}}, 3};
	characters[9] = (FontCharacter){{{{10, 0}, {10, 20}}, {{0, 0}, {20, 0}}, {{0, 20}, {10, 20}}, {{0, 20}, {0, 13}}}, 4};
	characters[10] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 10}, {20, 0}}, {{0, 10}, {20, 20}}}, 3};
	characters[11] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 20}, {20, 20}}}, 2};
	characters[12] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 0}, {10, 20}}, {{10, 20}, {20, 0}}, {{20, 0}, {20, 20}}}, 4};
	characters[13] = (FontCharacter){{{{0, 0}, {0, 20}}, {{20, 0}, {0, 20}}, {{20, 0}, {20, 20}}}, 3};
	characters[14] = (FontCharacter){{{{0, 3}, {0, 17}}, {{3, 0}, {0, 3}}, {{0, 17}, {3, 20}}, {{3, 0}, {17, 0}}, {{17, 0}, {20, 3}}, {{20, 3}, {20, 17}}, {{20, 17}, {17, 20}}, {{17, 20}, {3, 20}}}, 8};
	characters[15] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 0}, {20, 0}}, {{20, 0}, {20, 10}}, {{20, 10}, {0, 10}}}, 4};
	characters[16] = (FontCharacter){{{{0, 3}, {0, 17}}, {{3, 0}, {0, 3}}, {{0, 17}, {3, 20}}, {{3, 0}, {17, 0}}, {{17, 0}, {20, 3}}, {{20, 3}, {20, 17}}, {{20, 17}, {17, 20}}, {{17, 20}, {3, 20}}, {{20, 20}, {17, 17}}}, 9};
	characters[17] = (FontCharacter){{{{0, 0}, {0, 20}}, {{0, 0}, {17, 0}}, {{17, 0}, {20, 3}}, {{20, 3}, {20, 7}}, {{20, 7}, {17, 10}}, {{17, 10}, {0, 10}}, {{10, 10}, {20, 20}}}, 10};
	characters[18] = (FontCharacter){{{{20, 0}, {3, 0}}, {{3, 0}, {0, 3}}, {{0, 3}, {0, 7}}, {{0, 7}, {3, 10}}, {{3, 10}, {17, 10}}, {{17, 10}, {20, 13}}, {{20, 13}, {20, 17}}, {{20, 17}, {17, 20}}, {{17, 20}, {0, 20}}}, 9};
	characters[19] = (FontCharacter){{{{0, 0}, {20, 0}}, {{10, 0}, {10, 20}}}, 2};
	characters[20] = (FontCharacter){{{{0, 0}, {0, 17}}, {{0, 17}, {3, 20}}, {{3, 20}, {17, 20}}, {{17, 20}, {20, 17}}, {{20, 17}, {20, 0}}}, 5};
	characters[21] = (FontCharacter){{{{0, 0}, {10, 20}}, {{10, 20}, {20, 0}}}, 2};
	characters[22] = (FontCharacter){{{{0, 0}, {5, 20}}, {{5, 20}, {10, 0}}, {{10, 0}, {15, 20}}, {{15, 20}, {20, 0}}}, 4};
	characters[23] = (FontCharacter){{{{0, 0}, {20, 20}}, {{0, 20}, {20, 0}}}, 2};
	characters[24] = (FontCharacter){{{{0, 0}, {10, 10}}, {{10, 10}, {20, 0}}, {{10, 10}, {10, 20}}}, 3};
	characters[25] = (FontCharacter){{{{0, 0}, {20, 0}}, {{20, 0}, {0, 20}}, {{0, 20}, {20, 20}}}, 3};
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

Object enemy = (Object){
	{200, 300},
	Enemy
};

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
		{}, 0}
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
