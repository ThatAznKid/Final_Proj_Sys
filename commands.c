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
	int boolean = 0; 
	int origIndex = 0;
	int newIndex = 0;

	memset(newHand, '\0', sizeof(newHand));
	while (origHand[origIndex] != 0){

			if (strcmp(origHand[origIndex],playedCard) == 0){
				origIndex++;
				boolean = 1;
			}

		newHand[newIndex] = origHand[origIndex];

		newIndex++;
		origIndex++;
	}
	newHand[newIndex] = 0;
	
	return newHand;
}

/*
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