/*
    programme calculant la date
    du lendemain a partir d une date
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>


/*  Antécédent: jour , mois , annee  représentent  une  date  valide
	Conséquent: la date  est  écrite  sur la  sortie  standard
				avec le mois en  toutes  lettres
*/
void ecrireDate(int jour ,int mois ,int annee){
	char mois_lettre[12][10]= {"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};
	printf("%d %s %d\n",jour, mois_lettre[mois-1], annee);
}

/*  Antécédent: annee> AnneeMin  
    Conséquent: bissextile = vrai si l’année  est  bissextile , et
                faux  sinon
*/
int bissextile(int annee){
	return (annee%4==0 ? (annee%100==0 ? (annee%400==0 ? 1: 0): 1): 0);
}

/*  Antécédent: mois , annee , deux  entiers  qui  représentent  un mois
				et une  annee  valides
	Conséquent: retourne  le  nombre  de jour  dans le mois
*/
int joursDansMois(int mois ,int annee){
	switch (mois) {
	    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	    return 31;
	    case 2:
	    return (bissextile(annee) ? 29: 28);
	    default:
	    return 30;
	}
}

/*	Antecedent: jour, mois, annee 3 entiers
	Consequent: retourne vrai si la date est valide, faux sinon
*/
int valide(int jour, int mois, int annee){
	if(annee>=1600 && mois>=1 && mois<=12 && jour>=1 && jour<=joursDansMois(mois,annee)) return 1;
	return 0;
}

/*	Antecedent: jour, mois, annee 3 entiers valides
	Consequent: ecrit sur stdout un jour, mois et une annee correspondant
				au jour suivant l'antecedent
*/
void dateLendemain(int jour, int mois, int annee){
	if(jour==joursDansMois(mois,annee)){
	    jour=1; mois+=1;
	    if(mois>12){
	        mois=1; annee+=1;
	    }
	}
	else{
		jour+=1;
	}
	ecrireDate(jour,mois,annee);
}

int main(void){
	int jour,mois,annee;
	scanf("%d %d %d",&jour,&mois,&annee);
	assert(valide(jour,mois,annee));

	dateLendemain(jour,mois,annee);
	
	return EXIT_SUCCESS;
}

