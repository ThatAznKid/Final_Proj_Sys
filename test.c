#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char ** playable( char **origHand, char *playedCard ){
	//your part:
	//replaces currCard
	//write to playedCards
	printf("playedCard: %s\n", playedCard);
	char **newHand = (char **)malloc(sizeof(char *) * 1000);
	int boolean = 0; //checks to see if first appearance of card has been taken out 0 is false 1 is true
	int origIndex = 0;
	int newIndex = 0;

	memset(newHand, '\0', sizeof(newHand));
	while (origHand[origIndex] != 0){

			if (strcmp(origHand[origIndex],playedCard) == 0){
				origIndex++;
				boolean = 1;
			}
		//printf("--\n");
		//printf("orig index: %d\n", origIndex);
		//printf("orighand at orig index: %s\n", origHand[origIndex]);
		//printf("new index: %d\n", newIndex);
		//printf("new hand at new index: %s\n", newHand[newIndex]);

		newHand[newIndex] = origHand[origIndex];
		//printf("new hand at new index after: %s\n", newHand[newIndex]);

		newIndex++;
		origIndex++;
	}
	newHand[newIndex] = 0;
	
	return newHand;
}

int main(){
	char ** hand = (char **)calloc(1,sizeof(char *) * 1000 );

	int x =0;
	for(; x< 10;x++){
		char * s = (char *)calloc(1,sizeof(char) * 1000);
		sprintf(s, "%dd",x);
		hand[x] = s;
	}
	
	hand = playable(hand, "3d");
	
	//print out the hand
	int i;
	for (i = 0; i < 10; i++){
		printf("%s ",hand[i]);
	}
	printf("\n");
	

	return 0;
}