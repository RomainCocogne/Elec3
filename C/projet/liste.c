/*
    fonctions de base d'une liste
    implementation de liste.h
*/
#include "liste.h" 


/****************************/
//		  variables			//
/****************************/
const Liste ListeVide=NULL;

/****************************/
//		  fonctions			//
/****************************/

/*
	cree un nouvel element qui pointe vers une liste
*/
void initListe (Liste *l){
	*l=malloc(sizeof(struct noeud)); //allocation espace memoire
	*l=ListeVide;
}

/*
	renvoie le nombre de formes dans la liste
*/
int longueur (Liste l){
	int i=0;				//compteur 
	struct noeud *s= l;	    //noeud qui pointe vers la premiere forme
	while(s){				//tant qu'il y a des elements (a la fin ca vaudra NULL)
		i++;				//on incremente le compteur 
		s=s->suivant;		//on passe a l element suivant
	}
	return i;
}

/*
	renvoie l element a la ieme position
*/
void *ieme (Liste l, int r){
	assert(r>0 && r<=longueur(l));		//on verifie que r est valide
	struct noeud *s= l;			
	while(--r) s=s->suivant;			//on se positionne a la r'ieme position
	return (s->val);
}

/*
	insere element f au rang r
*/
void inserer (Liste *l, int r, void *f){
	assert(r>0 && r<=longueur(*l)+1);		//verfification (longueur+1 pour pouvoir ajouter un element a la fin)
	Liste newl=malloc(sizeof(struct noeud));	
	newl->suivant=NULL;						//pointe vers 'la terre'
	newl->val=f;							//creation d'un nouveau element
	while(--r) l=&(**l).suivant;			//on pointe sur la r'ieme position avec le pointeur l
	newl->suivant=*l;						//on insere le nouveau element
	*l=newl;								
}

/*
	supprime l element f an rang r
*/
void supprimer (Liste *l, int r){
	assert(r>0 && r<=longueur(*l));	
	while(--r) l=&(**l).suivant;		
	struct noeud *suivant=(**l).suivant; //on sauvegarde la forme suivante pour ne pas la perdre
	free(*l);							 //on supprime la forme
	*l=suivant;			   				 //on racorde les deux bouts
}
