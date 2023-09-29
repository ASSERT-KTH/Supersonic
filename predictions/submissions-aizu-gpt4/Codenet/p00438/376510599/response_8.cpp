#include <cstdio>
constexpr int MAX_SIZE = 17;

int main() {
  int a, b, n, t1, t2, way[MAX_SIZE][MAX_SIZE];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    std::fill(&way[0][0], &way[0][0] + sizeof(way) / sizeof(int), 0);
    while(n--) {
      scanf("%d %d", &t1, &t2);
      way[t2][t1] = -1;
    }
    way[1][1] = 1;
    for (int i = 1; i <= b; ++i) {
      for (int j = 1; j <= a; ++j) {
        if (i > 1 && way[i - 1][j] != -1) way[i][j] += way[i - 1][j];
        if (j > 1 && way[i][j - 1] != -1) way[i][j] += way[i][j - 1];
      }
    }
    printf("%d\n", way[b][a]);
  }
  return 0;
}