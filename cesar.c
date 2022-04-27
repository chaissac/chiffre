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

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// chiffrage Cesar
char *texteCesar(char *tab, int key, int sens)
{
    int i = 0;
    while (tab[i] != '\0')
    {
        if (tab[i] >= 'A' && tab[i] <= 'Z')
        {
            tab[i] = (tab[i] - 'A' + 26 + sens*key) % 26 + 'A';
        }
        else if (tab[i] >= '0' && tab[i] <= '9')
        {
            tab[i] = (tab[i] - '0' + 10 + sens*key) % 10 + '0';
        }
        i++;
    }
    return tab;
}
