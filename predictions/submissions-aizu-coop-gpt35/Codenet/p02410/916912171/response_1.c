#include <stdio.h>

int main() {
  int inact[100][100];
  int act[100];
  int row, col;
  int i, j, k;
  
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
    int ans = 0; // Temporary variable to accumulate product
    for (j = 0; j < col; j++) {
      ans += inact[i][j] * act[j];
    }
    printf("%d\n", ans);
  }
  
  return 0;
}