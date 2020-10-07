import cv2
cap = cv2.VideoCapture(0)
width = 1280
height = 960
cap.set(cv2.CAP_PROP_FRAME_WIDTH,width)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT,height)

while(True):
    ret,frame = cap.read()
    frame = cv2.flip(frame,-1)    
    cv2.imshow('frame',frame)
    
    input = cv2.waitKey(20)
    if input == ord('q'):
        cv2.imwrite("/home/pi/Desktop/1.jpg",frame)
        break
cap.release()
cv2.destroyAllWindows()
