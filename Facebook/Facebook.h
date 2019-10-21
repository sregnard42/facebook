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
    // fb[i] a pour ID tabId[i]. Et ses relations sont conserv�es dans tabRelation[(tabId[i])][0 � nbPers]
    // Une Personne a un ID lui correspondant, et ses relations peuvent �tre retrouv�es gr�ce � son ID.
    int IDLibre; //Garde en m�moire un ID pr�alablement d�tach� d'une personne afin qu'il soit � nouveau utilis�.

    Facebook()
    {
        nbPers=0;
        IDLibre=0;
        initialiseTabRelation();
    }; //Constructeur

    //Initialise le tableau des relations � false pour toutes les cases
    void initialiseTabRelation();


    void affiche(); //Affiche les personnes ainsi que leurs amiti�s sur le r�seau
    void afficheFbId(); //Permet de v�rifier le bon fonctionnement des m�thodes modifiant fb et tabId
    void afficheAmities(); //Permet de v�rifier le bon fonctionnement des m�thodes modifiant tabRelation

    void creerCompte(Personne& p)throw(int); //Permet la cr�ation d'un compte d'une personne
    /*
        Proc�dure creerCompte(p) lance exception entier
        param�tre : (D) p : Personne
    */

    void fermerCompte(Personne& p)throw(int); //Permet de supprimer le compte d'une personne
    /*
        Proc�dure fermerCompte(p) lance exception entier
        param�tre : (D) p : Personne
    */

    bool ajoutRelationAmitie(Personne& p, Personne& p2); //Permet d'ajouter une amiti� entre deux personnes
    /*
        Fonction ajoutRelationAmitie(p, p2) renvoie bool�en
        param�tres : (D) p : Personne
                     (D) p2 : Personne
    */

    bool supprimeRelationAmitie(Personne& p, Personne& p2); //Permet de supprimer une amiti� entre deux personnes
    /*
        Fonnction supprimeRelationamitie(p, p2) renvoie bool�en
        param�tres : (D) p : Personne
                     (D) p2 : Personne
    */

    bool amis(Personne& p, Personne& p2)throw(int); //Permet de v�rifier si deux personnes sont amis
    /*
        Fonction amis(p,p2) renvoie bool�en lance exception entier
        param�tres : (D) p : Personne
                     (D) p2 : Personne
    */

    void listerAmisCommuns(Personne& p, Personne& p2)throw(int); //Permet de lister les amis en communs de deux personnes
    /*
        Proc�dure listerAmisCommuns(p,p2) lance exception entier
        param�tres : (D) p : Personne
                     (D) p2 : Personne
    */

    bool amisIndirects (Personne& p, Personne& p2)throw(int); //Permet de v�rifier si deux personnes sont des amis indirects
    /*
        Fonction amisIndirects(p,p2) lance exception entier
        param�tres : (D) p : Personne
                     (D) p2 : Personne
    */

    Personne lePlusdAmi()throw(int); //Permet de trouver en renvoyer la personne ayant le plus d'amis, lance exception s'il n'y aucune amiti�
    /*
        Fonction lePlusdAmi renvoie Personne lance exception entier
    */

    bool idLibre(int id); //V�rifie si un ID est d�j� pris ou pas (Ainsi aucun risque d'�craser des donn�es existantes lors de la cr�ation d'un compte)
    /*
        Fonction idLibre (id) renvoie bool�en
        param�tre : (D) id : entier
    */

    int trouverID(Personne& p); //Permet de trouver l'ID d'une personne d'apr�s son Nom et Pr�nom
    /*
        Fonction trouverID(p) renvoie entier
        param�tre : (D) p : Personne
    */

    int trouverPlaceOrdreAlphabetique(Personne& p); //Permet de trouver o� placer une nouvelle personne souhaitant s'inscrire
    /*
        Fonction trouverPlaceOrdreAlphabetique(p) renvoie entier
        param�tre : (D) p : Personne
    */

    bool rechercheDichotomiqueTabFacebook(Personne& p, int& indice); //Recherche dans un tableau ordonn� alphab�tiquement.
    /*
        Fonction rechercheDichotomiqueTabFacebook (p, indice) renvoie bool�en
        param�tres : (D) p : Personne
                     (D) indice : entier
    */

    //M�thode s�quentielle de recherche. Renvoie vrai si la valeur cherch�e est trouv�e, ainsi que l'indice de la case.(inutilis�e dans le programme final)
    //bool rechercheBasiqueTabFacebook(Personne& p, int& indice);
};

#endif // FACEBOOK_H_INCLUDED
