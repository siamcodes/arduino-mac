# -*- coding: utf-8 -*-


from picamera import PiCamera
from time import sleep
import RPi.GPIO as GPIO
from line_notify import LineNotify

ACCESS_TOKEN = "j3DX08ec0q3Tqgsld9cAWu__________" # token
LINE_MSG = 'แจ้งเตือนการบุกรุก'		# your msg

swPin = 17
ledPin = 4

delay = 10	# delay

GPIO.setmode(GPIO.BCM)     
GPIO.setup(swPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)   
GPIO.setup(ledPin, GPIO.OUT)   

camera = PiCamera()

imageFile = './myimg2.jpg'


# take a photo
def takePhoto():
    # camera.rotation = 180
    camera.resolution = (640,480)
    camera.start_preview()
    for i in range(5):
        sleep(1)    
        camera.capture('./myimg%s.jpg' % i)
    
    # camera.capture(imageFile)
    camera.stop_preview()

def send2Line ():
    notify = LineNotify(ACCESS_TOKEN)

    notify.send(LINE_MSG, image_path=imageFile)


# -- main --
print('running')
try:  
    while True:       
        if GPIO.input(swPin): # if port == 1  
            print("PIR is 1/HIGH/True - Take Photo") 
            GPIO.output(ledPin, 0)  
            sleep(delay)            
        else:  
            print("PIR is 0/LOW/False - do nothing")  
            GPIO.output(ledPin, 1)         # set port/pin value to 0/LOW/False  

        sleep(1)         
  
finally:                 
    GPIO.cleanup()       
    print("cleanup")


