#include <stdio.h>
#define s scanf("%d", &b)
int a, b, c[999];
int main() {
  for (s, a = b; a--; c[b] = 1, s);
  for (s, a = b; a--; s) {
    c[b]++;
  }
  int d = 0;
  for (int i = 0; i < b; i++) {
    d += c[i];
  }
  printf("%d\n", d);
  return 0;
}