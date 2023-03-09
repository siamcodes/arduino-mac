import time
from subprocess import call

def capture():
	strDt = time.strftime("%Y-%m-%d-%H-%M-%S")
	# call(["fswebcam", "-r", "640x480", "--no-banner", strDt+".jpg"])	
	call(["fswebcam", "-r", "640x480", "--no-banner", "/home/pi/Pictures/"+strDt+".jpg"])	

# capture()

for i in range(0,5):
	capture()
	time.sleep(1)

