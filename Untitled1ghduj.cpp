#include <stdio.h>
#include <conio.h>
int main ()

{

char str1 [50], str2 [50] = { 'N', 'E', 'P', 'A', 'L'};

scanf("% [A-Z]", str1);

printf ("%s\n", str1);

printf ("% 0.5 s\n", str2);

printf ("% 5.3 s\n", str2);

printf ("%-0.3s", str2);

return 0;

}
