//
// Created by Stefan on 10/20/2020.
//

#ifndef NUMBER_TO_LETTERS_DEFS_H
#define NUMBER_TO_LETTERS_DEFS_H
#include <iostream>
#include <cstring>
using namespace std;

const string cifre_lit  [] =  { "o", "doua", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua" };
const string cifre_lit2 [] =   {"zece", "unsprezece", "doisprezece", "treisprezece", "paisprezece", "cincisprezece", "saisprezece", "saptesprezece", "optusprezece", "nouasprezece" };
const string cifre_lit3 [] =   { "douazeci", "treizeci", "patruzeci", "cincizeci", "saizeci", "saptezeci", "optzeci", "nouazeci" };
const string cifre_lit4 [] =   { "unu", "doi", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua" };

int cifre[10];

string creare_grupa(int, int);
string conversion(int);


#endif //NUMBER_TO_LETTERS_DEFS_H
