#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define typ int32_t

typ porovnani = 0;

void mer(typ *vstup, typ *vystup, typ zacatek_vstupu, typ pocet){
    //printf("%d %d ", zacatek_vstupu, pocet);
    if(pocet <= 1){
        vystup[0] = vstup[zacatek_vstupu];
        //printf("%d\n", vstup[zacatek_vstupu]);
        return;
    }
    //printf("\n");
    typ delic = pocet / 2;

    typ in1 = delic;
    typ in2 = pocet - delic;

    typ *pole_pred = (typ*)malloc(sizeof(typ) * in1);
    typ *pole_po = (typ*)malloc(sizeof(typ) * in2);

    if(pole_pred == NULL || pole_po == NULL)
        exit;

    mer(vstup, pole_pred, zacatek_vstupu, in1);
    mer(vstup, pole_po, zacatek_vstupu + delic, in2);

    in1 = 0;
    in2 = 0;
    //printf("- ");
    for(typ index = 0; index < pocet; index++){
        if(in1 >= delic){
            vystup[index] = pole_po[in2++];
            //printf("%d ", vystup[index]);
            continue;
        }
        else if(in2 >= pocet - delic){
            vystup[index] = pole_pred[in1++];
            //printf("%d ",vystup[index]);
            continue;
        }

        if(pole_pred[in1] < pole_po[in2])
            vystup[index] = pole_pred[in1++];
        else
            vystup[index] = pole_po[in2++];
        porovnani++;

        //printf("%d ", vystup[index]);
    }
    //printf("\n");

    free(pole_po);
    free(pole_pred);
    return;
}


int main()
{
    typ pocet;
    typ *pole, *vysledek;
    printf("Pocet prvku: ");
    scanf("%d", &pocet);

    pole = (typ*)malloc(sizeof(typ) * pocet);
    vysledek = (typ*)malloc(sizeof(typ) * pocet);

    if(pole == NULL || vysledek == NULL)
        return 1;

    printf("Prvky:\n");
    for(typ i = 0; i < pocet; i++)
        scanf("%d", &pole[i]);

    clock_t ted = clock();
    mer(pole, vysledek, 0, pocet);
    ted = clock() - ted;

    for(typ i = 0; i < pocet; i++)
        printf("%d\n", vysledek[i]);

    printf("Porovnani: %d\n", porovnani);
    printf("Cas vypoctu: %.2f\n", float(ted/CLOCKS_PER_SEC));
    free(pole);
    free(vysledek);
    return 0;
}
