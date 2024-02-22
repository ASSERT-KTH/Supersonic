#include <cstdio>
#include <cstring>

int main() {
  int a, b, n, way[17][17];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);

    memset(way, 0, sizeof(way));

    for (int i = 0; i < n; i++) {
      int t1, t2;
      scanf("%d %d", &t1, &t2);
      way[t2][t1] = -1;
    }

    way[1][1] = 1;

    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++) {
        if (way[i][j] != -1) {
          int w = 0, h = 0;
          if (way[i][j - 1] != -1)
            w = way[i][j - 1];
          if (way[i - 1][j] != -1)
            h = way[i - 1][j];
          way[i][j] = w + h;
        }
      }
    }

    int result = way[b][a];
    printf("%d\n", result);
  }

  return 0;
}