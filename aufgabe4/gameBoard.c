// gameBoard.c

#include "gameBoard.h"
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int population;

gameOfLifeEntry **fillBoard(int density, int rows, int columns)
{
    int population = 0;
    srand(time(NULL)); // Initialisierung des RandomGenerators

    gameOfLifeEntry **gameBoard = malloc(rows * sizeof(gameOfLifeEntry *));
    for (int i = 0; i < rows; i++)
    {
        gameBoard[i] = malloc(columns * sizeof(gameOfLifeEntry));
    }
    if (gameBoard == NULL)
    {
        perror("Nicht allokiert");
        exit(1);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            gameBoard[i][j].isAlive = ((rand() % 100) < density);
            population++;
        }
    }
    printf("%i\n", population);
    return gameBoard;
}

void printBoard(gameOfLifeEntry **gameBoard, int rows, int columns)
{
    printf("-");
    for (int j = 0; j < columns; j++)
    {
        printf("--");
    }

    for (int i = 0; i < rows; i++)
    {
        printf("\n|");
        for (int j = 0; j < columns; j++)
        {
            printf("%i|", gameBoard[i][j].isAlive);
        }
    }
    printf("\n-");
    for (int j = 0; j < columns; j++)
    {
        printf("--");
    }
    printf("\n");
}

bool nextRound(gameOfLifeEntry **gameBoard, int rows, int columns)
{

    bool hasChanged = false;
    population = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            int neighboursAlive = 0;

            if (i >= 0 && i < rows && j >= 0 && j < columns)
            {
                if (i < rows - 1)
                    neighboursAlive += gameBoard[i + 1][j].isAlive;
                if (i > 0)
                    neighboursAlive += gameBoard[i - 1][j].isAlive;
                if (j < columns - 1)
                    neighboursAlive += gameBoard[i][j + 1].isAlive;
                if (j > 0)
                    neighboursAlive += gameBoard[i][j - 1].isAlive;
            }

            if (neighboursAlive == 0 || neighboursAlive == 1)
                gameBoard[i][j].willBeAlive = false;
            if (neighboursAlive == 2)
                gameBoard[i][j].willBeAlive = gameBoard[i][j].isAlive;
            if (neighboursAlive == 3)
                gameBoard[i][j].willBeAlive = true;
            if (neighboursAlive == 4)
                gameBoard[i][j].willBeAlive = false;
        }
    }
    
    for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (!hasChanged && (gameBoard[i][j].isAlive != gameBoard[i][j].willBeAlive))
                    hasChanged = true;
                gameBoard[i][j].isAlive = gameBoard[i][j].willBeAlive;
                if(gameBoard[i][j].isAlive)
                    population++;
            }
        }
    printBoard(gameBoard, rows,columns);
    printf("%i\n", population);
    return hasChanged;
}
