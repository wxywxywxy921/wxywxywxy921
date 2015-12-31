#include <stdio.h>
#include "strStr.h"

int main()
{
  Solution solution;

  char a[] = "abcdefg";
  char b[] = "bacd";

  printf("result is=%d\n",
         solution.strStr(a, b));

  return 0;
}
