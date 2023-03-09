import RPi.GPIO as GPIO

print(GPIO.VERSION)


GPIO.setmode(GPIO.BCM)
ledPin = 4

GPIO.setup(4, GPIO.OUT)

GPIO.output(ledPin, 1)


