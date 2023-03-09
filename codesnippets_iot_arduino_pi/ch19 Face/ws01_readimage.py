
import cv2 

image = cv2.imread('./test.jpg',0) # ,0 bw
cv2.imshow('image',image)  
k = cv2.waitKey(0)
if k == 27:        
    cv2.destroyAllWindows()
elif k == ord('s'): 
    cv2.imwrite('testgray.jpg',image)
    cv2.destroyAllWindows()
