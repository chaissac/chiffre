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
 *  Nom du fichier : vigenere.c                                                *
 *                                                                             *
 ******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *texteVigenere(char *tab, char *key, int sens)
{
    int i = 0;
    int k = 0;
    int l = strlen(key);
    while (tab[i] != '\0')
    {
        if (tab[i] >= 'A' && tab[i] <= 'Z')
        {
            tab[i] = (tab[i] - 'A' + 26 + sens * (key[k] - 'A')) % 26 + 'A';
            k = (k + 1) % l;
        }
        else if (tab[i] >= '0' && tab[i] <= '9')
        {
            tab[i] = (tab[i] - '0' + 10 + sens * (key[k] - 'A')) % 10 + '0';
            k = (k + 1) % l;
        }
        i++;
    }
    return tab;
}
