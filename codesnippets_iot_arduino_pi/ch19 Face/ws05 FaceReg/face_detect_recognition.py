

import cv2
import cv2.cv as cv
import numpy as np
from os import listdir
import sys, time

def get_images(path, size):

	sub= 0
	images, labels= [], []
	people= []

	for subdir in listdir(path):
		for image in listdir(path+ "/"+ subdir):

			img= cv2.imread(path+"/"+subdir+"/"+image, cv2.IMREAD_GRAYSCALE)
			img= cv2.resize(img, size)

			images.append(np.asarray(img, dtype= np.uint8))
			labels.append(sub)



		people.append(subdir)
		sub+= 1

	return [images, labels, people]

if __name__== "__main__":
	if len(sys.argv)!= 3:
		print("Wrong number of arguments! See the usage.\n")
		print("Usage: face_recognition.py <fullpath/images/folder> <fullpath/../predict>")
		sys.exit()

	[images, labels, people]= get_images(sys.argv[1], (256, 256))


	labels= np.asarray(labels, dtype= np.int32)

	print("Initializing eigen FaceRecognizer and training...")
	sttime= time.clock()
	eigen_model= cv2.createEigenFaceRecognizer()
	eigen_model.train(images, labels)
	print("\tCompleted training in "+ str(time.clock()- sttime)+ " Secs!")


	for image_name in listdir(sys.argv[2]):
		try:
			color_image= cv2.imread(sys.argv[2]+ "/"+ image_name)
			[x, y]= color_image.shape[:2]
			x_factor= (float(y)/x)
			resize_y= 480

			color_image= cv2.resize(color_image, (int(resize_y* x_factor), resize_y))

			pre_image= cv2.imread(sys.argv[2]+ "/"+ image_name, cv2.IMREAD_GRAYSCALE)
			pre_image= cv2.resize(pre_image, (int(resize_y* x_factor), resize_y))
		except:
			print("Couldn't read image. Please check the path to image file.")
			sys.exit()


		frontal_face= cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

		bBoxes= frontal_face.detectMultiScale(pre_image, 
			scaleFactor=1.3, minNeighbors=4, minSize=(30, 30), 
			flags = cv.CV_HAAR_SCALE_IMAGE)

		for bBox in bBoxes:
			(p,q,r,s)= bBox

			cv2.rectangle(color_image, (p,q), (p+r,q+s), (2,255,25), 2)



			pre_crop_image= pre_image[q:q+s, p:p+r]
			pre_crop_image= cv2.resize(pre_crop_image, (256, 256))

			[predicted_label, predicted_conf]= eigen_model.predict(np.asarray(pre_crop_image))
			print("Predicted person in the image "+ image_name+ " : "+ people[predicted_label])

			box_text= format("Subject: "+ people[predicted_label])



			cv2.putText(color_image, box_text, (p-20, q-5), cv2.FONT_HERSHEY_PLAIN, 1.5, (5,205,2), 2)
		cv2.imshow("Win1", color_image)
		cv2.imshow("Win2", pre_crop_image)
		cv2.waitKey(0)


