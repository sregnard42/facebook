#include "Facebook.h"

void Facebook::initialiseTabRelation() //Initialise le tableau des relations � false pour toutes les cases
{
    for (int i=0; i<MAXP; i++)
    {
        for (int j=0; j<MAXP; j++)
        {
            tabRelation[i][j]=false;
            if (i==j) tabRelation[i][j]=true;
        }
    }
}

void Facebook::affiche()
{
    cout << "Voici les personnes inscrites sur Facebook : " << endl;
    for (int i=0; i<nbPers; i++)
    {
        cout << "- ";
        fb[i].affiche();
        cout << endl;
    }

    int j;
    cout << endl << "Et les amities pour chacun d'entre eux : " << endl;
    for (int i=0; i<nbPers; i++)
    {
        j=0;
        while (j<nbPers)
        {
            if (amis(fb[i],fb[j]) && !(fb[i]==fb[j]))
            {
                fb[i].affiche();
                cout << " est ami avec ";
                fb[j].affiche();
                cout << endl;
            }
            j++;
        }
    }
}

void Facebook::afficheFbId() //Permet de v�rifier le bon fonctionnement des m�thodes modifiant fb et tabId
{
    for (int i=0; i<nbPers; i++)
    {
        cout << "fb[" << i << "] : ";
        fb[i].affiche();
        cout << "       tab[" << i << "] : " << tabId[i];
        cout << endl;
    }
}

void Facebook::afficheAmities() //Permet de v�rifier le bon fonctionnement des m�thodes modifiant tabRelation
{
    cout << "tabRelation :" << endl;
    for (int i=0; i<nbPers; i++)
    {
        for (int j=0; j<nbPers; j++)
        {
            cout << "[" << i << "][" << j << "] : " << tabRelation[i][j] << "   ";
        }
        cout << endl;
    }
}

void Facebook::creerCompte(Personne& p)throw(int)
{
    if (!(p.inscription(*this))) //V�rifie que l'inscription est possible
    {
        throw(1);
    }
    while (!idLibre(IDLibre)) //Permet de s'assurer que l'ID est bien libre, et sert �galement d'auto-incr�mentation � chaque nouveau compte.
    {
        IDLibre++;
        if (IDLibre==MAXP-1) IDLibre=0;
    }
    int id=IDLibre;

    int indice;
    //Si personne n'est inscrit
    if (nbPers==0) indice=0; //On place la personne dans la case 0.

    //Au moins une personne inscrite
    else
    {
        indice=trouverPlaceOrdreAlphabetique(p); //On cherche o� placer la personne dans le tableau
        //Une fois l'indice trouv� il faut d�caler le tableau vers la droite si n�cessaire en fonction de l'indice
        for (int i=nbPers; i>indice; i--)
        {
            fb[i]=fb[i-1];
            tabId[i]=tabId[i-1];
        }
    }

    //On place la personne dans le tableau
    fb[indice]=p;
    tabId[indice]=id;
    nbPers++;

    cout << "Compte cree avec succes." << endl;
}

void Facebook::fermerCompte(Personne& p)throw(int)
{
    if (!p.quitter(*this)) //V�rifie que la d�sinscription est possible
    {
        throw(1);
    }

    IDLibre=trouverID(p); //Servira d'ID pour le prochain compte cr��.

    //On supprime tous les liens d'amiti�s avec cette ID/personne
    for (int i=0; i<nbPers; i++)
    {
        for (int j=0; i<nbPers; i++)
        {
            if (i!=j) tabRelation[i][j]=false;
        }
    }

    int indice;
    rechercheDichotomiqueTabFacebook(p, indice); //On retrouve o� sont stock�s la personne et son ID dans les tableaux

    Personne vide;
    fb[indice]=vide; //On "vide" la case o� est stock�e la personne dans fb
    tabId[indice]=-1; //On modifie l'ID de la personne � -1 (puisqu'on ne peut pas vider la case)

    //Deux cas selon la valeur de indice
    if (indice==nbPers-1) {} //Pas besoin de changer l'ordre du tableau
    else //Si l'indice est compris entre 0 et nbPers-1, on d�cale le tableau vers la gauche (en �crasant la personne � effacer), en fonction de la valeur de l'indice.
    {
        for (int i=indice; i<nbPers-1; i++)
        {
            fb[i]=fb[i+1];
            tabId[i]=tabId[i+1];
        }
    }
    nbPers--;
    cout << "Compte ferme avec succes." << endl;
}

