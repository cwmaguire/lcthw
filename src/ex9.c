#include <stdio.h>

int main(int argc, char *argv[])
{
  int numbers[4] = {0};
  char name[4] = {'a'};

  // first, print them out raw
  printf("numbers: %d %d %d %d\n",
         numbers[0], numbers[1],
         numbers[2], numbers[3]);

  printf("name each: %c %c %c %c\n",
      name[0], name[1],
      name[2], name[3]);

  printf("name: %s\n", name);

  // setup the numbers
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  // setup the name
  name[0] = 'Z';
  name[1] = 'e';
  name[2] = 'd';
  name[3] = '\0';

  // then print them out initialized
  printf("numbers: %d %d %d %d\n",
         numbers[0], numbers[1],
         numbers[2], numbers[3]);

  printf("name each: %c %c %c %c\n",
      name[0], name[1],
      name[2], name[3]);

  // print the name like a string
  printf("name: %s\n", name);

  // another way to use name
  char *another = "Zed";

  printf("another: %s\n", another);

  printf("another each: %c %c %c %c\n",
         another[0], another[1],
         another[2], another[3]);

  // assign chars to ints and print
  // Hmmm, int *charInts = {...} wouldn't work, but int charInts[4] would
  int charInts[4] = {'a', 'b', 'c', 'd'};
  printf("char ints: %d %d %d %d\n", charInts[0], charInts[1], charInts[2], charInts[3]);
  // Valgrind doesn't care about this

  int charInts2[4];
  charInts2[0] = 'a';
  charInts2[1] = 'b';
  charInts2[2] = 'c';
  charInts2[3] = 'd';
  printf("char ints: %d %d %d %d\n", charInts2[0], charInts2[1], charInts2[2], charInts2[3]);
  // Valgrind didn't care about that either.

  // ERROR
  // wide character array initialized from non-wide string
  // int stringInt[4] = "abc";

  // ERROR
  // Incompatible types when assigning to char[4] from char*
  // char lateAssign[4];
  // lateAssign = "abc";

  // Will int *blah = {<4 elems>} work?
  /* !! WHY U NO WORK? !!
  int *fourInts = {40, 50, 9, 87};
  */
  // init makes pointer from integer without cast (allowed by default)
  // Hmm, not sure what that means.
  // That works with C strings. (see line 44)
  // Maybe that's a compiler trick for C strings.

  int fourChars;
  //fourChars = 97 ... ?
  //fourChars = (int) {'a', 'b', 'c', 'd'};

  // Pointer from integer without cast ??
  //char *str0 = {'a', 'b', 'c', 'd'};

  char *str1 = "abc";

  // Segfault, core dumped
  //fourChars = (int) *str0;

  // Still just 97
  fourChars = (int) *str1;
  // just prints the value for the 'a': 97
  printf("Four chars crammed in an int: %d\n", fourChars);

  int fourChars2;
  char *str = "abcd";
  fourChars2 = (int) *str;
  printf("Three chars and a null (%s) crammed in an int: %d\n", str, fourChars2);
  printf("Chars as int: %d\n", (int) *str);

  int bitTwiddleTest = 1;
  bitTwiddleTest <<= 1; // should equal 2
  printf("Two: %d\n", bitTwiddleTest);

  int bitTwiddle = 0;
  // Duh, if you and with zero you get zero. :)
  //bitTwiddle &= str[0];
  bitTwiddle = str[0];
  printf("BitTwiddle set to 97? %d\n", bitTwiddle);
  bitTwiddle <<= 8;
  printf("Bit twiddle: %d\n", bitTwiddle);
  // Derp, I need to |, not &
  //bitTwiddle &= str[1];
  bitTwiddle |= str[1];
  printf("Bit twiddle: %d\n", bitTwiddle);
  bitTwiddle <<= 8;
  bitTwiddle |= str[2];
  printf("Bit twiddle: %d\n", bitTwiddle);
  bitTwiddle <<= 8;
  bitTwiddle |= str[3];
  printf("Bit twiddle: %d\n", bitTwiddle);

  printf("2nd char in str %s: %d\n", str, str[1]);

  // Nope: you only get d, which I'm assuming ... actually I don't
  // understand
  /*printf("Now get all the chars back: %c %c %c %c\n",*/
         /*(char) bitTwiddle,*/
         /*(char) bitTwiddle >> 24,*/
         /*(char) bitTwiddle >> 16,*/
         /*(char) bitTwiddle >> 8);*/

  // Nope, still just d
  printf("Now get all the chars back: %c %c %c %c\n",
         (char) bitTwiddle,
         (char) bitTwiddle << 24,
         (char) bitTwiddle << 16,
         (char) bitTwiddle << 8);

  // Both(?) 'd'
  // Maybe it just takes the least significant 8 bits?
  // But then why wouldn't shifting it get back the other letters?
  printf("Int not shifted: %c\n", (char) bitTwiddle);
  printf("Int not shifted: %c\n", (char) bitTwiddle);
  // These don't give anything but blank
  printf("Int left-shifted 24 bits: %c\n", (char) bitTwiddle << 24);
  // Since this is 97, why isn't it 'a'?
  printf("Int right-shifted 24 bits: %c\n", (char) bitTwiddle >> 24);
  printf("Int left-shifted 16 bits: %c\n", (char) bitTwiddle << 16);
  printf("Int right-shifted 16 bits: %c\n", (char) bitTwiddle >> 16);
  printf("Int left-shifted 8 bits: %c\n", (char) bitTwiddle << 8);
  printf("Int right-shifted 8 bits: %c\n", (char) bitTwiddle >> 8);

  // This is as I expected; not sure why it doesn't work for chars
  printf("Int left-shifted 24 bits: %d\n",  bitTwiddle << 24);
  printf("Int right-shifted 24 bits: %d\n",  bitTwiddle >> 24);
  printf("Int left-shifted 16 bits: %d\n",  bitTwiddle << 16);
  printf("Int right-shifted 16 bits: %d\n",  bitTwiddle >> 16);
  printf("Int left-shifted 8 bits: %d\n",  bitTwiddle << 8);
  printf("Int right-shifted 8 bits: %d\n",  bitTwiddle >> 8);

  // AHA! Operator precedence! bitTwiddle was being shifter AFTER the
  // cast. Derp.
  printf("Int right-shifted 24 bits: %c\n", (char) (bitTwiddle >> 24));
  printf("Int right-shifted 16 bits: %c\n", (char) (bitTwiddle >> 16));
  printf("Int right-shifted 8 bits: %c\n", (char) (bitTwiddle >> 8));

  // Yep, 0
  printf("0 left shifted 8 bits (zero still? or ones? I think zero.) %d\n", 0 << 8);
  // Nope, 0
  printf("0 right shifted 8 bits (pulls in 1s?) %d\n", 0 >> 8);

  // Nope, not even legal, thought it might bring in ones
  //printf("0 right shifted 8 bits (pulls in 1s?) %d\n", 0 >>> 8);

  return 0;
}
