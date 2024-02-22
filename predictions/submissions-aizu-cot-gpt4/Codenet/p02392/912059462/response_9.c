#include <stdio.h>
int main() {
  int a, b, c;
  fscanf(stdin, "%d%d%d", &a, &b, &c);
  if (a < b && b < c) {
    return printf("Yes\n"), 0;
  } else {
    return printf("No\n"), 0;
  }
}