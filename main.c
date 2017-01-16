#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "deck.h" 

int main(){
	system("clear");

/* START OF GAME */
/* Program takes in number of players by asking for name inputs. Game will start when 
   last player types in "START" */

    printf(	"\n"
    		"                    Welcome to UNO!!! \n" 
    		"                   ------------------- \n" 
    		"Please input player names, until there are 2 to 10 players. \n" 
    		"Start the game when you've entered all the player names you \n"
    		"wanted by typing 'START'.\n\n");

	int counter = 0;
    char pStr[100];
	char NAMES [10][20]; //array of names
	//----------------------------------------------------------------------
	//----------------------------------------------------------------------
	while (42) { 
	    printf("Player %d's name shall be: ", counter + 1);
      	char * player = pStr;
      	fgets(player,100,stdin);
      	player[strlen(player) - 1] = 0;
      	if (counter < 2 && (strcmp (player,"START") == 0)) { 
      	    printf ("\nWoah, there...You need at least two to tango.\n");
      	}
      	else if (counter > 9) { 
      	    printf ("\n You know, on second thought, I think this UNO game might \n"
      	    			"just take a bit too long to play...How about we leave it off \n"
      	    			"here...at 10 players!\n");
      	    break;
      	}
      	else if (strcmp (player, "") == 0) { 
      	    printf ("\nNo ghosts allowed pl0x\n"); 
      	}
      	else if (strcmp (player,"START") == 0) { 
      	    printf ("\nPLAYERS SET AND LOCKED IN!\n"); 
      	    break;
      	}
      	else {
      	    strcpy (NAMES[counter],player);
      	    counter++;
      	}
	}
	sleep(1);
	//----------------------------------------------------------------------
	//----------------------------------------------------------------------
    int i; 
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("Number of players: %d\n", counter);
    for (i = 0; i < counter; i++) 
 		printf ("Player %d: %s\n", i+1, NAMES[i]);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("\n");
    sleep(1);
    //----------------------------------------------------------------------
    //----------------------------------------------------------------------
    char *HANDS [10][7];
    int j;
    
    printf ("Generating the hands of each player...");
    //creating the 2d array, assigning random cards by drawing.
    for (i = 0; i < counter; i++){
    	for (j = 0; j < 7; j++){
    		char * randCard = draw(i,j);
    		HANDS[i][j] = randCard;
    	}
    }

/*
    //commented out for obvious testing purposes -- not gonna let other ppl see the hands
    //printing 2d array
    for (i = 0; i < counter; i++){
    	printf("Player %d's hand: ", i+1);
    	for (j = 0; j < 7; j++){
    		//HANDS[i][j] = {"a";
    		printf("|| %s ",HANDS[i][j]);
    	}
    	printf("||\n");
    }

    //printing player 2's hand (as an example)
	for (j = 0; j < 7; j++){
    		printf("|| %s ",HANDS[1][j]);
    }  
    printf("||\n");
*/

    /* finished. */
    /* example output:

    number of players: 3 (counter = 3)

PRINT OUTPUT:
-------------
Player 1's hand: || YEL SKIP || YEL REVERSE || BLU 1 || GRE 5 || YEL 4 || BLU REVERSE || RED SKIP ||
Player 2's hand: || RED 1 || GRE 7 || BLU 8 || YEL 0 || GRE 2 || YEL 1 || GRE 1 ||
Player 3's hand: || RED 1 || WILD +4 || BLU 6 || YEL 4 || GRE 3 || GRE 5 || BLU REVERSE ||

	----

	Player 2's hand:
		for (j = 0; j < 7; j++){
    			printf("|| %s ",HANDS[1][j]);       ((note that it's index 1 , not 2))
   		} 

PRINT OUTPUT:
-------------
|| RED 1 || GRE 7 || BLU 8 || YEL 0 || GRE 2 || YEL 1 || GRE 1 ||

*/
    printf("LET'S PLAY SOME UNO!!!!\n");
    int turnCounter = 1;
    while (42) { //let's play a game...
        //----------------------------------------------------------------------
        //----------------------------------------------------------------------
        printf("                 === TURN %d ===                  \n", turnCounter);
        //something about turnCounter++ xd
    
        /* WHEN IT IS UR TURN =================================================*/
        printf(	"Type the card to put down, or use a command. \n"
        		"Type “help” to display a set of commands: ");
    
        char str[100] = "";
        char *line = str;
        fgets(line,100,stdin);
        line[strlen(line) - 1] = 0;
        //printf("%s\n",line);
    
    
        /* calling for help commands */
        char helpBox[1000] = "********************************* \n"
        "* Commands:\n"
        "* 'Help' - prints out the current commands and descriptions\n"
        "* 'Draw' - draws a card, can only happen once per turn \n"
        "* 'Pass' - player skips his/her turn without playing a card,\n" 
        "           must draw a card before doing so\n" 
        "* 'Uno' - idk if this is a thing yet.\n"
        "* 'Sort' - sorts your hand alphabetically \n"
        "*********************************";
    
        if (strcmp(line,"help") == 0){
            printf("%s\n",helpBox);
            printf("Card or Command: ");
            char str[100] = "";
            char *line = str;
            fgets(line,100,stdin);
            line[strlen(line) - 1] = 0;
        }
        /* end of help commands call */
        
        turnCounter = turnCounter + 1; //end of a turn
    }
    
    return 0;
}