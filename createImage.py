import numpy as np
import cv2

arr = np.zeros([50,50])
arr[20,20] = 255;

cv2.imwrite('a.png', arr)

with open('a.png','rb', encoding='utf-8') as f:
  raw = f.read()
  print(raw[:100])
