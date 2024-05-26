#include <stdio.h>
#include "Stones.h"


int main()
{
   char* a = "00001000";
   int b = fromChartoInt(a);
   printf("%s %d", a, b);
   return 0;
}