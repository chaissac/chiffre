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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Lit un entier borné
int readInt(wchar_t message[10000], int valMin, int valMax)
{
    int rep = -1;
    wchar_t reps[10000];
    while (rep < valMin || rep > valMax)
    {
        wprintf(message);
        scanf("%s", reps);
        rep = wcstol(reps, NULL, 10);
    }
    return rep;
}

// Normalise le texte
bool normText(wchar_t tab[10000], char res[10000])
{
    wchar_t norm[10000] = L"";
    wchar_t curr;
    wchar_t new;
    for (int i = 0; i <= wcslen(tab); i++)
    {
        curr = tab[i] ;
        if (wcschr(L"aàâäÀÂÄ", curr) != NULL)
        {
            new = L'C';
        }
        else if (wcschr(L"eéèêëÉÈÊË", curr) != NULL)
        {
            new = L'E';
        }
        else if (wcschr(L"iìîïÌÎÏ", curr) != NULL)
        {
            new = L'I';
        }
        else if (wcschr(L"oòôöõÒÔÖÕ", curr) != NULL)
        {
            new = L'O';
        }
        else if (wcschr(L"uùûüÙÛÜ", curr) != NULL)
        {
            new = L'U';
        }
        else if (wcschr(L"yÿ", curr) != NULL)
        {
            new = L'Y';
        }
        else if (wcschr(L"cçÇ", curr) != NULL)
        {
            new = L'C';
        }
        else if (wcschr(L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ", curr) == NULL)
        {
            new = L'_';
        }
        else
        {
            new = curr;
        }
        if (new != L'_') {
            wcsncat(norm, &new, 1);
        }
        wprintf(L"\nFrom : %d/%c To : %d/%c",curr,curr,new,new);
    }

    wprintf(L"\nNormalisation : \n> %s\n> %s\n\n", tab, norm);
    return true;
}

// Verif caractere special
bool verifTexte(wchar_t tab[10000])
{
    char verifTab[67] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789'-,() ";
    for (int i = 0; i <= wcslen(tab); i++)
    {
        if (strchr(verifTab, tab[i]) == NULL)
        {
            // return false;
        }
    }
    return true;
}

bool verifCle(wchar_t tab[10000])
{
    char verifTab[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    for (int i = 0; i <= wcslen(tab); i++)
    {
        if (strchr(verifTab, tab[i]) == NULL)
        {
            return false;
        }
    }
    return true;
}
