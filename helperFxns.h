#pragma once 

void type_text(char *s);

int inHand( int currHandLen, int currPlayerIndex, char * play, char **hand );

int returnCTD(int d);

char * returnPlay(char *s);

int checkValidity (char *playedCard, char *currCard);

int cardImpact (char *playedCard);

