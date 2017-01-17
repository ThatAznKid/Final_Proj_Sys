#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

//DOESNT WORK GDI. GDI GDI GDI I WILL FIX THIS O:< (note to self)

int inHand( int currHandLen, int currPlayerIndex, char *play, char **hand ){
	int checker = 0; //lowkey boolean : 0 = false ; 1 = true
	int j;
    for (j = 0; j < currHandLen; j++){
            //printf("current card in hand = %s\n", HANDS[currPlayerIndex][j]);
            //printf("curr player index: %d\n", currPlayerIndex);
    	printf("working\n");
    	printf("%s\n", hand[0]);
    	printf("HANDS[currPlayerIndex][j]: %s\n", hand[j]);
    	printf("play: %s\n", play);
    	if (strcmp(play, hand[j]) == 0){
         	checker = 1;
            break;
      	}
 	}
 	return checker;
}