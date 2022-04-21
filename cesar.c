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
 *  Nom du fichier : cesar.c                                                   *
 *                                                                             *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// chiffrage Cesar
wchar_t *chiffreTexteCesar(wchar_t tab[10000], int key)
{
    for (int i = 0; i <= 10000; i++)
    {
        if (tab[i] >= 'A' && tab[i] <= 'Z')
        {
            tab[i] = (tab[i] - 'A' + key) % 26 + 'A';
        }
        else if (tab[i] >= '0' && tab[i] <= '9')
        {
            tab[i] = (tab[i] - '0' + key) % 10 + '0';
        }
    }
    return tab;
}

// Dechiffage Cesar
wchar_t *dechiffreTexteCesar(wchar_t tab[10000], int k)
{
    return chiffreTexteCesar(tab, -k);
}