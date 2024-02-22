#include <cstdio>
int main() {
  int a, b, n, way[17][17];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++)
        way[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
      int t1, t2;
      scanf("%d %d", &t1, &t2);
      way[t2][t1] = -1;
    }
    for (int i = 1; i <= a; i++) {
      if (way[1][i] == -1)
        break;
      way[1][i] = 1;
    }
    for (int i = 1; i <= b && way[i][1] != -1; i++) {
      way[i][1] = 1;
    }
    for (int i = 2; i <= b && way[i][1] != -1; i++) {
      int w = 0, h = 0;
      for (int j = 2; j <= a && way[i][j] != -1; j++) {
        if (way[i][j] != -1) {
          if (way[i][j - 1] != -1)
            w = way[i][j - 1];
          if (way[i - 1][j] != -1)
            h = way[i - 1][j];
          way[i][j] = w + h;
        }
      }
    }
    printf("%d\n", way[b][a]);
  }
  return 0;
}