#include "pch.h"
#include "testul.h"
#include <stdio.h>
#define NR 10 // MISRA: Evită directivele de preprocesare. Folosește const pentru valori constante.

int f(int v[], int, int, int);
void sortAsc(int v[], int n);
void sortDesc(int v[], int n);


int f(int v[], int p1, int p2, int x)
{
    int mijloc;
    if (p1 > p2)
        return -1;
    else {
        mijloc = (p1 + p2) / 2; // MISRA: Folosește paranteze suplimentare pentru a clarifica ordinea operațiilor.
        if (v[mijloc] == x)
            return mijloc;
        else if (x < v[mijloc])
            return f(v, p1, mijloc - 1, x);
        else
            return f(v, mijloc + 1, p2, x);
    }
}

// Funcție de sortare crescătoare
void sortAsc(int v[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp; // MISRA: Accesul și schimbul între elemente ar trebui efectuate cu funcții dedicate dacă sunt disponibile.
            }
        }
    }
}

// Funcție de sortare descrescătoare
void sortDesc(int v[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] < v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp; // MISRA: Accesul și schimbul între elemente ar trebui efectuate cu funcții dedicate dacă sunt disponibile.
            }
        }
    }
}
