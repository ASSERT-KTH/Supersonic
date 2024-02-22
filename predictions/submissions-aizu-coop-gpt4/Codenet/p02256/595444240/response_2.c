#include <stdio.h>
int main() {
  int a, b, c = 1, i, temp;
  scanf("%d%d", &a, &b);
  
  // Swap a and b if b > a
  if (b > a) {
    temp = a;
    a = b;
    b = temp;
  }

  // Use a do-while loop to eliminate unnecessary check at the beginning
  do {
    c = a % b;
    a = b;
    b = c;
  } while (c > 0);

  printf("%d\n", a);
}