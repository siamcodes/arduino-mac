# -*- coding: utf-8 -*-

import cv2
import cv2.cv as cv
import numpy as np
import os
import sys, time

def get_images(path, size):

    sub= 0
    images, labels= [], []
    people= []

    for subdir in os.listdir(path):
        for image in os.listdir(path+ "/"+ subdir):
            #print(subdir, images)
            img= cv2.imread(path+os.path.sep+subdir+os.path.sep+image, cv2.IMREAD_GRAYSCALE)
            img= cv2.resize(img, size)

            images.append(np.asarray(img, dtype= np.uint8))
            labels.append(sub)


        people.append(subdir)
        sub+= 1

    return [images, labels, people]

def detect_faces(image):

    frontal_face= cv2.CascadeClassifier("haarcascade_frontalface_default.xml")
    bBoxes= frontal_face.detectMultiScale(image, scaleFactor=1.3, 
        minNeighbors=4, minSize=(30, 30), flags = cv.CV_HAAR_SCALE_IMAGE)

    return bBoxes

def train_model(path):

    [images, labels, people]= get_images(sys.argv[1], (256, 256))

    labels= np.asarray(labels, dtype= np.int32)

    print("Initializing eigen FaceRecognizer and training...")
    sttime= time.clock()
    eigen_model= cv2.createEigenFaceRecognizer()
    eigen_model.train(images, labels)
    print("\tCompleted training in "+ str(time.clock()- sttime)+ " Secs!")

    return [eigen_model, people]

def majority(mylist):

    myset= set(mylist)
    ans= mylist[0]
    ans_f= mylist.count(ans)

    for i in myset:
        if mylist.count(i)> ans_f:
            ans= i
            ans_f= mylist.count(i)

    return ans


if __name__== "__main__":
    if len(sys.argv)!= 2:
        print("Wrong number of arguments! See the usage.\n")
        print("Usage: face_detrec_video.py <fullpath/images/folder>")
        sys.exit()

    arg_one= sys.argv[1]
    eigen_model, people= train_model(arg_one)

    cap= cv2.VideoCapture(0)
    cap.set(cv.CV_CAP_PROP_FRAME_WIDTH, 320) # kob 
    cap.set(cv.CV_CAP_PROP_FRAME_HEIGHT, 240) # kob

    counter= 0
    last_20= [0 for i in range(20)]
    final_5= []
    box_text= "Subject: "

    while(True):
        ret, frame= cap.read()
        frame = cv2.flip(frame,-1) # kob
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        gray_frame = cv2.equalizeHist(gray_frame)

        bBoxes= detect_faces(gray_frame)

        for bBox in bBoxes:
            (p,q,r,s)= bBox
            cv2.rectangle(frame, (p,q), (p+r,q+s), (25,255,25), 2)

            crop_gray_frame= gray_frame[q:q+s, p:p+r]
            crop_gray_frame= cv2.resize(crop_gray_frame, (256, 256))

            [predicted_label, predicted_conf]= eigen_model.predict(np.asarray(crop_gray_frame))
            last_20.append(predicted_label)
            last_20= last_20[1:]



            cv2.putText(frame, box_text, (p-20, q-5), cv2.FONT_HERSHEY_PLAIN, 1.3, (25,0,225), 2)

            if counter % 10 == 0:
                max_label= majority(last_20)

                box_text= format("Subject: "+ people[predicted_label])


        cv2.imshow("Video Window", frame)

        counter+= 1

        if (cv2.waitKey(5) & 0xFF== 27):
            break
            

    cv2.destroyAllWindows()
