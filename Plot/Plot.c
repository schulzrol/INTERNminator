#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define or ||
#define and &&

struct Coordinations{
    char name;
    int x;
    int y;
}Coordinations;

int length;

int BiggestX(struct Coordinations Coords[]);
int BiggestY(struct Coordinations Coords[]);
int SmallestX(struct Coordinations Coords[]);
int SmallestY(struct Coordinations Coords[]);
int ValidCoords(int x, int y, struct Coordinations Coords[]);
int IsIn(int axis, int num, struct Coordinations Coords[]);

int main()
{
    do{
        printf("How many points?\n: ");
        fflush(stdout);
        scanf("%d",&length);
    }while(length <= 0);

    struct Coordinations Coords[length];

    for(int i = 0; i<length; i++){
        Coords[i].name = 65+i;
        printf("\n%c(x,y)?: ",Coords[i].name);
        fflush( stdout );
        scanf("%d %d",&Coords[i].x, &Coords[i].y);
    }


    for(int i = 0; i<length; i++){
        printf("\n%C(%d,%d)\n", Coords[i].name, Coords[i].x, Coords[i].y);
    }

    printf("Plot:\n");
    for(int y = BiggestY(Coords)+1; y>= SmallestY(Coords)-1; y--){
        for(int x = SmallestX(Coords)-1; x<= BiggestX(Coords)+1; x++){
            if( ( IsIn('y',y,Coords) == IsIn('x',x,Coords) ) and (IsIn('x',x,Coords) >= 0) ){
                printf("   %c", Coords[IsIn('x',x,Coords)].name);  // pouzit kdyz zobrazuji cisla na osach
                //printf("%c", Coords[IsIn('x',x,Coords)].name); // pouzit kdyz NEzobrazuji cisla na osach
            }
            else if (x == 0){
                printf(" %3d", y); // zobrazi cisla na ose y
                //printf("|");        // zobrazi pouze caru na ose y
            }
            else if (y == 0){
                printf(" %3d", x); // zobrazi cisla na ose x
                //printf("-");        // zobrazi pouze caru na ose x
            }
            else{
                printf("   ."); // pouzit kdyz zobrazuji cisla na osach
                //printf(".");     // pouzit kdyz NEzobrazuji cisla na osach
            }
        }
        printf("\n");
    }

    getchar();
    return 0;
}


int BiggestX(struct Coordinations Coords[]){
    int maxX = Coords[0].x;

    for( int i = 0; i < length; i++){
        if(Coords[i].x > maxX)
            maxX = Coords[i].x;
    }

    return maxX;
}

int BiggestY(struct Coordinations Coords[]){
        int maxY = Coords[0].y;

    for( int i = 0; i < length; i++){
        if(Coords[i].y > maxY)
            maxY = Coords[i].y;
    }
    return maxY;
}

int SmallestX(struct Coordinations Coords[]){
    int minX = Coords[0].x;

    for( int i = 0; i < length; i++){
        if(Coords[i].x < minX)
            minX = Coords[i].x;
    }
    if (minX > 0){
        minX= -1;
    }
    return minX;
}

int SmallestY(struct Coordinations Coords[]){

    int minY = Coords[0].y;

    for( int i = 0; i < length; i++){
        if(Coords[i].y < minY)
            minY = Coords[i].y;
    }

    if (minY > 0){
        minY = -1;
    }
    return minY;
}

int IsIn(int axis, int num, struct Coordinations Coords[]){

        if( axis == 'x'){
            for( int i = 0; i < length; i++){
                if(num == Coords[i].x){
                    return(i);
                }
            }
        }
        else if( axis == 'y'){
            for( int i = 0; i < length; i++){
                if(num == Coords[i].y){
                    return(i);
                }
            }
        }

    return(-1);
}
