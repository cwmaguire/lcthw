#include <stdio.h>

// This works, but declaring it inside main doesn't
//char full_name[] = {'Z', 'e', 'd', ' ', 'A', '.', 'S', 'h', 'a', 'w'};

int main(int argc, char *argv[])
{
  int areas[] = {10, 12, 13, 14, 20};
  // Null terminator is added implicitly
  char name[] = "Zed";
  // This causes an error because there is no null terminator
  //char full_name[] = {'Z', 'e', 'd', ' ', 'A', '.', 'S', 'h', 'a', 'w'};
  char full_name[] = {'Z', 'e', 'd', ' ', 'A', '.', 'S', 'h', 'a', 'w', '\0'};

  // WARNING: On some systems you may have to change the
  // %ld in this code to a %u since it will use unsigned ints
  printf("The size of an int: %ld\n", sizeof(int));
  printf("The size of areas (int[]): %ld\n", sizeof(areas));
  printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
  printf("The first areas is %d, the 2nd %d.\n", areas[0], areas[1]);
  // Valgrind: "Conditional jump or move depends on uninitialised value(s)
  //printf("The first areas is %d, the 2nd %d.\n", areas[10], areas[1]);

  printf("the size of a char: %ld\n", sizeof(char));
  printf("The size of name (char[]): %ld\n", sizeof(name));
  printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));

  printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
  printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));

  printf("name=\"%s\" and full_name==\"%s\"\n", name, full_name);

  areas[3] = name[2];
  areas[4] = name[3];
  printf("areas[3] is %d and areas[4] is %d\n", areas[3], areas[4]);

  return 0;
}
