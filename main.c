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
int fonctionDechiffrageASCII(void);
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
        // R�cup�rer l'input de l'utilisateur
        printf("\n\nQue voulez-vous faire (rentrez la valeur de la commande souhaitee) ?\n\n");
        afficherMenuCommandeChiffrageASCII();
        scanf(" %d", &reponse);

        system("cls");

        // Switch case pour les diff�rentes commandes du programme
        switch (reponse)
        {
            // Commande pour terminer le programme
            case 0 :
                printf("Fin du programme");
                repetition = false;
                break;

            // Commande pour �crire dans le fichier source
            case 1 :
                ecrireFichierSource();
                break;

            // Commande pour afficher le contenu du fichier source
            case 2 :
                afficherFichierSource();
                break;


            // Commande pour �crire dans le fichier perroquet
            case 3 :
                ecrireFichierPerroquet();
                break;

            // Commande pour afficher le contenu du fichier perroquet
            case 4 :
                afficherFichierPerroquet();
                break;


            // Commande pour chiffrer le contenu de fichier source via perroquet par ASCII
            case 5 :
                fonctionChiffrageASCII();
                break;


            // Commande pour d�chiffrer le contenu de fichier dest.crt via perroquet par ASCII
            case 6 :
                fonctionDechiffrageASCII();
                break;

            // Commande pour afficher le r�sultat de dest.crt
            case 7 :
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
    printf("6. Dechiffrer le contenu du dest.crt par peroq.def par difference ASCII\n");
    printf("7. Afficher le resultat contenu dans dest.crt\n");

    printf("\n");
}



