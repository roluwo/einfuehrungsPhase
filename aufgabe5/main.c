//main.c

#include "number.c"
#include "leaderBoard.c"

#define FILENAME "leaderBoard.txt";

char filename[20] = "leaderBoard.txt";

char *getFilename();

int main(){

    bool playAgain = true;

    while(playAgain){
    
        int randomNumber = generateNumber();
        guessCounter = 0;

        while (!guessNumber(randomNumber)){
        
        printf("Falsche Nummer, rate nochmal.\n");
    
        }

        LeaderBoardEntry* leaderBoard = getBoard(getFilename());

        printf("Bitte gib deinen Namen ein:\n");
        char name[100];
        scanf(" %9s", name);

        LeaderBoardEntry newEntry;
        snprintf(newEntry.name, sizeof(newEntry.name), "%s", name);
        newEntry.guesses = guessCounter;

        writeBoardToFile(addToBoard(leaderBoard, newEntry), getFilename());

        free(leaderBoard);
        
        printf("Möchtest du nochmal spielen? (0/1)\n");
        int temp;
        scanf(" %d", &temp);
        if (temp == 1 || temp == 0) {
            playAgain = temp;
        }
        else {
            printf("Ungültige Antwort, Programm wird beendet.\n");
            playAgain = false;
        }

    }
    printf("Programm beendet!\n");
}

char *getFilename(){
    return FILENAME;
}

