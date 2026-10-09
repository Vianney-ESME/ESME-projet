#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void afficher_bilan(int scoreJoueur, int scoreOrdi);
void afficher_choix(int choix);

int main(void)
{
    int scoreJoueur = 0;
    int scoreOrdi = 0;
    int manche = 1;
    int choixJoueur;
    int choixOrdi;

    srand((unsigned int)time(NULL));

    printf("=== PIERRE, FEUILLE, CISEAUX, LEZARD, SPOCK ===\n");

    while (manche <= 7
        && scoreJoueur - scoreOrdi < 2
        && scoreOrdi - scoreJoueur < 2)
    {
        printf("--- Manche %d/7 ---\n", manche);

        // Saisie du joueur
        bool incorrect;

        do
        {
            printf("Choisissez un nombre parmi les suivants :\n");

            for (int i = 1; i <= 5; i = i + 1)
            {
                printf("%d = ", i);
                afficher_choix(i);
                printf("\n");
            }

            printf("Votre choix : ");

            if (scanf("%d", &choixJoueur) != 1)
            {
                // Saisie non numerique : on vide le buffer
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                choixJoueur = 0;
            }

            incorrect = choixJoueur < 1 || choixJoueur > 5;

            if (incorrect)
            {
                printf("Choix invalide, valeurs de 1 a 5 acceptees.\n");
            }

        } while (incorrect);

        // Choix aleatoire de l'ordinateur
        choixOrdi = (rand() % 5) + 1;

        printf("Vous avez choisi : ");
        afficher_choix(choixJoueur);
        printf("\n");

        printf("L'ordinateur a choisi : ");
        afficher_choix(choixOrdi);
        printf("\n");

        // Determination du gagnant de la manche
        if (choixJoueur == choixOrdi)
        {
            printf("Egalite !\n");
        }
        else if ((choixJoueur == 1 && (choixOrdi == 3 || choixOrdi == 4)) ||
                 (choixJoueur == 2 && (choixOrdi == 1 || choixOrdi == 5)) ||
                 (choixJoueur == 3 && (choixOrdi == 2 || choixOrdi == 4)) ||
                 (choixJoueur == 4 && (choixOrdi == 2 || choixOrdi == 5)) ||
                 (choixJoueur == 5 && (choixOrdi == 1 || choixOrdi == 3)))
        {
            printf("Vous gagnez cette manche !\n");
            scoreJoueur = scoreJoueur + 1;
        }
        else
        {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi = scoreOrdi + 1;
        }

        printf("Score actuel -> Vous : %d | Ordi : %d\n\n",
               scoreJoueur, scoreOrdi);

        manche = manche + 1;
    }

    // Bilan de la partie
    afficher_bilan(scoreJoueur, scoreOrdi);

    return 0;
}

// Fonction qui affiche le nom correspondant au choix
void afficher_choix(int choix)
{
    if (choix == 1)
    {
        printf("Pierre");
    }
    else if (choix == 2)
    {
        printf("Feuille");
    }
    else if (choix == 3)
    {
        printf("Ciseaux");
    }
    else if (choix == 4)
    {
        printf("Lezard");
    }
    else if (choix == 5)
    {
        printf("Spock");
    }
}

// Procedure qui affiche le bilan de la partie
void afficher_bilan(int scoreJoueur, int scoreOrdi)
{
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous : %d | Ordi : %d\n",
           scoreJoueur, scoreOrdi);

    if (scoreJoueur > scoreOrdi)
    {
        printf("Bravo, vous avez gagne la partie !\n");
    }
    else if (scoreOrdi > scoreJoueur)
    {
        printf("L'ordinateur remporte la partie...\n");
    }
    else
    {
        printf("Match nul parfait !\n");
    }
}