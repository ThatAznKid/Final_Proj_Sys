#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){

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