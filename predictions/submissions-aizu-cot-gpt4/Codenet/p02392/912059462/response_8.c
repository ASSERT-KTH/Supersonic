#include <stdio.h>
int main() {
  int a, b, c;
  char *result;
  scanf("%d%d%d", &a, &b, &c);
  if (a < b && b < c) {
    result = "Yes\n";
  } else {
    result = "No\n";
  }
  printf("%s", result);
  return 0;
}