// read a button
#include <wiringPi.h>
#include <stdio.h>

#define btn_pin 1 // aka pin 12 BOARD	

int main(void){
	wiringPiSetup(); // initialize wiring
	if (wiringPiSetup()==-1){  //when initialize wiring failed, print messa$
                printf("setup writingPi failed!");
                return 1;
        }

	pinMode(btn_pin,INPUT);//  btn_pin will receive signal 
	//pullUpDnControl (btn_pin,PUD_DOWN); //does not need it when using resistor
	while(1){
		int input_value = digitalRead(btn_pin);// get the  value of btn_pin
		if (input_value == 0){// if the button has been pressed

			printf("The button has been pressed.\n");
			while (input_value == 0){//  when the button is pressed, keep check it status until it is released
				input_value = digitalRead(btn_pin);
			}
		}	
	}
}
