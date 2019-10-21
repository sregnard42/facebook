#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXP=21; //On peut créer jusqu'à MAXP-1=20 comptes différents

class Facebook;
class Personne
{
public:

    Personne() //Constructeur sans paramètre
    {
        nom_="";
        prenom_="";
    };

    Personne(string nom, string prenom) //Constructeur avec nom et prénom fournis
    {
        nom_=nom;
        prenom_=prenom;
    };

    void affiche(); //Affiche le nom et prénom de la personne ciblée
    void saisir(); //Permet de saisir le nom et prénom de la personne ciblée

    string getNom(); //Renvoie le nom de la personne ciblée
    /*
        Fonction getNom() renvoie chaîne de caractères
    */

    string getPrenom(); //Renvoie le prénom de la personne ciblée
    /*
        Fonction getPrenom() renvoie chaîne de caractères
    */

    bool operator==(Personne& p); //Permet de vérifier si deux personnes ont le même nom et prénom
    /*
        Fonction operator==(p) renvoie booléen
        paramètre : (D) p : Personne
    */

    bool operator>(Personne& p); //Permet de vérifier alphabétiquement si une personne est supérieure à une autre
    /*
        Fonction operator>(p) renvoie booléen
        paramètre : (D) p : Personne
    */

    bool operator>=(Personne& p); //Permet de vérifier alphabétiquement si une personne est supérieure ou égale à une autre
    /*
        Fonction operator>=(p) renvoie booléen
        paramètre : (D) p : Personne
    */

    bool operator<(Personne& p); //Permet de vérifier alphabétiquement si une personne est inférieure à une autre
    /*
        Fonction operator<(p) renvoie booléen
        paramètre : (D) p : Personne
    */

    bool operator<=(Personne& p); //Permet de vérifier alphabétiquement si une personne est inférieure ou égale à une autre
    /*
        Fonction operator<=(p) renvoie booléen
        paramètre : (D) p : Personne
    */

    bool existe(Facebook& f); //Permet de vérifier s'il existe déjà une personne ayant le même nom et prénom dans Facebook que la personne ciblée.
    /*
        Fonction existe(f) renvoie booléen
        paramètre : (D) f : Facebook
    */

    bool inscription(Facebook& f); //Permet de vérifier si une personne est apte à s'inscrire Facebook
    /*
        Fonction inscription(f) renvoie booléen
        paramètre : (D) f : Facebook
    */

    bool quitter(Facebook& f); //Permet de vérifier si une personne est apte à quitter Facebook
    /*
        Fonction quitter(f) renvoie booléen
        paramètre : (D) f : Facebook
    */

    bool inviterUnAmi(Personne& p, Facebook& f); //Permet de vérifier que l'ajout d'une relation entre deux personnes sur un réseau est possible
    /*
        Fonction inviterUnAmi(p,f) renvoie booléen
        paramètre : (D) p : Personne
                    (D) f : Facebook
    */

    bool supprimerUnAmi(Personne& p, Facebook& f); //Permet de vérifier que la suppression d'une relation entre eux personnes sur un réseau est possible
    /*
        Fonction supprimerUnAmi(p,f) renvoie booléen
        paramètre : (D) p : Personne
                    (D) f : Facebook
    */

private :
    string nom_;
    string prenom_;
};

#endif // PERSONNE_H_INCLUDED
