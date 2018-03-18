#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "argValid.h"

int argValid(const char* arg, long int* storeArg, unsigned int base){
    char* endptr = NULL;
    long int temp;
   
    errno = 0;
    temp = strtol(arg, &endptr, base);

    if( (errno) || (*endptr) )
        return -1; 

    /* if we got here, argument is valid */
   *storeArg = temp;

   return 0;
}
