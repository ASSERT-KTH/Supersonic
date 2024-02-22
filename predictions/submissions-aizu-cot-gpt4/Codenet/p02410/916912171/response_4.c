#include <stdio.h>
int main() {
  int inact[100][100] = {0}; // Initialize with zeros at declaration
  int row, col;
  int i, j;
  
  scanf("%d %d", &row, &col);

  int act[col]; // Declare 'act' after knowing 'col'
  int ans[row] = {0}; // Declare and initialize 'ans' after knowing 'row'

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
    printf("%d\n", ans[i]); // Combine calculation and printing
  }
  
  return 0;
}