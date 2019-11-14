/**
*   This file is part of os_labs
*   (https://github.com/rromanotero/os_labs).
*
*   Copyright (c) 2019 Rafael Roman Otero.
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
**/

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h> 
#include "system.h"
#include "hal/hal.h"
#include "drivers/delays/delays.h"
#include "alice.h"
#include "hal/shapes.h"
#include "drivers/uart/uart.h"
#include "./kprintf/kprintf.h"


/*
*     For some reason, GCC's built in memcpy doesn't work on the Physical device
*     (even though it works on QEMU), so until I figure this out,
*     here is a custom copy of memcpy
*/
void *memcpy(void *dest, void *src, size_t n){
	uint8_t *my_dest = (uint8_t *)dest;
	uint8_t *my_src = (uint8_t *)src;

	while (n--) {
		*my_dest++ = *my_src++;
	}

	return dest;
}

void wait_for_ten_secs(void);

uint32_t zoom_title=1;
uint32_t zoom_text=1;
const uint8_t maxBullets = 10;
bool changed=true;
unsigned long prevbullet = 0;

void main(){

	kprintf("\r\nenemyposy:%d",enemy.origin.y);

    hal_io_serial_init();
	shapes_init();

    if( hal_video_init() == HAL_FAILED ){
        while(true){
            hal_io_serial_puts( SerialA, "Failed initializing Video. Cannot continue.\n\r" );
            wait_for_ten_secs();
        }
    }

	//for(uint32_t i=0; i<SYSTEM_SCREEN_WIDTH - 5; i++)
	//	put_pixel_raw( i + SYSTEM_SCREEN_WIDTH * 45, 0xFFFFFFFF );
	
	// GAME LOOP (20 fps)
	while(true){
    	uint8_t c=0;
		uart0_nonblocking_getc(&c);
		if (c == 'a')
			ship.origin.x -= 10;
		if (c == 'd')
			ship.origin.x += 10;
		if (c == 'k'){
			if(get_system_timer() - prevbullet >= 250000) {
				for(uint8_t i = 0; i < MAX_BULLETS;i++) {
					if(bulletArr[i].origin.y <=0) {
						prevbullet = get_system_timer();
						bulletArr[i] = (Object){{ship.origin.x, ship.origin.y},Bullet};
						break;
					}
				}
			}
		}

		//clearDrawScreen();
		// drawShape(&enemy);
		drawShape(&ship);

		// drawShape(&enemy);
		for(uint8_t i = 0; i < MAX_ENEMIES; i++) {
			if(enemyArr[i].origin.y != -10) {
				drawShape(&enemyArr[i]);
			}
		}
		for(uint8_t i = 0; i<MAX_BULLETS;i++) {
			
			if(bulletArr[i].origin.y >=10) {
				drawShape(&bulletArr[i]);
				bool killed = false;
				for(uint8_t t = 0; t < MAX_ENEMIES; t++) {
					if(enemyArr[t].origin.y != -10) {
						// kprintf("\n\a%d",i);
						
						if((bulletArr[i].origin.y <= enemyArr[t].origin.y+20 && bulletArr[i].origin.y >= enemyArr[t].origin.y-20)
						&& (bulletArr[i].origin.x <= enemyArr[t].origin.x+20 && bulletArr[i].origin.x >= enemyArr[t].origin.x-20)){
							bulletArr[i].origin.y = 0;
							kprintf("\n\rkilled");
							killed=true;
						}
					}
				}
				if(!killed) {
					kprintf("\r\nbulletposy:%d",bulletArr[i].origin.y);
					bulletArr[i].origin.y -=10;
				}
			}
		}
		draw();
		hal_cpu_delay(50);
	}
    hal_io_serial_puts( SerialA, "It focking works\n\r" );

}


void wait_for_ten_secs(void){
    for(uint32_t i=0; i<10; i++)
        hal_cpu_delay(1000);
}
