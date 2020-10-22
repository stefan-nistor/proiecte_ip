#include "defs.h"
using namespace std;

string conversion(int number)
{
    string rezultat = "";
    int nrp = number, index = 0;

    for (int i = 0; i < 8; i++)
        cifre[i] = 0;

    while (nrp)
    {
        cifre[index++] = nrp % 10;
        nrp = nrp / 10;
    }


    switch ((((cifre[8] * 10) + cifre[7]) * 10) + cifre[6])
    {
        case 1: rezultat += "unmilion"; break;
        case 2: rezultat += "douamilioane"; break;
        case 3: rezultat += "treimilioane"; break;
        case 4: rezultat += "patrumilioane"; break;
        case 5: rezultat += "cincimilioane"; break;
        case 6: rezultat += "sasemilioane"; break;
        case 7: rezultat += "saptemilioane"; break;
        case 8: rezultat += "optmilioane"; break;
        case 9: rezultat += "nouamilioane"; break;
        default:
        {
            if (((cifre[7] * 10) + cifre[6]) > 0)
            {
                if (((cifre[7] * 10) + cifre[6]) > 20)
                    rezultat += creare_grupa(6, 8) + "demilioane";
                else
                    rezultat += creare_grupa(6, 8) + "milioane ";
            }
            break;
        }
    }

    switch ((((cifre[5] * 10) + cifre[4]) * 10) + cifre[3])
    {
        case 1: rezultat += "omie"; break;
        case 2: rezultat += "douamii"; break;
        case 3: rezultat += "treimii"; break;
        case 4: rezultat += "patrumii"; break;
        case 5: rezultat += "cincimii"; break;
        case 6: rezultat += "sasemii"; break;
        case 7: rezultat += "saptemii"; break;
        case 8: rezultat += "optmii"; break;
        case 9: rezultat += "nouamii"; break;
        default:
        {
            if (((cifre[4] * 10) + cifre[3]) > 0)
            {
                if (((cifre[4] * 10) + cifre[3]) > 20)
                    rezultat += creare_grupa(3, 5) + "de mii";
                else
                    rezultat += creare_grupa(3, 5) + "mii";
            }
            break;
        }
    }

    switch ((((cifre[2] * 10) + cifre[1]) * 10) + cifre[0])
    {
        case 1: rezultat += "unu"; break;
        case 2: rezultat += "doi"; break;
        case 3: rezultat += "trei"; break;
        case 4: rezultat += "patru"; break;
        case 5: rezultat += "cinci"; break;
        case 6: rezultat += "sase"; break;
        case 7: rezultat += "sapte"; break;
        case 8: rezultat += "opt"; break;
        case 9: rezultat += "noua"; break;
    }
    rezultat += creare_grupa(0, 2);
    return rezultat;
}

string creare_grupa(int start, int end)
{
    string grupa_string = "";
    if (cifre[end] != 0)
    {
        grupa_string = cifre_lit[cifre[end] - 1];
        if (cifre[end] == 1) grupa_string += "suta";
        else grupa_string += "sute";
    }
    end--;
    if (cifre[end] != 0)
    {
        if ((cifre[end] * 10) + cifre[end - 1] > 9 && (cifre[end] * 10) + cifre[end - 1] < 20)
            grupa_string += cifre_lit2[((cifre[end] * 10) + cifre[end - 1]) - 10];
        else
        {
            grupa_string += cifre_lit3[cifre[end] - 2];
            if (cifre[end - 1] != 0)
                grupa_string += "si ";
            if (cifre[end - 1] != 0)
                grupa_string += cifre_lit4[cifre[end - 1] - 1];
        }
    }
    else
    {
        if (cifre[end - 1] != 0 && cifre[2] != 0)
            grupa_string += cifre_lit4[cifre[end - 1] - 1];
    }
    return grupa_string;
}

int main () {
    return 0;
}