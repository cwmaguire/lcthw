#include <stdio.h>

int main(int argc, char *argv[])\
{
  // go through each string in argv

  int i = 0;
  while(i < argc) {
    printf("arg %d: %s\n", i, argv[i]);
    i++;
  }

  // let's make our own array of strings
  char *states[] = {"Cali", "Oregon", "Wash.", "Texas"};
  int num_states = 4;
  i = 0; // watch for this
  while(i < num_states) {
    printf("state %d: %s\n", i, states[i]);
    i++;
  }

  // while loop counting backwards
  i = 4;
  while(i > 0){
    printf("state initial: %c\n", states[i - 1][0]);
    i--;
  }

  i = 0;
  while(i < (argc -1)){
    states[i] = argv[i];
    i++;
  }

  i = 0;
  while(i < num_states){
    printf("States[%d]: %s\n", i, states[i]);
    i++;
  }

  printf("argc is %d\n", argc);

  return 0;
}
