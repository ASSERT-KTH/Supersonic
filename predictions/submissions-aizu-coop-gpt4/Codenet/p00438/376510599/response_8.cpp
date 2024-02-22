#include <cstdio>
#include <cstring>
int main() {
  int a, b, n, t1, t2;
  int way[17][17];
  bool blocked[17][17];

  while (scanf("%d %d", &a, &b), a || b) {
    memset(way, 0, sizeof(way));  // Initialize the array to 0 using memset
    memset(blocked, false, sizeof(blocked));  // Initialize the blocked array to false using memset

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &t1, &t2), blocked[t2][t1] = true;  // Mark the blocked cells
    }
    for (int i = 1; i <= a; i++) {
      if (blocked[1][i])
        break;
      way[1][i] = 1;
    }
    for (int i = 1; i <= b; i++) {
      if (blocked[i][1])
        break;
      way[i][1] = 1;
    }
    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        if (!blocked[i][j]) {
          int w = way[i][j - 1];
          int h = way[i - 1][j];
          way[i][j] = w + h;
        }
      }
    }
    printf("%d\n", way[b][a]);
  }
  return 0;
}