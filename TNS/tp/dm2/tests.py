#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jan 18 14:26:53 2019

@author: romain
"""

import numpy as np
from scipy.signal import get_window
from scipy.fftpack import ifft,fft, fftshift
import math
import matplotlib.pyplot as plt
eps = np.finfo(float).eps

def dftModel(x, w, N):

	#Analysis/synthesis of a signal using the discrete Fourier transform
	#x: input signal, w: analysis window, N: FFT size
	#returns y: output signal

	if not(isPower2(N)):                                 # raise error if N not a power of two
		raise ValueError("FFT size (N) is not a power of 2")

	if (w.size > N):                                        # raise error if window size bigger than fft size
		raise ValueError("Window size (M) is bigger than FFT size")

	if all(x==0):                                           # if input array is zeros return empty output
		return np.zeros(x.size)
	hN = (N//2)+1                                           # size of positive spectrum, it includes sample 0
	hM1 = (w.size+1)//2                                     # half analysis window size by rounding
	hM2 = int(math.floor(w.size/2))                         # half analysis window size by floor
	fftbuffer = np.zeros(N)                                 # initialize buffer for FFT
	y = np.zeros(x.size)                                    # initialize output array
	#----analysis--------
	xw = x*w                                                # window the input sound
	fftbuffer[:hM1] = xw[hM2:]                              # zero-phase window in fftbuffer
	fftbuffer[-hM2:] = xw[:hM2]        
	X = fft(fftbuffer)                                      # compute FFT
	absX = abs(X[:hN])                                      # compute ansolute value of positive side
	absX[absX<np.finfo(float).eps] = np.finfo(float).eps    # if zeros add epsilon to handle log
	mX = 20 * np.log10(absX)                                # magnitude spectrum of positive frequencies in dB     
	pX = np.unwrap(np.angle(X[:hN]))                        # unwrapped phase spectrum of positive frequencies
	#-----synthesis-----
	Y = np.zeros(N, dtype = complex)                        # clean output spectrum
	Y[:hN] = 10**(mX/20) * np.exp(1j*pX)                    # generate positive frequencies
	Y[hN:] = 10**(mX[-2:0:-1]/20) * np.exp(-1j*pX[-2:0:-1]) # generate negative frequencies
	fftbuffer = np.real(ifft(Y))                            # compute inverse FFT
	y[:hM2] = fftbuffer[-hM2:]                              # undo zero-phase window
	y[hM2:] = fftbuffer[:hM1]
	return y



M=256;
N=8*M;
w=get_window('blackman',M)
w=np.concatenate([w,np.zeros(N-M)])
f=np.arange(-N/2,N/2,1)
W=fft(w)
Wor=W
W=W/np.max(abs(W))
print(W)
plt.plot(f,abs(fftshift(W)))
plt.show()
plt.plot(f,20*np.log10(abs(fftshift(W))+eps))
plt.show()
print(np.sum(w**2))
print(np.sum(abs(Wor)**2)/N)