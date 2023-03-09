# take_show_btn.py
from picamera import PiCamera
from time import sleep
import subprocess
import RPi.GPIO as GPIO

swPin = 17
ledPin = 4

GPIO.setmode(GPIO.BCM)    
GPIO.setup(swPin, GPIO.IN, pull_up_down=GPIO.PUD_UP) 
GPIO.setup(ledPin, GPIO.OUT) 

camera = PiCamera()

imageFile = './myimg.jpg'

# take a photo
def takePhoto():
	camera.rotation = 180
	camera.resolution = (640,480)
	camera.start_preview()
	sleep(3)    
	camera.capture(imageFile)
	camera.stop_preview()

def displayPhoto():
	#Display the image
	image = subprocess.Popen(["feh", "--hide-pointer", "-x", "-q", \
		"-B", "black", "-g", "640x480", imageFile])
	sleep(3)
	image.kill()		


# -- main --
print('Press btn to take a photo..')
try:  
    while True:         
        if GPIO.input(swPin):  

            GPIO.output(ledPin, 0)       
        else:  
            print("Port sw is 0/LOW/False - Pressed - takePhoto")  
            GPIO.output(ledPin, 1)         
            takePhoto()
            displayPhoto()
        sleep(0.2)       
  
finally:                  
    GPIO.cleanup()         
    print("cleanup")



