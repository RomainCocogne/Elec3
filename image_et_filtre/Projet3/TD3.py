#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Apr 12 13:45:51 2019

@author: cquentin
"""

import numpy as np
import scipy.fftpack 
import matplotlib.pyplot as plt
import cv2
from huffman import *
import sys 



def dct(img):
    res = np.zeros(img.shape)
    for i in range(0,img.shape[0]):
        res[:,i] = scipy.fftpack.dct(img[:,i],norm="ortho")
    for j in range(0,img.shape[1]):
        res[j,:] = scipy.fftpack.dct(res[j,:],norm="ortho")
    return res 

def idct(img):
    res = np.zeros(img.shape)
    for i in range(0,img.shape[0]):
        res[:,i] = scipy.fftpack.idct(img[:,i],norm="ortho")
    for j in range(0,img.shape[1]):
        res[j,:] = scipy.fftpack.idct(res[j,:],norm="ortho")
    return res 
#Ne prend pas en compte les bords 
#def dct8_8(img):
#    res = np.zeros(img.shape)
#    for i in range(0,int(img.shape[0]/8)):
#        for j in range(0,int(img.shape[1]/8)):
#            res[8*i:8*(i+1),8*j:8*(j+1)] = dct(img[8*i:8*(i+1),8*j:8*(j+1)])
#            #print("Decoupage entre",8*i,";",8*j, " et ", 8*i+8,";",8*j+8)
#    return res


#Quantifie un bloc 8x8 avec un facteur de qualité qual 
def matrice_quantif(shape,qual):
    res = np.zeros(shape)
    for i in range(shape[0]):
        for j in range(shape[1]):
            res[i,j] = 1 + (1+i+j)*qual
    return res


def print_blocs(img):
    for octet_x in np.arange(0,img.shape[0],8):
        for octet_y in np.arange(0,img.shape[1],8): 
            print(img[octet_x:octet_x+8,octet_y:octet_y+8])

#Prend en compte les bords 
def dct8_8(img,qual):
    while (img.shape[0]%8 !=0):
        img=np.concatenate((img, img[-1,:].reshape(1,img.shape[1])),axis=0)
        
    while (img.shape[1]%8 !=0):
        img=np.concatenate((img, img[:,-1].reshape(img.shape[0],1)),axis=1)
    
    F=np.zeros(img.shape);
    Q = matrice_quantif((8,8),qual)
    for octet_x in np.arange(0,img.shape[0],8):
        for octet_y in np.arange(0,img.shape[1],8): 
            square=img[octet_x:octet_x+8,octet_y:octet_y+8]
            F[octet_x:octet_x+8,octet_y:octet_y+8]= np.around(dct(square)/Q)
    return F


def zigzag_matrice():
    x,y,i= (0,0,0)
    sens = 1
    res = np.zeros((64,2))
    while (x<8 and y<8):
        res[i] = (y,x)
        if (y==0 or y==7) :
            x+=1; 
            sens = -sens; 
            i+=1
            res[i] = (y,x)
        elif (x==0 or x==7) : 
            y+=1; 
            sens = -sens;
            i+=1
            res[i] = (y,x)
        x+= sens
        y-= sens
        i+=1
    return res.astype(int)

zigzag = zigzag_matrice()

def jpeg(img,qual):
    while (img.shape[0]%8 !=0):
        img=np.concatenate((img, img[-1,:].reshape(1,img.shape[1])),axis=0)
        
    while (img.shape[1]%8 !=0):
        img=np.concatenate((img, img[:,-1].reshape(img.shape[0],1)),axis=1)
    
    F=[]
    Q = matrice_quantif((8,8),qual)
    zigzag = zigzag_matrice()
    for octet_x in np.arange(0,img.shape[0],8):
        for octet_y in np.arange(0,img.shape[1],8): 
            square=img[octet_x:octet_x+8,octet_y:octet_y+8]
            square=np.around(dct(square)/Q)
#            print(idct(square*Q))
            freq_dict, enc_dict = huffman_compute(square) #Generation de l'arbre de Huffman
#            print(enc_dict)
            squareflat = square[zigzag[:,0],zigzag[:,1]] #Parcourt du bloc 8x8 en zig-zag
            code = huffmanEncode(enc_dict,squareflat) #Encodage du bloc 8x8 avec Huffman
            F.append([code,freq_dict]) #Stockage du bloc encodé ainsi que des informations pour le décoder
    return np.array(F)

def unjpeg(jpg,q):
    Q = matrice_quantif((8,8),q)
    zigzag = zigzag_matrice()
    dim_x,dim_y=(int(jpg.shape[0]/8),int(jpg.shape[0]/8))
    img = np.zeros((dim_x,dim_y))
    octet_y=0;
    octet_x=0;
    for bloc in jpg:
        tree= buildHuffmanTree(bloc[1])
        squareflat = huffmanDecode(tree,bloc[0])
        new_square = np.zeros((8,8))
        new_square[zigzag[:,0],zigzag[:,1]] = squareflat
        img[octet_x:octet_x+8,octet_y:octet_y+8]=np.around(idct(new_square*Q)).astype(int)
        octet_y+=8;
        if(octet_y>=dim_y):
            octet_y=0
            octet_x+=8
    return img
    

img = cv2.imread('lena.png',0)
#dct_entiere = dct(img)
#plt.figure()
#plt.imshow(dct_entiere, vmin=0,vmax=np.max(dct_entiere)*1E-3)
#plt.title("Dct image enitère")
#dct_jpeg = dct8_8(img,0)
#plt.figure()
#plt.imshow(dct_jpeg, vmin=0,vmax=np.max(dct_jpeg)*1E-2,cmap = 'gray')
#plt.title("Dct image 8x8")

#dct_jpeg_2 = dct8_8(img,2)
#plt.figure()
#plt.imshow(dct_jpeg_2, vmin=np.min(dct_jpeg_2)*1E-1,vmax=np.max(dct_jpeg_2)*1E-1,cmap = 'gray')
#plt.title("Dct image 8x8 avec quantification (Q = 2)")

#jpeg_1 = jpeg(img,1)
#plt.figure()
#plt.imshow(jpeg_1,cmap = 'gray')
#plt.title("jpeg avec quantification (Q = 1)")

jpeg_2 = jpeg(img,2)
#plt.figure()
#plt.imshow(jpeg_2,cmap = 'gray')
#plt.title("jpeg avec quantification (Q = 2)")
#
#dct_jpeg_30 = dct8_8(img,30)
#plt.figure()
#plt.imshow(dct_jpeg_30,vmin=np.min(dct_jpeg_2)*1E-1,vmax=np.max(dct_jpeg_2)*1E-1,cmap = 'gray')
#plt.title("Dct image 8x8 avec quantification (Q = 30)")

#jpeg_30 = jpeg(img,30)
#plt.figure()
#plt.imshow(jpeg_30,cmap = 'gray')
#plt.title("jpeg avec quantification (Q = 30)")


#Faire
# Taille(octets) en fonction de Q
#EQM en fonction de Q
#EQM en fonction de taille (octets) 