import numpy as np
import cv2
import serial
import time
ser = serial.Serial("COM10", 9600, timeout=.25)


if __name__=="__main__":
    
    face_cascade = cv2.CascadeClassifier('./haarcascades/haarcascade_frontalface_alt.xml')
    eye_cascade = cv2.CascadeClassifier('./haarcascades/haarcascade_eye.xml')
    
    cam = cv2.VideoCapture(0)
    
    while True:
        judgement=0
        for count in range(10):
            _, img = cam.read()
            gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            gray = cv2.equalizeHist(gray)
            faces_rect = face_cascade.detectMultiScale(gray, 1.2, 5)
            
            for (x, y, w, h) in faces_rect:
                cv2.rectangle(img, (x,y), (x+w,y+h), (0,255,0), 2)
                face_roi = gray[y:y+h, x:x+w]
                eyes = eye_cascade.detectMultiScale(face_roi,1.4,6)
                
                for (ex,ey,ew,eh) in eyes:
                    judgement +=1
                    cv2.rectangle(img,(x+ex,y+ey),(x+ex+ew,y+ey+eh),(255,0,0),2)
                
                    
            cv2.imshow('img', img)
            c = cv2.waitKey(1)
            if c & 0xFF == 27:
                break
        if judgement > 6:
            print "your eyes are open"
            ser.write("1")
        else:
            print "your eyes are closed"
            ser.write("0")
    cv2.destroyAllWindows()