bool Facebook::ajoutRelationAmitie(Personne& p, Personne& p2)
{
    if (!p.inviterUnAmi(p2, *this)) //V�rifie si p est bien autoris� � ajouter p2 � ses amis dans f.
    {
        return false;
    }
    if (p==p2)
    {
        cout << "Ce sont les memes personnes ! " << endl;
        return false;
    }
    if (amis(p,p2))
    {
        cout << "Ces personnes sont deja amis !" << endl;
        return false;
    }
    int idp, idp2; //Correspond aux ID de p et p2
    idp=trouverID(p); //qui sont trouv�es par la m�thode trouverID
    idp2=trouverID(p2);

    //Et finalement confirmer l'amiti� des deux personnes dans tabRelation
    tabRelation[idp][idp2]=true;
    tabRelation[idp2][idp]=true;
    cout << "Ajout d'une amitie confirme !" << endl;
    return true;
}

bool Facebook::supprimeRelationAmitie(Personne& p, Personne& p2)
{
    if (!p.supprimerUnAmi(p2, *this)) //V�rifie si p est bien autoris� � supprimer p2 de ses amis dans f.
    {
        return false;
    }
    if (p==p2)
    {
        cout << "Ce sont les memes personnes ! " << endl;
        return false;
    }
    if (!(amis(p,p2)))
    {
        cout << "Ces personnes ne sont pas amis !" << endl;
        return false;
    }
    int idp, idp2; //Correspond aux ID de p et p2
    idp=trouverID(p); //qui sont trouv�es par la m�thode trouverID
    idp2=trouverID(p2);

    //Et finalement on met un terme � leur amiti� dans tabRelation gr�ce � l'ID
    tabRelation[idp][idp2]=false;
    tabRelation[idp2][idp]=false;
    cout << "Suppression d'une amitie confirme !" << endl;
    return true;
}

bool Facebook::amis(Personne& p, Personne& p2)throw(int)
{
    if (!p.existe(*this))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        p.affiche();
        cout << endl;
        throw(2);
    }
    if (!p2.existe(*this))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        p2.affiche();
        cout << endl;
        throw(2);
    }

    int idp, idp2;
    idp=trouverID(p);       //On retrouve les ID des personnes
    idp2=trouverID(p2);
    return (tabRelation[idp][idp2] && tabRelation[idp2][idp]);   //Puis renvoie la valeur les concernant stock�e dans tabRelation
}

void Facebook::listerAmisCommuns(Personne& p, Personne& p2)throw(int)
{
    if (!p.existe(*this))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        p.affiche();
        cout << endl;
        throw(2);
    }
    if (!p2.existe(*this))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        p2.affiche();
        cout << endl;
        throw(2);
    }

    int idp, idp2;
    idp=trouverID(p);
    idp2=trouverID(p2);
    int indice;
    int nbAmis(0);

    for (int i=0; i<MAXP; i++)
    {
        if (tabRelation[idp][i] && tabRelation[idp2][i] && i!=idp && i!=idp2)
        {
            nbAmis++;
            if (nbAmis==1) cout << "Amis en communs :" << endl;
            rechercheTab1D(i, tabId, nbPers, indice);
            fb[indice].affiche();
            cout << endl;
        }
    }
    if (nbAmis==0) cout << "Aucun ami en commun." << endl;
}

bool Facebook::amisIndirects(Personne& p, Personne& p2)throw (int)
{
    if (!p.existe(*this))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        p.affiche();
        cout << endl;
        throw(2);
    }
    if (!p2.existe(*this))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        p2.affiche();
        cout << endl;
        throw(2);
    }

    int idp, idp2;
    idp=trouverID(p);       //On retrouve les ID des personnes
    idp2=trouverID(p2);
    bool trouve;       //Si on trouve un ami en commun
    int i(0);

    while (!trouve && i<MAXP)
    {
        trouve=(tabRelation[idp][i] && tabRelation[idp2][i] && i!=idp && i!=idp2); //On fait attention au fait qu'un personne est ami avec elle-m�me lors du i!=idp && i!=idp2
        i++;
    }
    return trouve;
}

