#include <stdio.h>

int main() {
  int inact[100][100];
  int act[100];
  int ans[100] = {0}; // Initialize ans array to 0
  int row, col;
  int i, j;
  
  scanf("%d %d", &row, &col);
  
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }
  
  for (i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }
  
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      ans[i] += inact[i][j] * act[j];
    }
    printf("%d\n", ans[i]); // Print each answer as soon as it's calculated
  }
  
  return 0;
}