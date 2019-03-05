clear;
xdel(winsid());
t=linspace (0,20,1E5);
p=poly(0,'p');

K=1;

H=syslin('c',K/(p*(p+1)*(p+2)));
T=syslin('c',K/(p+0.1*p*p+p*p*p));
Tbf=T/(1+T);
MGH=g_margin(H);
MPH=p_margin(H);
MGT=g_margin(T);
MPT=p_margin(T);

scf(1);
bode(H,1E-3,100);
a=gcf(); a.figure_name='bode H';
scf(2);
black(H,1E-3,100);
a=gcf(); a.figure_name='black H';
scf(3);
bode(T,1E-3,100);
a=gcf(); a.figure_name='bode T';
scf(4);
black(T,1E-3,100);
a=gcf(); a.figure_name='black T';
scf(5);
tbf=csim('step',t,Tbf);
plot2d(t,tbf);
a=gcf(); a.figure_name='rep indicielle en bf T';
