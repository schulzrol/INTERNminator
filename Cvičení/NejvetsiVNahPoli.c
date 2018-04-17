#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assignRandoms.h"
#include "IndexNejvetsiho.h"
#include "toNumber.h"
#include "isBlankLine.h"

#define ALLOCJUMP 5
#define DEFBASE 10

int main(int argc, char *argv[]){    
    size_t len = 0,
           mem2alloc;
    long int largestpos,
             largest,
             numcount = 0,
             arrlength = ALLOCJUMP,
             llen,
             number,
             *arr;
    FILE    *fp = NULL;
    char    *line = NULL;

    /* Check if correctly executed */
    if(argc != 2){
        printf("USAGE:\tmaxinarr [FILE_NAME]\n\t\tFILE_NAME\n\t\t\tName of file in which you wish to find the largest number (current directory by default).\n\n)");
        return -1;
    }

    /* Check file */
    fp = fopen(argv[1], "r");
    if (fp == NULL){
        fprintf(stderr, "ERROR:\tFailed to open file: %s\n", argv[1]);
        return -1;
    }
    
    mem2alloc = (size_t) arrlength * sizeof(unsigned int);
    arr = malloc( mem2alloc );

    /* if malloc couldn't allocate that much memory */
    if(arr == NULL) {  
        fprintf(stderr, "ERROR:\tFailed to allocate %zu bytes of memory!\n", mem2alloc);
        return -1;
    }

    while( (llen = getline(&line, &len, fp)) != -1 ){
        
        /* Checko for blanko lineo */
        if(isBlankLine(line, llen) == 0){
            
            /* Check if line content is valid number */
            if(toNumber(line, &number, DEFBASE) == 0){
                numcount++;
                
                /* Check if array can hold another number */
                if(numcount > arrlength){
                    arrlength += ALLOCJUMP;
                    mem2alloc = (size_t) arrlength * sizeof(unsigned int);
                    arr = realloc(arr, mem2alloc); 
                    
                    /* if realloc couldn't allocate that much memory */
                    if(arr == NULL) {
                       fprintf(stderr, "ERROR:\tFailed to allocate %zu bytes of memory!\n", mem2alloc);
                       return -1;
                     }
                }

                arr[numcount-1] = number;
            }
            else{
                fprintf(stderr,"ERROR:\tFailed to parse argument: '%s'\n", line);
                return -1;
            }
        
        }
    
    }
    

    largestpos = IndexNejvetsiho(arr, numcount);
    largest = arr[largestpos];


    /* Deallocate all pointers */
    free(arr);
    free(fp);
    free(line);
    arr = NULL;
    fp = NULL;
    line = NULL;

    printf("=> arr[%ld] = %ld\n", largestpos, largest );
    return 0;
}
