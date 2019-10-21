#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXP=21; //On peut cr�er jusqu'� MAXP-1=20 comptes diff�rents

class Facebook;
class Personne
{
public:

    Personne() //Constructeur sans param�tre
    {
        nom_="";
        prenom_="";
    };

    Personne(string nom, string prenom) //Constructeur avec nom et pr�nom fournis
    {
        nom_=nom;
        prenom_=prenom;
    };

    void affiche(); //Affiche le nom et pr�nom de la personne cibl�e
    void saisir(); //Permet de saisir le nom et pr�nom de la personne cibl�e

    string getNom(); //Renvoie le nom de la personne cibl�e
    /*
        Fonction getNom() renvoie cha�ne de caract�res
    */

    string getPrenom(); //Renvoie le pr�nom de la personne cibl�e
    /*
        Fonction getPrenom() renvoie cha�ne de caract�res
    */

    bool operator==(Personne& p); //Permet de v�rifier si deux personnes ont le m�me nom et pr�nom
    /*
        Fonction operator==(p) renvoie bool�en
        param�tre : (D) p : Personne
    */

    bool operator>(Personne& p); //Permet de v�rifier alphab�tiquement si une personne est sup�rieure � une autre
    /*
        Fonction operator>(p) renvoie bool�en
        param�tre : (D) p : Personne
    */

    bool operator>=(Personne& p); //Permet de v�rifier alphab�tiquement si une personne est sup�rieure ou �gale � une autre
    /*
        Fonction operator>=(p) renvoie bool�en
        param�tre : (D) p : Personne
    */

    bool operator<(Personne& p); //Permet de v�rifier alphab�tiquement si une personne est inf�rieure � une autre
    /*
        Fonction operator<(p) renvoie bool�en
        param�tre : (D) p : Personne
    */

    bool operator<=(Personne& p); //Permet de v�rifier alphab�tiquement si une personne est inf�rieure ou �gale � une autre
    /*
        Fonction operator<=(p) renvoie bool�en
        param�tre : (D) p : Personne
    */

    bool existe(Facebook& f); //Permet de v�rifier s'il existe d�j� une personne ayant le m�me nom et pr�nom dans Facebook que la personne cibl�e.
    /*
        Fonction existe(f) renvoie bool�en
        param�tre : (D) f : Facebook
    */

    bool inscription(Facebook& f); //Permet de v�rifier si une personne est apte � s'inscrire Facebook
    /*
        Fonction inscription(f) renvoie bool�en
        param�tre : (D) f : Facebook
    */

    bool quitter(Facebook& f); //Permet de v�rifier si une personne est apte � quitter Facebook
    /*
        Fonction quitter(f) renvoie bool�en
        param�tre : (D) f : Facebook
    */

    bool inviterUnAmi(Personne& p, Facebook& f); //Permet de v�rifier que l'ajout d'une relation entre deux personnes sur un r�seau est possible
    /*
        Fonction inviterUnAmi(p,f) renvoie bool�en
        param�tre : (D) p : Personne
                    (D) f : Facebook
    */

    bool supprimerUnAmi(Personne& p, Facebook& f); //Permet de v�rifier que la suppression d'une relation entre eux personnes sur un r�seau est possible
    /*
        Fonction supprimerUnAmi(p,f) renvoie bool�en
        param�tre : (D) p : Personne
                    (D) f : Facebook
    */

private :
    string nom_;
    string prenom_;
};

#endif // PERSONNE_H_INCLUDED
