//
// Created by Stefan on 10/22/2020.
//
// A = 0, C = 1, G = 2, T = -1
#ifndef DNA_CODIF_DEFS_H
#define DNA_CODIF_DEFS_H
#define MAX_ADN 10
#include <iostream>
#include <cstring>
typedef char sirADN[MAX_ADN];

void codificareADN(long , sirADN );
void decodificareADN (sirADN , long &);
void adunareADN(sirADN , sirADN , sirADN  );

int pow (int exp){
    int aux = 4;
    if (exp == 0)   return 1;
    if (exp == 1)   return 4;

    for(int i = 2; i<=exp;i++)
        aux *= 4;
    return aux;
}

void swapCod (sirADN cod)
{
    for(int i = 0; i<strlen(cod); i++)
        switch(cod[i]){
            case -1: cod[i] = 'T'; break;
            case 0:  cod[i] = 'A'; break;
            case 1:  cod[i] = 'C'; break;
            case 2:  cod[i] = 'G'; break;

            case 'T': cod[i] = -1;break;
            case 'A': cod[i] = 0; break;
            case 'C': cod[i] = 1; break;
            case 'G': cod[i] = 2; break;
        }
}

int solution[MAX_ADN];

void write(int k, char sirADN[MAX_ADN]) {
    int i;
    for (i = 0; i < k; i++) {
        if (solution[i] == -1) sirADN[k - 1 - i] = 'T';
        if (solution[i] == 0) sirADN[k - 1 - i] = 'A';
        if (solution[i] == 1) sirADN[k - 1 - i] = 'C';
        if (solution[i] == 2) sirADN[k - 1 - i] = 'G';
    }
    sirADN[k] = '\0';
}

#endif //DNA_CODIF_DEFS_H
