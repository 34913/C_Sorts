#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void posun(int p, int *pole){
    int index = 0;
    int pomocna;

    while(1){
        if(index*2 + 1 < p){
            if(pole[index] < pole[index*2 + 1]){
                pomocna = pole[index];
                pole[index] = pole[index*2 + 1];
                pole[index*2 + 1] = pomocna;
            }
        }
        if(index*2 + 2 < p){
            if(pole[index] < pole[index*2 + 2]){
                pomocna = pole[index];
                pole[index] = pole[index*2 + 2];
                pole[index*2 + 2] = pomocna;
            }
        }

        if(++index == p)
            break;
    }
    return;
}

int main()
{
    int pocet;
    int *pole;

    scanf("%d", &pocet);
    pole = (int*)malloc(sizeof(int) * pocet);
    for(int i = 0; i < pocet; i++)
        scanf("%d", &pole[i]);

    posun(pocet, pole);

    while(1) {
        printf("%d ", pole[0]);
        if(pocet == 1)
            break;
        pole[0] = pole[--pocet];
        posun(pocet, pole);
    }
    printf("\n");

    return 0;
}

