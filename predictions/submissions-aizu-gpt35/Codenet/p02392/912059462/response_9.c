#include <stdio.h>
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a < b && b < c) {
    printf("Yes\n"); //print newline character along with the string
  } else {
    printf("No\n"); //print newline character along with the string
  }
  return 0;
}