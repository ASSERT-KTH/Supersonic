#include <stdio.h>

int main(void) {
  char input[100];
  
  fgets(input, sizeof(input), stdin);
  int a, b, c;
  sscanf(input, "%d %d %d", &a, &b, &c);
  
  if (a < b && b < c) {
    puts("Yes");
  } else {
    puts("No");
  }
  
  return 0;
}