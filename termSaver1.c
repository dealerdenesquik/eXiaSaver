#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "../Fonctions/printf_center.h"
#include "../Fonctions/clear.h"

int main(int argc, char *argv[]) {
  FILE* fichier = NULL;
  char caractere;
  char c;
  char chaine[10];

  int MIN = 1;
  int MAX = 5;
  int nombreAleatoire = 0;
  srand(time(NULL));
  nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;

  sprintf(chaine, "../termSaver1/PBM/image_%d.pbm", nombreAleatoire);
  fichier = fopen(chaine, "r"); // OUVRE LE FICHIER EN LECTURE

  term_clear(); // EFFACE LE TERMINAL
  if (fichier != NULL) { // SI L'IMAGE EST BIEN RECUE
    fseek (fichier, 14, SEEK_SET); // SKIP LES PREMIERS ELEMENTS POUR ALLER A L'IMAGE 0/1
    do {
      caractere = fgetc(fichier); // AFFECTE LA LIGNE DANS CHAINE
      if (caractere == '0') {caractere = ' ';} // SI IL Y A UN 0 DANS LE FICHIER PBM -> LE REMPLACER PAR UN ESPACE
      //else if (caractere == ' ') {caractere = '\0';} // SUPPRIME LES ESPACES DU FICHIER PBM
      else if (caractere == '1') {caractere = 'X';} // SI IL Y A UN 1 DANS LE FICHIER PBM -> LE REMPLACER PAR UN X
      printf("%c", caractere); // AFFICHE LE CARACTERE (X ou ESPACE)
    } while (caractere != EOF); // LIT JUSQU'A LA FIN DU FICHIER
    //fclose(fichier); // FERME LE FICHIER
  }
  else {printf("Le fichier ne peut pas être ouvert\n");} // SI L'IMAGE N'EST PAS RECUE
  c = getchar(); // ATTEND QUE L'UTILSATEUR ENTRE UNE TOUCHE POUR FERMER LE PROGRAMME
  if (c == ' ') {return EXIT_SUCCESS;}
}


// CENTRER : WIDTH / 2 - (LONGUEUR / 2)
