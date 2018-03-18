#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 4000000000

int main(){
    srand(time(NULL)); // call just once! sets time for rand() function
    short int   dice1, // declaration of first die
                dice2; // declaration of second die
    unsigned long int   sums[11] = {0}, // array of sum occurences
                        throws = LIMIT+1, // var to store how many times to roll the two dice
                        divider;
    unsigned long long int tsum = 0; // sum of all occurences - total sum

    while (throws > LIMIT){ // very dumb protection against variable overflow, but as long as it does the job... - repeats until "throws" in range of 2^32
        printf("Kolik hodu kostkami? max. 4.000.000.000\n"); // asks how many times to roll the dice
        printf("  42xxxxxxxx\n"); // reference to max value possible
        printf(": ");
        fflush( stdout ); //flushes input buffer for the scanf
        scanf("%lu",&throws); // gets number of wanted throws
    }
    for (unsigned long int i = 0; i < throws; i++) {
        dice1 = (rand() % 6) + 1; // rolls first die - random number between 1 and 6
        dice2 = (rand() % 6) + 1; // rolls second die - random number between 1 and 6
        sums[(dice1+dice2)-2]++; // saves the sum occurence in its proper place
    }
    for( int i = 0; i < 11; i++ ){  // Sum of all occurences
        tsum += sums[i];
    }

    divider = (tsum/sizeof(sums))+1; // idk how this piece works, but it does...and thats cool to me

    printf("\nHody:\t  Vyskyt:\tP(A):\t\n\n"); // Prints header
    for( int i = 0; i < 11; i++ ){  // go through the array and print...
        printf("%2d:\t%9lu\t%lf\t", i+2, sums[i], sums[i]/(throws* 1.0)); //...from sum 2 to 12, prints occurrences of sums and probabilities
        if(sums[i] > 0){
            for(int j = 0; j < floor(sums[i]/divider)+1; j++){ // Prints graph of usages
            printf("/");                                       // one backslash used as unit of measure
            }
        }
        printf("\n");
    }
    return 0;
}
