//leaderBoard.c

#include "leaderBoard.h"
#include <stdlib.h>
#include <stdio.h>

LeaderBoardEntry *getBoard(char filename[20]){

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Fehler beim Öffnen der Datei.\n");
        return NULL;
    }

    size_t leaderBoardSize = LEADERBOARDSIZE;

    LeaderBoardEntry* leaderBoard = malloc(leaderBoardSize*sizeof(LeaderBoardEntry));
    if (leaderBoard == NULL) {
        printf("Speicherplatz konnte nicht zugewiesen werden.\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < leaderBoardSize; i++) {
        fscanf(file, "%9s %d\n", leaderBoard[i].name, &leaderBoard[i].guesses);
            
    }
    fclose(file);
    return leaderBoard;

}

int compareGuesses(const void *a, const void *b) {
    const LeaderBoardEntry *playerA = (const LeaderBoardEntry *)a;
    const LeaderBoardEntry *playerB = (const LeaderBoardEntry *)b;
    
    // Sortiere aufsteigend nach der Anzahl der Versuche (guesses)
    return playerA->guesses - playerB->guesses;
}

void sortBoard(LeaderBoardEntry* playerArray, int entrys) {
    qsort(playerArray, entrys, sizeof(LeaderBoardEntry), compareGuesses);
}

void writeBoardToFile(LeaderBoardEntry* board, char filename[20]){

    FILE *file = fopen(filename, "w");
    int size = LEADERBOARDSIZE;

    if (file != NULL) {
        for(int i = 0; i < size; i++){
            fprintf(file, "%s %d\n", board[i].name, board[i].guesses);
        }
    } else {
        printf("Fehler beim Öffnen der Datei.\n");
    }

    fclose(file);

}

LeaderBoardEntry *addToBoard(LeaderBoardEntry *board, LeaderBoardEntry newEntry){

    int size = LEADERBOARDSIZE;
    sortBoard(board, size);

    if (newEntry.guesses <= board[size-1].guesses){
        for(int i = 0; i < (size-1); i++){
            board[size-i-1] = board[size-i-2];
        }
        board[0] = newEntry;
    }
    sortBoard(board, size);
    return board;

}