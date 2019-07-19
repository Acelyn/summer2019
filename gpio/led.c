//blinking an Led
#include <wiringPi.h>
#include <stdio.h>

#define LedPin 0  //aka pin 11 On BOARD 

int main(void){
	wiringPiSetup(); // initialize wiring
	if (wiringPiSetup()==-1){  //when initialize wiring failed, print message to screen(unnecessary)
		printf("setup writingPi failed!");
		return 1;
	}

	pinMode(LedPin, OUTPUT);  // LedPin will send signal to the led
	while(1){
		digitalWrite(LedPin, LOW);//send low signal to led through pin11
		printf("led on...\n");
		delay(500);
		digitalWrite(LedPin,HIGH);//send high signal to led through pin11
		printf("led off...\n");
		delay(500);
	}
	return 0;
}

	
