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

    if( (errno) || (*endptr) ){
        fprintf(stderr, "Error parsing argument: '%c'\n", *arg);
        return -1; 
    }
    /* if we got here, argument is valid */
   *storeArg = temp;

   return 0;
}
