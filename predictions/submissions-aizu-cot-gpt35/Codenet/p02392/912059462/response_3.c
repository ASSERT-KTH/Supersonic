#include <stdio.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  
  if (a < b) {
    puts("Yes");
  } else {
    puts("No");
  }
  
  return 0;
}