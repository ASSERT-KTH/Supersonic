#include <cstdio>

int main() {
  int n, m;
  int x, y, a[100][100], b[100];
  int c = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &x);
      a[i][j] = x;
    }
  }
  for (int j = 0; j < m; j++) {
    scanf("%d", &y);
    b[j] = y;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    printf("%d\n", c);
    c = 0;
  }
  return 0;
}