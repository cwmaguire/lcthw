#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  // go through each string in argv
  // why am I skipping argv[0]?
  // (because it's the executable name)
  for(i = 1; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }

  // lets make our own array of strings
  char *states[] = {"California", "Oregon", NULL, "Washington", "Texas"};
  //int num_states = 4;
  int num_states = 6;

  for(i = 0; i < num_states; i++) {
    printf("state %d: %s\n", i, states[i]);
  }

  int j;
  for(i = 0, j = 0; i < 10 && j < 10; i++, j++){
    printf("i is %d and j is %d\n", i, j);
  }

  // change argv and print
  argv[1] = states[1];
  for(i = 1; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }

  // assign states elem to argv & print
  states[2] = argv[2];
  for(i = 1; i < 4; i++) {
    printf("arg %d: %s\n", i, states[i]);
  }

  return 0;
}
