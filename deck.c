#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h> 
#include <time.h> 

void drawHelper (char * retstr, int r); 

char * draw () {
    
    srand(time(NULL));
    int r = rand() % 108; //rand number [0,107]
    printf ("int recieved: %d\n", r); 
    char * retstr = malloc (50);
    if ( r >= 0 && r < 25) {
        strcpy (retstr,"GRE"); 
        drawHelper(retstr,r);
    }
    else if ( r >= 25 && r < 50 ) { 
        strcpy (retstr,"RED"); 
        r = r - 25;
        drawHelper(retstr,r);
    }
    else if ( r >= 50 && r < 75 ) { 
        strcpy (retstr, "BLU"); 
        r = r - 50;
        drawHelper(retstr,r);
    }
    else if ( r >= 75 && r < 100 ) { 
    	strcpy (retstr,"YEL"); 
    	r = r - 75;
    	drawHelper(retstr,r);
    }
    else { 
        strcpy (retstr, "WILD"); 
            if (r > 103) { 
                strcat (retstr, " +4");
            }
            else { 
                strcat (retstr, " COLOR"); 
            }
    }
    return retstr;
    
}

void drawHelper (char * retstr, int r) {
    if (r == 0) { 
          strcat (retstr, " 0"); 
        }
        if (r == 1 || r == 2) { 
          strcat (retstr, " 1"); 
        }
        if (r == 3 || r == 4) { 
          strcat (retstr, " 2"); 
        }
        if (r == 5 || r == 6) { 
          strcat (retstr, " 3"); 
        }
        if (r == 7 || r == 8) { 
          strcat (retstr, " 4"); 
        }
        if (r == 9 || r == 10) { 
          strcat (retstr, " 5"); 
        }
        if (r == 11 || r == 12) { 
          strcat (retstr, " 6"); 
        }
        if (r == 13 || r == 14) { 
          strcat (retstr, " 7"); 
        }
        if (r == 15 || r == 16) { 
          strcat (retstr, " 8"); 
        }
        if (r == 17 || r == 18) { 
          strcat (retstr, " 9"); 
        }
        if (r == 19 || r == 20) { 
          strcat (retstr, " +2"); 
        }
        if (r == 21 || r == 22) { 
          strcat (retstr, " SKIP"); 
        }
        if (r == 23 || r == 24) { 
          strcat (retstr, " REVERSE"); 
        }
}

int main ()  {
    
    printf ("Card recieved: %s\n", draw());
    return 0; 
    
}