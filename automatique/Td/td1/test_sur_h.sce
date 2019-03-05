t=linspace (0,10,1000);
p=poly(0,'p');
a=95/13
S=%pi*(2.5^2)
Ts=100  //tps de simulation en min
Qs=40
G=1

Tau=S/(a*G);
G=syslin('c',10/(1+Tau*p))
h=csim('step',t,G);

plot2d(t,h);
