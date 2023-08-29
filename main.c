#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void afficherMenuChiffrageASCII(void);
void afficherMenuCommandeChiffrageASCII(void);
int ecrireFichierSource(void);
int afficherFichierSource(void);
int ecrireFichierPerroquet(void);
int afficherFichierPerroquet(void);
int fonctionChiffrageASCII(void);
int afficherFichierResultat(void);


int main()
{
    // Affichage du Menu Principal
    afficherMenuChiffrageASCII();

    // Initialisation des variables pour la boucle
    int reponse = 1;
    bool repetition = true;

    // Tant que nous ne sortons pas de la boucle en mettant 0 faire
    while(repetition == true)
    {
        // Récupérer l'input de l'utilisateur
        printf("\n\nQue voulez-vous faire (rentrez la valeur de la commande souhaitee) ?\n\n");
        afficherMenuCommandeChiffrageASCII();
        scanf(" %d", &reponse);

        system("cls");

        // Switch case pour les différentes commandes du programme
        switch (reponse)
        {
            // Commande pour terminer le programme
            case 0 :
                printf("Fin du programme");
                repetition = false;
                break;

            // Commande pour écrire dans le fichier source
            case 1 :
                ecrireFichierSource();
                break;

            // Commande pour afficher le contenu du fichier source
            case 2 :
                afficherFichierSource();
                break;


            // Commande pour écrire dans le fichier perroquet
            case 3 :
                ecrireFichierPerroquet();
                break;

            // Commande pour afficher le contenu du fichier perroquet
            case 4 :
                afficherFichierPerroquet();
                break;


            // Commande pour chiffrer le contenu de fichier source via perroquet par ASCII (WIP)
            case 5 :
                fonctionChiffrageASCII();
                break;


            // Commande pour afficher le résultat de dest.crt
            case 6 :
                afficherFichierResultat();
                break;

            // Commande si la valeur input n'est pas bonne
            default :
                printf("Valeur saisie erronee.\n");
                break;

        }


    }


    return 0;
}


// Fonction d'affichage du Menu
void afficherMenuChiffrageASCII()
{
    printf("Hello, Happy world!\n\nProjet C : Chiffrage ASCII\n\n");

    printf("Ce programme a pour but de faire du chiffrage de message en utilisant l'algorithme du << perroquet >>.\n");
    printf("Vous pouvez faire plusieurs choses dans ce programme.");
}


// Fonction d'affichage des commandes du Menu
void afficherMenuCommandeChiffrageASCII()
{
    printf("0. Quitter le programme\n");
    printf("1. Ecrire un message source dans le source.txt\n");
    printf("2. Afficher le message source contenu dans source.txt\n");
    printf("3. Modifier le perroquet contenu dans peroq.def\n");
    printf("4. Afficher le perroquet contenu dans peroq.def\n");
    printf("5. Chiffrer le contenu du source.txt par peroq.def par difference ASCII\n");
    printf("6. Afficher le resultat contenu dans dest.crt\n");

    printf("\n");
}



// Fonction d'écriture dans le fichier source
int ecrireFichierSource()
{
    // Déclaration et initialisation du pointeur sur le FILE
    FILE *fp = NULL;

    fp = fopen("source.txt", "w+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    // Récupération du message de l'utilisateur
    char input[255] = "\0";
    printf("Que souhaitez-vous ecrire dans le source.txt ? \n");
    scanf("%s", input);

    // Ecriture dans le fichier source
    fwrite(&input, sizeof(char), strlen(input), fp);
    printf("Votre message a ete ecrit dans source.txt.\n");
    // Arret du pointeur sur FILE
    fclose(fp);
    return 0;

}


// Fonction d'affichage du fichier source
int afficherFichierSource()
{
    // Déclaration et initialisation du pointeur sur le FILE
    FILE *fp = NULL;

    fp = fopen("source.txt", "r+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    // Variable de stockage du file pour ensuite l'afficher
    char buffer[255];
    printf("Le message source dans le source.txt est : ");
    while(fgets(buffer, 255, fp) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}



// Fonction d'écriture dans le fichier perroquet
int ecrireFichierPerroquet()
{
    // Déclaration et initialisation du pointeur sur le FILE
    FILE *fp = NULL;

    fp = fopen("peroq.def", "w+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    // Récupération du perroquet de l'utilisateur
    char input[255] = "\0";
    printf("Que souhaitez-vous ecrire dans peroq.def ? \n");
    scanf("%s", input);

    // Ecriture dans le fichier perroquet
    fwrite(&input, sizeof(char), strlen(input), fp);
    printf("Votre message a ete ecrit dans peroq.def.\n");
    // Arret du pointeur sur FILE
    fclose(fp);
    return 0;
}


// Fonction d'affichage du fichier perroquet
int afficherFichierPerroquet()
{
    // Déclaration et initialisation du pointeur sur le FILE
    FILE *fp = NULL;

    fp = fopen("peroq.def", "r+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    // Variable de stockage du file pour ensuite l'afficher
    char buffer[255];
    printf("Le message source dans peroq.def est : ");
    while(fgets(buffer, 255, fp) != NULL)
    {
        printf("%s", buffer);
    }
    // Arret du pointeur sur FILE
    fclose(fp);
    return 0;
}


// Fonction d'affichage du résultat dans dest.crt
int afficherFichierResultat()
{
    // Déclaration et initialisation du pointeur sur le FILE
    FILE *fp = NULL;

    fp = fopen("dest.crt", "r+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    // Variable de stockage du file resultat dest.crt pour ensuite l'afficher
    char buffer[255];
    printf("Le message dans dest.crt est : ");
    while(fgets(buffer, 255, fp) != NULL)
    {
        printf("%s", buffer);
    }
    // Arret du pointeur sur FILE
    fclose(fp);
    return 0;
}



// Fonction de chiffrage du contenu de source via perroquet par ASCII (WIP)
int fonctionChiffrageASCII()
{
    // Déclaration et initialisation du pointeur source sur le FILE
    FILE *f_source = NULL;
    f_source = fopen("source.txt", "r+");
    if (f_source == NULL)
    {
        printf("Erreur Open Source");
        return 0;
    }

    // Déclaration et initialisation du pointeur perroquet sur le FILE
    FILE *f_peroquet = NULL;
    f_peroquet = fopen("peroq.def", "r+");
    if (f_peroquet == NULL)
    {
        printf("Erreur Open Perroquet");
        return 0;
    }

    char stockage_source[255];
    fgets(stockage_source, 255, f_source);






    char stockage_perroquet[255];
    fgets(stockage_perroquet, 255, f_peroquet);

    printf(" debugg ");



    while(fgets(stockage_source, 255, f_source) != NULL)
    {
        printf("%s", stockage_source);
    }

    while(fgets(stockage_perroquet, 255, f_peroquet) != NULL)
    {
        printf("%s", stockage_perroquet);
    }



    printf(" apres debugg ");

    // Arret des pointeurs sur FILE
    fclose(f_source);
    fclose(f_peroquet);
}





