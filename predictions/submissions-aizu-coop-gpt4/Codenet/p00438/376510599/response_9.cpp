#include <cstdio>

int main() {
  int a, b, n, t1, t2, way[17][17];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++)
        way[i][j] = 1; // Initialize all cells to 1
    }
    for (int i = 0; i < n; i++)
      scanf("%d %d", &t1, &t2), way[t2][t1] = -1; // Mark blocked cells

    // If the first cell is blocked, can't move at all
    if (way[1][1] == -1) {
      printf("0\n");
      continue;
    }

    for (int i = 2; i <= a; i++) {
      if (way[1][i] == -1)
        way[1][i] = 0; // If a cell in the first row is blocked, it can't be reached
      else
        way[1][i] += way[1][i - 1]; // Sum up the ways to reach this cell
    }
    for (int i = 2; i <= b; i++) {
      if (way[i][1] == -1)
        way[i][1] = 0; // If a cell in the first column is blocked, it can't be reached
      else
        way[i][1] += way[i - 1][1]; // Sum up the ways to reach this cell
    }

    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        if (way[i][j] != -1) {
          way[i][j] = (way[i][j - 1] != -1 ? way[i][j - 1] : 0) + (way[i - 1][j] != -1 ? way[i - 1][j] : 0);
        } else {
          way[i][j] = 0;
        }
      }
    }
    printf("%d\n", way[b][a]);
  }
  return 0;
}