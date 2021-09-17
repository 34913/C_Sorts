#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int32_t typ;
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

void ins(typ *vstup, typ *vystup, typ delka, typ index){
    if(index == delka)
        return;
    if(index == 0 || (index > 0 && vstup[index] > vystup[index - 1])){
        vystup[index] = vstup[index];
        if((index > 0 && vstup[index] > vystup[index - 1]))
            porovnani++;
    }
    else{
        for(typ i = 0; 1; i++){
            porovnani++;
            if(vstup[index] <= vystup[i]){
                for(typ y = index; y > 0; y--)
                    vystup[y] = vystup[y - 1];
                vystup[i] = vstup[index];
                break;
            }
        }
    }
    //tisk(vystup, index + 1);
    return ins(vstup, vystup, delka, index + 1);
}

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
        return;

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

void select(typ *prvky, typ od, typ celkem) {
    if(od != celkem - 1){
        typ n_index = od;
        typ n_nejmensi = prvky[od];

        for(typ i = (od + 1); i < celkem; i++){
            if(prvky[i] < n_nejmensi) {
                n_nejmensi = prvky[i];
                n_index = i;
            }
            porovnani++;
        }

        typ pomocna = prvky[od];
        prvky[od] = n_nejmensi;
        prvky[n_index] = pomocna;

        return select(prvky, od + 1, celkem);
    }
    return;
}

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

int main() {
    printf("Zvol tridici algoritmus (1-5)\n");
    printf("merge ... 0\n");
    printf("bubble ... 1\n");
    printf("select ... 2\n");
    printf("insert ... 3\n");
    printf("quick ... 4\n");

    typ algo;
    scanf("%d\n", &algo);
    if(!(algo >= 0 && algo <= 4)){
        printf("Zadej index sortu\n");
        return 1;
    }

    typ pocet;
    scanf("%d\n", &pocet);

    typ *pole = (typ*)malloc(sizeof(typ) * pocet);
    if(pole == NULL){
        perror("Chyba: ");
        return 1;
    }
    typ *vystup = (typ*)malloc(sizeof(typ) * pocet);
    if(vystup == NULL){
        perror("Chyba: ");
        return 1;
    }

    for(typ i = 0; i < pocet; i++)
        scanf("%d", &pole[i]);

    switch(algo){
    case 0:
        mer(pole, vystup, 0, pocet);
        break;
    case 1:
        bubble(pole, 0, pocet, 0);
        vystup = pole;
        break;
    case 2:
        select(pole, 0, pocet);
        vystup = pole;
        break;
    case 3:
        ins(pole, vystup, pocet, 0);
        break;
    case 4:
        quick(pole, 0, pocet - 1);
        vystup = pole;
        break;
    default:
        return 1;
    }

    printf("porovnani: %d\n", porovnani);
    printf("%d", vystup[0]);
    for(typ i = 1; i < pocet; i++)
        printf(", %d", vystup[i]);

    if(vystup != pole)
        free(vystup);
    free(pole);

    return 0;
}
