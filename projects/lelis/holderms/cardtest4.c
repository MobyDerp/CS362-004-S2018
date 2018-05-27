#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

// UnitTest for council_room
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
int council_roomEffect (struct gameState *state, int currentPlayer, int handPos);

int main (void)
{
	struct gameState G;
	printf ("\n**Card Test 4 -- council_room**\n");
	int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 4, &G);

	int origBuys = G.numBuys;
	printf("orig Buys: %d\n", origBuys);

	//play cards
	cardEffect(council_room, 0,0,0, &G, 0, 0);
	//council_roomEffect(&G, 0, 0);
	printf("G.numBuys: %d\n", G.numBuys);
	//assert(G.numBuys == origBuys + 1);

	if (G.numBuys == origBuys + 1) {
		printf("council_room test passed\n");
	} else {
		printf("council_room FAILED; expect numBuys to be +1\n");
	}

	printf ("**Card Test 4 council_room Ends**\n");
	return 0;
}
