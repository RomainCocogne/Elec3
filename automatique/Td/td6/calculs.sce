clear;
xdel(winsid());
t=linspace (0,100,1E4);
p=poly(0,'p');

Go=syslin('c',1/(p*(1+0.5*p)*(1+0.05*p)));
Tau=0.13; a=3.17;
C=syslin('c',10*(1+a*Tau*p)/(1+Tau*p));
Gf=C*Go/(1+C*Go);
//scf(1);
//bode(Go);
//a=gcf(); a.figure_name='bode G ';
//
scf(2);
black(10*Go);
a=gcf(); a.figure_name='Black G';
//
//scf(3);
//y=csim(2*t,t,Gf);
//plot2d(t,[y;2*t]');
//a=gcf(); a.figure_name='reponse rampe G';


//Exercice 2
Go2=syslin('c',10/((1+0.1*p)*(1+20*p)));
Tau2=1;
C2=syslin('c',10*(1+1/(Tau2*p)));
scf(4);
y=csim('step',t,Go2);
plot2d(t,y);
a=gcf(); a.figure_name='reponse indicielle G2';
scf(5);
black(25*Go2);
a=gcf(); a.figure_name='back G2';
scf(6);
bode(Go2);
a=gcf(); a.figure_name='bode G2 ';
