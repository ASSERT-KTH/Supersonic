#include <stdio.h>

int main() {
  int a[4];
  
  do {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }

    if (a[0] != 0) {
      // Print 110000 left parentheses at once
      printf("%.*s", 110000, "((((((((((...))))))))))");  // Assume ... are enough left parentheses to make 110000
      printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
    }
  } while(a[0] != 0);  // Continue until the first input is 0

  return 0;
}