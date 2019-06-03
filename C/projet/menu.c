#include "menu.h"

void init_display(int argc, char *argv[], void *d){
  CloseWindow();
  Widget window;
  window=MakeWindow("menu",NULL,NONEXCLUSIVE_WINDOW);
  SetCurrentWindow(window);
  Widget welcome,highest_scores,rules,difficulty,diff_3x2,diff_4x3,diff_4x4,diff_5x4,diff_6x5,diff_8x4,start,quit,space1,space2,space3,space4 ;

  //labels.
  welcome=MakeLabel("Welcome to MEMORY");
  difficulty=MakeLabel("Difficulty:");
  space1=MakeLabel("");
  space2=MakeLabel("");
  space3=MakeLabel("                  ");
  space4=MakeLabel("        ");

  //création de pop_up.
  rules=MakeButton("Rules",ruler,NULL);

  //création des boutons.
  highest_scores=MakeButton("Highest_scores",NULL,NULL);
  start=MakeButton("Start",genereGame,NULL);
  quit=MakeButton("Quit", quiter,NULL);

  //menu difficulté.
  diff_3x2=MakeButton("3x2",NULL,NULL);
  diff_4x3=MakeButton("4x3",NULL,NULL);
  diff_4x4=MakeButton("4x4",NULL,NULL);
  diff_5x4=MakeButton("5x4",NULL,NULL);
  diff_6x5=MakeButton("6x5",NULL,NULL);
  diff_8x4=MakeButton("8x4",NULL,NULL);

  //position des widgets.
  SetWidgetPos(highest_scores,PLACE_UNDER,welcome,NO_CARE,NULL);
  SetWidgetPos(space4,PLACE_UNDER,welcome,PLACE_RIGHT,highest_scores);
  SetWidgetPos(rules,PLACE_RIGHT,space4,PLACE_UNDER,welcome);
  SetWidgetPos(space1,PLACE_UNDER,highest_scores,NO_CARE,NULL);
  SetWidgetPos(difficulty,PLACE_UNDER,space1,NO_CARE,NULL);
  SetWidgetPos(diff_3x2,PLACE_UNDER,difficulty,NO_CARE,NULL);
  SetWidgetPos(diff_4x3,PLACE_RIGHT,diff_3x2,PLACE_UNDER,difficulty);
  SetWidgetPos(diff_4x4,PLACE_RIGHT,diff_4x3,PLACE_UNDER,difficulty);
  SetWidgetPos(diff_5x4,PLACE_UNDER,diff_3x2,NO_CARE,NULL);
  SetWidgetPos(diff_6x5,PLACE_RIGHT,diff_5x4,PLACE_UNDER,diff_4x3);
  SetWidgetPos(diff_8x4,PLACE_RIGHT,diff_6x5,PLACE_UNDER,diff_4x4);
  SetWidgetPos(space2,PLACE_UNDER,diff_5x4,NO_CARE,NULL);
  SetWidgetPos(start,PLACE_UNDER,space2,NO_CARE,NULL);
  SetWidgetPos(space3,PLACE_RIGHT,start,PLACE_UNDER,space2);
  SetWidgetPos(quit,PLACE_RIGHT,space3,PLACE_UNDER,space2);

  ShowDisplay(); 
}


