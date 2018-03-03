#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int IndexNejvetsiho(int *arr, unsigned length, int *largest);
void assignRandoms(int *arr, unsigned int arrlength, int randmin, int randmax);

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

    srand((unsigned)time(NULL));

    if(argc - 1){   /* If there are any main arguments */
        switch (argc){
            case 2:     /* user inputed second argument "arrlength" */
                arrlength = atoi(*( argv + 1 ));
            case 3:     /* user inputed third argument "randmin" */
                randmin = atoi(*( argv + 2 ));
            case 4:     /* user inputed fourth argument "randmax" */
                randmax = atoi(*( argv + 3 ));
            default:    /* user inputed some #$@&%*! */
                printf("=> maxinarr [length] [randmin] [randmax]\n" );
                printf("\t\t-length\tsets the number of elements in array\n" );
                printf("\t\t-randmin\tsets the lowest possible value that can occur in array\n" );
                printf("\t\t-randmax\tsets the highest possible value that can occur in array\n" );
                return -1;
        }
    }
    else{   /* No arguments in main*/
        arrlength = defaultLENGTH;
        randmin = defaultRANDMIN;
        randmax = defaultRANDMAX;
    }

    arr = malloc( arrlength * sizeof(unsigned int) );  /* dynamically allocate array for 'arraylengh' unsigned ints */

    if (arr == NULL) {  /* if malloc couldn't allocate that much memory */
        printf("=> Not enough memory bro :(\n");
        return -1;
    }

    assignRandoms(arr, arrlength, randmin, randmax);    /* scramble things up a bit */
    largestpos = IndexNejvetsiho(arr, arrlength, &largest);

    free(arr);

    printf("=> arr[%u] = %d\n", largestpos, largest );
    return 0;
}

unsigned int IndexNejvetsiho(int *arr, unsigned int length, int *largest){
    unsigned int largestpos;

    *largest = *arr;

    for (int i = 0; i < length; i++){
        if(arr[i] > *largest){
            *largest = arr[i];
            largestpos = i;
        }
    }
    return largestpos;
}

void assignRandoms(int *arr, unsigned int arrlength, int randmin, int randmax){
    for (int i = 0; i < arrlength; i++){
        *(arr+i) = (rand() % randmax) + randmin;
    }
}
