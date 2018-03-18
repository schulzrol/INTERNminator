#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assignRandoms.h"
#include "IndexNejvetsiho.h"
#include "printHelp.h"
#include "argValid.h"

#define defaultRANDMAX 1000
#define defaultRANDMIN 0
#define defaultLENGTH 100

int main(int argc, char *argv[]){
    long int largest,
        randmin,
        randmax;
    int *arr;
    long int largestpos,
             arrlength;

    srand((int)time(NULL));

    /* setting default values */
    arrlength = defaultLENGTH;
    randmin = defaultRANDMIN;
    randmax = defaultRANDMAX;




    /* If there are any main arguments rewrite default values */
    if(argc > 1){
        if( argValid(argv[1], &arrlength, 10) < 0 ){
            printf("=> Cannot use '%s' !\n", argv[1]);
            return -1;
        }
        if(argc >= 3){
            if( argValid(argv[2], &randmin, 10) < 0){
                printf("=> Cannot use '%s' !\n", argv[2]);
                return -1;
            }
        }
        if(argc == 4){
            if( argValid(argv[3], &randmax, 10) < 0){
                printf("=> Cannot use '%s' !\n", argv[3]);
                return -1;
            }
        }
        if(argc > 4){
            printHelp();
            return -1;
        }
    }

    arr = malloc( arrlength * sizeof(int) );  /* dynamically allocate array for 'arraylengh' ints */

    if (arr == NULL) {  /* if malloc couldn't allocate that much memory */
        printf("=> Not enough memory bro\n");
        return -1;
    }

    assignRandoms(arr, arrlength, randmin, randmax);    /* scramble things up a bit */
    largestpos = IndexNejvetsiho(arr, arrlength);
    largest = arr[largestpos];


    free(arr);
    arr = NULL;

    printf("=> arr[%ld] = %ld\n", largestpos, largest );
    return 0;
}
