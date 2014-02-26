#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  FILE *stdout = fdopen(STDOUT_FILENO, "w");

  puts("Hello world.");
  fputc(36, stdout);
  putchar(37);

  return 0;
}
