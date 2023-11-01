//gameBoard.h

#include <stdbool.h>

typedef struct{
    bool isAlive;
    bool willBeAlive;
}gameOfLifeEntry;

int population;

gameOfLifeEntry **fillBoard(int density, int rows, int columns);
bool nextRound(gameOfLifeEntry** gameBoard, int rows, int columns);
void printBoard(gameOfLifeEntry **gameBoard, int rows, int columns);