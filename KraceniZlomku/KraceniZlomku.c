#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

int delenec,
    delitel,
    bigger,
    maxdiv;

    printf("Zadejte celociselny nezaporny zlomek ve formatu x/x\n: ");

    fflush( stdout );

    if ( (delitel != 0) && (scanf("%d/%d", &delenec, &delitel)) ){
        if( delenec < delitel){
            bigger = delenec;
        }
        else{
            bigger = delitel;
        }

        for(int i=1; i <= bigger; i++){
            if( !(delenec%i) && !(delitel%i) ){
                maxdiv = i;
            }
        }

        if ( (delitel/maxdiv) == 1){
            printf("-> %d = %d/%d\n", delenec/maxdiv, delenec/maxdiv, delitel/maxdiv);
        }
        else{
            printf("-> %d/%d\n", delenec/maxdiv, delitel/maxdiv);
        }
    }
    else{
        printf("\nNeplatne hodnoty!\n");
    }
    return 0;
}
