#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"

/*
 * randomtestcard1.c -- randomly tests adventurer
 */
int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
int adventurerFunc(int currentPlayer, struct gameState *state, int handPos);

int main (int argc, char** argv) {
	 printf("\n**Random Testing: adventurer card in randomtestcard1.c **\n");
    srand(time(NULL));
    printf("RANDOM TESTS\n");

    int numGames = 500;
    int numTest = 3;
    int failedTest = 0;
    for(int i = 0; i < numGames; i++)
    {
        int numplayers = rand() % MAX_PLAYERS + 1; // Value between 2 and 4.
        struct gameState G;
        int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};

        initializeGame(numplayers, k, rand(), &G);

        int player = rand() % numplayers;
        G.whoseTurn = player;

        int handPos = rand() % MAX_HAND;

        struct gameState orig;
        memcpy(&orig, &G, sizeof(struct gameState));

        cardEffect(adventurer, 0,0,0, &G, handPos,0);

        if(G.handCount[player] != orig.handCount[player] + 2)
        {
            printf("TEST FAILED Player %d did not draw 2 cards.\n", player);
            failedTest++;
        }

        int cardDrawn1 = G.hand[player][G.handCount[player] - 1];
        if(cardDrawn1 != copper || cardDrawn1 != silver || cardDrawn1 != gold)
        {
            printf("TEST FAILED: Player %d's newest card is not money.\n", player);
            failedTest++;
        }

        int cardDrawn2 = G.hand[player][G.handCount[player] - 2];
        if(cardDrawn2 != copper || cardDrawn2 != silver || cardDrawn2 != gold)
        {
            printf("TEST FAILED: Player %d's second newest card is not money.\n", player);
            failedTest++;
        }
    }

    printf("%d of %d TESTS PASSED for adventurer\n", numGames * numTest - failedTest, numGames * numTest);
}
