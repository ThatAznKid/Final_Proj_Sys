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
        			 "* 'help' - prints out the current commands and descriptions\n"
        			 "* 'draw' - draws a card, can only happen once per turn, then \n"
        			 "*          moves on to next player.\n"
        			 "* 'pass' - draws a card if player hasn't already, player\n" 
        			 "*          skips his/her turn without playing a card.\n" 
        			 "*********************************";



char ** playable( char **origHand, char *playedCard ){
	char **newHand = (char **)malloc(sizeof(char *) * 1000);
	int boolean = 0; 
	int origIndex = 0;
	int newIndex = 0;
	memset(newHand, '\0', sizeof(newHand));
	while (origHand[origIndex] != 0 && origHand[origIndex+1] != 0){ //accounts for last
 			if (strcmp(origHand[origIndex],playedCard) == 0){
				origIndex++; //have to account for last if incrementing
				boolean = 1;
				if (strcmp(origHand[origIndex], playedCard) == 0){
					break;
				}
			}
		newHand[newIndex] = origHand[origIndex];
		newIndex++;
		origIndex++;
	}
	if (origHand[origIndex] == 0){
		newHand[newIndex] = 0;
	return newHand;
	}

	if (strcmp(origHand[origIndex], playedCard) == 0){
		newHand[newIndex] = 0;
			int t;
			for (t = 0; t < newIndex; t++){printf("|| %s ",newHand[t]);}  
    		printf("||\n\n");
    	return newHand; //return statement terminates function
	}
		newHand[newIndex] = origHand[origIndex];
		newIndex++;
		origIndex++;
	newHand[newIndex] = 0;
	return newHand;
}

//leave the handling of the array one size bigger in the main conditional 
void drawCard(char * HAND[], int d) { //input the player's hand who you want the card to be added to
    char * toBeAdded = draw(1,1, d); 
    int count = 0;
    while (HAND[count]) { 
        count++;           
    }
    HAND[count] = toBeAdded; 
    HAND[count + 1] = NULL;
}

