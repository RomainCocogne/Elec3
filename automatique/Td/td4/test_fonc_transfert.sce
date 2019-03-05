clear;
xdel(winsid());
t=linspace (0,1E-2,1E4);
p=poly(0,'p');
K=0.47;
Taum=0.034;
Taue=0.0005;

M3=syslin('c',K/(1+Taum*p));
m3=csim('step',t,M3);
M2=syslin('c',K/((1+Taum*p)*(1+Taue*p)));
m2=csim('step',t,M2);
M1=syslin('c',K/(1+Taum*p+Taum*Taue*p*p));
m1=csim('step',t,M1);

C=syslin('c',(1+Taum*p)/(Taum*p))

M1bf=M1/(1+M1);
M2bf=M2/(1+M2);
M3bf=M3/(1+M3);


scf(1);
plot2d(t,[m1;m2;m3]',,leg='2nd ordre amorti @ 2 1er ordre en serie @ 1 seule cst de tps');
a=gcf(); a.figure_name='M1 M2 M3 indicielle';

scf(2);
evans(C*M1);
sgrid(1,2425.36);
a=gcf(); a.figure_name='Lieu evans M1*C';
scf(3);
evans(C*M2);
sgrid(1,2425.36);
a=gcf(); a.figure_name='Lieu evans M2*C';
scf(4);
evans(C*M3);
sgrid(1,2425.36);
a=gcf(); a.figure_name='Lieu evans M3*C';

