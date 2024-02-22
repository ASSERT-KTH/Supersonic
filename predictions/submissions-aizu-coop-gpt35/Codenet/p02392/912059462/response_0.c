#include <stdio.h>

int main() {
  char input[32];
  fgets(input, sizeof(input), stdin);
  
  int a, b, c;
  sscanf(input, "%d%d%d", &a, &b, &c);
  
  if (a < b && b < c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
}