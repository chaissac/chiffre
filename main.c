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
#include "defs.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <wchar.h>
#include "cesar.h"
#include "vigenere.h"
#include "verif.h"
#include "fcntl.h"

void main()
{
    char *locale = setlocale(LC_ALL, "");

    printf("\nLocale : %s\n", locale);

    FILE *fichier = NULL;
    char tab[SIZE];
    char text[SIZE] = "";

    // Initialisation du tableau et saisie du text
    wprintf(L"\nTapez votre message crypté ou à décrypter :\n> ");

    // fgetws(tab1, SIZE, stdin);
    scanf("%[^\n]s", tab);

    normText(tab, text, false);

    wprintf(L"\nTexte normalisé : %s\n", text);

    fichier = fopen("resultat.txt", "w");
    fprintf(fichier, "Texte saisi : %s\n", text);

    // choix de l'algorithme
    int rep1 = readInt(L"\nChoisir la méthode de chiffrement :\n 1-César\n 2-Vigénère\n> ", 1, 2);

    // choix pour chiffrer ou dechiffre le message saisi
    int rep2 = readInt(L"\nTaper 1 pour chiffrer votre message, et 2 pour le déchiffrer.\n> ", 1, 2);

    // déroulé du programme
    if (rep1 == 1)
    {
        int key = readInt(L"\nSaisir la valeur de la clef Cesar (entre 1 et 25)\n> ", 1, 25);
        if (rep2 == 1)
        {
            fprintf(fichier, "Chiffrement César avec Clef=%d\n", key);
            wprintf(L"Message chiffré : %s\n", texteCesar(text, key,1));
        }
        else // forcément rep2=2
        {
            fprintf(fichier, "Dechiffrement Cesar avec Clef=%d\n", key);
            wprintf(L"Message déchiffré : %s\n", texteCesar(text, key,-1));
        }
    }
    else // forcément rep = 2
    {
        char key[SIZE];
        int k;
        wprintf(L"Saisir la clé.\n");
        
        // fgetws(tab1, SIZE, stdin);
        tab[0] = '\0';
        scanf("%[^\n]s", tab);
        key[0] = '\0';
        normText(tab, key, true);
        wprintf(L"\nClé normalisée : %s\n", key);
        if (rep2 == 1)
        {
            fprintf(fichier, "Chiffrement Vigenere avec Clef = %s\n", key);
            printf("Message chiffre : %s\n", texteVigenere(text, key, 1));
        }
        else // forcément rep2=2
        {
            fprintf(fichier, "Dechiffrement Vigenere avec Clef = %s\n", key);
            printf("Message dechiffre : %s\n", texteVigenere(text, key, -1));
        }
    }
    fprintf(fichier, "Resultat : %s\n", text);
    fclose(fichier);
    printf("Retrouvez le resultat dans le fichier : resultat.txt \n");
}
