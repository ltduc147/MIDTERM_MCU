/*
 * fsm_button_normal.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "fsm_button_normal.h"

void fsm_button_normal_run(){
	switch (status) {
		case RESET_STATE:
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

			if (isButtonPress(0)){
				counter = 0;
				display7SEG();
				setTimer3(TIME_OUT);
			}
			if (timer3_flag && !isButtonPress(0) && !isButtonPress(1) && !isButtonPress(2)){
				setTimer2(100);
				status = NOBUTTON_STATE;
			}

			break;
		case INC_STATE:
			if (isButtonPress(1)){
				counter++;
				display7SEG();
				setTimer3(TIME_OUT);
			}

			if (isButtonPress(2)){
				counter--;
				display7SEG();
				status = DEC_STATE;
				setTimer3(TIME_OUT);
			}
			if (isButtonPress(0)){
				counter = 0;
				display7SEG();
				status = RESET_STATE;
				setTimer3(TIME_OUT);
			}

			if (isButtonLongPress(1)){
				setTimer2(100);
				status = LONG_INC_STATE;
				break;
			}
			else if (timer3_flag && !isButtonPress(0) && !isButtonPress(1) && !isButtonPress(2)){
				setTimer2(100);
				status = NOBUTTON_STATE;
			}


			break;
		case DEC_STATE:
			if (isButtonPress(1)){
				counter++;
				display7SEG();
				status = INC_STATE;
				setTimer3(TIME_OUT);
			}
			if (isButtonPress(2)){
				counter--;
				display7SEG();
				setTimer3(TIME_OUT);
			}

			if (isButtonPress(0)){
				counter = 0;
				display7SEG();
				status = RESET_STATE;
				setTimer3(TIME_OUT);
			}

			if (isButtonLongPress(2)){
				setTimer2(100);
				status = LONG_DEC_STATE;
				break;
			}
			else if (timer3_flag && !isButtonPress(0) && !isButtonPress(1) && !isButtonPress(2)){
				setTimer2(100);
				status = NOBUTTON_STATE;
			}


			break;
		default:
			break;

	}
}
