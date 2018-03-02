#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int IndexNejvetsiho(unsigned int *arr, unsigned length);

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


    max = *arr;


    printf("arr[%u] = %u\n", IndexNejvetsiho(arr, LENGTH), max );

    return 0;
}
unsigned int IndexNejvetsiho(unsigned int *arr, unsigned int length){
    for (i = 0; i < LENGTH; i++){
        if(arr[i] > max){
            max = arr[i];
            maxpos = i;
        }
    }
    return maxpos;
}
