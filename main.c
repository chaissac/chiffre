/******************************************************************************
 *  ASR => 4R2.04                                                              *
 *******************************************************************************
 *                                                                             *
 *  N° de Sujet : 3                                                            *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Intitulé : Chiffrement de message                                          *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom-prénom1 : PETIT Auxence                                                *
 *                                                                             *
 *  Nom-prénom2 : LECLERC Flavien                                              *
 *                                                                             *
 *  Nom-prénom3 : BIBICH Rim                                                   *
 *                                                                             *
 *  Nom-prénom4 : CHAISSAC Nathan                                              *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom du fichier : main.c                                                    *
 *                                                                             *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "cesar.h"
#include "vigenere.h"
#include "verif.h"
#include "fcntl.h"

void main()
{
    wchar_t tab1[10000];
    wchar_t tab2[10000];
    // _setmode(_fileno(stdout), _O_U8TEXT);

    FILE *fichier = NULL;
    // Initialisation du tableau et saisie du text
    wprintf(L"\nTapez votre message (sans caractere spécial) :\n> ");
    scanf("%[^\n]s", tab1);

    for (int j = 0; j <= wcslen(tab1); j++)
    {
        tab2[j] = toupper(tab1[j]);
    }
    // verification de la validite du texte saisi
    if (verifTexte(tab2) == false)
    {
        wprintf(L"Erreur dans le texte\n");
        exit(1);
    }
    else
    {
        wprintf(L"Texte valide\n");
    }
    // normText(tab2);
    fichier = fopen("resultat.txt", "w");
    fprintf(fichier, "Texte saisi : %s\n", tab2);
    // choix de l'algorithme
    int rep = readInt(L"\nChoisir la methode de chiffrement :\n 1-Cesar\n 2-Vigenere\n> ", 1, 2);
    // choix pour chiffrer ou dechiffre le message saisi
    int rep2 = readInt(L"\nTaper 1 pour chiffrer votre message, et 2 pour le dechiffrer.\n> ", 1, 2);

    // déroulé du programme
    if (rep == 1)
    {
        int k = readInt(L"\nSaisir la valeur de la clef Cesar (entre 1 et 25)\n> ", 1, 25);
        if (rep2 == 1)
        {
            fprintf(fichier, "Chiffrement Cesar avec Clef=%d\n",k);
            wprintf(L"Message chiffré : %s\n", chiffreTexteCesar(tab2, k));

        }
        else // forcément rep2=2
        {
            fprintf(fichier, "Dechiffrement Cesar avec Clef=%d\n",k);
            wprintf(L"Message déchiffré : %s\n", dechiffreTexteCesar(tab2, k));
        }
    }
    else // forcément rep1 = 2
    {
        wchar_t cle[1000];
        int k;
        wprintf(L"Saisir la clé.\n");
        scanf("%s", cle);
        if (rep2 == 1)
        {
            fprintf(fichier, "Chiffrement Vigenere avec Clef = %s\n",cle);
            printf("Message chiffre : %s\n", chiffreTexteVigenere(tab2, cle));
        }
        else // forcément rep2=2
        {
            fprintf(fichier, "Dechiffrement Vigenere avec Clef = %s\n",cle);
            printf("Message dechiffre : %s\n", dechiffreTexteVigenere(tab2, cle));
        }
    }
    fprintf(fichier, "Resultat : %s\n", tab2);
    fclose(fichier);
    printf("Retrouvez le resultat dans le fichier : resultat.txt \n");
}
