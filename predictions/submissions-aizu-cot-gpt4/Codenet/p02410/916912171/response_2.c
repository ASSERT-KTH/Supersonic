#include <stdio.h>
int main() {
  int row, col;
  scanf("%d %d", &row, &col);
  int inact[row][col];
  int act[col];
  int ans[row] = {0};
  
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }
  for (int i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      ans[i] += inact[i][j] * act[j];
    }
  }
  for (int i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}