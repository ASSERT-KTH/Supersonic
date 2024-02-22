#include <cstdio>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int H, W;
  while (scanf("%d %d", &H, &W) && H != 0 && W != 0) {
    char cell = '.';
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        printf("%c", cell);
        cell = (cell == '.' ? '#' : '.');
      }
      printf("\n");
      if(W % 2 == 0) cell = (cell == '.' ? '#' : '.');
    }
    printf("\n");
  }

  return 0;
}