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
 *  Nom du fichier : verif.c                                                   *
 *                                                                             *
 ******************************************************************************/
#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <wchar.h>

// Lit un entier borné
int readInt(wchar_t *message, int valMin, int valMax)
{
    int rep = -1;
    char reps[SIZE];
    while (rep < valMin || rep > valMax)
    {
        wprintf(message);
        while ((getchar()) != '\n');
        scanf("%[^\n]s", reps);
        if (reps[0] == '0')
        {
            printf("\nExit !\n");
            exit(0);
        }
        rep = strtol(reps, NULL, 10);
    }
    return rep;
}

// Normalise le texte
char *normText(char *tab, char *res, bool strict)
{
    char curr;
    char new;
    int i = 0;
    // res[0] = '\0';
    while (tab[i] != '\0')
    {
        curr = tab[i];
        if (curr == -57 || curr == -58 || curr == -73 || curr == -74 || curr == -75 || curr == -96 || curr == -113 || curr == -114 || curr == -122 || curr == -123 || curr == -124 || curr == -125)
        {
            new = 'A';
        }
        else if (curr == -110 || curr == -111)
        {
            new = 'A';
        }
        else if (curr == -44 || curr == -45 || curr == -46 || curr == -112 || curr == -118 || curr == -119 || curr == -120 || curr == -126)
        {
            new = 'E';
        }
        else if (curr == -34 || curr == -40 || curr == -41 || curr == -42 || curr == -95 || curr == -115 || curr == -116 || curr == -117)
        {
            new = 'I';
        }
        else if (curr == -27 || curr == -28 || curr == -29 || curr == -30 || curr == -32 || curr == -48 || curr == -94 || curr == -101 || curr == -103 || curr == -107 || curr == -108 || curr == -109)
        {
            new = 'O';
        }
        else if (curr == -21 || curr == -22 || curr == -23 || curr == -102 || curr == -105 || curr == -106 || curr == -93 || curr == -127)
        {
            new = 'U';
        }
        else if (curr == -19 || curr == -20 || curr == -104)
        {
            new = 'Y';
        }
        else if (curr == -121 || curr == -128)
        {
            new = 'C';
        }
        else if (curr == -47)
        {
            new = 'D';
        }
        else if (curr == -91 || curr == -92)
        {
            new = 'N';
        }
        else if (curr >= 'a' && curr <= 'z')
        {
            new = toupper(curr);
        }
        else
        {
            new = curr;
        }
        // printf("\nFrom : %d/%c To : %d/%c", curr, curr, new, new);
        if (new != '_')
        {
            if (!strict || (new >= 'A' && new <= 'Z'))
            {
                strncat(res, &new, 1);
            }
        }
        i++;
    }
    return res;
}
