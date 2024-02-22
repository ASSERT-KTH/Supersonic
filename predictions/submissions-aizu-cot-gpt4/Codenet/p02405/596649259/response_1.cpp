#include <cstdio>
using namespace std;
int main() {
  int H, W;
  char map[2][2] = { {'.', '#'}, {'#', '.'} };
  while (scanf("%d %d", &H, &W) != EOF && H != 0 && W != 0) {
    for (int i = 0; i < H; i++) {
      string row = "";
      for (int j = 0; j < W; j++) {
        row += map[i%2][j%2];
      }
      printf("%s\n", row.c_str());
    }
    printf("\n");
  }
  return 0;
}