#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// global count of test failures
int failCount = 0;

// function to check if two ints are equal or not
void assertTrue(int a, int b) {
  if (a == b) {
      printf("Test: PASSED\n");
  } else {
      printf("Test: FAILED\n");
      failCount++;
  }
}

int main () {
    int numbPlayers = 2;
    int player = 0;

    // kingdom cards
    int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};
    int seed = 1000;
    struct gameState state;
	  printf("\n** Unit test 3: Shuffle Function **\n");
    memset(&state,23,sizeof(struct gameState));
    initializeGame(numbPlayers, k, seed, &state);

    state.deckCount[player] = 0;
    printf("\nPlayer deck count is 0\n");
    assertTrue(shuffle(player,&state),-1);

    printf("\nPlayer deck count is 10 before and after shuffle\n");
    state.deckCount[player] = 10;
    shuffle(player,&state);
    assertTrue(state.deckCount[player],10);

    printf("\nCards are shuffled\n");
    int pre_shuffle_card = state.deck[player][0];
    shuffle(player,&state);
    int post_shuffle_card = state.deck[player][0];
    if (pre_shuffle_card != post_shuffle_card) {
        assertTrue(1,1);
    }
    else {
        assertTrue(0,1);
    }

    if (failCount) {
        printf("\nTEST FAILED\n");
        printf("Fails: %d\n",failCount);
    }
    else {
        printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
    }
    printf("\n** End of Unit Test 3: shuffle Function**\n");
    return 0;
}
