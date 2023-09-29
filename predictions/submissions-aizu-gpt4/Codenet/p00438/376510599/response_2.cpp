#include <cstdio>
int main() {
  int a, b, n, t1, t2;
  static int way[17][17];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    for (int i = 0; i <= b; ++i) {
      for (int j = 0; j <= a; ++j)
        way[i][j] = 0;
    }
    while(n--){
      scanf("%d %d", &t1, &t2);
      way[t2][t1] = -1;
    }
    way[1][1] = 1;
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++) {
        if (way[i][j] != -1) {
          if (i > 1 && way[i - 1][j] != -1) way[i][j] += way[i - 1][j];
          if (j > 1 && way[i][j - 1] != -1) way[i][j] += way[i][j - 1];
        }
      }
    }
    printf("%d\n", way[b][a]);
  }
  return 0;
}