/*
 * led_display.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "led_display.h"


void display7SEG(){
	if (counter > 9){
		counter = 0;
	}
	if (counter < 0){
		counter = 9;
	}
	switch (counter) {
		case 0:
			GPIOB->ODR = 0x80ff;
			break;
		case 1:
			GPIOB->ODR = 0xf2ff;
			break;
		case 2:
			GPIOB->ODR = 0x48ff;
			break;
		case 3:
			GPIOB->ODR = 0x60ff;
			break;
		case 4:
			GPIOB->ODR = 0x32ff;
			break;
		case 5:
			GPIOB->ODR = 0x24ff;
			break;
		case 6:
			GPIOB->ODR = 0x04ff;
			break;
		case 7:
			GPIOB->ODR = 0xf0ff;
			break;
		case 8:
			GPIOB->ODR = 0x00ff;
			break;
		case 9:
			GPIOB->ODR = 0x20ff;
			break;
		default:
			break;
	}
}

