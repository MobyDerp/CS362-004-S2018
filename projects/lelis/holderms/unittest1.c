
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Unit test 1 tests cards existance, can player buy the card,and re-check card amount
int main (int argc, char** argv){
	struct gameState G;
	printf("\n** Unit test 1: Buying Cards **\n");
	G.numBuys = 2;
	G.coins = 2;
	printf("\nDoes player have enough coins?\n");
 	int test = buyCard(2, &G);
		if(test == -1)
			printf("Test Passed\n");
		else
			printf("Test Failed\n");

	printf("\nAttempting to buy desired card!\n");
	G.coins = 10;
	test = buyCard(2, &G);
	if(test == 0){
		printf("Testing Passed\n");
	} else {
		printf("Testing Failed\n");
	}

 	printf("\nChecking amount?\n");
 	test = buyCard(2, &G);
	if(test == 0) {
		printf("Test Passed\n");
	} else {
		printf("Test Failed\n");
	}

 	printf("Check to see if player still has existing Buys: \n");
 	G.coins = 6;
	test = buyCard(2, &G);
	if(test == -1)
	{
		printf("Test Passed\n");
	} else {
		printf("Test Failed\n");
	}

 	printf("\n** End of Unit Test 1: Buying Cards **\n");

 	return 0;
}
