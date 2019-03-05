# -*- coding: utf-8 -*-
import numpy as np
import scipy.integrate
from matplotlib import pyplot as plt

cc= lambda t: np.sqrt(2)*np.cos(2.0*np.pi*t)
ss= lambda t: np.sqrt(2)*np.sin(2.0*np.pi*t)
b2_cos= lambda t: np.random.normal(0,energy_moy3(signal)/2,101)
b2_sin= lambda t: np.random.normal(0,energy_moy3(signal)/2,101)
b1_cos= lambda t: np.random.normal(0,energy_moy3(signal)/100,101)
b1_sin= lambda t: np.random.normal(0,energy_moy3(signal)/100,101)
#fonctions
def v (k):
    return lambda t: (2*(k%4-1)-1)*cc(t) + (2*(k//4-1)-1)*ss(t)
def v_bruite_1(k):
    return lambda t: v(k)(t)+b1_cos(t)*cc(t)+b1_sin(t)*ss(t)
def v_bruite_2(k):
    return lambda t: v(k)(t)+b2_cos(t)*cc(t)+b2_sin(t)*ss(t)


#attention le retour est un string
def int_to_binaire(i):
    b=''
    while i>=1:
        b=str(i%2)+b
        i=i//2
    while (len(b)%4!=0):
        b="0"+b
    return b


def binaire_to_int(b):
    i=0; p=0;
    for c in reversed(b):
        if (c=='1'):
            i+=pow(2,p)
        p+=1
    return i
    
#attention le retour est un string
def str_to_binaire(s): 
    b=''
    for c in s:
        b+=int_to_binaire(ord(c))
    return b

def cut (s,t):
    while (len(s)%t!=0):
        s="0"+s
    s_cut=np.array([])
    mot=""
    i=1
    for b in s:
        mot+=b
        if(i==t):
            s_cut=np.append(s_cut,mot)
            mot=""
            i=0
        i=i+1
    return s_cut

#def binaire_to_string(b):
    

def signal_int(mot,taille):
    signal=str_to_binaire(mot)
    signal=np.array(cut(signal,taille))
    for i in range(0,len(signal)):
        signal[i]=binaire_to_int(signal[i])
    return  signal

###################

def modul_signal(t,signal,b):
    if(b==0):
        m=np.array([v(int(signal[0]))(t)])
    elif (b==1):
        m=np.array([v_bruite_1(int(signal[0]))(t)])
    else:
        m=np.array([v_bruite_2(int(signal[0]))(t)])
    for i in range(1,len(signal)):
        if (b==0):
            m=np.append(m,[v(int(signal[i]))(t)],axis=0)
        elif (b==1):
            m=np.append(m,[v_bruite_1(int(signal[i]))(t)],axis=0)
        else:
            m=np.append(m,[v_bruite_2(int(signal[i]))(t)],axis=0)
    return m
        

def trois_premiers(t,signal,b):
    if (b==0):
        plt.plot(t,v(int(signal[0]))(t))
        plt.plot(t,v(int(signal[1]))(t))
        plt.plot(t,v(int(signal[2]))(t))
    elif(b==1):
        plt.plot(t,v_bruite_1(int(signal[0]))(t))
        plt.plot(t,v_bruite_1(int(signal[1]))(t))
        plt.plot(t,v_bruite_1(int(signal[2]))(t))
    else:
        plt.plot(t,v_bruite_2(int(signal[0]))(t))
        plt.plot(t,v_bruite_2(int(signal[1]))(t))
        plt.plot(t,v_bruite_2(int(signal[2]))(t))
    plt.show()
    
def constellation(t,signal,b,c='b'):
    for i in signal:
        if(b==0):
            x=scipy.integrate.simps(v(int(i))(t)*cc(t),t)
            y=scipy.integrate.simps(v(int(i))(t)*ss(t),t)
        elif(b==1):
            x=scipy.integrate.simps(v_bruite_1(int(i))(t)*cc(t),t)
            y=scipy.integrate.simps(v_bruite_1(int(i))(t)*ss(t),t)
        else:
            x=scipy.integrate.simps(v_bruite_2(int(i))(t)*cc(t),t)
            y=scipy.integrate.simps(v_bruite_2(int(i))(t)*ss(t),t)
        plt.plot(np.array([x]),np.array([y]),c+'o')
    plt.show()
    
def constellation2 (t,s,c='b'):
    for i in s:
        x=scipy.integrate.simps(s*cc(t),t)
        y=scipy.integrate.simps(s*ss(t),t)
        plt.plot(np.array([x]),np.array([y]),c+'o')
    #plt.show()
    
def energy_moy(t,signal,b):
    moyenne=0
    for i in signal:
        if (b==0):
            moyenne+=scipy.integrate.simps(v(int(i))(t)*v(int(i))(t),t)
        elif(b==1):
            moyenne+=scipy.integrate.simps(v_bruite_1(int(i))(t)*v_bruite_1(int(i))(t),t)
        else:
            moyenne+=scipy.integrate.simps(v_bruite_2(int(i))(t)*v_bruite_2(int(i))(t),t)
    return moyenne/len(signal)

def energy_moy2(t,s):
    moyenne=0
    for i in s:
        moyenne+=scipy.integrate.simps(i*i,t)
    return moyenne/len(s)

def energy_moy3(signal):
    moyenne =0
    for k in signal:
        k=int(k)
        moyenne+=(2*(k%4-1)-1)*(2*(k%4-1)-1)+(2*(k//4-1)-1)*(2*(k//4-1)-1)
    return moyenne/len(signal)
        
def reception_mot(t,s):
    mot=0; dp=10000;
    x=scipy.integrate.simps(s*cc(t),t)
    y=scipy.integrate.simps(s*ss(t),t)
    for i in range(0,16):
        x_b=scipy.integrate.simps(v(i)(t)*cc(t),t)
        y_b=scipy.integrate.simps(v(i)(t)*ss(t),t)
        if ((x-x_b)*(x-x_b)+(y-y_b)*(y-y_b)<dp):
            dp=(x-x_b)*(x-x_b)+(y-y_b)*(y-y_b)
            mot=i
    return mot

        
def reception (t,s):
    mot_binaire=''
    for m in range (len(s)):
        mot_binaire+=int_to_binaire(reception_mot(t,s[m]))
    lettre='';mot=''
    for b in mot_binaire:
        lettre+=b
        if(len(lettre)%8==0):
            mot+=chr(int(binaire_to_int(lettre)))
            lettre=''
    return mot

def erreur_mot (t,signal,n,b):
    erreur=0
    for i in range(n):
        mot_rec_byte= reception_mot(t,modul_signal(t,signal,b)[i%16])
        mot_env_byte= int(signal[i%16])
        if(mot_rec_byte != mot_env_byte):
            erreur+=1
    print("nombre d'erreur:"+ str(erreur))
    return erreur/n

def erreur_byte (t,signal,n,b):
    erreur=0
    for i in range(n):
        mot_rec_byte= int_to_binaire(reception_mot(t,modul_signal(t,signal,b)[i%16]))
        mot_env_byte= int_to_binaire(int(signal[i%16]))
        #print(str(reception_mot(t,modul_signal(t,signal,b)[i%16]))+" "+signal[i%16])
        #print(mot_rec_byte+" "+mot_env_byte)
        for j in range(len(mot_env_byte)):
            if(mot_env_byte[j] != mot_rec_byte[j]):
                print(mot_rec_byte[j]+" "+mot_env_byte[j])
                erreur+=1
    print("nombre d'erreur:"+ str(erreur))
    return erreur/(n*7)


t=np.arange(0,1.0000001,0.01)
signal=signal_int("CocogneRomain",4)
#signal=modul(signal,t)
#signal_modul=modul(signal)


#trois premiers mots
#trois_premiers(t,signal)
#constellation du signal
#constellation(t,signal)
s=np.zeros(16)
for i in range(16):
    s[i]=i

nuage=np.array(modul_signal(t,s,2))
for i in range (0,int(50)):
    nuage=np.append(nuage,modul_signal(t,s,2),axis=0)
#constellation2(t,nuage)
#constellation2(t,modul_signal(t,s,0),'r')
plt.show()



























