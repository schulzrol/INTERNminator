#include "IndexNejvetsiho.h"
unsigned int IndexNejvetsiho(long int *arr, unsigned int arrlength){
        
        unsigned int largestpos = 0;

        int largest = *arr;

        for(int i = 0; i < arrlength; i++){
                if(*(arr+i) > largest){
                        largest = *(arr+i);
                        largestpos = i;
                }
        }
        return largestpos;
}
