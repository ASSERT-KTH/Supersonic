#include <cstdio>

int main() {
  int a = 0, H[100], W[100];
  while (true) {
    scanf("%d%d", &H[a], &W[a]);
    if (H[a] == 0 && W[a] == 0)
      break;
    a++;
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < H[i]; j++) {
      for (int k = 0; k < W[i]; k++) {
        printf("#");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}