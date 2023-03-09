# camera3 vdo 

from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.start_preview()
camera.start_recording('./myvdo720.h264')
sleep(10)
camera.stop_recording()
camera.stop_preview()

