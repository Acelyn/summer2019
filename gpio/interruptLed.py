import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD) # decide name of pins that we are going to used
GPIO.setup(11,GPIO.OUT)
GPIO.setup(12, GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # decide the iput signal to use

LED_ON = True

def my_callback(channel):
    global LED_ON
	
    print("stop")
    if LED_ON:
        GPIO.output(11,GPIO.HIGH)
    else:
        GPIO.output(11,GPIO.LOW)

    LED_ON = not LED_ON

    #time.sleep(2)

GPIO.add_event_detect(12, GPIO.RISING, callback=my_callback,bouncetime=1000)
while True: 
    try:
        print("working")
        #GPIO.output(11,GPIO.LOW)
        time.sleep(1)
        pass
    except KeyboardInterrupt:
        break
        pass
    pass

GPIO.cleanup()
