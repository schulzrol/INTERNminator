#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assignRandoms.h"
#include "IndexNejvetsiho.h"
#include "printHelp.h"

#define defaultRANDMAX 1000
#define defaultRANDMIN 0
#define defaultLENGTH 100

int main(int argc, char *argv[]){
    int largest,
        randmin,
        randmax;
    int *arr;
    unsigned int largestpos,
                 arrlength;

    srand((int)time(NULL));

    /* setting default values */
    arrlength = defaultLENGTH;
    randmin = defaultRANDMIN;
    randmax = defaultRANDMAX;

    if(argc > 1){
        arrlength = abs(atoi(*(argv+1)));
        if(argc >= 3) randmin = atoi(*(argv+2));
        if(argc == 4) randmax = atoi(*(argv+3));
        if(argc > 4){
            printHelp();
            return -1;
        }
    }

    arr = malloc( arrlength * sizeof(int) );
    if (arr == NULL) {  /* if malloc couldn't allocate that much memory */
        printf("=> Not enough memory bro ;(\n");
        return -1;
    }

    assignRandoms(arr, arrlength, randmin, randmax);
    largestpos = IndexNejvetsiho(arr, arrlength);
    largest = arr[largestpos];


    free(arr);
    arr = NULL;

    printf("=> arr[%u] = %d\n", largestpos, largest );
    return 0;
}
