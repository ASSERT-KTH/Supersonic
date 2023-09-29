#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 17;
int main() {
  int a, b, n, t1, t2, way[MAXN][MAXN];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    memset(way, 0, sizeof(way));
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &t1, &t2);
      way[t2][t1] = -1;
    }

    if (way[1][1] == -1) {
      printf("0\n");
      continue;
    }

    way[1][1] = 1;
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++) {
        if (way[i][j] == -1)
          continue;
        if (j > 1 && way[i][j - 1] != -1)
          way[i][j] += way[i][j - 1];
        if (i > 1 && way[i - 1][j] != -1)
          way[i][j] += way[i - 1][j];
      }
    }
    printf("%d\n", way[b][a]);
  }
  return 0;
}