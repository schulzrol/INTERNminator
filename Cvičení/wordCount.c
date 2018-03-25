#include <stdio.h>
#include <ctype.h>
#include "wordCount.h"

#define TRUE 1
#define FALSE  0
unsigned int wordCount(const char* strp){
        unsigned int wcount = 0;
        
        const char* lstrp = strp;
        int inside = FALSE;
        
        /*Until end of string*/
        while(*lstrp++){
            /*If current char == whitespace*/
            if(isspace(*lstrp)){
                if (inside){
                    inside = FALSE ;
                    wcount++;
                }
            }
            else
                if(!inside){
                        inside = TRUE;
                        wcount++;
                }
                inside = TRUE;
        }
        
        return wcount;
}
