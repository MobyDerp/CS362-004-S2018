#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define ASSERT_END 0
#define MAX_TESTS 10000

int myAssert(int c, char *s);
int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

/*
 * randomtestcard3.c -- randomly tests great_hall
 */

int main() {

  printf("\n**Random Testing: great_hall in randomtestcard3.c **\n");
  int k[10] = {adventurer, ambassador, great_hall, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};

  int i, j, n, r, errors=0, handPos = 0, players, player, handCount, numActions,deckCount, seed, rseed, address, totalC;
  struct gameState G;


  rseed = time(NULL);
  srand(rseed);
  for(n = 0; n < MAX_TESTS; n++){

   //Create random gameState
   players = rand() % 3 + 2; // Gen 2-4 players
   player = players;
   seed = rand();

   //Initiazling game
   printf("Initalizing game\n");
   r = initializeGame(players, k, seed, &G);
   myAssert(r == 0, "Initiazling game failed.");

   //Gen random decks
   G.deckCount[player] = rand() % MAX_DECK;
   G.discardCount[player] = rand() % MAX_DECK;
   G.handCount[player] = rand() % MAX_HAND;
   totalC = G.deckCount[player] + G.deckCount[player] + G.discardCount[player];

   //Print state before test
   printf("BEFORE\n");
   printf("HandCount: %d\n", G.handCount[player]);
   printf("DeckCount: %d\n", G.deckCount[player]);
   printf("DiscardCount: %d\n", G.discardCount[player]);
   printf("TotalC: %d\n", totalC);

   //Values to be compared against
   handCount =  G.handCount[player];
   numActions = G.numActions;


   r = cardEffect(great_hall, 0, 0, 0, &G, 0, 0);
   if(r!=0)
     errors++;

   r = myAssert(handCount == G.handCount[player],"handCount"); // Check that one card was discarded and one was drawn for a net change of nothing
   if(r!=0)
     errors++;

   r = myAssert(G.numActions == numActions + 1,"numActions"); // Check that one action was added
   if(r!=0)
     errors++;

   //Print state after test
   printf("After\n");
   printf("HandCount: %d\n", G.handCount[player]);
   printf("DeckCount: %d\n", G.deckCount[player]);
   printf("DiscardCount: %d\n", G.discardCount[player]);
   totalC = G.deckCount[player] + G.deckCount[player] + G.discardCount[player];
   printf("TotalC: %d\n", totalC);

 }	//End test block
 if(errors > 0)
   printf("There were %d errors for great_hall", errors);
 else
   printf("ALL TESTS OK\n");
 exit(0);
}

int myAssert(int c, char *s) {
 if(!c) {
   printf("Assertion failed: %s\n", s);
   return 1;
   if(ASSERT_END) {
       exit(1);
   }
 }
 return 0;
}
