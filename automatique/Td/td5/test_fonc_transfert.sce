clear;
xdel(winsid());
t=linspace (0,1E-2,1E4);
p=poly(0,'p');
K=0.47;

R=0.8;
L=400E-6;
Kc=20.52E-3;
J=180E-6;
Cr=0;

Taum=(R*J)/(Kc*Kc);
Taue=L/R;
Gi=1;
Kci=1;
Kd=0.001*30/%pi;
Kp=10;
Gw0=1171;
w0=1787.8;
K1=(Gi*Taum)/((Gi*Taum*Kci)+(R*Taue));
Tau1=Taum/((Gi*Taum*Kci)/(R*Taue)+1);
zeta=0.5*(1/sqrt(Tau1))*(J/sqrt(J))*(sqrt(Kd*Kc*K1*Gw0)/(Kd*Kc*K1*Gw0))
Gp=0.238;

Bo=syslin('c',(K1*Kc*Kd)/((1+Tau1*p)*J*p));
Bf=syslin('c',(1/Kd)/(1+2*zeta*p/w0+p*p/(w0*w0)));
bo=csim('step',t,Bo);

Ai=syslin('c',K1/(1+Tau1*p));
ai=csim('strep',t,Ai);

Do=Kp*Gp*Bf/p;
Df=syslin('c',(Gp/Kd)/(p*p*p/(w0*w0)+p*p*2*zeta/w0+p+Gp*Kp/Kd));
df=csim('strep',t,Df);
scf(1);
plot2d(t,ai);
a=gcf(); a.figure_name='Ai indicielle';

scf(2);
plot2d(t,bo);
a=gcf(); a.figure_name='B indicielle';

scf(3);
evans(Bo,2000);
sgrid(0.7,w0);
a=gcf(); a.figure_name='evans de b ouverte';

scf(4);
black(Do);
a=gcf(); a.figure_name='black de D';

scf(5);
evans(Do,2.5);
a=gcf(); a.figure_name='evans de D ouverte';

scf(6);
plot2d(t,df);
a=gcf(); a.figure_name='reponse indicielle D fermee';

