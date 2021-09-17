#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int32_t typ;

typ porovnani = 0;

void quick(typ *pole, typ Lmez, typ Pmez){
    if(Lmez < Pmez){
        typ pivot = pole[Pmez];
        typ vec = Lmez;

        for(typ i = Lmez; i <= Pmez; i++){
            if(pole[i] <= pivot){
                typ pomocna = pole[vec];
                pole[vec] = pole[i];
                pole[i] = pomocna;
                vec++;
            }
            porovnani++;
        }

        quick(pole, Lmez, vec - 2);
        quick(pole, vec, Pmez);

    }
    return;
}

int main()
{
    typ pocet;
    scanf("%d", &pocet);

    typ *pole = (typ*)malloc(sizeof(typ) * pocet);
    for(typ i = 0; i < pocet; i++)
        scanf("%d", &pole[i]);

    quick(pole, 0, pocet - 1);

    printf("%d\n", porovnani);
    printf("%d", pole[0]);
    for(typ i = 1; i < pocet; i++)
        printf(", %d", pole[i]);

    putchar('\n');
    return 0;
}
