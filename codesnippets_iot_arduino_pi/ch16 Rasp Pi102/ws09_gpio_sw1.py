import RPi.GPIO as GPIO  
from time import sleep    

swPin = 17
ledPin = 4

GPIO.setmode(GPIO.BCM)    
GPIO.setup(swPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)    
GPIO.setup(ledPin, GPIO.OUT) 
  
try:  
    while True:            
        if GPIO.input(swPin): 
            print("Port sw is 1/HIGH/True - LED ON") 
            GPIO.output(ledPin, 1)      
        else:  
            print("Port sw is 0/LOW/False - LED OFF")  
            GPIO.output(ledPin, 0)   
        sleep(0.2)       
  
finally:                 
    GPIO.cleanup()       
    print("cleanup")
