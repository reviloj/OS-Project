
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
	// kprintf("\n\r%d",enemyArr[curEnemyArr[curEnemy]].origin.x);
	if(index!=curEnemy) {
		curEnemyArr[index] = curEnemyArr[curEnemy];
	}

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
	{500, 750},
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

Point objectSize[3] = { 
	(Point){(9*PIXEL_SIZE)/2,(9*PIXEL_SIZE)/2},
	(Point){0,0},
	(Point){0,0}
};

Point enemyPath[4][120] = {{{666.49, 753.818}, {651.689, 751.39}, {637.015, 748.287}, {622.499, 744.513}, {608.171, 740.078}, {594.062, 734.991}, {580.2, 729.262}, {566.616, 722.904}, {553.338, 715.929}, {540.393, 708.352}, 
	{527.81, 700.191}, {515.614, 691.46}, {503.831, 682.18}, {492.486, 672.369}, {481.603, 662.048}, {471.205, 651.239}, {461.313, 639.964}, {451.949, 628.248}, {443.131, 616.115}, {434.88, 603.59}, 
	{427.211, 590.7}, {420.142, 577.472}, {413.687, 563.933}, {407.859, 550.113}, {402.671, 536.04}, 
	{395.385, 512.117}, {393.079, 497.325}, {393.971, 482.38}, {398.021, 467.967}, {405.043, 454.744}, {414.716, 443.318}, {426.598, 434.209}, {440.145, 427.836}, {454.738, 424.489}, {469.708, 424.322}, 
	{484.372, 427.342}, {498.057, 433.411}, {510.14, 442.252}, {520.066, 453.46}, {527.381, 466.522}, {531.752, 480.841}, {532.978, 495.762}, {531.003, 510.603}, {525.917, 524.684}, {517.953, 537.361}, 
	{507.475, 548.055}, {494.963, 556.276}, {480.989, 561.649}, {466.192, 563.927}, {451.249, 563.007}, {436.844, 558.93}, {423.635, 551.882}, {412.226, 542.187}, {403.141, 530.288}, {396.793, 516.729}, 
	{396.793, 516.729}, {396.793, 501.729}, {396.793, 486.729}, {396.793, 471.729}, {396.793, 456.729}, {396.793, 441.729}, {396.793, 426.729}, {396.793, 411.729}, {396.793, 396.729}, {396.793, 381.729}, 
	{396.793, 366.729}, {396.793, 351.729}, {396.793, 336.729}, {396.793, 321.729}, {396.793, 306.729}, {396.793, 291.729}, {396.793, 276.729}, {396.793, 261.729}, {396.793, 246.729}, {396.793, 231.729}, 
	{396.793, 216.729}, {396.793, 201.729}, {396.793, 186.729}, {396.793, 171.729}, {396.793, 156.729}, {396.793, 141.729}, {396.793, 126.729}, {396.793, 111.729}, {396.793, 96.729}, {396.793, 81.729}, 
	{396.793, 66.729}, {396.793, 51.729}, {396.793, 36.729}, {396.793, 21.729}},
	
	{{390, 50}, {390, 65}, {390, 80}, {390, 95}, {390, 110}, {390, 125}, {390, 140}, 
	{390, 150}, {389.064, 164.961}, {386.269, 179.688}, {381.661, 193.953}, {375.31, 207.531}, {367.316, 220.212}, 
	{349, 239.85}, {337.571, 249.565}, {326.142, 259.279}, {314.713, 268.994}, {303.284, 278.709}, {291.855, 288.424}, {280.425, 298.138}, {268.996, 307.853}, {257.567, 317.568}, {246.138, 327.283}, 
	{234.709, 336.997}, {223.28, 346.712}, {211.851, 356.427}, {200.422, 366.141}, {188.993, 375.856}, {177.564, 385.571}, {166.135, 395.286}, 
	{155.44, 404.492}, {145.49, 415.687}, {137.802, 428.541}, {132.644, 442.603}, {130.198, 457.38}, {130.549, 472.354}, {133.685, 487}, {139.496, 500.805}, {147.779, 513.284}, {158.243, 524.001}, 
	{170.521, 532.58}, {184.182, 538.72}, {198.749, 542.205}, {213.711, 542.914}, {228.542, 540.822}, {242.723, 536.001}, {255.757, 528.622}, {267.187, 518.943}, {276.613, 507.302}, {283.704, 494.109}},
	// 72
	{{230, 250}, {228.135, 235.156}, {222.655, 221.234}, {213.901, 209.102}, {202.418, 199.512}, {188.919, 193.061}, {174.244, 190.15}, {159.305, 190.961}, {145.031, 195.442}, {132.31, 203.316}, 
	{121.931, 214.092}, {114.542, 227.1}, {110.6, 241.533}, {110.352, 256.492}, {113.813, 271.047}, {120.766, 284.294}, {130.781, 295.408}, {143.235, 303.699}, 
	{164.552, 310.638}, {179.104, 314.276}, {193.656, 317.914}, {208.209, 321.552}, {222.761, 325.19}, {237.313, 328.828}, {251.865, 332.466}, {266.417, 336.104}, {280.969, 339.742}, 
	{295.521, 343.38}, {310.074, 347.018}, {324.626, 350.656}, {339.178, 354.294}, {353.73, 357.932}, {368.282, 361.571}, {382.834, 365.209}, {397.386, 368.847}, {411.938, 372.485}, 
	{427.88, 378.138}, {441.476, 384.454}, {454.255, 392.294}, {466.046, 401.552}, {476.693, 412.106}, {486.054, 423.816}, {494.004, 436.526}, {500.439, 450.066}, {505.272, 464.258}, {508.438, 478.911}, 
	{510, 499}, {510, 514}, {510, 529}, {510, 544}, {510, 559}, {510, 574}, {510, 589}, {510, 604}, {510, 619}, {510, 634}, 
	{510, 649}, {510, 664}, {510, 679}, {510, 694}, {510, 709}, {510, 724}, {510, 739}, {510, 754}, {510, 769}, {510, 784}, {510, 799}, {510, 814}, {510, 829}, {510, 844}, {510, 859}, {510, 874}},
	// 121
	{{230, 250}, {228.135, 235.156}, {222.655, 221.234}, {213.901, 209.102}, {202.418, 199.512}, {188.919, 193.061}, {174.244, 190.15}, {159.305, 190.961}, {145.031, 195.442}, {132.31, 203.316}, 
	{121.931, 214.092}, {114.542, 227.1}, {110.6, 241.533}, {110.352, 256.492}, {113.813, 271.047}, {120.766, 284.294}, {130.781, 295.408}, {143.235, 303.699}, 
	{164.552, 310.638}, {179.104, 314.276}, {193.656, 317.914}, {208.209, 321.552}, {222.761, 325.19}, {237.313, 328.828}, {251.865, 332.466}, {266.417, 336.104}, {280.969, 339.742}, 
	{295.521, 343.38}, {310.074, 347.018}, {324.626, 350.656}, {339.178, 354.294}, {353.73, 357.932}, {368.282, 361.571}, {382.834, 365.209}, {397.386, 368.847}, {411.938, 372.485}, 
	{427.88, 378.138}, {441.476, 384.454}, {454.255, 392.294}, {466.046, 401.552}, {476.693, 412.106}, {486.054, 423.816}, {494.004, 436.526}, {500.439, 450.066}, {505.272, 464.258}, {508.438, 478.911}, 
	{510, 499}, {510, 514}, {510, 529}, {510, 544}, {510, 559}, {510, 574}, {510, 589}, {510, 604}, {510, 619}, {510, 634}, 
	{510, 649}, 
	{510, 670}, {509.064, 684.961}, {506.269, 699.688}, {501.661, 713.953}, {495.31, 727.531}, {487.316, 740.212}, {477.803, 751.797}, {466.92, 762.105}, {454.836, 770.977}, {441.741, 778.272}, 
	{427.839, 783.878}, {413.346, 787.707}, {398.488, 789.699}, {383.499, 789.824}, {368.61, 788.078}, {354.056, 784.49}, {340.062, 779.116}, {326.848, 772.038}, {314.619, 763.369}, {303.567, 753.242}, 
	{293.863, 741.817}, {285.659, 729.27}, {279.084, 715.799}, {274.239, 701.614}, {271.201, 686.934}, {270.017, 671.991}, {270.704, 657.017}, {273.254, 642.245}, {277.625, 627.906}, {283.75, 614.224}, 
	{291.533, 601.413}, {300.852, 589.671}, {311.563, 579.184}, {323.497, 570.113}, {336.469, 562.601}, {350.277, 556.765}, {364.704, 552.696}, {379.527, 550.458}, {394.512, 550.085}, {409.427, 551.583}, 
	{424.039, 554.929}, {438.12, 560.071}, {451.45, 566.928}, {463.821, 575.393}, {475.04, 585.335}, {484.932, 596.598}, {493.343, 609.006}, {500.141, 622.367}, {505.22, 636.47}, {508.502, 651.097}, 
	{510, 679}, {510, 694}, {510, 709}, {510, 724}, {510, 739}, {510, 754}, {510, 769}, {510, 784}, {510, 799}, {510, 814}, {510, 829}, {510, 844}, {510, 859}, {510, 874}}};
