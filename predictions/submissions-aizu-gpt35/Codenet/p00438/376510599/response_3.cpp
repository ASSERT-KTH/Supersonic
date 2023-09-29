#include <cstdio>
int way[17][17];
int main() {
  int a, b, n, t1, t2;
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    for (int i = 1; i <= b; i++)
      for (int j = 1; j <= a; j++)
        way[i][j] = 0;
    for (int i = 0; i < n; i++)
      scanf("%d %d", &t1, &t2), way[t2][t1] = -1;
    for (int i = 1; i <= a; i++)
      way[1][i] = way[1][i] != -1 ? 1 : 0;
    for (int i = 1; i <= b; i++)
      way[i][1] = way[i][1] != -1 ? 1 : 0;
    for (int i = 2; i <= b; i++)
      for (int j = 2; j <= a; j++)
        way[i][j] = way[i][j] != -1 ? (way[i][j-1] + way[i-1][j]) : 0;
    printf("%d\n", way[b][a]);
  }
  return 0;
}