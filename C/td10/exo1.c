/*
    jouer avec les structs, avec une date et des fonctions 
    initDate, lireDate, ecrirelndate, dateValide
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

typedef struct
{
	int jour, mois, annee;
	char nomDuMois [10];
}Date;


/********************* programmes td4 *********************/

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

/******************************************************************/

/*	Antecedent: jour, mois, annee 3 entiers
	Consequent: retourne vrai si la date est valide, faux sinon
*/
int dateValide(Date date){
	if(date.annee>=1600 && date.mois>=1 && date.mois<=12 && date.jour>=1 && date.jour<=joursDansMois(date.mois,date.annee)) return 1;
	return 0;
}

/*
	Arguments   : jour as int, mois as int, annee as int
	Consequents	: 
*/
Date initDate (int jour, int mois, int annee){
	char nomDuMois[12][10]= {"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};
	Date date = {jour,mois,annee};
	assert(dateValide(date));
	//date.jour=jour; date.mois=mois; date.annee=annee;
	strcpy(date.nomDuMois,nomDuMois[mois-1]);
	return date;
}

/*
	Arguments   : 
	Consequents	: 
*/
Date lireDate (){
	int jour,mois,annee;
	scanf("%d/%d/%d",&jour,&mois,&annee);
	return initDate(jour,mois,annee);
}

/*
	Arguments   : date as Date
	Consequents	: date on stdout
*/
void ecrirelnDate (Date date){
	printf("date: %d %s %d\n", date.jour, date.nomDuMois, date.annee);
}

int main(void){
	ecrirelnDate(initDate (27,1,2011));
	ecrirelnDate(initDate (28,2,2017));
	ecrirelnDate(lireDate ());

	return EXIT_SUCCESS;
}