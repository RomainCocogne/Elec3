#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 25 12:39:57 2019

@author: romain
"""

import numpy as np
import matplotlib.pyplot as plt
import cv2
import scipy
import scipy.fftpack as fftpack
import sys

block=np.array([0,0,0,1,1,1,0,1,0,0,1,1,1,1])

def rle(liste):
    new_liste=np.array([])
    uns=0
    for i in liste:
        if(i==0):
            if(uns !=0):
                new_liste=np.append(new_liste,uns)
                uns=0
            new_liste=np.append(new_liste,i)
        else:
            uns=uns+1
    if(uns!=0):
        new_liste=np.append(new_liste,uns)
    return new_liste.astype(int)

def irle(liste):
    new_liste=np.array([])
    for i in liste:
        if(i==0):
            new_liste=np.append(new_liste,i)
        else:
            for uns in range(i):
                new_liste= np.append(new_liste,1)
    return new_liste.astype(int)