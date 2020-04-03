
//DO NOT RUN THIS PROGRAM ON SMART COMPILERS LIKE VISUAL STUDIO.RUN IT ON DUMB ONLINE COMPILERS TO UNDERSTAND THE DIFFERENCE
#include <stdio.h>
#include <string.h>

int noOverlappingDestinationswithmemmove()
{
  char string[] = "stackoverflow";
  char *first, *second;
  first = string;
  second = string;

  puts(string);
  memmove(second + 5, second, 5);
  puts(second);
  return 0;
}

int noOverlappingDestinationswithmemcpy()
{
  char string[] = "stackoverflow";
  char *first, *second;
  first = string;
  second = string;

  puts(string);
  memcpy(first + 5, first, 5);
  puts(first);
  return 0;
}

int overlappingDestinationsWithmemmove()
{
  char string[] = "stackoverflow";
  char *third, *fourth;
  third = string;
  fourth = string;

  puts(string);
  memmove(fourth + 5, fourth, 7);
  puts(fourth);
  //Output : stackstackstw
  //It is because "memmove()" handles overlap of source and destination :
  return 0;
}

int overlappingDestinationsWithmemcpy()
{
  char string[] = "stackoverflow";
  char *third, *fourth;
  third = string;
  fourth = string;

  puts(string);
  memcpy(fourth + 5, fourth, 7);
  puts(fourth);

  //Output : stackstackstw
  //It is because "memcpy()" does the following :
  //           1.  stackoverflow
  //           2.  stacksverflow
  //           3.  stacksterflow
  //           4.  stackstarflow
  //           5.  stackstacflow
  //           6.  stackstacklow
  //           7.  stackstacksow
  //           8.  stackstackstw

  return 0;
}

int main(void)
{
  noOverlappingDestinationswithmemmove();
  noOverlappingDestinationswithmemcpy();
  overlappingDestinationsWithmemmove();
  overlappingDestinationsWithmemcpy();
  return 0;
}