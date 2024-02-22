#include <cstdio>
#define MAX_SIZE 17
int main() {
  int a, b, n, t1, t2;
  int ways[MAX_SIZE][MAX_SIZE];
  bool blocked[MAX_SIZE][MAX_SIZE];
  
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    
    // Initialize the ways and blocked arrays.
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a; j++) {
        ways[i][j] = 0;
        blocked[i][j] = false;
      }
    }
    
    // Read blocked cells and mark them in the blocked array.
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &t1, &t2);
      blocked[t2][t1] = true;
    }
    
    // Calculate number of ways for the first row until a blocked cell is encountered.
    for (int i = 1; i <= a; i++) {
      if (blocked[1][i])
        break;
      ways[1][i] = 1;
    }
    
    // Calculate number of ways for the first column until a blocked cell is encountered.
    for (int i = 1; i <= b; i++) {
      if (blocked[i][1])
        break;
      ways[i][1] = 1;
    }
    
    // Calculate number of ways for the rest of the cells.
    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        if (!blocked[i][j]) {
          ways[i][j] = ways[i][j - 1] + ways[i - 1][j];
        }
      }
    }
    
    printf("%d\n", ways[b][a]);
  }
  
  return 0;
}