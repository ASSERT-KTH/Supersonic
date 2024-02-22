#include <stdio.h>

int main() {
  int row, col;
  scanf("%d %d", &row, &col);
  
  int inact[col][row], act[col], ans[row];
  
  for (int i = 0; i < row; i++) {
    ans[i] = 0;
    for (int j = 0; j < col; j++) {
      scanf("%d", &inact[j][i]);  // read into transposed matrix
    }
  }
  
  for (int i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }
  
  // do the multiplication using the transposed matrix
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      ans[i] += inact[j][i] * act[j];
    }
  }
  
  for (int i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }
  
  return 0;
}