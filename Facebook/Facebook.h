#ifndef FACEBOOK_H_INCLUDED
#define FACEBOOK_H_INCLUDED
#include "Personne.h"
#include "ssProg.h"

class Facebook
{
public :
    Personne fb[MAXP];
    int tabId[MAXP];
    int nbPers;
    bool tabRelation[MAXP][MAXP];
    // fb[i] a pour ID tabId[i]. Et ses relations sont conservées dans tabRelation[(tabId[i])][0 à nbPers]
    // Une Personne a un ID lui correspondant, et ses relations peuvent être retrouvées grâce à son ID.
    int IDLibre; //Garde en mémoire un ID préalablement détaché d'une personne afin qu'il soit à nouveau utilisé.

    Facebook()
    {
        nbPers=0;
        IDLibre=0;
        initialiseTabRelation();
    }; //Constructeur

    //Initialise le tableau des relations à false pour toutes les cases
    void initialiseTabRelation();


    void affiche(); //Affiche les personnes ainsi que leurs amitiés sur le réseau
    void afficheFbId(); //Permet de vérifier le bon fonctionnement des méthodes modifiant fb et tabId
    void afficheAmities(); //Permet de vérifier le bon fonctionnement des méthodes modifiant tabRelation

    void creerCompte(Personne& p)throw(int); //Permet la création d'un compte d'une personne
    /*
        Procédure creerCompte(p) lance exception entier
        paramètre : (D) p : Personne
    */

    void fermerCompte(Personne& p)throw(int); //Permet de supprimer le compte d'une personne
    /*
        Procédure fermerCompte(p) lance exception entier
        paramètre : (D) p : Personne
    */

    bool ajoutRelationAmitie(Personne& p, Personne& p2); //Permet d'ajouter une amitié entre deux personnes
    /*
        Fonction ajoutRelationAmitie(p, p2) renvoie booléen
        paramètres : (D) p : Personne
                     (D) p2 : Personne
    */

    bool supprimeRelationAmitie(Personne& p, Personne& p2); //Permet de supprimer une amitié entre deux personnes
    /*
        Fonnction supprimeRelationamitie(p, p2) renvoie booléen
        paramètres : (D) p : Personne
                     (D) p2 : Personne
    */

    bool amis(Personne& p, Personne& p2)throw(int); //Permet de vérifier si deux personnes sont amis
    /*
        Fonction amis(p,p2) renvoie booléen lance exception entier
        paramètres : (D) p : Personne
                     (D) p2 : Personne
    */

    void listerAmisCommuns(Personne& p, Personne& p2)throw(int); //Permet de lister les amis en communs de deux personnes
    /*
        Procédure listerAmisCommuns(p,p2) lance exception entier
        paramètres : (D) p : Personne
                     (D) p2 : Personne
    */

    bool amisIndirects (Personne& p, Personne& p2)throw(int); //Permet de vérifier si deux personnes sont des amis indirects
    /*
        Fonction amisIndirects(p,p2) lance exception entier
        paramètres : (D) p : Personne
                     (D) p2 : Personne
    */

    Personne lePlusdAmi()throw(int); //Permet de trouver en renvoyer la personne ayant le plus d'amis, lance exception s'il n'y aucune amitié
    /*
        Fonction lePlusdAmi renvoie Personne lance exception entier
    */

    bool idLibre(int id); //Vérifie si un ID est déjà pris ou pas (Ainsi aucun risque d'écraser des données existantes lors de la création d'un compte)
    /*
        Fonction idLibre (id) renvoie booléen
        paramètre : (D) id : entier
    */

    int trouverID(Personne& p); //Permet de trouver l'ID d'une personne d'après son Nom et Prénom
    /*
        Fonction trouverID(p) renvoie entier
        paramètre : (D) p : Personne
    */

    int trouverPlaceOrdreAlphabetique(Personne& p); //Permet de trouver où placer une nouvelle personne souhaitant s'inscrire
    /*
        Fonction trouverPlaceOrdreAlphabetique(p) renvoie entier
        paramètre : (D) p : Personne
    */

    bool rechercheDichotomiqueTabFacebook(Personne& p, int& indice); //Recherche dans un tableau ordonné alphabétiquement.
    /*
        Fonction rechercheDichotomiqueTabFacebook (p, indice) renvoie booléen
        paramètres : (D) p : Personne
                     (D) indice : entier
    */

    //Méthode séquentielle de recherche. Renvoie vrai si la valeur cherchée est trouvée, ainsi que l'indice de la case.(inutilisée dans le programme final)
    //bool rechercheBasiqueTabFacebook(Personne& p, int& indice);
};

#endif // FACEBOOK_H_INCLUDED
