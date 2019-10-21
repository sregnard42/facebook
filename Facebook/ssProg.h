#ifndef SSPROG_H_INCLUDED
#define SSPROG_H_INCLUDED
#include "Facebook.h"

int menu(); //Renvoie le choix de l'utilisateur
/*
    Fonction menu renvoie entier
*/

bool rechercheTab1D (int x, int tab[MAXP], int nbVal, int& indice); //Recherche une valeur donnée dans un tableau donné et retourne vrai si trouvée.
/*
    Fonction rechercheTab1D(x,tab,nbVal,indice) renvoie booléen
    paramètres : (D) x : entier
                 (D) tab : tableau [1,MAXP] d'entiers
                 (D) nbVal : entier
                 (R) indice : entier
*/

#endif // SSPROG_H_INCLUDED
