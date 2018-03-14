#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int IndexNejvetsiho(int *arr, unsigned arrlengtht);
void assignRandoms(int *arr, unsigned int arrlength, int randmin, int randmax);
void printHelp(void);
int argValid(const char* arg, long int* storeArg, unsigned int base);

#define defaultRANDMAX 1000
#define defaultRANDMIN 0
#define defaultLENGTH 100

int main(int argc, char *argv[]){
    long int largest,
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




    /* If there are any main arguments rewrite default values */
    if(argc > 1){
        if(!(argValid(argv[1], &arrlength, 10))){
            printf("Cannot parse '%s' !\n", argv[1]);
            return -1;
        }
        if(argc >= 3){
            if(!(argValid(argv[1], &randmin, 10))){
                printf("Cannot parse '%s' !\n", argv[2]);
                return -1;
            }
        }
        if(argc == 4){
            if(!(argValid(argv[1], &randmax, 10))){
                printf("Cannot parse '%s' !\n", argv[3]);
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
        printf("=> Not enough memory bro ;(\n");
        return -1;
    }

    assignRandoms(arr, arrlength, randmin, randmax);    /* scramble things up a bit */
    largestpos = IndexNejvetsiho(arr, arrlength);
    largest = arr[largestpos];


    free(arr);
    arr = NULL;

    printf("=> arr[%u] = %d\n", largestpos, largest );
    return 0;
}

unsigned int IndexNejvetsiho(int *arr, unsigned int arrlength){
    unsigned int largestpos = 0;

    int largest = *arr;

    for (int i = 0; i < arrlength; i++){
        if(*(arr+i) > largest){
            largest = *(arr+i);
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

int argValid(const char* arg, long int* storeArg, unsigned int base){
    char* endptr = NULL;
    long int temp;

    temp = strtol(arg, &endptr, base);

    /* no digits in string */
    if(endptr == arg){
        return -1;
    }

    /* argument containts characters other than valid numbers in base chosen*/
    if(*endptr){
        return -2;
    }

    /* if we got here, argument is valid */

   *storeArg = temp;

   return 1;
}
