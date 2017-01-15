#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){

/* START OF GAME */
/* Program takes in number of players by asking for name inputs. Game will start when 
   last player types in "START" */
    printf("Hi, WELCOME!!! input player names, until you have at least 2 players or at most 10 players. Start the game when you've entered all the player names you wanted by typing 'START' \n");
	int counter = 0;
    char pStr[100];
	char NAMES [10][20]; //array of names
	
	while (42) { 
	    printf("Player %d's name shall be: ", counter + 1);
      	char * player = pStr;
      	fgets(player,100,stdin);
      	player[strlen(player) - 1] = 0;
      	if (counter < 2 && (strcmp (player,"START") == 0)) { 
      	    printf ("Woah, there...You need at least two to tango.\n");
      	}
      	else if (counter > 9) { 
      	    printf ("You know, on second thought, I think this UNO game might just take a bit too long to play...How about we leave it off here...at 10 players...\n");
      	    break;
      	}
      	else if (strcmp (player, "") == 0) { 
      	    printf ("No ghosts allowed pl0x\n"); 
      	}
      	else if (strcmp (player,"START") == 0) { 
      	    printf ("PLAYERS SET AND LOCKED IN!\n"); 
      	    break;
      	}
      	else {
      	    strcpy (NAMES[counter],player);
      	    counter++;
      	}
	}
    
    int i; 
    
    printf("================================================\n");
    for (i = 0; i < counter; i++) { 
        printf ("Player %d: %s\n", i+1, NAMES[i]);
    }
    printf("Number of players: %d\n", counter);
    printf("================================================\n");
    printf("\n");
    
    //----------------------------------------------------------------------------------------------- 
    
    printf("Type the card to put down, or use a command. Type “help” to display set of commands: ");
    char str[100] = "";
    char *line = str;
    fgets(line,100,stdin);
    line[strlen(line) - 1] = 0;
    //printf("%s\n",line);
    
    char helpBox[1000] = "********************************* \n"
    "* Commands:\n"
    "* 'Help' - prints out the current commands and descriptions\n"
    "* 'Draw' - draws a card, can only happen once per turn \n"
    "* 'Pass' - player skips his/her turn without playing a card, must draw a card before doing so\n" 
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
    
    return 0;
}