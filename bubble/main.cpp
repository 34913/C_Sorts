#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define typ int32_t

typ porovnani = 0;

void bubble(typ *pole, typ index, typ delka, typ zmena) {
    if(index == delka - 1 && zmena == 0){
        return;
    }
    if(index == delka - 1){
        index = 0;
        zmena = 0;
    }

    typ pomocna = 0;
    if(pole[index] > pole[index + 1]){
        pomocna = pole[index];
        pole[index] = pole[index + 1];
        pole[index + 1] = pomocna;
        zmena++;
    }
    porovnani++;

    return bubble(pole, index + 1, delka, zmena);
}


int main()
{
    typ *pole;
    typ pocet = 0;

    printf("Pocet prvku: ");
    scanf("%d", &pocet);

    pole = (typ*)malloc(sizeof(typ) * pocet);
    if(pole == NULL)
        return 1;

    printf("Prvky:\n");
    for(int i = 0; i < pocet; i++){
        scanf("%d", &pole[i]);
    }

    clock_t ted = clock();
    rekurze(pole, 0, pocet, 0);
    ted = clock() - ted;

    for(int i = 0; i < pocet; i++){
        printf("%d\n", pole[i]);
    }

    printf("Porovnani: %d\nCas propoctu: %.2f\n", porovnani, float(ted/CLOCKS_PER_SEC));

    free(pole);
    return 0;
}

