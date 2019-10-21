#include "ssProg.h"

int main()
{
    Facebook f;
    Personne p;
    Personne p2;

    int choix;
    while((choix=menu())!=10)
    {
        cout << endl;
        try
        {
            //Correspond à un des choix proposés dans menu()
            switch(choix)
            {
            case (1) :
            {
                cout << "Creation d'un nouveau compte :" << endl;
                p.saisir();
                f.creerCompte(p);
                break;
            }
            case (2) :
            {
                if (f.nbPers>0)
                {
                    cout << "Compte a effacer :" << endl;

                    cout << endl;
                    f.affiche();
                    cout << endl;
                    p.saisir();

                    f.fermerCompte(p);
                }
                else cout << "Personne n'est inscrit sur le reseau !" << endl;
                break;
            }
            case (3) :
            {
                if (f.nbPers>1)
                {
                    cout << "Ajouter un ami :" << endl;

                    cout << endl;
                    f.affiche();
                    cout << endl;
                    cout << "Vous etes :" << endl;
                    p.saisir();
                    cout << "Vous souhaitez ajouter en ami :" << endl;
                    p2.saisir();

                    f.ajoutRelationAmitie(p,p2);
                }
                else cout << "Moins de deux personnes sur le reseau, impossible d'effectuer cette tache." << endl;
                break;
            }
            case (4) :
            {
                if (f.nbPers>1)
                {
                    cout << "Supprimer un ami :" << endl;

                    cout << endl;
                    f.affiche();
                    cout << endl;
                    cout << "Vous etes :" << endl;
                    p.saisir();
                    cout << "Vous souhaitez ajouter en ami :" << endl;
                    p2.saisir();

                    f.supprimeRelationAmitie(p,p2);
                }
                else cout << "Moins de deux personnes sur le reseau, impossible d'effectuer cette tache." << endl;
                break;
            }
            case (5) :
            {
                if (f.nbPers>1)
                {
                    cout << "Ces deux personnes sont-elles amies ?" << endl;

                    cout << endl;
                    f.affiche();
                    cout << endl;
                    cout << "Premiere personne :" << endl;
                    p.saisir();
                    cout << "Deuxieme personne :" << endl;
                    p2.saisir();

                    if (f.amis(p,p2))
                    {
                        p.affiche();
                        cout << " est ami avec ";
                        p2.affiche();
                        cout << '.' << endl;
                    }
                    else
                    {
                        p.affiche();
                        cout << " n'est pas ami avec ";
                        p2.affiche();
                        cout << '.' << endl;
                    }
                }
                else cout << "Moins de deux personnes sur le reseau, impossible d'effectuer cette tache." << endl;
                break;
            }
            case (6) :
            {
                if (f.nbPers>1)
                {
                    cout << "Quels sont les amis en commun de ces deux personnes ?" << endl;

                    cout << endl;
                    f.affiche();
                    cout << endl;
                    cout << "Premiere personne :" << endl;
                    p.saisir();
                    cout << "Deuxieme personne :" << endl;
                    p2.saisir();

                    f.listerAmisCommuns(p,p2);
                }
                else cout << "Moins de deux personnes sur le reseau, impossible d'effectuer cette tache." << endl;
                break;
            }
            case (7) :
            {
                if(f.nbPers>1)
                {
                    cout << "Ses deux personnes ont-elles un ami en commun ?" << endl;

                    cout << endl;
                    f.affiche();
                    cout << endl;
                    cout << "Premiere personne :" << endl;
                    p.saisir();
                    cout << "Deuxieme personne :" << endl;
                    p2.saisir();

                    if (f.amisIndirects(p, p2)) cout << "Oui !" << endl;
                    else cout << "Non..." << endl;
                }
                else cout << "Moins de deux personnes sur le reseau, impossible d'effectuer cette tache." << endl;
                break;
            }
            case (8) :
            {
                if(f.nbPers>0)
                {
                    p=f.lePlusdAmi();
                    p.affiche();
                    cout << " est celui qui a le plus d'amis." << endl;
                }
                else cout << "Personne n'est inscrit sur le reseau !" << endl;
                break;
            }
            case (9) :
            {
                if (f.nbPers>0)
                {
                    cout << endl;
                    f.affiche();
                    cout << endl;
                }
                else cout << "Personne n'est inscrit sur le reseau !" << endl;
                break;
            }
            }
        }
        catch(int) {}
        cout << endl;

        //Permet un affichage plus propre et lisible
        system("pause"); //Le programme attend tant que l'utilisateur n'appuie pas sur une touche (Ne marche que sur Windows)
        system("cls"); //Nettoie la console (Ne marche que sur Windows)
        //for (int i=0; i<10; i++) cout << endl; //À utiliser si vous n'êtes pas sur Windows
    }
    system("cls"); //Nettoie la console (Ne marche que sur Windows)
    cout << "A bientot !" << endl;
    return 0;
}
