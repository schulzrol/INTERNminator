#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define RANDLIMIT 10
#define and &&
#define or ||
#define not !
#define CLS system("cls") // Clears Windows console
#define TOPTILE "[%2d]"
#define INSTILE "[  ]"

// tests functions
int maxinArray(int arr[], int size);
void vertHisto(int arr[], int size);
void delay(int milliseconds);
void bubblesort(int *arr[], int size);

int main(){
    srand(time(NULL)); // call just once! sets time for rand() function
    //int array[N] = {1,2,3,4,5,6,7,8,9,10};
    int array[N];
    int length = sizeof(array)/sizeof(array[0]); // gets length of array

    for (int i = 0; i < length; ++i) { // assigns random number between 0 and n to array location i
        array[i] = rand()%(RANDLIMIT+1);
    }

    bubblesort(array, length);
    getchar();
    return 0;
}

int maxinArray(int arr[], int size){ // returns the biggest value in array
    int biggest = arr[0];

    for(int i=1; i < size; i++){
        if (arr[i] > biggest) {
            biggest = arr[i];
        }
    }
    return biggest;
}

void vertHisto(int arr[], int size){ // prints vertical histogram of given array and array size
    int maxnum = maxinArray(arr, size);
    for(int j=maxnum; j> 0; j--){ // go from height of biggest bar to bottom
        for(int i=0; i < size; i++){ // go from the first element to last
            if(arr[i] == j) // if on top of given height/bar...
                printf(TOPTILE, j); // ...print top bar tile
            else if(j < arr[i]) // if inside bar print inside bar
                printf(INSTILE); // ...print inside bar tile
            else{
                printf("    "); // otherwise print nothing (spaces to match bar tile length)
            }
        printf(" ");
        }
        printf(":%2d\n",j);
    }
    for (int i= 0; i < size; i++)
        printf("%3d. ", i);
}

void delay(int milliseconds){

    clock_t start_time = clock(); // Starting start time

    while (clock() < start_time + milliseconds); // looping till required time is not acheived
}

void swapInt(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void bubblesort(int *arr[], int size){
    vertHisto(arr, size);
    for (int j = 0; j < size; j++){
        for ( int i = 0; i < size-1; i++){
            if (arr[i] < arr[i+1]){
                delay(166);
                CLS;
                swapInt(&arr[i], &arr[i+1]);
                vertHisto(arr, size);
            }
        }
    }
}
