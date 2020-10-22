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
    int index = 0, rest, cat, ok;

    if(nr > 0){         //pentru nr pozitive
        while(nr){
            ok = 0;
            rest = nr % 4;

            if(rest % 4 != 3)
                solution[index++] = rest;
            else{
                cat = nr / 4;
                cat++;
                solution[index++] = nr - cat*4;
                ok = 1;
            }

            if(!ok)
                nr = nr/4;
            else nr = cat;
        }
    }
    else
    {
        while (nr != 0){    //pt nr negative
            ok = 0;
            rest = nr % 4;
            if(rest % 4 != 3)
                solution[index ++] = rest;
            else{
                cat = nr / 4;
                cat --;
                solution[index ++ ] = nr - cat*4;
                ok = 1;
            }
            if(!ok)
                nr = nr/4;
            else nr = cat;
        }
    }

    write(index, cod);
}

void adunareADN(sirADN first, sirADN second, sirADN sum){
    long  a = 0, b = 0, s = 0;
    decodificareADN(first,a);
    decodificareADN(second, b);
    s = a+b;
    codificareADN(s, sum);
}

int main() {

    return 0;
}

