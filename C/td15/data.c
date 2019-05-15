#include "data.h"

void initValCourante(ValeurCourante *val){
	val->valeur=0.0;
	val->tauxDeChange=2.0;
	val->ZoneSaisie=NULL;
}