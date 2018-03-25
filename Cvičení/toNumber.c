#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "toNumber.h"

int toNumber(const char* arg, long int* storeArg, unsigned int base){
    char* endptr = NULL;
    long int temp;
   
    errno = 0;
    temp = strtol(arg, &endptr, base);

    if( (errno) || (endptr == 0) ){
        fprintf(stderr, "ERROR: Cannot parse argument: '%s'\n", arg);
        return -1; 
    }
    /* if we got here, argument is valid */
   *storeArg = temp;

   return 0;
}
