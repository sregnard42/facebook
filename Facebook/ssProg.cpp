#include "ssProg.h"

int menu() //Renvoie le choix de l'utilisateur
{
    int choix;
    cout << "                               MP1: Facebook                               " << endl << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|                                                                         |" << endl;
    cout << "|      1 - Creation d'un nouveau compte                                   |" << endl;
    cout << "|      2 - Supprimer un compte                                            |" << endl;
    cout << "|      3 - Ajouter un ami                                                 |" << endl;
    cout << "|      4 - Supprimer un ami                                               |" << endl;
    cout << "|      5 - Ces deux personnes sont-elles amies ?                          |" << endl;
    cout << "|      6 - Quels sont les amis en commun de ces deux personnes ?          |" << endl;
    cout << "|      7 - Ces deux personnes ont-elles un ami en commun ?                |" << endl;
    cout << "|      8 - Qui a le plus d'ami ?                                          |" << endl;
    cout << "|      9 - Qui se trouve sur le reseau ?                                  |" << endl;
    cout << "|      10 - Terminer le programme                                         |" << endl;
    cout << "|                                                                         |" << endl;
    cout << "---------------------------------------------------------------------------" << endl << endl;
    cout << endl << "Faites votre choix : ";
    cin >> choix;
    while(!cin || choix>10) //Si la saisie n'est pas valide. Saisie d'autre chose qu'un int, ou si la valeur est trop grande par rapport aux choix proposés.
    {
        cout << endl << "Choix non valide veuillez reessayer : ";
        cin.clear();
        cin.ignore();
        cin >> choix;
    }
    return choix;
}

bool rechercheTab1D (int x, int tab[MAXP], int nbVal, int& indice) //Recherche une valeur donnée dans un tableau donné et retourne vrai si trouvée.
{
    bool trouve(false);
    int i(0);
    indice=-1;
    while (i<nbVal && !trouve)
    {
        trouve=(x==tab[i]);
        if (!trouve) i++;
    }
    if (trouve) indice=i;
    return trouve;
}
