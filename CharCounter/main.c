#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PATH "Test/Macbeth.txt"   // testing Path to text file
#define ASCIIstart 65             // capital A
#define ASCIIend 90               // capital Z

int main(){
    FILE *fp;
    char textfile[256] = {PATH};
    int c,  // used to get
        i,  // used to index
        divider; // used to optimize the size of histo
    unsigned int alphabet[ASCIIend - ASCIIstart + 1] = {0},
                 csum = 0,   // number of characters in .txt file
                 tsum = 0;   // total of used characters

//    printf("Enter the path to text file you want to use ( including .txt ): \n"); // user chooses relative path to .txt file ! CANT CONTAIN SPACES !
//    scanf("%s", textfile);

    fp = fopen(textfile,"r");   //Opens file in relative path textfile
    if( fp == NULL ){    // if file isnt present at location, print error message
        printf ("Failed to open file\n");
        return -1;
    }
    while( ( c = (getc(fp))) != EOF ){    // do until at the end of file
        csum++; // raising the number of characters in .txt file
        if(toupper(c) >= ASCIIstart && toupper(c) <= ASCIIend){    // ask if given character is in alphabet
            alphabet[toupper(c)-ASCIIstart]++;  // raising the usage of a character
            tsum++;
        }
    }
    fclose(fp); // closes the opened .txt file

    divider = tsum/sizeof(alphabet);

    printf("Characters found in %s: \n", textfile);
    printf("\nUsage:  \tHistogram:\n");
    for( i = 0; i < 26; i++ ){
        printf("%c: %4d \t", i+ASCIIstart, alphabet[i]); //go through the alphabet array sums and print number of usages
        if( alphabet[i] > 0 ){
            for( int j = 0; j <= floor(alphabet[i]/divider); j++ ){
                printf("[]");
            }
        }
        printf("\n");
    }
    printf("Total: %6d\n",tsum); // prints sum of all usages
    printf("Characters in file: %7d\n",csum); // prints how many characters there are in a .txt file
    return 0;
}
