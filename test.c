#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/*

char * playable( const char origHand[], const char *playedCard ){
	//your part:
	//replaces currCard
	//write to playedCards

	char *newHand[100];
	int boolean = 0; //checks to see if first appearance of card has been taken out 0 is false 1 is true
	int origIndex = 0;
	int newIndex = 0;

	while (*origHand){
		
		if (boolean == 0){ 
			if (strcmp(&origHand[origIndex],playedCard) == 0){
				origIndex++;
				boolean = 1;
			}
		}
		strcpy(newHand[newIndex],&origHand[origIndex]);
		printf("%s\n", newHand[newIndex]);
		printf("%c\n", origHand[origIndex]);
		newIndex++;
		origIndex++;
	}
	newHand[newIndex] = 0;
	return *newHand;
}

int main(){
	char *a[] = {"1d","2d","3d","4d","1d","5d","6d","7d"};
	*a = playable(*a, "1d");
	int i;

	for (i = 0; i < 7; i++){
		printf("%s",a[i]);
	}

	return 0;
}
*/

char * playable( char *origHand[][], char *playedCard ){
	//your part:
	//replaces currCard
	//write to playedCards

	char *newHand[100][20];
	int boolean = 0; //checks to see if first appearance of card has been taken out 0 is false 1 is true
	int origIndex = 0;
	int newIndex = 0;
	int i;
	/*
	for (i = 0; i < 99; i++){
		newHand[i] = "0";
	}
	*/
	memset(newHand, '\0', sizeof(newHand));
	while (origHand[origIndex] != 0){
		/*
		if (boolean == 0){ 
			int i;
			for (i = 0; i < 7; i++){
				printf(origHand[i]);
			}
			printf("%d\n", origIndex);
			printf("%s\n", origHand[origIndex]);
			printf("%s\n", playedCard);*/
			if (strcmp(origHand[origIndex],playedCard) == 0){
				//printf("hidere\n");
				origIndex++;
				boolean = 1;
			}
		
		printf("%d\n", origIndex);
		printf("%s\n", origHand[origIndex]);
		printf("--\n");
		printf("%d\n", newIndex);
		printf("%s\n", newHand[newIndex]);

		strcpy(newHand[newIndex],*origHand[origIndex]);
		//strcpy(newHand[newIndex][20],origHand[origIndex]);
		printf("%s\n", newHand[newIndex]);

		printf("hidere\n");
		//printf("%s\n", origHand[origIndex]);
		newIndex++;
		origIndex++;
	}
	newHand[newIndex] = 0;
	return *newHand;
}

int main(){
	char *a[][2] = {"1d","2d","3d","4d","1d","5d","6d","7d"};
	*a = playable(a, "1d");
	int i;

	
	for (i = 0; i < 7; i++){
		printf("%s",a[i]);
	}
	
	return 0;
}