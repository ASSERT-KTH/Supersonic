#include <stdio.h>

int b, d;
char c[999];

int main() {
  for (scanf("%d", &b), int a = b; a--; )
    scanf("%*d");
  
  for (scanf("%d", &b), int a = b; a--; d += c[b])
    scanf("%*d");

  printf("%ld\n", d);
  return 0;
}