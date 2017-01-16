#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char * playable( char *origHand, char *playedCard ){
	//your part:
	//replaces currCard
	//write to playedCards

	char *newHand[100];
	int boolean = 0; //checks to see if first appearance of card has been taken out 0 is false 1 is true
	int origIndex = 0;
	int newIndex = 0;

	while (*origHand){
		/*
		if (boolean == 0){ 
			if (strcmp(origHand[origIndex],playedCard) == 0){
				origIndex++;
				boolean = 1;
			}
		}*/
		//strcpy(newHand[newIndex],origHand[origIndex]);
		printf("%s\n"; )
		newIndex++;
		origIndex++;
	}
	newHand[newIndex] = 0;
}

int main(){
	char *a[] = {"1","2","3","4","1","5","6","7"};
	*a = playable(*a, "1");
	int i;

	for (i = 0; i < 7; i++){
		printf("%s",a[i]);
	}

	return 0;
}