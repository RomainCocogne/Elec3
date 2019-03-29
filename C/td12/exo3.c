/*
    structure de formes. jouer avec les pointeurs
    simuler des tableaux dynamiques
    comme exo2 mais avec des fonctions longueur, ieme, inserer, supprimer	
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

/*
	definition du type forme
*/
typedef enum { carre , rond , triangle } forme;

/*
	definition du type noeud et listedeforme
*/
typedef struct noeud {
	forme f; 				// forme
	struct noeud *suivant;	//pointeur vers forme suivante
} * ListeDeFormes;

/*
	afficher une forme
*/
void afficherForme(forme f) {
	switch(f) {
		case carre    : printf("carre\n")   ; 		break; 
		case rond     : printf("rond\n")    ; 		break;
		case triangle : printf("triangle\n"); 		break;
		default       : printf("forme  inconnue\n");
	}
}

/*
	cree un nouvel element qui pointe vers un listedeforme
*/
void *	initForme (forme f){
	ListeDeFormes lf=malloc(sizeof(struct noeud)); //allocation espace memoire
	lf->f=f;			//initialise la forme
	lf->suivant=NULL;	//pointe vers 'la terre'
	return lf;
}

/*
	affiche une liste de formes
*/
void afficherListedeForme (ListeDeFormes lf){
	struct noeud *s= lf;		// noeud qui pointe vers la premiere forme
	while(s){
		afficherForme(s->f);	//on affiche chaque forme
		s=s->suivant;			//on passe a la forme suivante
	}
}

/*
	renvoie le nombre de formes dans la liste
*/
int longueur (ListeDeFormes lf){
	int i=0;				//compteur 
	struct noeud *s= lf;	//noeud qui pointe vers la premiere forme
	while(s){				//tant qu'il y a des formes (a la fin ca vaudra NULL)
		i++;				//on incremente le compteur 
		s=s->suivant;		//on passe a la forme suivante
	}
	return i;
}

/*
	renvoie la forme a la ieme position
*/
forme ieme (ListeDeFormes lf, int r){
	assert(r>0 && r<=longueur(lf));		//on verifie que r est valide
	struct noeud *s= lf;			
	while(--r) s=s->suivant;			//on se positionne a la r'ieme position
	return s->f;
}

/*
	insere forme f au rang r
*/
void inserer (ListeDeFormes *lf, int r, forme f){
	assert(r>0 && r<=longueur(*lf)+1);		//verfification (longueur+1 pour pouvoir ajouter une forme a la fin)
	ListeDeFormes newlf = initForme(f);		//creation d'une nouvelle forme
	while(--r) lf=&(**lf).suivant;			//on pointe sur la r'ieme position avec le pointeur lf
	newlf->suivant=*lf;						//on insere la nouvelle forme
	*lf=newlf;								
	
}

/*
	supprime la forme f an rang r
*/
void supprimer (ListeDeFormes *lf, int r){
	assert(r>0 && r<=longueur(*lf));	
	while(--r) lf=&(**lf).suivant;		
	free(*lf);				//on supprime la forme
	*lf=(**lf).suivant;		//on racorde les deux bouts
	//free((**lf).suivant);
}

int main(int argc, char const *argv[]){
//definition de la liste de forme
	ListeDeFormes lf;
	lf=initForme(rond);

	inserer(&lf,2, carre);
	inserer(&lf,3, triangle);
	inserer(&lf,4, carre);
	inserer(&lf,5, rond);
//affichage de lf
	printf("une liste de formes: \n");
	afficherListedeForme(lf); 
	printf("-----------\n");

//ajouter un carre en premiere position
	inserer(&lf,1,carre);
//affichage de lf
	printf("ajout d'un carre au debut: \n");
	afficherListedeForme(lf); 
	printf("-----------\n");

//supprimer une forme
	supprimer(&lf,4);
//affichage de lf
	printf("suppression de la 4eme forme: \n");
	afficherListedeForme(lf); 
	printf("-----------\n");

//longueur de lf
	printf("longueur de lf: %d\n", longueur(lf));
//ieme position
	printf("element a la 3eme position: ");
	afficherForme(ieme(lf,3));

	return EXIT_SUCCESS;
}