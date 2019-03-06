/*
    nombres complexes
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>


typedef struct{
	double reel; double img;
} Complexe;

const Complexe I = {0.0,1.0};

/*
	Arguments   : c as Complexe
	Consequents	: c.reel
*/
double partieReelle (const Complexe c){
	return c.reel;
}
/*
	Arguments   : c as Complexe
	Consequents	: c.img
*/
double partieImaginaire (const Complexe c){
	return c.img;
}

/*
	Arguments   : c as Complexe
	Consequents	: module de c
*/
double rho (const Complexe c){
	return sqrt(partieReelle(c)*partieReelle(c)+partieImaginaire(c)*partieImaginaire(c));
}

/*
	Arguments   : c as Complexe
	Consequents	: argument de c
*/
double theta (const Complexe c){
	return atan2(partieImaginaire(c),partieReelle(c));
}

/*
	Arguments   : rho as double, theta as double
	Consequents	: c en cartesien
*/
Complexe polComplexe (const double rho, const double theta){
	Complexe c = {rho*cos(theta), rho*sin(theta)};
	return c;
}

/* 
	operations sur complexes
*/
Complexe  plus  (const Complexe a, const Complexe b) {Complexe c = {a.reel+b.reel, a.img+b.img}; return c;}
Complexe  moins (const Complexe a, const Complexe b) {Complexe c = {a.reel-b.reel, a.img-b.img}; return c;}
Complexe  mult  (const Complexe a, const Complexe b) {return polComplexe(rho(a)*rho(b),theta(a)+theta(b));}
Complexe  divi  (const Complexe a, const Complexe b) {return polComplexe(rho(a)/rho(b),theta(a)-theta(b));}

/*
	fonctions de comparaison
*/
int egal (const Complexe c1, const Complexe c2){
	double epsilon = 1e-8;
	Complexe res = moins(c1,c2);
	return ((res.reel<epsilon && res.img<epsilon));
}
int different (const Complexe c1, const Complexe c2){ return !egal(c1,c2);}

int main(void){
	Complexe z = {2.0,1.0};
	printf("re(I)=%f, im(I)=%f\n",partieReelle(I),partieImaginaire(I));
	printf("re(z)=%f, im(z)=%f\n",partieReelle(z),partieImaginaire(z));
	printf("theta(z)=%f\n", theta(z));
	Complexe c =polComplexe (rho(z)+1.0,theta(z));
	printf("re(c)=%f, im(c)=%f\n",partieReelle(c),partieImaginaire(c));
	printf("re(c/z)=%f, im(c/z)=%f\n",partieReelle(divi(c,z)),partieImaginaire(divi(c,z)));
	printf("c!=z? %d\n", different(c,z));
	return EXIT_SUCCESS;
}