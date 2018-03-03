#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int IndexNejvetsiho(int *arr, unsigned arrlength, int *largest);
void assignRandoms(int *arr, unsigned int arrlength, int randmin, int randmax);
void printhelp();

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

    if(argc > 1){   /* If there are any main arguments rewrite default values */
        if(argc >= 2) arrlength = atoi(*(argv+1));  /* user inputed second argument "arrlength" */
        if(argc >= 3) randmin = atoi(*(argv+2));    /* user inputed third argument "randmin" */
        if(argc == 4) randmax = atoi(*(argv+3));    /* user inputed fourth argument "randmax" */
        if(argc > 4){                               /* user inputed some #$@&%*! */
            printHelp();
            return -1;
        }
    }

    arr = malloc( arrlength * sizeof(int) );  /* dynamically allocate array for 'arraylengh' ints */

    if (arr == NULL) {  /* if malloc couldn't allocate that much memory */
        printf("=> Not enough memory bro ;(\n");
        return -1;
    }
    printf("\nrandmax: %d\nrandmin: %d\narrlength: %u\n\n", randmax, randmin, arrlength);

    assignRandoms(arr, arrlength, randmin, randmax);    /* scramble things up a bit */
    largestpos = IndexNejvetsiho(arr, arrlength, &largest);

    free(arr);
    arr = NULL;

    printf("=> arr[%u] = %d\n", largestpos, largest );
    return 0;
}

unsigned int IndexNejvetsiho(int *arr, unsigned int arrlength, int *largest){
    unsigned int largestpos;

    *largest = *arr;

    for (int i = 0; i < arrlength; i++){
        if(*(arr+i) > *largest){
            *largest = *(arr+i);
            largestpos = i;
        }
    }
    return largestpos;
}

void assignRandoms(int *arr, unsigned int arrlength, int randmin, int randmax){
    for (int i = 0; i < arrlength; i++){
        *( arr + i ) = (rand()%( (randmax+1) - randmin))+randmin;
    }
}

void printHelp(){
    printf("\n=> maxinarr [length] [randmin] [randmax]\n" );
    printf("\t:length \tsets the number of elements in array\n" );
    printf("\t:randmin\tsets the lowest possible value that can occur in array\n" );
    printf("\t:randmax\tsets the highest possible value that can occur in array\n" );
}
