from re import I
import cv2  
import numpy as np
import os, sys

path= os.path.dirname(sys.argv[0])
print(path)
width = 1920
height = 1080


DIR = path + "/"
i = 0


while i < 255:
    blank_image  = np.ones((300,300,1),np.uint8)*i
    cv2.imwrite(DIR+ str(i) + str(".png"), blank_image)
    i += 1