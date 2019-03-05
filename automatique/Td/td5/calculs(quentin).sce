t = linspace(0,1,1000)
p = poly(0,'p')

R=0.8;
L=400E-6;
Kc=20.52E-3;
J=18E-5;
Cr=9.23E-3;
taum=R*J/Kc^2;
taue=L/R;
Krpm=60/(2*%pi);
Kci=1;
Kd=0.001;
Kdrad = Kd*Krpm

Gi = 1;
K1 = Gi*taum/(R*taue + Kci*Gi*taum);
tau1 = taum/(1+Kci*Gi*taum/R/taue);
Gw = J/(4*(0.7)^2*Kc*Kdrad*K1*tau1)



//AI = syslin('c',K1/(1+tau1*p))
Bo = syslin('c',Kdrad*K1*Kc/((J*p)*(1+tau1*p)))
//B1 = syslin('c',Gw*AI*Kc/(J*p)/(1+Gw*AI*Kc*Kd/(J*p)))

evans(Bo,2000);
sgrid(0.7,1787);

//e = 11000*ones(t)
//s = csim(e,t,Kd*B1)
//scf(1)
//plot2d(t,s)
