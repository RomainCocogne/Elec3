#include "callbacks.h"

void quiter (Widget w,void *d){
  exit(EXIT_SUCCESS);
}

void ruler (Widget w,void *d){
  Widget window,label_rules;
  window=MakeWindow("Rules",NULL,NONEXCLUSIVE_WINDOW);
  SetCurrentWindow(window);
  label_rules=MakeLabel(" The cards are layed in rows, face down.\n Turn over any two cards.If the two cards match,they are kept shown.\n If they don't match,they are turned back over if you click anywhere on the screen.\n Remember what was on each card and where it was.\n The game is over when all the cards have been matched and revealed");
  SetWidgetPos(label_rules,NO_CARE,NULL,NO_CARE,NULL);

  ShowDisplay();
  
}
  
  
  
