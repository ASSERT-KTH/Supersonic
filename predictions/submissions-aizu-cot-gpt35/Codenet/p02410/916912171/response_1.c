#include <stdio.h>
#include <string.h>

int main() {
  int inact[100][100];
  int act[100];
  int ans[100];
  int row, col;
  int i, j;

  scanf("%d %d", &row, &col);

  // Initialize inact array
  memset(inact, 0, sizeof(inact));

  // Read inact array
  for (i = 0; i < row; i++) {
    char line[1024];
    fgets(line, sizeof(line), stdin);
    char* token = strtok(line, " ");
    for (j = 0; j < col; j++) {
      sscanf(token, "%d", &inact[i][j]);
      token = strtok(NULL, " ");
    }
  }

  // Read act array
  char line[1024];
  fgets(line, sizeof(line), stdin);
  char* token = strtok(line, " ");
  for (i = 0; i < col; i++) {
    sscanf(token, "%d", &act[i]);
    token = strtok(NULL, " ");
  }

  // Calculate ans array
  for (i = 0; i < row; i++) {
    int sum = 0;
    for (j = 0; j < col; j += 4) {
      sum += inact[i][j] * act[j];
      sum += inact[i][j+1] * act[j+1];
      sum += inact[i][j+2] * act[j+2];
      sum += inact[i][j+3] * act[j+3];
    }
    ans[i] = sum;
  }

  // Output ans array
  char output[1024];
  char* outputPtr = output;
  for (i = 0; i < row; i++) {
    outputPtr += sprintf(outputPtr, "%d\n", ans[i]);
  }
  fputs(output, stdout);

  return 0;
}