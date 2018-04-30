#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

// UnitTest for great_hall
int greatHallFunc(int currentPlayer, struct gameState *state, int handPos);
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);

int main (int argc, char** argv) {
	printf ("\n**Card Test 3 great_hall Begins **\n");

	srand(time(NULL)); // Seed rand function
	/* Prepare arguments for initializeGame */
	int randomSeed = rand();
	struct gameState G;
	int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};

  initializeGame(2, k, randomSeed, &G);

	int origAct = G.numActions;

  cardEffect(great_hall, 0,0,0, &G, 0, NULL);
	//expect # numActions to be +1
	assert(G.numActions == origAct + 1);

	if (G.numActions == origAct + 1) {
		printf("great_hall test PASSED\n");
	} else {
		printf("great_hall test FAILED; expect actions to be +1\n");
	}

	printf ("**Card Test 3 great_hall Ends**\n");
	return 0;
}
