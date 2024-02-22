#include <cstdio>
#include <vector>
using namespace std;

int n;
int y, x, M[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int y, int x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1) {
      solve(ny, nx);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8; j++) {
      char s[10];
      scanf("%s", s);
      for (int k = 0; k < 8; k++) {
        M[j][k] = s[k] - '0';
      }
    }
    scanf("%d %d", &x, &y);
    solve(y - 1, x - 1);
    printf("Data %d:\n", i + 1);
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        printf("%d", M[j][k]);
      }
      printf("\n");
    }
  }
  return 0;
}