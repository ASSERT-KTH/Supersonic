#include <cstdio>
int main() {
  int a, b, n, t1, t2, way[17][17] = {0};
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    for (int i = 1; i <= b; ++i) {
      for (int j = 1; j <= a; ++j)
        way[i][j] = (i == 1 || j == 1) ? 1 : 0;
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &t1, &t2), way[t2][t1] = -1;
      if (t1 == 1) for (int j = t2; j <= b; ++j) way[j][1] = 0;
      if (t2 == 1) for (int j = t1; j <= a; ++j) way[1][j] = 0;
    }
    for (int i = 2; i <= b; ++i) {
      for (int j = 2; j <= a; ++j) {
        if (way[i][j] != -1) {
          if (way[i][j - 1] != -1) way[i][j] += way[i][j - 1];
          if (way[i - 1][j] != -1) way[i][j] += way[i - 1][j];
        }
      }
    }
    printf("%d\n", way[b][a]);
  }
  return 0;
}