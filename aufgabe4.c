// aufgabe4

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define STANDARDSIZE 16

int height;
int width;
int currentPopulation = 0;
int formerPopulation = -1;
int densityLevel;
bool ***gameBoard;
bool ***copiedGameBoard;

void getSize();
void createGameBoard();
int getPopulation();
void calculateGameBoard();
void copieGameBoard();
bool stagnationOccured();
void getDensity();

int main()
{

    getDensity();
    printf("Test\n");
    getSize();
    printf("Test\n");
    createGameBoard();

    printf("The game begins!\n");

    printf("Test\n");

    int pop = 4;

    printf("%d\n", pop);

    calculateGameBoard();

    sleep(1);
}

void getDensity()
{

    printf("Please enter a number between 0 and 9 to determine the density level of the cells: (0 -> all dead, 9 all alive)\n");
    scanf(" %d", &densityLevel);

    if (densityLevel < 0 || densityLevel > 9)
    {

        perror("Density out of bound:");
        exit(1);
    }
}

void getSize()
{

    char answer;

    printf("Do you want to use the standard size? (y/n)\n");
    scanf(" %c", &answer);
    printf("%c\n", answer);

    if (answer == 'y')
    {

        height = STANDARDSIZE;
        width = STANDARDSIZE;
        
    }
    else if (answer == 'n')
    {

        printf("Enter Height:\n");
        scanf(" %d", &height);

        printf("Enter Width:\n");
        scanf(" %d", &width);
    }
    else
    {

        perror("Invalid answer:");
        exit(1);
    }
}

void createGameBoard()
{

    srand(time(NULL));//Initialisierung des RandomGenerators

    bool ***gameBoard = malloc(height * sizeof(bool *)); // Speicherreservierung für das Array
    for (int i = 0; i < height; i++) {
        gameBoard[i] = malloc(width * sizeof(bool));
    }
    if (gameBoard == NULL)
    {
        perror("gameBoard not allocated:");
        exit(1);
    }

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            
            int random = rand() % 10;
            
            if (random <= densityLevel)
            {
                
                gameBoard[i][j] = true;

            }
            else
            {
                
                gameBoard[i][j] = false;
                
            }
        }
    }
}

int getPopulation()
{

    currentPopulation = 0;

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            if ((*gameBoard)[i][j] == true)
            {

                currentPopulation++;
            }
        }
    }

    return currentPopulation;
}

void copieGameBoard()
{
    printf("Test3\n");
    bool ***copiedGameBoard = malloc(height * sizeof(bool *)); // Speicherreservierung für das Array
    for (int i = 0; i < height; i++) {
        printf("Test4\n");
        copiedGameBoard[i] = malloc(width * sizeof(bool));
    }
    if (copiedGameBoard == NULL)
    {
        perror("copiedGameBoard not allocated:");
        exit(1);
    }

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            copiedGameBoard[i][j] = gameBoard[i][j];
        }
    }
}

void calculateGameBoard()
{
    printf("Test1\n");
    copieGameBoard();
    printf("Test2\n");
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            int tempNeighbourCounter = 0;

            if (copiedGameBoard[i + 1][j])
            {
                tempNeighbourCounter++;
            }
            if (copiedGameBoard[i][j + 1])
            {
                tempNeighbourCounter++;
            }
            if (copiedGameBoard[i - 1][j])
            {
                tempNeighbourCounter++;
            }
            if (copiedGameBoard[i][j - 1])
            {
                tempNeighbourCounter++;
            }

            switch (tempNeighbourCounter)
            {
            case 0:
                (*gameBoard)[i][j] = false;
                break;
            case 1:
                (*gameBoard)[i][j] = false;
                break;
            case 2:
                break;
            case 3:
                (*gameBoard)[i][j] = true;
                break;
            case 4:
                (*gameBoard)[i][j] = false;
                break;
            default:
                perror("Something substential went wrong!!!");
                exit(1);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        free(copiedGameBoard[i]);
    }

    free(copiedGameBoard);
}

bool stagnationOccured()
{

    if (formerPopulation == currentPopulation)
        return true;
    else
        return false;
}