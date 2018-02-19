#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define LENGTH 6

unsigned int BinarySearch(unsigned int x, unsigned int arr[], unsigned int length);

int main()
{
    float PC,           /* Pocatecni Cena */
          ROVPRVSAZ[LENGTH] = {20, 11, 5.5, 2.15, 1.4, 1.02},       /* pole SAZeb za PRVni rok pri ROVnomernem odpisu */
          ROVDALSAZ[LENGTH] = {40, 22.25, 10.5, 5.15, 3.4, 2.02};   /* pole SAZeb za DALsi roky pri ROVnomernem odpisu */

    unsigned int x,             /* odpisova skupina */
                 ZC,            /* Zustatkova Cena */
                 odpis,         /* rocni odpisy */
                 opravka = 0,   /* rocni opravky */
                 OS[LENGTH] = {1, 2, 3, 4, 5, 6},               /* pole Odpisovych Skupin */
                 DO[LENGTH] = {3, 5, 10, 20, 30, 50},           /* pole Delek Odpisu */
                 ZRYPRVSAZ[LENGTH] = {3, 5, 10, 20, 30, 50},    /* pole SAZeb za PRVni rok pri ZRYchlenem odpisu */
                 ZRYDALSAZ[LENGTH] = {4, 6, 11, 21, 31, 51};    /* pole SAZeb za DALsi roky pri ZRYchlenem odpisu */

    unsigned short MO,      /* Metoda Odpisu */
                   iOS,     /* index vybrane odpisove skupiny */
                   roky,    /* pocet let, po které se bude odepisovat */
                   RP;      /* Rok Porizeni */

    printf("Zadejte...\n");
    printf(" odpisovou skupinu\n :");
    scanf("%d", &x);
    printf(" puvodni cenu\n :");
    scanf("%f", &PC);
    ZC = PC;
    printf(" rok porizeni\n :");
    scanf("%hu", &RP);
    printf(" rovnomerne nebo zrychlene odpisy [R][Z]\n :");
    if (getchar()){
        MO = toupper(getchar());
    }

    //printf("\nodpisova skupina: %d\npuvodni cena: %f\nrok porizeni: %d\nodpisovaci skupina(BS): %d\nrocni sazba za dalsi roky: %.2f\n\n", x, PC, RP, BinarySearch(x, OS, LENGTH), ROVDALSAZ[BinarySearch(x, OS, LENGTH)]);

    if(MO == 'R'){
        printf("    \t       \tROVNOMERNE ODPISY\n");
    }
    else{
        printf("    \t       \tZRYCHLENE ODPISY\n");
    }
    printf(" Rok\t   Odpis\t Opravky   Zustatkova Cena\n");
    printf("---------------------------------------------------\n");

    iOS = BinarySearch(x, OS, LENGTH);
    roky = DO[iOS];

    switch(MO){
        case 'R':
            odpis = ceilf(PC*ROVPRVSAZ[iOS])/100;                               /*                               */
            opravka += odpis;                                                   /* Provede vypocet pro první rok */
            ZC -= odpis;                                                        /*                               */
            printf("%4u\t%8u\t%8u\t  %8u\n", RP, odpis, opravka, ZC);             /*                               */
            for(int i = 1; i < roky; i++){
                odpis = ceilf(PC*ROVDALSAZ[iOS])/100;
                opravka += odpis;
                ZC -= odpis;
                printf("%4u\t%8u\t%8u\t  %8u\n", RP+i, odpis, opravka, ZC);
            }
            break;
        case 'Z':
            odpis = ceilf(PC/ZRYPRVSAZ[iOS]);                                   /*                               */
            opravka += odpis;                                                   /* Provede vypocet pro první rok */
            ZC -= odpis;                                                        /*                               */
            printf("%4u\t%8u\t%8u\t  %8u\n", RP, odpis, opravka, ZC);             /*                               */
            for(int i = 1; i < roky; i++){
                odpis = ceilf((2*ZC)/(ZRYDALSAZ[iOS]-i));
                opravka += odpis;
                ZC -= odpis;
                printf("%4u\t%8u\t%8u\t  %8u\n", RP+i, odpis, opravka, ZC);
            }
            break;


    }
return 0;
}

unsigned int BinarySearch(unsigned int x, unsigned int arr[], unsigned int length){

    unsigned long int L = 0,         /* Left Wall */
                 R = length--,  /* Right Wall */
                 M = (L+R)/2;   /* Middle */

    while (L <= R){
        if (arr[M] == x)    /* if we found the searched element */
            return M;       /* return its index in arr[] */
        if (arr[M] < x){    /* if the element is to the right of the middle */
            L = M++;        /* set the Left Wall to the left most point in the subarray */
            M = (L+R)/2;    /* set middle */
        }
        else{               /* if the element is to the left of the middle */
            R = M--;        /* set the Right Wall to the right most point in the subarray */
            M = (L+R)/2;    /* set middle */
        }
    }
    return -1;  /* if x not found in array */
}
