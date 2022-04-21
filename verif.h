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
*  Nom du fichier : verif.h                                                   *
*                                                                             *
******************************************************************************/

// Lit un entier borné
int readInt(wchar_t message[10000], int valMin,int valMax);
// Normalise le texte
bool normText(wchar_t tab[10000], char res[10000]);
//verif caratere special
bool verifTexte(wchar_t tab[10000]);
//verif cle Vigenere
bool verifCle(wchar_t tab[10000]);