#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//unit test 4 tests to check next player's turn
//this acts to check if another player is existant
int main (int argc, char** argv)	{
  struct gameState G;
  int a;
  int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};

	printf ("\n** Unit Test 4: whoseTurn Function **\n");

	printf("\nNote: Run Test 4 times since test is set to 5 players\n");
	printf("Check to see if other 4 players still have legal targets\n");
  for (int x = 2 ; x < 6 ; ++x)	{
      a = initializeGame(2, k, 6, &G);
      a = whoseTurn(&G);
      assert(a == G.whoseTurn);
	printf("Test Passed\n");
	}
	printf("** End of Unit Test 4: whoseTurn Function **\n");

	return 0;
}
