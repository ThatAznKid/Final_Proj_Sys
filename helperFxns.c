#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "deck.h"
#include "commands.h" 

//xd cooler version of printf
void type_text(char *s){
   for (; *s; s++) {
      putchar(*s);
      fflush(stdout); /* alternatively, do once: setbuf(stdout, NULL); */
      usleep(120*200);
   }
}

int inHand( int currHandLen, int currPlayerIndex, char *play, char **hand ){
	int checker = 0; //lowkey boolean : 0 = false ; 1 = true
	int j;
    for (j = 0; j < currHandLen; j++){
            //printf("current card in hand = %s\n", HANDS[currPlayerIndex][j]);
            //printf("curr player index: %d\n", currPlayerIndex);
    	//printf("working\n");
    	//printf("%s\n", hand[0]);
    	//printf("HANDS[currPlayerIndex][j]: %s\n", hand[j]);
    	//printf("play: %s\n", play);
    	if (strcmp(play, hand[j]) == 0){
         	checker = 1;
            break;
      	}
 	}
    //printf("CHECKER : %d-----\n", checker);
 	return checker;
}

char * returnPlay(char *s){
  //printf("successful return of helper function: %s\n", s);
  return s;
}

//can player put down his card based on curr card?
// 1 -- yes
// 0 -- no
int checkValidity (char *playedCard, char *currCard){

  char FIRSTLETTER = currCard[0];
  char SECLETTER = currCard[4];

  if (playedCard[0] == FIRSTLETTER)
      return 1; //bool 
  
    if (playedCard[4] == SECLETTER)
      return 1; //bool 

  return 0; //not a valid card to put down

}
  //Wild is weird 
  //Returns:
  /*  
    1 = regular card --> normal play!!
    2 = +2 --> force next player to draw 2 cards
    3 = Wild Color --> prompt user for what color they want to set
    4 = +4 --> force next player to draw 4 cards
    5 = Skip --> force next player to not be able to do anything
    6 = Reverse --> uhh LOL nothing for now??

  */

/*
int cardImpact (char *playedCard, char *currCard){
  char *FIRSTLETTERS[4];
  FIRSTLETTERS = {"G","R","B","Y"};
  char *SECLETTERS[13];
  SECLETTERS = {"0","1","2","3","4","5","6","7","8","9","+","S","R"};
  int i;
  for (i=0; i < 4; i++){
    if (playedCard[0] == FIRSTLETTERS[i])
      return 1; //bool 
  } 
  for (i=0; i < 13; i++){
    if (playedCard[4] == SECLETTERS[i])
      return 1; //bool 
  } 

  //if it's a wild card
  if (playedCard[0] == "W"){
    if (playedCard[4] == "C")
      return 3; //haha get it because C is the 3rd letter of alphabet haha
    if (playedCard[4] == "+")
      if (playedCard[6] == "4")
        return 4;
    }

  return 0;
}
*/
