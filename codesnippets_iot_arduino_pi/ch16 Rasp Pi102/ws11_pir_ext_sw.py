# ext from sw

import RPi.GPIO as GPIO  
from time import sleep   

pirPin = 17
ledPin = 4

GPIO.setmode(GPIO.BCM)   
GPIO.setup(pirPin, GPIO.IN)  
GPIO.setup(4, GPIO.OUT)  
  
try:  
    while True:          
        if GPIO.input(pirPin): # 
            print("PIR: 1/HIGH/True - LED ON, Intruder Detected!!") 
            GPIO.output(ledPin, 1)   
        else:  
            print("PIR: 0/LOW/False - LED OFF, No Intruder")  
            GPIO.output(ledPin, 0)   
        sleep(0.2)        
  
finally:                  
    GPIO.cleanup()        
    print("cleanup")
