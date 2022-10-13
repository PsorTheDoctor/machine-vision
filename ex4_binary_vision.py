import numpy as np
import cv2

img = cv2.imread('rice.png')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
_, otsu = cv2.threshold(gray, 200, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

kernel = np.ones((5, 5), np.uint8)
eroded = cv2.erode(otsu, kernel)

analysis = cv2.connectedComponentsWithStats(eroded, 10, cv2.CV_32S)
labels, labelIds, values, centroid = analysis
print(labels)

cv2.imshow('', eroded)
cv2.waitKey(0)
