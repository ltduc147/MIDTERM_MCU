/*
 * fsm_button_longpress.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "fsm_button_longpress.h"

void fsm_button_longpress_run(){
	switch (status) {
		case LONG_INC_STATE:
			if (timer2_flag == 1){
				setTimer2(1000);
				counter++;
				display7SEG();
			}
			if (!isButtonLongPress(1)){
				status = INC_STATE;
				setTimer3(TIME_OUT);
			}
			break;
		case LONG_DEC_STATE:
			if (timer2_flag == 1){
				setTimer2(1000);
				counter--;
				display7SEG();
			}
			if (!isButtonLongPress(2)){
				status = DEC_STATE;
				setTimer3(TIME_OUT);
			}
			break;
		default:
			break;

	}
}
