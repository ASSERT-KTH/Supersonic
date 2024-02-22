#include <cstdio>
using namespace std;
int main() {
  int H, W;
  while (scanf("%d %d", &H, &W) && H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      char line[W+1];
      for (int j = 1; j <= W; j++) {
        line[j-1] = ".#"[(i + j) % 2 == 0];
      }
      line[W] = '\0';
      printf("%s\n", line);
    }
    printf("\n");
  }
  return 0;
}