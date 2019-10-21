#include "Personne.h"
#include "Facebook.h"

void Personne::affiche()
{
    cout << nom_ << ' ' << prenom_;
}

void Personne::saisir()
{
    cout << "Nom et prenom : ";
    cin >> (nom_) >> (prenom_);
    nom_[0]=toupper(nom_[0]);
    prenom_[0]=toupper(prenom_[0]);
}

string Personne::getNom()
{
    return nom_;
}

string Personne::getPrenom()
{
    return prenom_;
}

bool Personne::operator==(Personne& p)
{
    return (nom_==p.nom_ && prenom_==p.prenom_);
}

bool Personne::operator>(Personne& p)
{
    if (nom_>p.nom_ || (nom_==p.nom_ && prenom_>p.prenom_)) return true;
    return false;
}

bool Personne::operator>=(Personne& p)
{
    return (operator==(p) || operator>(p));
}
bool Personne::operator<(Personne& p)
{
    return (!(operator>=(p)));
}

bool Personne::operator<=(Personne& p)
{
    return (operator==(p) || operator<(p));
}

bool Personne::existe(Facebook& f) //Permet de vérifier s'il existe déjà une personne ayant le même nom et prénom dans Facebook que la personne ciblée.
{
    int null;
    return(f.rechercheDichotomiqueTabFacebook(*this, null)); //Le deuxième paramètre renvoie normalement l'indice où se trouve la cible dans le tableau, dont on a pas besoin ici.
}

bool Personne::inscription(Facebook& f)
{
    bool possible(true);
    //S'il n'y a plus de place dans le réseau ou s'il existe déjà une personne avec ce nom et prénom dans Facebook, possible est faux.
    if (!(f.nbPers<MAXP-1))
    {
        cout << "Plus de place dans le reseau !" << endl;
        possible=false;
    }
    if (existe(f))
    {
        cout << "Personne deja existante dans le reseau : ";
        affiche();
        cout << endl;
        possible=false;
    }
    return possible;
}

bool Personne::quitter(Facebook& f)
{
    bool possible(true);
    //Si la personne n'est pas dans Facebook, désincription impossible
    if (!existe(f))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        affiche();
        cout << endl;
        possible=false;
    }
    return possible;
}

bool Personne::inviterUnAmi(Personne& p, Facebook& f)
{
    bool possible(true);
    //Si la première ou la deuxième personne n'est pas dans Facebook alors ce n'est pas possible.
    if (!existe(f))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        affiche();
        cout << endl;
        possible=false;
    }
    if (!p.existe(f))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        p.affiche();
        cout << endl;
        possible=false;
    }
    return possible;
}

bool Personne::supprimerUnAmi(Personne& p, Facebook& f)
{
    bool possible(true);
    //Si la première ou la deuxième personne n'est pas dans Facebook alors ce n'est pas possible.
    if (!existe(f))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        affiche();
        cout << endl;
        possible=false;
    }
    if (!p.existe(f))
    {
        cout << "Le compte en question n'existe pas dans Facebook : ";
        p.affiche();
        cout << endl;
        possible=false;
    }
    return possible;
}
