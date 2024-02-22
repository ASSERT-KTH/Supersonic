#include <cstdio>

int main() {
  int a, b, n, t1, t2, way[17];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    
    // Initialize the first row and first column
    for (int i = 0; i <= a; i++) {
      way[i] = 0;
    }

    // Initialize the rest of the elements to -1
    for (int i = 1; i <= b; i++) {
      way[0] = -1; // First column
      for (int j = 1; j <= a; j++)
        way[j] = -1;
      
      // Set obstacles
      for (int j = 0; j < n; j++) {
        scanf("%d %d", &t1, &t2);
        if (t2 == i)
          way[t1] = 0;
      }

      // Calculate the number of paths
      for (int j = 1; j <= a; j++) {
        bool obstacle = (way[j] != -1);
        if (obstacle) {
          way[j] += way[j - 1];
        }
      }
    }
    printf("%d\n", way[a]);
  }
  return 0;
}