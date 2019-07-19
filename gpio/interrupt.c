
#include <wiringPi.h>
#include <stdio.h> 

#define  btn_pin 1 // aka pin 12 on BOARD 


unsigned long last_interrupt_time = 0; // initialize last interrupt time

void my_interrupt_handler(){ // interript event
	unsigned long interrupt_time = millis();
  		if (interrupt_time - last_interrupt_time > 500){ // check time interval 
    			printf("stop\n");		
 		 }
  		last_interrupt_time = interrupt_time; // update interrupt time
}	

int main (void){

    wiringPiSetup();
    if (wiringPiSetup()==-1){//when initialize writing failed, print message to screen(unnecessary)
		printf("setup writingPi failed!");
		return 1;
	}

    pinMode(btn_pin, INPUT);//  btn_pin will receive signal
   // pullUpDnControl (btn_pin, PUD_UP);// does not need it when using resistor

	
    wiringPiISR(btn_pin,INT_EDGE_RISING,&my_interrupt_handler); 
    if (wiringPiISR(btn_pin,INT_EDGE_RISING,&my_interrupt_handler)<0){ // when set up event failed, print message to screen(unnecessary)
	printf("interrupt function register failture\n");
	}
    while(1){// keep printing message
        delay(1000);
	printf("I'm working...\n");
	

}
return 0;
}

