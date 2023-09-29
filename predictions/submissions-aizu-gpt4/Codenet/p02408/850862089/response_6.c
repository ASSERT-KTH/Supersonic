#include <stdio.h>
int main(void) {
  int cards[4][13] = {0};
  int n, num;
  char mark;
  scanf("%d", &n);
  while(n--) {
    scanf(" %c%d", &mark, &num);
    switch(mark) {
      case 'S': cards[0][num - 1] = 1; break;
      case 'H': cards[1][num - 1] = 1; break;
      case 'C': cards[2][num - 1] = 1; break;
      case 'D': cards[3][num - 1] = 1; break;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      if (!cards[i][j]) {
        printf("%c %d\n", "SHCD"[i], j + 1);
      }
    }
  }
  return 0;
}