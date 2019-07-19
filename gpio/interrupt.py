import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD) #use the pin number on board

GPIO.setup(12, GPIO.IN) #pin12 will receive signal #,pull_up_down=GPIO.PUD_DOWN) # does not need it when using resistor


def my_callback(channel):
    print("button pressed!")  # the program will print this when it is interruptted

#GPIO.add_event_detect(11, GPIO.RISING, callback=my_callback) # add event without debouncing
GPIO.add_event_detect(12, GPIO.RISING, callback=my_callback,bouncetime=200) # add even with debounce
while True: #keep printing "I'm working" every 3 seconds
    try:
        print("I'm working...")
        time.sleep(3)
        pass
    except KeyboardInterrupt:
        break
        pass
    pass

GPIO.cleanup()

