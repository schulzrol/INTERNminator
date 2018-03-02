#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int IndexNejvetsiho(unsigned int *arr, unsigned length, unsigned int *max);

#define LENGTH 100
#define RANDLIMIT 1000

int main(){
    srand((unsigned)time(NULL));

    unsigned int arr[LENGTH],
                 i,
                 max,
                 maxpos;

    for (i = 0; i < LENGTH; i++){
        arr[i] = rand() % (RANDLIMIT+1);
    }

    maxpos = IndexNejvetsiho(arr, LENGTH, &max);

    printf("arr[%u] = %u\n", maxpos, max );

    return 0;
}

unsigned int IndexNejvetsiho(unsigned int *arr, unsigned int length, unsigned int *max){
    unsigned int maxpos;

    *max = *arr;

    for (int i = 0; i < length; i++){
        if(arr[i] > *max){
            *max = arr[i];
            maxpos = i;
        }
    }
    return maxpos;
}
