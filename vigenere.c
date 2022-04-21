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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//
wchar_t* chiffreTexteVigenere(wchar_t tab[10000],wchar_t k[1000]){
    int key;
    int j;
     for(int i=0;i<=10000;i++){
        if(isalnum(tab[i])){
            j = i%wcslen(k);
            key=k[j]-97;
            for(int p = 1;p<=key; p++){
                if(tab[i]=='Z'){
                    tab[i]='A';
                } else if (tab[i]=='9') {
                    tab[i]='1';
                } else {
                    tab[i]=tab[i]+1;
                }
            }
        } else {
            tab[i]=tab[i];
        }
    }
    return tab;
}

wchar_t* dechiffreTexteVigenere(wchar_t tab[10000],wchar_t k[1000]){
    int key;
    int j;
     for(int i=0;i<=10000;i++){
        if(isalnum(tab[i])){
            j = i%wcslen(k);
            key=k[j]-97;
            for(int p = 1;p<=key; p++){
                if(tab[i]=='A'){
                    tab[i]='Z';
                } else if (tab[i]=='9') {
                    tab[i]='1';
                } else {
                    tab[i]=tab[i]-1;
                }
            }
        } else {
            tab[i]=tab[i];
        }
    }
    return tab;
}