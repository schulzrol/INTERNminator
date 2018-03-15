#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "argValid.h"

int argValid(const char* arg, long int* storeArg, unsigned int base){
 
    char* endptr = NULL;
    long int temp;
   
    
    errno = 0;
    temp = strtol(arg, &endptr, base);

    /* underflow or overflow */
    if(errno == ERANGE){
        return -0;
    }
    
    if(errno != 0 && temp == 0){
        return -0;
    }

    /* no digits in string */
    if( (endptr == arg) || (errno == EINVAL) ){
        return -0;
    }

    /* argument containts characters other than valid numbers in base chosen*/
    if(*endptr != '\0'){
        return -0;
    }

    /* if we got here, argument is valid */
   *storeArg = temp;

   return 1;
}
