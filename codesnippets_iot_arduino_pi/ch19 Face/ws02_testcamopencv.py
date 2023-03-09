
import cv 
import cv2 # for preview


imgW = 640
imgH = 480
 

cv.NamedWindow("window1", cv.CV_WINDOW_AUTOSIZE)
camera_index = 0
 
capture = cv.CaptureFromCAM(camera_index)
 
cv.SetCaptureProperty(capture, cv.CV_CAP_PROP_FRAME_WIDTH, imgW);
cv.SetCaptureProperty(capture, cv.CV_CAP_PROP_FRAME_HEIGHT, imgH);
 
while True:
    frame = cv.QueryFrame(capture)
    cv.ShowImage("window1", frame)
 

    command = cv.WaitKey(10)
 
    # if press 'q' -> exit program
    if command == ord('q'):
        print "Ending program"
        break  # end program
 
    # if press 's' -> save the image
    elif command == ord('s'):
        print "Saving image"
        cv.SaveImage("test.jpg",frame)    

        img = cv2.imread('test.jpg')
        cv2.imshow('image',img)     
