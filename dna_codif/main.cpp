#include "defs.h"

void decodificareADN (sirADN cod, long &nr){
    int exponent = strlen(cod);
    nr = 0;

    for(int i = 0; i<exponent; i++)
    {
        switch (cod[exponent-1-i])
        {
            case 'A': nr += pow( i) * 0; break;
            case 'G': nr += pow( i) * 2; break;
            case 'C': nr += pow( i) * 1; break;
            case 'T': nr += pow( i) * -1;break;
            default: break;
        }
    }
}

void codificareADN(long nr, sirADN cod)
{
    int lungime = 0; bool pozitiv = true;

    if(nr >= 0){
        while(nr > pow(lungime) *2.5){
            cod[lungime++] = 0;
        }
        cod[lungime] = 0;
    }

    if(nr < 0){
        int sum = 2;
        pozitiv = false;
        nr = -nr;
        while( nr>= sum){
            cod[lungime++] = 0;
            sum+=pow(lungime);
        }
        cod[lungime] = 0;
    }

    for(int i = lungime; i>=0; i--){
        int rest = nr % 4;
        switch (rest){
            case 0: break;
            case 1: pozitiv ? cod[i] ++ : cod[i] --; break;
            case 2: cod[i]+=2; pozitiv ? : cod[i-1] -=1; break;
            case 3: pozitiv ? cod[i] --, cod[i-1]++ : cod[i] ++, cod[i-1] --; break;

        }

        switch (cod[i]) {
            case 3: cod[i]--, cod[i-1]++; break;
            case -2: cod[i] = 2, cod[i-1] --; break;
            case -3: cod[i] = 1, cod[i-1]--; break;
        }

        nr/=4;
    }
    swapCod(cod);
}

void adunareADN(sirADN first, sirADN second, sirADN sum){
    long  a = 0, b = 0, s = 0;
    decodificareADN(first,a);
    decodificareADN(second, b);
    s = a+b;
    codificareADN(s, sum);
}

int main() {

    sirADN sir; long nr;
    codificareADN(27,sir);
    std::cout << sir << '\n';
    decodificareADN(sir, nr);
    std::cout << nr;
    return 0;
}

