/*
 * Ce programme lit une lettre minuscule sur
 * l'entrée standard et écrit sa forme majuscule sur
 * la sortie standard
 *
 * @author vg@unice.fr 01/10/2010
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
  char lettre;

  printf("Tapez une lettre minuscule : ");
  scanf("%c", &lettre);

  if (!islower(lettre)) {
    /* lettre n'est pas une minuscule */
    fprintf(stderr, "Erreur : lettre minuscule attendue\n");
    return EXIT_FAILURE;
  }
  /* lettre est une minuscule => écrire sa majuscule */
  printf("minuscule : %c - masjuscule : %c\n", lettre, toupper(lettre));

  return EXIT_SUCCESS;
}
