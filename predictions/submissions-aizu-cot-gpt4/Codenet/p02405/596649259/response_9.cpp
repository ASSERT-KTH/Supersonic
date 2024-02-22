#include <cstdio>
#include <string>
using namespace std;
int main() {
  int H, W;
  while (scanf("%d %d", &H, &W) == 2 && H != 0 && W != 0) {
    string line;
    for (int i = 1; i <= H; i++) {
      line.clear();
      for (int j = 1; j <= W; j++) {
        line += ".#"[(i + j) & 1];
      }
      printf("%s\n", line.c_str());
    }
    printf("\n");
  }
  return 0;
}