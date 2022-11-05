/*
 * fsm_countdown.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "fsm_countdown.h"

void fsm_countdown_run(){
	switch (status){
		case NOBUTTON_STATE:
			if (timer2_flag == 1){
				setTimer2(1000);
				if (counter > 0){
					counter --;
				}
				display7SEG();
			}
			if (isButtonPress(0)){
				counter = 0;
				display7SEG();
				status = RESET_STATE;
				setTimer3(TIME_OUT);
			}
			if (isButtonPress(1)){
				counter++;
				display7SEG();
				status = INC_STATE;
				setTimer3(TIME_OUT);
			}

			if (isButtonPress(2)){
				counter--;
				display7SEG();
				status = DEC_STATE;
				setTimer3(TIME_OUT);
			}

			break;
		default:
			break;
	}
}
