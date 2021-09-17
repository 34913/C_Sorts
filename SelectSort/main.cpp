#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

unsigned long porovnavani = 0;

void select(long **prvky, long od, long celkem) {
    if(od != celkem - 1){
        long n_index = od;
        long n_nejmensi = (*prvky)[od];

        for(long i = (od + 1); i < celkem; i++){
            if((*prvky)[i] < n_nejmensi) {
                n_nejmensi = (*prvky)[i];
                n_index = i;
            }
            porovnavani++;
        }

        long pomocna = (*prvky)[od];
        (*prvky)[od] = n_nejmensi;
        (*prvky)[n_index] = pomocna;

        return select(prvky, od + 1, celkem);
    }
    return;
}

int main()
{
    printf("Pozor na preteceni pameti pro pocet porovnani! Max cisel pro porovnani je %d!\n", 36329);
    long pocet, *cisla;
    printf("Nahodne? ");
    char ch = getchar();
    printf("Pocet cisel: ");
    scanf("%lu", &pocet);
    cisla = (long*)malloc(sizeof(long) * pocet);
    if(cisla == NULL){
        perror("Chyba");
        return -1;
    }
    if(ch == '1'){
        srand(time(NULL));
        for(long i = 0; i < pocet; i++)
            cisla[i] = rand()%((pocet*4)-(pocet*2));
    }
    else {
        for(long i = 0; i < pocet; i++)
            scanf("%lu", &cisla[i]);
    }

    putc('\n', stdout);
    clock_t ted = clock();
    trideni(&cisla, 0, pocet);
    ted = clock() - ted;

    for(long i = 0; i < pocet; i++){
        printf("%lu\n", cisla[i]);
    }
    printf("Pocet porovnani: %lu; Delka propoctu %.3f\n", porovnavani, (float)((float)ted/CLOCKS_PER_SEC));
    return 0;
}

