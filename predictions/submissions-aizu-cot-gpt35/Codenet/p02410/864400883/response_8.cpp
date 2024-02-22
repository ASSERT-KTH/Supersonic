#include <cstdio>

int main() {
  int n, m;
  int a[100][100], b[100];

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int j = 0; j < m; j++) {
    scanf("%d", &b[j]);
  }

  for (int i = 0; i < n; i++) {
    int result = 0;
    for (int j = 0; j < m; j++) {
      result += a[i][j] * b[j];
    }
    printf("%d\n", result);
  }

  return 0;
}