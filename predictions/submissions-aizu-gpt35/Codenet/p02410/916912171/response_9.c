#include <stdio.h>
int main() {
    int inact[100][100];
    int act[100];
    int ans[100] = {0}; //initialize to 0
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
        int sum = 0; //use a temporary variable to store sum
        for (j = 0; j < col; j++) {
            sum += inact[i][j] * act[j];
        }
        ans[i] = sum; //store the sum in ans array
    }
    for (i = 0; i < row; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}