#include <stdio.h>
int main(void) {
  setbuf(stdout, NULL);
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  return (a < b && b < c) ? printf("Yes\n"), 0 : printf("No\n"), 0;
}