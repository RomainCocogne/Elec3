xdel(winsid())
clear

t=linspace (0,10,1000);
p=poly(0,'p');

G=2; Tau=1;K=1;


//A=syslin('c',G/(1+Tau*p));  //pour la question 2
//A=syslin('c',G/p);        //pour la question 3
A=syslin('c',K/(p+0.2*p*p+p*p*p));        //pour la question 4
B=1;

F=syslin('c',A/(1+B*A));
f=csim('step',t,F);

epsilon1= ones(t)-f;

scf(1);
plot2d(t,f);
plot2d(t,epsilon1);

scf(2);
deff('u=rampe(t)','u=t');
fr=csim(rampe,t,F);
epsilon2= rampe(t)-fr;

plot2d(t,fr);
plot2d(t,epsilon2);

scf(3);
bode(A,1E-2,100);
scf(4);
black(F);
