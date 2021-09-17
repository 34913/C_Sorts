#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _data int32_t

_data porovnani = 0;

void tisk (_data *pole, _data delka){
    for(_data i = 0; i < delka; i++){
        printf("%d", pole[i]);
        if(i + 1 < delka)
            putchar(' ');
        else
            putchar('\n');
    }
    return;
}

void ins(_data *vstup, _data *vystup, _data delka, _data index){
    if(index == delka)
        return;
    if(index == 0 || (index > 0 && vstup[index] > vystup[index - 1])){
        vystup[index] = vstup[index];
        if((index > 0 && vstup[index] > vystup[index - 1]))
            porovnani++;
    }
    else{
        for(_data i = 0; 1; i++){
            porovnani++;
            if(vstup[index] <= vystup[i]){
                for(_data y = index; y > 0; y--)
                    vystup[y] = vystup[y - 1];
                vystup[i] = vstup[index];
                break;
            }
        }
    }
    //tisk(vystup, index + 1);
    return ins(vstup, vystup, delka, index + 1);
}

int main()
{
    _data delka_vstup;
    printf("Pocet prvku: ");
    scanf("%d", &delka_vstup);
    _data *vstup = (_data*)malloc(sizeof(_data)*delka_vstup);
    _data *vystup = (_data*)malloc(sizeof(_data)*delka_vstup);
    if(vstup == NULL || vystup == NULL)
        return 0;

    printf("Zadej prvky:\n");
    for(_data i = 0; i < delka_vstup; i++)
        scanf("%d", &vstup[i]);
    getchar();

    clock_t ted = clock();
    rekurze(vstup, vystup, delka_vstup, 0);
    ted = clock() - ted;

    free(vstup);
    tisk(vystup, delka_vstup);
    free(vystup);

    printf("Porovnani: %d\n", porovnani);
    printf("Cas propoctu: %.2f\n", (float)(ted/CLOCKS_PER_SEC));

    return 0;
}
