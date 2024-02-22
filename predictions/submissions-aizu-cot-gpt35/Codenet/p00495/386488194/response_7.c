#include <stdio.h>

int main() {
  int n;
  scanf("%d%*d", &n);

  int c[5004], d[5004];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }

  int x;
  while (scanf("%d", &x) != EOF) {
    int m = 0, u = 0;
    for (int i = 1; i <= n; i++) {
      int t = d[i];
      d[i] = (x - c[i]) ? u : t + 1;
      u = (d[i] > m) ? d[i] : m;
      m = (d[i] > m) ? d[i] : m;
    }
    printf("%d\n", m);
  }

  return 0;
}