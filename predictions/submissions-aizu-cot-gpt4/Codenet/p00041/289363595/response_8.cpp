#include <stdio.h>

#define SIZE 4
#define NUM_BRACKETS 110000

int main() {
  int a[SIZE];
  
  while (1) {
    scanf("%d", &a[0]);
    if (a[0] == 0) {
      break;
    }

    for (int i = 1; i < SIZE; ++i) {
      scanf("%d", &a[i]);
    }
    
    printf("%*c", NUM_BRACKETS, '(');
    printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
  }
  
  return 0;
}