#include <cstdio>
#include <cstring>
int main() {
  int a, b, n, t1, t2, way[17][17];
  while (scanf("%d %d", &a, &b), a | b) {
    scanf("%d", &n);
    memset(way, 0, sizeof(way));
    for (int i = 0; i < n; i++)
      scanf("%d %d", &t1, &t2), way[t2][t1] = -1;
    for (int i = 1; i <= a; i++) {
      if (way[1][i] == -1)
        break;
      way[1][i] = 1;
    }
    for (int i = 1; i <= b; i++) {
      if (way[i][1] == -1)
        break;
      way[i][1] = 1;
    }
    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        int wayVal = way[i][j];
        if (wayVal != -1) {
          int w = (way[i][j - 1] != -1) ? way[i][j - 1] : 0;
          int h = (way[i - 1][j] != -1) ? way[i - 1][j] : 0;
          way[i][j] = w + h;
        }
      }
    }
    printf("%d\n", way[b][a]);
  }
  return 0;
}