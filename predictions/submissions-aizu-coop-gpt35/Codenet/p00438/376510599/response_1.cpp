#include <cstdio>
#include <vector>

int main() {
  int a, b, n, t1, t2;
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);

    // Dynamically allocate the 2D array
    std::vector<std::vector<int>> way(b + 1, std::vector<int>(a + 1, 0));

    for (int i = 0; i < n; i++) {
      scanf("%d %d", &t1, &t2);
      way[t2][t1] = -1;
    }

    // Initialize the necessary elements of the "way" matrix
    for (int i = 1; i <= a; i++) {
      if (way[1][i] == -1) {
        break;
      }
      way[1][i] = 1;
    }
    for (int i = 1; i <= b; i++) {
      if (way[i][1] == -1) {
        break;
      }
      way[i][1] = 1;
    }

    // Calculate the number of ways using dynamic programming
    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        if (way[i][j] != -1) {
          int w = way[i][j - 1];
          int h = way[i - 1][j];
          way[i][j] = (w == -1 ? 0 : w) + (h == -1 ? 0 : h);
        }
      }
    }

    printf("%d\n", way[b][a]);
  }

  return 0;
}