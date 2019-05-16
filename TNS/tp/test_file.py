#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue May  7 18:53:24 2019

@author: romain
"""

import numpy as np
import matplotlib.pyplot as plt
import cv2
import sys 

img=open("lena.png","r")
new_img=open("imgsecre.png","w+")

for c in img.read():
    new_img.write(c+'10')
    
new_img.close()
img.close()











