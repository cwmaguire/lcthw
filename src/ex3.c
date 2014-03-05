#include <stdio.h>

int main()
{
  int age = 10;
  int height = 72;

  printf("I am %d years old.\n", age);
  printf("I am %d inches tall.\n", height);

  printf(" \\\" \\ \n \111 \x10 \u2093 %X test test\n", 10);
  printf("\u2050\n");

  char format[1000] = "";
  int i = 0;
  for(i = 2050; i < 2080; i++){
    sprintf(format, "\\u%d %%d \n", i);
    /*printf("%s", format);*/
    printf(format, i);
  }

  return 0;
}
