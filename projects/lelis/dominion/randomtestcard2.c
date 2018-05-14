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

int main (int argc, char** argv) {
    printf("\n**Random Testing: council_room in randomtestcard2.c **\n");

    srand(time(NULL));

    printf("RANDOM TESTS\n");

    int numtests = 100;
    int NUMQUESTIONS = 0;
    int bad = 0;
    for(int i = 0; i < numtests; i++){
        int numplayers = rand() % (MAX_PLAYERS - 1) + 2; // Value between 2 and 4.
        NUMQUESTIONS += numplayers;
        struct gameState G;
        int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};

        initializeGame(numplayers, k, rand(), &G);

        int player = rand() % numplayers;
        G.whoseTurn = player;

        int bonus = rand() % 50;
        int choice1 = rand() % 50;
        int choice2 = rand() % 50;
        int choice3 = rand() % 50;
        int handPos = rand() % MAX_HAND;

        struct gameState orig;
        memcpy(&orig, &G, sizeof(struct gameState));

        cardEffect(council_room, choice1, choice2, choice3, &G, handPos, &bonus);

        for(int i = 0; i < numplayers; i++){
            if(i == player){
                if(G.handCount[i] != orig.handCount[i] + 3){
                    printf("TEST FAILED: Player %d did not get 3 more cards.\n", i);
                    bad++;
                }
            }else{
                if(G.handCount[i] != orig.handCount[i] + 1){
                    printf("TEST FAILED: Player %d did not draw 1 card.\n", i);
                    bad++;
                }
            }
        }
    }

    printf("%d of %d TESTS PASSED For council_room\n", NUMQUESTIONS - bad, NUMQUESTIONS);
}