// Fonction d'�criture dans le fichier source
int ecrireFichierSource()
{
    // D�claration et initialisation du pointeur sur le FILE
    FILE *fp = NULL;

    fp = fopen("source.txt", "w+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    // R�cup�ration du message de l'utilisateur
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
    // D�claration et initialisation du pointeur sur le FILE
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



// Fonction d'�criture dans le fichier perroquet
int ecrireFichierPerroquet()
{
    // D�claration et initialisation du pointeur sur le FILE
    FILE *fp = NULL;

    fp = fopen("peroq.def", "w+");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    // R�cup�ration du perroquet de l'utilisateur
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
    // D�claration et initialisation du pointeur sur le FILE
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


// Fonction d'affichage du r�sultat dans dest.crt
int afficherFichierResultat()
{
    // D�claration et initialisation du pointeur sur le FILE
    FILE *fp = NULL;

    fp = fopen("dest.crt", "r");
    if (fp == NULL)
    {
        printf("Erreur Open ");
        return 0;
    }

    // Variable de stockage du file resultat dest.crt pour ensuite l'afficher
    char buffer[255] = "\0";
    printf("Le message dans dest.crt est : ");
    while(fgets(buffer, 255, fp) != NULL)
    {
        printf("%s", buffer);
    }
    // Arret du pointeur sur FILE
    fclose(fp);
    return 0;
}



// Fonction de chiffrage du contenu de source via perroquet par ASCII
int fonctionChiffrageASCII()
{
    // D�claration et initialisation du pointeur source sur le FILE
    FILE *f_source = fopen("source.txt", "r");
    if (f_source == NULL)
    {
        printf("Erreur Open Source");
        return 0;
    }

    // D�claration et initialisation du pointeur perroquet sur le FILE
    FILE *f_peroquet = fopen("peroq.def", "r");
    if (f_peroquet == NULL)
    {
        printf("Erreur Open Perroquet");
        return 0;
    }


    // Initialisation d'une variable de stockage pour le contenu de fichier source
    char stockage_source[255] = "\0";
    fgets(stockage_source, 255, f_source);

    // Initialisation d'une variable de stockage pour le contenu de fichier perroquet
    char stockage_perroquet[255] = "\0";
    fgets(stockage_perroquet, 255, f_peroquet);

    // Arret des pointeurs sur FILE
    fclose(f_source);
    fclose(f_peroquet);


    // D�claration et initialisation du pointeur resultat sur le FILE
    FILE *f_resultat = fopen("dest.crt", "w");
    if (f_resultat == NULL)
    {
        printf("Erreur Open Perroquet");
        return 0;
    }
    // Cr�ation d'une variable de stockage pour le contenu de fichier perroquet
    char stockage_resultat[255] = "\0";

    // Variable de longueur de source et perroquet
    int longueur_source = strlen(stockage_source);
    int longueur_perroquet = strlen(stockage_perroquet);

    // Si la longueur de source est inf�rieur � la longueur de perroquet
    if (longueur_source <= longueur_perroquet)
    {
        // D�roulement de l'algorithme normalement avec l'�criture dans stockage r�sultat
        for (int i = 0; i < longueur_source; i++)
        {
            stockage_resultat[i] = stockage_source[i] - stockage_perroquet[i];
        }
    }
    else // ( longueur source est > longueur perroquet )
    {

        for (int j = 0; j < longueur_source; j++)
        {
            stockage_resultat[j] = stockage_source[j] - stockage_perroquet[j %longueur_perroquet];
        }


    }



    // Ecriture dans dest.crt
    fwrite(&stockage_resultat, sizeof(char), strlen(stockage_resultat), f_resultat);
    printf("Votre message chiffre a ete ecrit dans dest.crt.\n");

    // Fermeture du pointeur
    fclose(f_resultat);
    return 0;

}


// Fonction de d�chiffrage du contenu de source via perroquet par ASCII (WIP)
int fonctionDechiffrageASCII()
{

    // D�claration et initialisation du pointeur perroquet sur le FILE
    FILE *f_peroquet = fopen("peroq.def", "r");
    if (f_peroquet == NULL)
    {
        printf("Erreur Open Perroquet");
        return 0;
    }

    // D�claration et initialisation du pointeur resultat sur le FILE
    FILE *f_resultat = fopen("dest.crt", "w");
    if (f_resultat == NULL)
    {
        printf("Erreur Open Perroquet");
        return 0;
    }


    // Initialisation d'une variable de stockage pour le contenu de fichier resultat
    char stockage_resultat[255] = "\0";
    fgets(stockage_resultat, 255, f_resultat);

    // Initialisation d'une variable de stockage pour le contenu de fichier perroquet
    char stockage_perroquet[255] = "\0";
    fgets(stockage_perroquet, 255, f_peroquet);

    // Arret des pointeurs sur FILE
    fclose(f_resultat);
    fclose(f_peroquet);


    // D�claration et initialisation du pointeur dechiffrage sur le FILE
    FILE *f_dechiffrage = fopen("resultat_dechiffrage.txt", "r");
    if (f_dechiffrage == NULL)
    {
        printf("Erreur Open Source");
        return 0;
    }

    // Cr�ation d'une variable de stockage pour le contenu de fichier dechiffrage
    char stockage_dechiffrage[255] = "\0";


    // Variable de longueur de resultat et perroquet
    int longueur_resultat = strlen(stockage_resultat);
    int longueur_perroquet = strlen(stockage_perroquet);


    // Si la longueur de r�sultat est inf�rieur � la longueur de perroquet
    if (longueur_resultat < longueur_perroquet)
    {
        // D�roulement de l'algorithme normalement avec l'�criture dans stockage dechiffrage
        for (int i = 0; i < longueur_resultat; i++)
        {
            stockage_dechiffrage[i] = stockage_resultat[i] + stockage_perroquet[i];
        }

    }
    else // ( longueur resultat est > longueur perroquet )
    {

        for (int j = 0; j < longueur_resultat; j++)
        {
            stockage_dechiffrage[j] = stockage_resultat[j] + stockage_perroquet[j% longueur_perroquet];
        }


    }

    // Ecriture dans resultat_dechiffrage.txt
    fwrite(&stockage_dechiffrage, sizeof(char), strlen(stockage_dechiffrage), f_dechiffrage);
    printf("Votre message dechiffre a ete ecrit dans resultat_dechiffrage.\n");

    // Fermeture du pointeur
    fclose(f_dechiffrage);

    return 0;

}


