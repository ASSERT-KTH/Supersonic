#include <stdio.h>
int main() {
  int a, b, c;
  if(scanf("%d%d%d", &a, &b, &c) == 3) {
    if (a < b && b < c) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  } else {
    fprintf(stderr, "Invalid input\n");
  }
  return 0;
}