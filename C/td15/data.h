#pragma once

#include <libsx.h>
#include <stdlib.h>


typedef  struct{
	double valeur;
	double tauxDeChange;
	Widget  ZoneSaisie;
} ValeurCourante;

void initValCourante(ValeurCourante *val);