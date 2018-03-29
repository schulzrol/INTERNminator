#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printStacks(int *Stacks, unsigned int noStacks);

int nim(){

    int noStacks,
        noSticks,
        *Stacks,
        player,
        Sticks2Take;
    char chosenStack;

    printf("How many stacks?\n");
    getchar();
    scanf("%u", &noStacks);
    
    printf("By how many sticks?\n");
    getchar();
    scanf("%u", &noSticks);

    Stacks = malloc(noStacks *  sizeof(int));
    memset(Stacks, noSticks, noStacks);

    noSticks *= noStacks;

    while( noSticks > 0 ){
        player *= -1;

        printStacks(Stacks, noStacks);

        printf("Take from what stack?\n");
        getchar();
        scanf("%c", &chosenStack);
        chosenStack = toupper(chosenStack);
        printf("How many?\n");
        getchar();
        scanf("%d", &Sticks2Take);
        
        Stacks[(int)chosenStack - 'A'] -= Sticks2Take;
        noSticks -= Sticks2Take;
    }
    
    free(Stacks);
    Stacks = NULL;

    /*
     * -1 represents PLAYER 2 
     *  1 represents PLAYER 1
     */

    if(player == -1){
        printf("player 1 WINS!\n");
        return 0;
    }
    else{
        printf("player 2 WINS!\n");
        return 0;
    }

}


void printStacks(int *Stacks, unsigned int noStacks){

    printf("Stack:\tSticks left:\n");
    
    for(int i = 0; i < noStacks; i++){
        printf("%c\t\t%d\n", 'A'+i, Stacks[i]);    
    }

}
