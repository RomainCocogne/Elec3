#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libsx.h>
#include "callbacks.h"
#include "data.h"


void init_display(int argc, char **argv, void *d){
	Widget stringentry, buttonquit, buttoneuro, buttondollars, buttontaux;
	buttonquit=MakeButton("quit",quit,NULL);
	buttondollars=MakeButton("dollars",dollars,d);
	buttoneuro=MakeButton("euro",euro,d);
	buttontaux=MakeButton("change taux",changetaux,d);
	stringentry=MakeStringEntry("",200, NULL,d);

	((ValeurCourante *)d)->ZoneSaisie=stringentry;

	SetWidgetPos(buttoneuro,PLACE_RIGHT,buttonquit,PLACE_UNDER,stringentry);
	SetWidgetPos(buttondollars,PLACE_RIGHT,buttoneuro,PLACE_UNDER,stringentry);
	SetWidgetPos(buttontaux,PLACE_RIGHT,buttondollars,PLACE_UNDER,stringentry);
	SetWidgetPos(buttonquit,PLACE_UNDER,stringentry,NO_CARE,NULL);
	GetStandardColors();
}

int main (int argc ,char **argv){
	if(OpenDisplay(argc , argv) == 0) {
		fprintf(stderr ,"Can’t open  display\n");
		return EXIT_FAILURE;
	}

	ValeurCourante val;
	initValCourante(&val);
	init_display(argc, argv, &val);
	ShowDisplay();
	MainLoop();
	return EXIT_SUCCESS;
}