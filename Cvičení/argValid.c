#include <stdlib.h>
#include "argValid.h"

int argValid(const char* arg, long int* storeArg, unsigned int base){
 
    char* endptr = NULL;
    int temp;

    temp = strtol(arg, &endptr, base);

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
