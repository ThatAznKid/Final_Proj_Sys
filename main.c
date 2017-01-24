#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "deck.h"
#include "commands.h" 
#include "helperFxns.h"

int main(){
    system("clear");

/* START OF GAME */
/* Program takes in number of players by asking for name inputs. Game will start when 
   last player types in "START" */

    printf( "\n"
            "                    Welcome to UNO!!! \n" 
            "                   ------------------- \n");
    usleep(500000);
    type_text(     
            "Please input player names, until there are 2 to 10 players. \n" 
            "Start the game when you've entered all the player names you \n"
            "wanted by typing 'START'.\n\n");

    int counter = 0;
    char pStr[100];
    char NAMES [10][20]; //array of names
    while (42) { 
        printf("Player %d's name shall be: ", counter + 1);
        char * player = pStr;
        fgets(player,100,stdin);
        player[strlen(player) - 1] = 0;
        if (counter < 2 && (strcmp (player,"START") == 0)) { 
            type_text("\nWoah, there...You need at least two to tango.\n");
        }
        else if (counter > 9) { 
            type_text("\n You know, on second thought, I think this UNO game might \n"
                        "just take a bit too long to play...How about we leave it off \n"
                        "here...at 10 players!\n\n");
            break;
        }
        else if (strcmp (player, "") == 0) { 
            type_text("\nNo ghosts allowed pl0x\n\n"); 
        }
        else if (strcmp (player,"START") == 0) { 
            type_text("\nPLAYERS SET AND LOCKED IN!\n"); 
            break;
        }
        else {
            strcpy (NAMES[counter],player);
            counter++;
        }
    }
    usleep(500000);
    int i; 
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - \n");
    type_text("Number of players: ");
    printf("%d\n",counter);
    for (i = 0; i < counter; i++) 
        printf ("Player %d: %s\n", i+1, NAMES[i]);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("\n");
    char * HANDS[10][100]; //(char ***)malloc(sizeof(char**) * 1000); //initially we only need 8 spaces, but 100 bc celine says so
    int j;
    
    type_text("Generating the hands of each player ...");
    fflush(stdout);

    //creating the 2d array, assigning random cards by drawing.
    for (i = 0; i < counter; i++){
      for (j = 0; j < 7; j++){
            char * randCard = draw(i,j,0);
            HANDS[i][j] = randCard;
        }
        HANDS[i][j] = 0;
    }
    usleep(500000);
    type_text(" ..."); //xd for dramatic effect
    fflush(stdout);
    usleep(700000);
    type_text(" ... "); //xd for dramatic effect
    fflush(stdout);
    usleep(900000);

    type_text("LET'S PLAY SOME UNO!!!!\n");
    usleep(800000);
    int turnCounter = 1;

    //determining which player goes by mod; this basically shifts NAMES one index over.
    char NAMES2 [10][20];
    int k;
    for (k = counter; k > 0; k--){   
      strcpy(NAMES2[k],NAMES[k-1]);
    }
    strcpy(NAMES2[0],NAMES[counter-1]);
    char * currCard = draw(1,1,0);
    while (strcmp(currCard, "WILD COLOR") == 0 || strcmp(currCard, "WILD +4") == 0) //test that it aint a wild >:c
        currCard = draw(1,1,0);
 
    //printf("\nCurrent card: %s\n", currCard); 
    
    int cardDrawn = 0; 
    int cardToDraw = 0; // for +2 / +4

    while (42) { //let's play a game... 

        system("clear");
        int currPlayerNumba = turnCounter % counter; //whose turn it is
        int currPlayerIndex = turnCounter % counter - 1; //index in HANDS is counter
        if (currPlayerIndex == -1) 
            currPlayerIndex = counter - 1;

        printf("           =======================================\n");
        printf("           =====  TURN %d --- [ %s's Turn ]  =====\n", turnCounter, NAMES2[currPlayerNumba]); //moddin'
        printf("           =======================================\n");
        /* find the length of all players' hands */
        /* ------------------------------------- */
        int arrayLen = 0;
        for (i = 0; i < counter; i++){
            while (HANDS[i][arrayLen]){arrayLen++;} //see how long the array is
            if (arrayLen == 0){
                printf("Congratulations to %s for winning the game!\n", NAMES[i]);
                break;
                break;
            }
            printf("           P%d: Number of Cards in %s's hand: %d\n", i+1, NAMES[i], arrayLen);
            arrayLen = 0; //reset length of array counter
            usleep(150000);
        }
        usleep(150000);
        /* find the length of player's hand */
        /* -------------------------------- */
        int currHandLen = 0; //var currHandLen stores current length of hand
        while (HANDS[currPlayerIndex][currHandLen]){currHandLen++;} //see how long current player's hand is

                 if (cardToDraw != 0){
                if (cardToDraw == 2){ //+2
                    type_text("\nYou drew 2 new cards!\n");
                    drawCard(HANDS[currPlayerIndex],1); 
                    drawCard(HANDS[currPlayerIndex],2);
                    currHandLen += 2; 
                }
                if (cardToDraw == 4){ //+4
                    type_text("\nYou drew 4 new cards!\n");
                    drawCard(HANDS[currPlayerIndex],0); 
                    drawCard(HANDS[currPlayerIndex],1);
                    drawCard(HANDS[currPlayerIndex],2);
                    drawCard(HANDS[currPlayerIndex],3);
                    currHandLen += 4; 
                }
                cardToDraw = 0; //reset to 0
            }


        printf("\n%s's hand:\n", NAMES2[currPlayerNumba]);    
        for (j = 0; j < currHandLen; j++){printf("|| %s ",HANDS[currPlayerIndex][j]);}  
        printf("||\n\n"); 
        usleep(300000);
        printf("\n           ******* Current card: %s *******\n\n", currCard);
        usleep(300000);
        //printf("THE CARDDD TO DRAW: %d\n", cardToDraw);
        usleep(300000);
        /* prompt the user */
        /* --------------- */
        type_text(  "Type the card to put down, or use a command. \n"
                    "Type “help” to display a set of commands: "); 
    
        /* var *** play *** is the card that player put down */
        /* ------------------------------------------------- */
        char str[100] = "";
        char *play = str;
        fgets(play,100,stdin);
        play[strlen(play) - 1] = 0;
        printf("\n");
        
    if (strcmp(play,"pass") != 0  && strcmp (play,"draw") != 0){
        char *PLAY; 
        PLAY = returnPlay(play);
         while (strcmp(PLAY,"help") == 0){
            printf("%s\n\n",helpBox);
            printf("\nCard or Command: ");
            char str[100] = "";
            char *play = str;
            fgets(play,100,stdin);
            play[strlen(play) - 1] = 0;
            printf("\n");
            PLAY = returnPlay(play);
        }

            if ((strcmp (PLAY,"draw") == 0) && cardDrawn == 0) {
            type_text("\nYou drew a card!\n");
            usleep(300000);
            type_text("\nHere's your new hand:\n");  
            drawCard(HANDS[currPlayerIndex],0); 
            currHandLen++; 
            for (j = 0; j < currHandLen; j++){
                printf("|| %s ",HANDS[currPlayerIndex][j]);
            }  
            printf("||\n");
            usleep(300000);
            cardDrawn = 1;
            
        } 
        
        else if (strcmp (PLAY,"pass") == 0) {  
            if (cardDrawn == 0) { 
                type_text("\nBefore passing you must draw a card at least once.\n");
                type_text("\nYou drew a card!\n");
                usleep(300000);
                type_text("\nHere's your new hand:\n");  
                drawCard(HANDS[currPlayerIndex],0); 
                currHandLen++; 
                for (j = 0; j < currHandLen; j++){
                    printf("|| %s ",HANDS[currPlayerIndex][j]);
                }  
                printf("||\n");
                usleep(300000);
            }
            cardDrawn = 1;
            
        }

        else if (strcmp(play,"pass") != 0  && strcmp (play,"draw") != 0){

         int x = inHand(currHandLen, currPlayerIndex, PLAY, HANDS[currPlayerIndex]);
         int v = checkValidity(PLAY, currCard);
        while (x == 0 || v == 0){ 
            if (x == 0){
                type_text("Your card was not playable. Your card was typed incorrectly\n"
                   "or it is not in your hand. If you do not have a playable card, \n"
                   "you must draw. Try again: ");
            }
            else if (v == 0){
                type_text("Your card was not playable. The current card is ");
                printf("%s.\n", currCard);
                type_text("You may only play a card that is the same color or number, \nor any Wild card. Try again: ");
            }
            //how to make recursive???
            char str[100] = "";
            char *newplay = str;
            fgets(newplay,100,stdin);
            newplay[strlen(newplay) - 1] = 0;
            printf("\n");

            PLAY = returnPlay(newplay);

     while (strcmp(PLAY,"help") == 0){
            printf("%s\n",helpBox);
            printf("\nCard or Command: ");
            char str[100] = "";
            char *play = str;
            fgets(play,100,stdin);
            play[strlen(play) - 1] = 0;
            printf("\n");
            PLAY = returnPlay(play);
        }


            if (strcmp(PLAY,"pass") == 0 || strcmp (PLAY,"draw") == 0)
                break;
            x = inHand(currHandLen, currPlayerIndex, PLAY, HANDS[currPlayerIndex]);
            v = checkValidity(PLAY, currCard);
        }

        play = returnPlay(PLAY);

        /* if so... */
        /* --------- */        
        if (x == 1 && v == 1){ //if in hand!!! :D
          int j = 0;
          char ** p = playable(HANDS[currPlayerIndex], play);
          while(*p != 0){
            HANDS[currPlayerIndex][j] = *p;
            p++;
            j++;
          }
          HANDS[currPlayerIndex][j] = 0;      
            type_text("\nYou played ");
            printf("%s!\n", play);
            strcpy(currCard, play);
            usleep(300000);
            type_text("\nHere's your new hand:\n");  
            currHandLen--; 
            for (j = 0; j < currHandLen; j++){
                printf("|| %s ",HANDS[currPlayerIndex][j]);
            }     
            printf("||\n");


            if (cardImpact(play) == 2){
                cardToDraw = returnCTD(2);
            }

            if (cardImpact(play) == 93){ 
            type_text("\nYou put down a WILD COLOR. Indicate what color you would like\n"
            "to place: ");
            char str[100] = "";
            char *newplay = str;
            fgets(newplay,100,stdin);
            newplay[strlen(newplay) - 1] = 0;
            printf("\n");
            PLAY = returnPlay(newplay);
            while(strcmp(PLAY,"BLU")!= 0 && strcmp(PLAY,"GRE")!=0 && strcmp(PLAY,"RED")!=0 && strcmp(PLAY,"YEL")!=0){
            type_text("\nYou may only type a valid color in the form of BLU, GRE, RED, or YEL.\n"
            "Try again: ");
                char str[100] = "";
                char *newplay = str;
                fgets(newplay,100,stdin);
                newplay[strlen(newplay) - 1] = 0;
                printf("\n");
                PLAY = returnPlay(newplay);
            }
            strcpy(currCard, PLAY);
            }

            if (cardImpact(play) == 94){
            type_text("\nYou put down a WILD +4. Indicate what color you would like\n"
            "to place: ");
            char str[100] = "";
            char *newplay = str;
            fgets(newplay,100,stdin);
            newplay[strlen(newplay) - 1] = 0;
            printf("\n");
            PLAY = returnPlay(newplay);
            while(strcmp(PLAY,"BLU")!= 0 && strcmp(PLAY,"GRE")!=0 && strcmp(PLAY,"RED")!=0 && strcmp(PLAY,"YEL")!=0){
            type_text("\nYou may only type a valid color in the form of BLU, GRE, RED, or YEL.\n"
            "Try again: ");
                char str[100] = "";
                char *newplay = str;
                fgets(newplay,100,stdin);
                newplay[strlen(newplay) - 1] = 0;
                printf("\n");
                PLAY = returnPlay(newplay);
            }
            strcpy(currCard, PLAY);
            cardToDraw = returnCTD(4);
            }
        } 
        }
        } //end of if play conditional
        
        if ((strcmp (play,"draw") == 0) && cardDrawn == 0) {
            type_text("\nYou drew a card!\n");
            usleep(300000);
            type_text("\nHere's your new hand:\n");  
            drawCard(HANDS[currPlayerIndex],0); 
            currHandLen++; 
            for (j = 0; j < currHandLen; j++){
                printf("|| %s ",HANDS[currPlayerIndex][j]);
            }  
            printf("||\n");
            usleep(300000);
            cardDrawn = 1;
        } 
        
        if (strcmp (play,"pass") == 0) {  
            if (cardDrawn == 0) { 
                type_text("\nBefore passing you must draw a card at least once.\n");
                type_text("\nYou drew a card!\n");
                usleep(300000);
                type_text("\nHere's your new hand:\n");  
                drawCard(HANDS[currPlayerIndex],0); 
                currHandLen++; 
                for (j = 0; j < currHandLen; j++){
                    printf("|| %s ",HANDS[currPlayerIndex][j]);
                }  
                printf("||\n");
                usleep(300000);
            }
            cardDrawn = 1;
        }

        cardDrawn = 0; //reset the one draw per turn allowance
        turnCounter++; //end of a turn

        usleep(300000);
        type_text("\n\nMoving on to next player...");
        usleep(500000);
        type_text(" ...");
        usleep(500000);
        type_text(" ...");
        sleep(1);
    }

    return 0;
}
