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
      if (strcmp(play, hand[j]) == 0){
          checker = 1;
            break;
        }
  }
  return checker;
}

char * returnPlay(char *s){
  return s;
}

int returnCTD(int d){ //Card To Draw
  return d;
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

  if (strcmp(playedCard, "WILD COLOR") == 0 || strcmp(playedCard, "WILD +4") == 0)
    return 1;


  if (playedCard[0] == FIRSTLETTER)
    return 1; 

  if (playedCard[4] == SECLETTER)
    return 1;

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

  char four = playedCard[4];
  char five = playedCard[5];

  int i;

  //WILD
  if (strcmp(playedCard, "WILD COLOR") == 0)

      return 93; //WILD COLOR trigger
  if (strcmp(playedCard, "WILD +4") == 0)

      return 94; //WILD +4 trigger
  
  //+2/+4
  if (strcmp(playedCard, "RED +2") == 0 || strcmp(playedCard, "BLU +2") == 0 ||strcmp(playedCard, "GRE +2") == 0 || strcmp(playedCard, "YEL +2") == 0)
      return 2; //+2 trigger

  //skip and reverse
    if (strcmp(&four, "S") == 0)
      return 5; //skip trigger
    if (strcmp(&four, "R") == 0)
      return 6; //reverse trigger

  return 0; //should never happen ???
}


