#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int sum = 0;
    /*
    printf("Main arguments:\n");
    for(int i = 0; i < argc; i++){
            printf("argv[%d]: %c\n", i, *argv[i]);
    }
    */

    if(argc-1){
        for(int i = 1; i <= argc-1; i++){
            if(atoi(argv[i])){
                sum += atoi(argv[i]);
            }
        }
        printf("> %d\n", sum);
    }
    else{
        printf("> No arguments :(");
        return -1;
    }

    return 0;
}
