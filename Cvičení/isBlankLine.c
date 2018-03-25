#include "isBlankLine.h"
#include <ctype.h>

int isBlankLine(const char* line, unsigned int llen){
    unsigned int wscount = 0;

    for(unsigned int i = 0; i < llen-1; i++){
        if(isspace(line[i])){
            wscount++;    
        }
    }

    if(wscount < llen){
        return 0;
    }
    else{
        return -1;
    }
}
