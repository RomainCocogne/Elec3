/*
    
*/
#include "header.h"

int main(int argc, char const *argv[]){
	Player joueur;
	joueur.name="Romain";
	joueur.score=20;
	addScore(joueur);
	return EXIT_SUCCESS;
}