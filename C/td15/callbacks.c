#include "callbacks.h"

void quit (Widget w, void *d){
	exit(EXIT_SUCCESS);
}

void dollars(Widget w, void *d){
	char str[100];
	strcpy(str,GetStringEntry(((ValeurCourante*)d)->ZoneSaisie));
	((ValeurCourante *)d)->valeur=atof(str);
	double newval=((ValeurCourante *)d)->valeur* ((ValeurCourante *)d)->tauxDeChange;
	sprintf(str,"%lf",newval);
	SetStringEntry(((ValeurCourante*)d)->ZoneSaisie,str);
}

void euro (Widget w, void *d){
	char str[100];
	strcpy(str,GetStringEntry(((ValeurCourante*)d)->ZoneSaisie));
	((ValeurCourante *)d)->valeur=atof(str);
	double newval=((ValeurCourante *)d)->valeur/ ((ValeurCourante *)d)->tauxDeChange;
	sprintf(str,"%lf",newval);
	SetStringEntry(((ValeurCourante*)d)->ZoneSaisie,str);

}

void changetaux(Widget w, void *d){
	
}
