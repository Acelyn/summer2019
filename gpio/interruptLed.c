#include <wiringPi.h>
#include <stdio.h> 

#define  btn_pin 1 
#define led_pin 0

unsigned long last_interrupt_time = 0;

void my_interrupt_handler(){
	unsigned long interrupt_time = millis();
  		if (interrupt_time - last_interrupt_time > 500){
			printf("stop\n");
			digitalWrite(led_pin,HIGH);
			//delay(5000);	
		}
	last_interrupt_time = interrupt_time;
}


int main (void){

    wiringPiSetup();
    if (wiringPiSetup()==-1){/*when initialize writing failed, print message to screen*/
		printf("setup writingPi failed!");
		return 1;
	}

    pinMode(btn_pin, INPUT);
    pinMode(led_pin, OUTPUT);
  //  pullUpDnControl (btn_pin, PUD_UP);

    if (wiringPiISR(btn_pin,INT_EDGE_FALLING,&my_interrupt_handler)<0){
	printf("interrupt function register failture\n");
	}


    while(1){
	printf("working..\n");
	digitalWrite(led_pin, LOW);
	delay(2000);
}
return 0;
}

