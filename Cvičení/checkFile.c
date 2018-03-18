#include <stdio.h>
#include <stdlib.h>
#include "toNumber.h"
#include "wordCount.h"

unsigned int checkNumFile(FILE* fp, unsigned int base ){
    int ch;
    bool inside

    if(!fp){
        fprintf(stderr, "Null file pointer!/n");
        return -1;
    }
    
    while( (ch = getc(fp)) != EOF ){
        if( toNumber() ){
                
        }
    
    }


return 
}
