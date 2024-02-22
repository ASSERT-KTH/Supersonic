#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  
  // Simplify the condition and reduce number of printf calls
  if (a >= b || b >= c) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
  
  return 0;
}