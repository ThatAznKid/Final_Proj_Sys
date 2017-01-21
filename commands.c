#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "deck.h"
#include "helperFxns.h"

char helpBox[1000] = "********************************* \n"
        			 "* Commands:\n"
        			 "* 'Help' - prints out the current commands and descriptions\n"
        			 "* 'Draw' - draws a card, can only happen once per turn, then \n"
        			 "*          has the option to play a card.\n"
        			 "* 'Pass' - draws a card if player hasn't already, player\n" 
        			 "*          skips his/her turn without playing a card.\n" 
        			 "* 'Uno' - idk if this is a thing yet.\n"
        			 "* 'Sort' - sorts your hand alphabetically \n"
        			 "*********************************";



char ** playable( char **origHand, char *playedCard ){
	//your part:
	//replaces currCard
	//write to playedCards
	//printf("playedCard: %s\n", playedCard);
	char **newHand = (char **)malloc(sizeof(char *) * 1000);
	int boolean = 0; 
	int origIndex = 0;
	int newIndex = 0;
	memset(newHand, '\0', sizeof(newHand));
	while (origHand[origIndex] != 0 && origHand[origIndex+1] != 0){ //accounts for last
		//printf("=====================================");
		//printf("orig index + 1 is: %d\n", origIndex+1);
		//printf("origHand [orig index + 1]is: %s\n", origHand[origIndex+1]);
 			if (strcmp(origHand[origIndex],playedCard) == 0){
				//printf("FOUND THE CARD!! \n");
				origIndex++; //have to account for last if incrementing
				boolean = 1;
				if (strcmp(origHand[origIndex], playedCard) == 0){
					//printf("ima break \n");
					break;
				}
			}
		//printf("orig index: %d\n", origIndex);
		//printf("new index: %d\n", newIndex);
		newHand[newIndex] = origHand[origIndex];
		//printf("newHand[newIndex]: %s\n", newHand[newIndex]);
		newIndex++;
		//if (strcmp(origHand[origIndex+1], playedCard) == 0) break; //save 2nd to last card
		origIndex++;
		//printf("orig index++ : %d\n", origIndex);
		//printf("new index++ : %d\n", newIndex);
	}
	//printf("helloOOO this works!\n");
	//if playedCard was the last card in hand... this takes care of it.
	//printf("origHand[origIndex] = %s playedCard = %s\n", origHand[origIndex], playedCard);
	if (origHand[origIndex] == 0){
		//printf("in the if\n");
		newHand[newIndex] = 0;

	printf("printing out hand from fxn:\n");
	int j;
	for (j = 0; j < newIndex; j++){printf("|| %s ",newHand[j]);}  
    printf("||\n\n");
	return newHand;
	}

	//printf("%d\n", strcmp(origHand[origIndex], playedCard));
	
	if (strcmp(origHand[origIndex], playedCard) == 0){
		//printf("heyo\n");
		newHand[newIndex] = 0;
			//printf("LAST CARD TEST PRINT: printing out hand from fxn:\n");
			int t;
			for (t = 0; t < newIndex; t++){printf("|| %s ",newHand[t]);}  
    		printf("||\n\n");
    	return newHand; //return statement terminates function
	}

	//printf("hello this works!\n");
	//otherwise, proceed with cloning last card and insert null.

	//printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	//	printf("orig index: %d\n", origIndex);
	//	printf("new index: %d\n", newIndex);
		newHand[newIndex] = origHand[origIndex];
	//	printf("newHand[newIndex]: %s\n", newHand[newIndex]);
		newIndex++;
		origIndex++;
	//	printf("orig index++ : %d\n", origIndex);
	//	printf("new index++ : %d\n", newIndex);
	//printf("last index: %d\n", newIndex);
	newHand[newIndex] = 0;

	printf("printing out hand from fxn:\n");
	int j;
	for (j = 0; j < newIndex; j++){printf("|| %s ",newHand[j]);}  
    printf("||\n\n");
	return newHand;
}

//leave the handling of the array one size bigger in the main conditional 
void drawCard(char * HAND[]) { //input the player's hand who you want the card to be added to
    char * toBeAdded = draw(1,1); 
    int count = 0;
    while (HAND[count]) { 
        count++;           
    }
    HAND[count] = toBeAdded; 
    HAND[count + 1] = NULL;
}


//JUST COMMENTED OUT TESTING CODE FROM HERE ON OUT!!!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PLAYABLE TESTING PURPOSES ---------------------------------------
int main(){
	char ** hand = (char **)calloc(1,sizeof(char *) * 1000 );

	int x =0;
	for(; x< 10;x++){
		char * s = (char *)calloc(1,sizeof(char) * 1000);
		sprintf(s, "%dd",x);
		hand[x] = s;
	}
	
	hand = playable(hand, "3d");

	int i;
	for (i = 0; i < 10; i++){
		printf("%s ",hand[i]);
	}
	printf("\n");

	return 0;
}
*/

