#include <cstdio>

int main() {
  int H, W;
  while (1) {
    scanf("%d%d", &H, &W);
    if (H == 0 && W == 0)
      break;
    for (int i = 1; i <= H; i++) {
      char ch;
      if (i == 1 || i == H) {
        ch = '#';
      } else {
        ch = '.';
      }
      for (int j = 1; j <= W; j++) {
        if (j == 1 || j == W) {
          printf("#");
        } else {
          printf("%c", ch);
        }
      }
      printf("\n");
    }
    printf("\n");
  }
}