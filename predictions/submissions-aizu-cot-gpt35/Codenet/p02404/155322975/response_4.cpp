#include <cstdio>

int main() {
  int H, W;
  while (true) {
    scanf("%d %d", &H, &W);
    if (H == 0 && W == 0)
      break;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
          printf("#");
        } else {
          printf(".");
        }
      }
      printf("\n");
    }
    printf("\n");
  }
}