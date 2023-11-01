//main.c

#include "gameBoard.h"
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int rows = 100;
int columns = 100;
int percentage = 66;

int  main(int argc, char** argv){
    
    gameOfLifeEntry** test = fillBoard(percentage,rows,columns);
    
    printBoard(test, rows,columns);

    printf("%i\n", population);

    while (nextRound(test, rows,columns)){
        sleep(1);
    }
}