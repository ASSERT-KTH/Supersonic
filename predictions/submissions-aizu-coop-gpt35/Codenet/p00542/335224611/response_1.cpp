#include <cstdio>
int main() {
  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  int ans = a + b + c + d - min(min(a, b), min(c, d)) + max(e, f);
  printf("%d\n", ans);
  return 0;
}