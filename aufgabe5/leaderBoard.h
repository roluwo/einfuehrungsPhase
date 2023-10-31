//leaderBoard.h

#include <stdio.h>
#include <string.h>

#define LEADERBOARDSIZE 10;

typedef struct
{
    char name[100];
    int guesses;
}LeaderBoardEntry;

LeaderBoardEntry *getBoard(char filename[20]);
void writeBoardToFile(LeaderBoardEntry *board, char filename[20]);
int compareGuesses(const void *a, const void *b);
void sortBoard(LeaderBoardEntry *board, int entrys);
LeaderBoardEntry *addToBoard(LeaderBoardEntry *board, LeaderBoardEntry newEntry);