#ifndef SSPROG_H_INCLUDED
#define SSPROG_H_INCLUDED
#include "Facebook.h"

int menu(); //Renvoie le choix de l'utilisateur
/*
    Fonction menu renvoie entier
*/

bool rechercheTab1D (int x, int tab[MAXP], int nbVal, int& indice); //Recherche une valeur donn�e dans un tableau donn� et retourne vrai si trouv�e.
/*
    Fonction rechercheTab1D(x,tab,nbVal,indice) renvoie bool�en
    param�tres : (D) x : entier
                 (D) tab : tableau [1,MAXP] d'entiers
                 (D) nbVal : entier
                 (R) indice : entier
*/

#endif // SSPROG_H_INCLUDED
