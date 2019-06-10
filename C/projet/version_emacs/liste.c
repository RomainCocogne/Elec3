/*
  fonctions de base d'une liste
  implementation de liste.h
*/
#include "liste.h" 


/****************************/
//	 variables	    //
/****************************/
const Liste ListeVide=NULL;

/****************************/
//	  fonctions	    //
/****************************/

/*
  cree un nouvel element qui pointe vers une liste
  @args:
  - l: Pointeur sur la liste a initialiser
*/
void initListe (Liste *l){
  *l=malloc(sizeof(struct noeud)); //allocation espace memoire
  *l=ListeVide;
}

/*
  supprimer une liste
  @args:
  - l: Pointeur sur la liste a supprimer
*/
void rmListe(Liste *l){
  struct noeud *s= *l;	
  for (int i = 1; i <= longueur(*l); ++i)	//on parcourt toute la liste
    {
      struct noeud *suivant= s;			//on sauvegarde la position de l'eement suivant
      free(s);				        //on supprime l'element courant
      s=suivant;				//on passa au suivant
    }
  free(s);

}

/*
  renvoie le nombre d'elements dans la liste
  @args:
  - Liste dont on veut connaitre la longueur
  @return:
  - Int la taille de la liste
*/
int longueur (Liste l){
  int i=0;				//compteur 
  struct noeud *s= l;	                //noeud qui pointe vers la premiere forme
  while(s){				//tant qu'il y a des elements (a la fin ca vaudra NULL)
    i++;				//on incremente le compteur 
    s=s->suivant;		        //on passe a l element suivant
  }
  return i;
}

/*
  renvoie l'element a la ieme position
  @args:
  - l: Liste dont on veut chercher l'element
  - r: Int representant la position de l'element, 1 etant le premier de la liste
  @return:
  - element de la liste
*/
void *ieme (Liste l, int r){
  assert(r>0 && r<=longueur(l));		//on verifie que r est valide
  struct noeud *s= l;			
  while(--r) s=s->suivant;			//on se positionne a la r'ieme position
  return (s->val);
}

/*
  insere element f au rang r
  @args:
  - l: Pointeur sur la liste que l'on veut modifier
  - r: Int representant le rang d'insertion. 1 etant le debut de la liste
  - f: Pointeur sur void sera l'element a ajouter a la liste
*/
void inserer (Liste *l, int r, void *f){
  assert(r>0 && r<=longueur(*l)+1);		//verfification (longueur+1 pour pouvoir ajouter un element a la fin)
  Liste newl=malloc(sizeof(struct noeud));	
  newl->suivant=NULL;			        //pointe vers 'la terre'
  newl->val=f;					//creation d'un nouveau element
  while(--r) l=&(**l).suivant;			//on pointe sur la r'ieme position avec le pointeur l
  newl->suivant=*l;				//on insere le nouveau element
  *l=newl;								
}

/*
  supprime l element f an rang r
  @args:
  - l: Pointeur sur la liste que l'on veut modifier
  - r: Int representant le rang de suppression. 1 etant le debut de la liste
*/
void supprimer (Liste *l, int r){
  assert(r>0 && r<=longueur(*l));	
  while(--r) l=&(**l).suivant;		
  struct noeud *suivant=(**l).suivant;                           //on sauvegarde la forme suivante pour ne pas la perdre
  free(*l);							 //on supprime l'element
  *l=suivant;			   				 //on racorde les deux bouts
}
