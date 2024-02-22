#include <stdio.h>

int main() {
  int a, b, c;
  if(scanf("%d%d%d", &a, &b, &c) != 3) {
    printf("Invalid input\n");
    return 1; // return non-zero to indicate failure
  }
  
  if (a < b) {
    if (b < c) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  } else {
    printf("No\n");
  }
  
  return 0;
}