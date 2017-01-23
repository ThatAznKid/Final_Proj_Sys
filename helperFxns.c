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

  if (currCard[4] == 0){ //for wild Color card
    if (playedCard[0] == currCard[0])
      return 1;
  }

  if (playedCard[0] == "W") //if wild +4 it's fine!
    return 1;

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
    4 = +4 --> force next player to draw 4 cards
    5 = Skip --> force next player to not be able to do anything
    6 = Reverse --> uhh LOL nothing for now??
    93 = WILD Color --> prompt user to declare color
    94 = WILD +4 --> prompt user to declare color, next user draws 4 times
  */


int cardImpact (char *playedCard){
  char *NORMAL[10];
  NORMAL = {"0","1","2","3","4","5","6","7","8","9"};

  int i;
  //normal
  for (i=0; i < 10; i++){
    if (playedCard[4] == NORMAL[i])
      return 1; //normal card
  } 
  //WILD
  if (playedCard[0] == "W"){
    if (playedCard[4] == "C")
      return 93; //WILD COLOR trigger
    if (playedCard[4] == "+")
      return 94; //WILD +4 trigger
  //+2/+4
  if (playedCard[4] == "+"){
    if (playedCard[5] == "2")
      return 2; //+2 trigger
    if (playedCard[5] == "4")
      return 4; //+4 trigger
  }
  //skip and reverse
    if (playedCard[4] == "S")
      return 5; //skip trigger
    if (playedCard[4] == "R")
      return 6; //reverse trigger
  return 0; //should never happen ???
}

if (cardImpact(PLAY) == 93){
  //prompt user to call for color. fgets. 
  type_text("\nYou put down a WILD COLOR. Indicate what color you would like\n"
            "to place: ");
  char str[100] = "";
  char *newplay = str;
  fgets(newplay,100,stdin);
  newplay[strlen(newplay) - 1] = 0;
  printf("\n");
  PLAY = returnPlay(newplay);
  strcpy(currCard, PLAY);
}

if (cardImpact(PLAY) == 94){
  //prompt user to call for color. fgets. +4 on next players turn
  type_text("\nYou put down a WILD +4. Indicate what color you would like\n"
            "to place: ");
  char str[100] = "";
  char *newplay = str;
  fgets(newplay,100,stdin);
  newplay[strlen(newplay) - 1] = 0;
  printf("\n");
  PLAY = returnPlay(newplay);
  strcpy(currCard, PLAY);
  cardtoDraw = 4;
}

int cardToDraw = 0;

if (cardImpact(PLAY) == 2){
  cardToDraw = 2;
}
if (cardImpact(PLAY) == 4){
  cardtoDraw = 4;
}
if (cardImpact(PLAY) == 5){
  //skip next person's turn, update by increasing 1 on currPlayerIndex
  //too hard
}
if (cardImpact(PLAY) == 6){
  //nothing (reverse)
}

//placed in beginning of turn, keeps track of if previous person placed +2 or +4
if (cardToDraw != 0){
  if (cardtoDraw == 2){ //+2
    type_text("You drew 2 new cards!\n")
    drawCard(HANDS[currPlayerIndex]); 
    drawCard(HANDS[currPlayerIndex]);
    currHandLen += 2; 
  }
  if (cardToDraw == 4){ //+4
    type_text("You drew 4 new cards!\n")
    drawCard(HANDS[currPlayerIndex]); 
    drawCard(HANDS[currPlayerIndex]);
    drawCard(HANDS[currPlayerIndex]);
    drawCard(HANDS[currPlayerIndex]);
    currHandLen += 4; 
  }
  cardToDraw = 0; //reset to 0
}



