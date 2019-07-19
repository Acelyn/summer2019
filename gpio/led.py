# blinking an Led
import RPi.GPIO as GPIO
import time

while True:
	GPIO.setmode(GPIO.BOARD)  # use the pin number on board
	GPIO.setup(11,GPIO.OUT) # pin11 will send signal to led 
	GPIO.output(11,GPIO.HIGH)  # send high signal to led through pin11 
	print("led off...")
	time.sleep(0.5)            
	GPIO.output(11,GPIO.LOW)    #send low signal to led through pin11
	print("led on...")
	time.sleep(0.5)
	GPIO.cleanup()

