//number.c

#include "number.h"
#include <stdio.h>
#include <time.h>

int guessCounter = 0;

int generateNumber(){

    srand(time(NULL));//Initialisierung des RandomGenerators

    return ((rand() % 100) +1);

}

bool guessNumber(int randomNumber) {

    int guess;

    printf("Welche Zahl willst du raten?\n");
    scanf(" %d", &guess);
    guessCounter++;

    if(randomNumber < guess){
        printf("Die Zahl ist kleiner als %d.\n", guess);
        return false;
    }
    else if(randomNumber > guess){
        printf("Die Zahl ist größer als %d.\n", guess);
        return false;
    }
    else if (guess < 1 || guess > 100){
        printf("Zahl zu hoch oder zu niedrig, rate im Bereich von 1-100!\n");
        return false;
    }
    else{
        printf("Glückwunsch, du hast die Zahl in %d Versuchen erraten.\n", guessCounter);
        return true;
    }

}