#read a button
import RPi.GPIO as GPIO

while True:
	GPIO.setmode(GPIO.BOARD) # use the pin number on board
	GPIO.setup(12,GPIO.IN) # pin12 will receive signal 
	input_value = GPIO.input(12) #get the value of pin12
	if input_value == 0: # if the button has been pressed
		print("The button has been pressed.")
		while input_value == 0: #  when the button is pressed, keep check it status until it is released
			input_value = GPIO.input(12)
		GPIO.cleanup()
