#include <stdlib.h>
#include "argValid.h"

int argValid(const char* arg, int* storeArg, unsigned int base){
    unsigned int defBase = 0;
    char* endptr = NULL;
    int temp;

    /* checking base */
    if( ((base >= 2) && (base <= 32)) && (base <> defBase) ){
        defBase = base;
    }
    else{
        /* invalid base */
        return -1;
    }

    temp = strtol(arg, &endptr, defBase);

    /* no digits in string */
    if(endptr == arg){
        return -2;
    }

    /* argument containts characters other than valid numbers in base chosen*/
    if(*endptr != '\0'){
        return -3;
    }

    /* if we got here, argument is valid */
   *storeArg = temp;

   return 1;
}
