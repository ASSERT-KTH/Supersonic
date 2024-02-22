#include <stdio.h>

int main() {
  char input[100];
  int n, m;
  
  fgets(input, sizeof(input), stdin);
  sscanf(input, "%d%d", &n, &m);
  
  if (n > m) {
    printf("%d\n", n - m - 1);
  } else {
    printf("Invalid input\n");
  }
  
  return 0;
}