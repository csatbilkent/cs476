#include <stdio.h>
#include <string.h>
#define MAXCHR 500
#define DIV 23

/* DIV = NUMBER_OF_STATES */

int main(int argc, char **argv){
  char w[MAXCHR];
  int table[DIV][2];
  
  int i;
  int state;

  if (argc != 2) {
    printf("%s <w as binary string>\n", argv[0]);
    return -1;
  }
  
  strcpy(w, argv[1]);
  
  for (i=0;i<DIV;i++){
    table[i][0] = 2*i % DIV;
    table[i][1] = (2*i+1) % DIV;
  }
  
  state = 0;

  for (i=0;i<strlen(w);i++){
    if (w[i]=='0')
      state = table[state][0];
    else  if (w[i]=='1') 
      state = table[state][1]; 
    else{ 
      printf("The input w:%s has errors (non 0/1 character(s)).\n", w);
      return -1;
    }
  }

  if (state == 0)
    printf("w is divisible by %d\n", DIV);
  else
    printf("w mod %d = %d \n", DIV, state);
}
