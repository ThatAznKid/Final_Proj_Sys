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
	printf("HI WELCOME !! input player names. Start the game by typing 'START' \n");
	int counter = 0;
	char Pstr[100] = "";
	char * NAMES[100]; //array of names

	while ((strcmp(Pstr, "START")) != 0){
   	printf("Player %d Name: ", counter + 1);
  	char *player = Pstr;
  	fgets(player,100,stdin);
  	player[strlen(player) - 1] = 0;
  	NAMES[counter] = player;
  	counter++;
  }
  NAMES[counter-1] = 0;

  printf("================================================\n");
  printf("Player names: %s\n", NAMES[0]); //???
  printf("Player names: %s\n", NAMES[1]);
  printf("Number of players: %d\n", counter-1);
  printf("================================================\n");
  printf("\n");
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