#with finally

import RPi.GPIO as GPIO  
import time

ledPin = 4


def blink(pin):  
        GPIO.output(pin,GPIO.HIGH)
        print("On")
        time.sleep(0.8)  
        GPIO.output(pin,GPIO.LOW)
        print("Off")
        time.sleep(1.0)  
        return  


GPIO.setmode(GPIO.BCM)  


GPIO.setup(ledPin, GPIO.OUT)  


try: 
        
        while True:
            blink(ledPin)

finally:         
        GPIO.cleanup()
        print("clean")

print("done")
