#include <stdio.h>
int main(void) {
  int a, b, c;
  const char* output;
  scanf("%d %d %d", &a, &b, &c);
  output = (a < b && b < c) ? "Yes\n" : "No\n";
  printf("%s", output);
  return 0;
}