Personne Facebook::lePlusdAmi()throw(int)
{
    int maxAmis(1);
    int nbAmis;
    int indice; //Correspond � l'indice de la personne avec le plus d'amis dans fb
    Personne p; //Personne renvoy�e (avec le plus d'amis)
    int idp(-1); //Si idp reste �gale � -1 � la fin de la m�thode, cela signifie qu'il n'y a aucune amiti� dans le r�seau.
    for (int i=0; i<MAXP; i++)
    {
        nbAmis=0;
        for (int j=0; j<MAXP; j++)
        {
            if (tabRelation[i][j]==true)
            {
                nbAmis++;
            }
        }
        if (nbAmis>maxAmis)
        {
            maxAmis=nbAmis;
            idp=i;              // L'ID est �gale � l'indice de tabRelation.
        }
    }
    rechercheTab1D(idp, tabId, nbPers, indice);
    if(idp!=-1) p=fb[indice]; //Si on a bien trouv� une personne avec le plus d'amis.
    else //Si idp==-1 et donc qu'il n'y a pas d'amiti�
    {
        cout << "Il n'y aucune amitie dans le reseau !" << endl;
        throw(2);
    }
    return p;
}

bool Facebook::idLibre(int id) //V�rifie si un ID est d�j� pris ou pas (Ainsi aucun risque d'�craser des donn�es existantes lors de la cr�ation d'un compte)
{
    int null;
    if (nbPers==0) return true; //S'il n'y a personne sur le r�seau l'ID est forc�ment libre.
    return (!rechercheTab1D(id, tabId, nbPers, null)); //Recherche de id dans tabId. Si la recherche renvoie vrai, alors l'ID n'est pas libre et la m�thode renvoie elle faux.
}

int Facebook::trouverID(Personne& p) //Permet de trouver l'ID d'une personne d'apr�s son Nom et Pr�nom
{
    int indp, idp; //Correspond aux indices de p et p2, puis � leur ID.
    rechercheDichotomiqueTabFacebook(p, indp); //On recherche l'indice qu'a p dans la table fb et donc tabId.
    idp=tabId[indp]; //Gr�ce � cela on peut trouver l'ID de p
    return idp; //Que l'on retourne
}

//M�me but mais en utilisant cette fois une m�thode similaire � la recherche dichotomique
int Facebook::trouverPlaceOrdreAlphabetique(Personne& p)
{
    //Permet de trouver o� placer la personne et son ID dans les tables fb et tabId selon l'ordre alphab�tique
    int indice;
    if (p<fb[0]) indice=0;
    else if (p>fb[nbPers-1]) indice=nbPers;
    else
    {
        bool trouve(false);
        int debut, fin;
        debut=0;
        fin=nbPers-1;
        while (!trouve)
        {
            indice=(debut+fin)/2;
            trouve=(fb[indice]<p && p<fb[indice+1]);
            if (!trouve && p<fb[indice]) fin=indice-1;
            else debut=indice+1;
        }
        indice++;
    }
    return indice;
}

//Recherche dans un tableau ordonn� alphab�tiquement.
bool Facebook::rechercheDichotomiqueTabFacebook(Personne& p, int& indice)
{
    bool trouve(false);
    int debut, pivot, fin;
    debut=0;
    fin=nbPers-1;
    while (!trouve && debut<=fin)
    {
        pivot=(debut+fin)/2;
        trouve=(fb[pivot]==p);
        if (!trouve && fb[pivot]>p) fin=pivot-1;
        else debut=pivot+1;
    }
    if (trouve) indice=pivot;
    return trouve;
}

//M�thode s�quentielle de recherche. Renvoie vrai si la valeur cherch�e est trouv�e, ainsi que l'indice de la case.(inutilis�e dans le programme final)
/*bool Facebook::rechercheBasiqueTabFacebook(Personne& p, int& indice)
{
    bool trouve(false);
    indice=0;
    while (!trouve && indice<nbPers)
    {
        trouve=(fb[indice]==p);
        if (!trouve) indice++;
    }
    return trouve;
}*/
