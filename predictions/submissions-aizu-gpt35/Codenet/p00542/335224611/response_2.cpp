#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  int mn = min(min(a, b), min(c, d));
  int ans = a + b + c + d - mn + max(e, f);
  printf("%d\n", ans);
  return 0;
}