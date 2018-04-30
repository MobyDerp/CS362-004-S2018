#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


// Unit Test for Adventurer
int adventurerFunc(int currentPlayer, struct gameState *state, int handPos);
int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

int main (int argc, char** argv) {

  struct gameState G;
  int choice1 = 0, choice2 = 0, choice3 = 0;
	printf ("\n**Card Test 1 -- Adventurer**\n");

	int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};

  initializeGame(2, k, 4, &G);

  assert(cardEffect(adventurer, choice1, choice2, choice3, &G, 0, NULL) == 0);
  printf("Adventurer test passed\n");
	printf ("**Card Test 1 Ends**\n");

}
