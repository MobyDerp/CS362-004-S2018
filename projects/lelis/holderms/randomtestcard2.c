#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"

/*
 * randomtestcard2.c -- randomly tests council_room
 */
int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
int council_roomEffect (struct gameState *state, int currentPlayer, int handPos);

int main (void) {
    printf("\n**Random Testing: council_room in randomtestcard2.c **\n");

    srand(time(NULL));

    printf("RANDOM TESTS\n");

    int numtests = 100;
    int NUMQUESTIONS = 0;
    int bad = 0;
    for(int i = 0; i < numtests; i++)
    {
        int numPlayers = rand() % (MAX_PLAYERS - 1) + 2; // Value between 2 and 4.
        NUMQUESTIONS += numPlayers;
        struct gameState G;
        int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};

        initializeGame(numPlayers, k, rand(), &G);

        int player = rand() % numPlayers;
        G.whoseTurn = player;

        int handPos = rand() % MAX_HAND;

        struct gameState orig;
        memcpy(&orig, &G, sizeof(struct gameState));

        cardEffect(council_room, 0,0,0, &G, handPos, 0);

        for(int i = 0; i < numPlayers; i++){
            if(i == player){
                if(G.handCount[i] != orig.handCount[i] + 4){
                    printf("TEST FAILED: Player %d did not get exactly 4 more cards.\n", i);
                    printf("prior handcount is %d; current handcount is %d\n", orig.handCount[i], G.handCount[i]);
                    bad++;
                }
            }else{
                if(G.handCount[i] != orig.handCount[i] + 1){
                    printf("TEST FAILED: Player %d did not draw 1 card.\n", i);
                    bad++;
                }
            }

            if(i ==player){
              if(G.numBuys != orig.numBuys + 1)
              {
                  printf("TEST FAILED: numBuys supposed to increase by 1.\n");
                  bad++;
              }
            }
        }
    }
    printf("%d of %d TESTS PASSED For council_room\n", NUMQUESTIONS - bad, NUMQUESTIONS);
}
