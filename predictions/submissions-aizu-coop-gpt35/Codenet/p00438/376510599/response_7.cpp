#include <cstdio>
#include <vector>

int main() {
  int a, b, n, t1, t2;
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);

    // Create a 1D array to store the number of unique paths
    std::vector<int> way(b + 1, 0);

    // Preprocess the grid and mark obstacle positions
    std::vector<std::vector<bool>> hasObstacle(b + 1, std::vector<bool>(a + 1, false));
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &t1, &t2);
      hasObstacle[t2][t1] = true;
    }

    // Calculate the number of unique paths
    way[1] = 1;
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++) {
        if (!hasObstacle[i][j]) {
          if (j > 1)
            way[j] += way[j - 1];
        } else {
          way[j] = 0; // Reset the number of unique paths for the current column
        }
      }
    }

    printf("%d\n", way[a]);
  }

  return 0;
}