#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define STANDARDSIZE 16

int height;
int width;
int currentPopulation;
int formerPopulation;
int densityLevel;
bool** gameBoard;
bool** copiedGameBoard;

void getSize() {

    char answer;

    printf("Do you want to use the standard size? (y/n)\n");
    fflush(stdin);
    scanf("%c", &answer);
    printf("%c\n", answer);
    
    if (answer == 'y') {

        height = STANDARDSIZE;
        width = STANDARDSIZE;

    }
    else if (answer == 'n') {
        
        printf("Enter Height:\n");
        fflush(stdin);
        scanf("%d", &height);

        printf("Enter Width:\n");
        fflush(stdin);
        scanf("%d", &width);

    }
    else {
        
        perror("Invalid answer:");
        exit(1);

    }

}

int main() {
    getSize();
}