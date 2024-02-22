#include <cstdio>
int main() {
  int a, b, n, t1, t2, way[17][17];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    for (int i = 1; i <= b; ++i) {
      for (int j = 1; j <= a; ++j)
        way[i][j] = (i == 1 || j == 1) ? 1 : 0; // Initialize to 1 for edges and 0 otherwise
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &t1, &t2), way[t2][t1] = -1;
    }
    for (int i = 2; i <= b; ++i) {
      for (int j = 2; j <= a; ++j) {
        if (way[i][j] != -1) {
          way[i][j] = way[i][j - 1] + way[i - 1][j]; // Add the number of ways from the cell above and to the left
        }
      }
    }
    printf("%d\n", way[b][a]);
  }
  return 0;
}