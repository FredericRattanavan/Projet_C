#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void ecrireFichier(void);
void afficherFichier(void);

int main()
{
    printf("Hello, Happy world!\n\nProjet C : Chiffrage\n\n");
/*
    FILE *fp = NULL;

    fp = fopen("fichier.txt", "r+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }
*/
    printf("Ce programme a pour but de faire du chiffrage de message en utilisant l'algorithme du << perroquet >>.\n");
    printf("Vous pouvez faire plusieurs choses dans ce programme.\n\n");
    printf("0.Quitter le programme\n");
    printf("1.Ecrire un message source dans le fichier.txt\n");
    printf("2.Afficher le message source dans le fichier.txt\n");

    char c;
    char input[] = "a";

    int reponse = 1;
    bool repetition = true;

    while(repetition == true)
    {
        printf("\nQue voulez-vous faire (rentrez la valeur de la commande souhaitee) ?\n\n");
        scanf(" %d", &reponse);

        printf("\n");

        switch (reponse)
        {
            case 0 :
                printf("Fin du programme");
                repetition = false;
                break;

            case 1 :
                ecrireFichier();
                break;
/*
                printf("Que souhaitez-vous ecrire dans le fichier.txt ? \n");
                scanf("%s", input);
                fputs(input, fp);
                printf("Votre message a ete ecrit dans fichier.txt.\n\n");
*/

            case 2 :
                afficherFichier();
                break;
/*
                printf("Le message source dans le fichier.txt est : ");
                while(fgets(buffer, 255, fp) != NULL)
                {
                    printf("%s", buffer);
                }
*/
            default :
                printf("Valeur saisie erronee.\n");
                break;


        }



    }






    //fclose(fp);

    return 0;
}




void ecrireFichier()
{
    FILE *fp = NULL;

    fp = fopen("fichier.txt", "r+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    char input[20];
    printf("Que souhaitez-vous ecrire dans le fichier.txt ? \n");
    scanf("%s", input);
    //fprintf("%s", input);
    fwrite(&input, sizeof(input), sizeof(char*), fp);
    printf("Votre message a ete ecrit dans fichier.txt.\n");
    fclose(fp);

}


void afficherFichier()
{
    FILE *fp = NULL;

    fp = fopen("fichier.txt", "r+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    char buffer[255];
    printf("Le message source dans le fichier.txt est : ");
    while(fgets(buffer, 255, fp) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(fp);
}












