#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

// UnitTest for smithy
int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

int main (int argc, char** argv) {

  struct gameState G;
	int player = 0;
	int prev_Count;
	printf ("\n**Card Test 2 -- Smithy**\n");

	int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};


  initializeGame(2, k, 2, &G);

	// store old action count
	prev_Count = G.handCount[player];

  cardEffect(smithy, 0, 0, 0, &G, 0, NULL);
  //expect #cards to be +3 but then you disgard 1
	//assert(G.handCount[player] == prev_Count + 2);
  if (G.handCount[player] == prev_Count + 2) {
    printf("Smithy test passed\n");
  } else {
    printf("Smithy test FAILED; expect cards to be +3\n");
  }

	printf ("**Card Test 2 Ends**\n");

  return 0;

}
