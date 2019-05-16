#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 11 13:53:20 2019

@author: romain
"""

import numpy as np
from scipy.signal import get_window
from scipy.fftpack import ifft,fft, fftshift
import math
import matplotlib.pyplot as plt

w=np.arange(1e-9,2e8)
R=2.4; L=60*1e-6; C=822*1e-9
Z_square=R*R+(w*L)*(w*L)
V=1845; I0=19.5
P0=R*V*V/Z_square

plt.plot(P0)
plt.show()

V=560
new_Z_square=R*R+(L*w-1/(C*w))*(L*w-1/(C*w))

P0=R*V*V/new_Z_square
plt.plot(P0)
plt.show()
























