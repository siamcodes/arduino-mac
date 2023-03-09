# take_show_feh.py
from picamera import PiCamera
from time import sleep

imageFile = './myimg.jpg'

camera = PiCamera()

camera.rotation = 180
camera.resolution = (640,480)
camera.start_preview()
sleep(3)    
camera.capture(imageFile)
camera.stop_preview()


import subprocess
image = subprocess.Popen(["feh", "--hide-pointer", "-x", "-q", \
	"-B", "black", "-g", "640x480", imageFile])

sleep(3)

image.kill()