#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 100
#define RANDLIMIT 1000

int main(){
    srand((unsigned)time(NULL));

    unsigned int arr[100],
                 max = 0,
                 maxpos = 0,
                 i;

    for (i = 0; i < LENGTH; i++){
        arr[i] = rand() % (RANDLIMIT+1);
    }

    max = *arr;

    for (i = 0; i < LENGTH; i++){
        if(arr[i] > max){
            max = arr[i];
            maxpos = i;
        }
    }
    printf("arr[%u] = %u\n", maxpos, max );

    return 0;
}
