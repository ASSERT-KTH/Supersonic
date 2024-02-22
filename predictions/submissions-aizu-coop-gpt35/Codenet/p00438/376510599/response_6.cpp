#include <cstdio>
#include <cstdlib>

int main() {
  int a, b, n, t1, t2;
  
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);

    // Dynamically allocate memory for the way array
    int** way = (int**)malloc((b+1) * sizeof(int*));
    for (int i = 0; i <= b; i++) {
      way[i] = (int*)calloc((a+1), sizeof(int));
    }

    for (int i = 0; i < n; i++) {
      scanf("%d %d", &t1, &t2);
      way[t2][t1] = -1;
    }

    // Combine initialization and obstacle check into a single loop
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++) {
        if (way[i][j] != -1) {
          if (i == 1 && j == 1)
            way[i][j] = 1;
          else {
            int w = (way[i][j-1] != -1) ? way[i][j-1] : 0;
            int h = (way[i-1][j] != -1) ? way[i-1][j] : 0;
            way[i][j] = w + h;
          }
        }
      }
    }

    printf("%d\n", way[b][a]);

    // Free dynamically allocated memory
    for (int i = 0; i <= b; i++) {
      free(way[i]);
    }
    free(way);
  }

  return 0;
}