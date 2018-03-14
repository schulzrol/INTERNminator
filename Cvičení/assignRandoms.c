#include <stdlib.h>
#include "assignRandoms.h"

void assignRandoms(int *arr, unsigned int arrlength, int randmin, int randmax){
    for (int i = 0; i < arrlength; i++){
        *( arr + i ) = (rand()%( (randmax+1) - randmin))+randmin;
    }
}
