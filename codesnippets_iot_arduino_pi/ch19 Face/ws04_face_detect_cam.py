
import cv2

cap = cv2.VideoCapture(0)
cap.set(3, 384) 
cap.set(4, 288) 


faceCascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

while(True):

	ret, frame = cap.read()
	frame = cv2.flip(frame,-1)


	gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)


	faces = faceCascade.detectMultiScale(
		gray,
		scaleFactor=1.3,
		minNeighbors=5,
		minSize=(30, 30),
    	flags = cv2.cv.CV_HAAR_SCALE_IMAGE		
	)

	print("Found {0} faces!".format(len(faces)))


	for (x, y, w, h) in faces:
		cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

	cv2.imshow('frame', frame)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break


cap.release()
cv2.destroyAllWindows()

