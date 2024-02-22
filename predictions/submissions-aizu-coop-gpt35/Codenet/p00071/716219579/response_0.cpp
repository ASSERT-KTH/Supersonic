#include <iostream>
using namespace std;

#define REP(i, N) for (int i = 0; i < (N); i++)

int n;
int y, x;
bool M[8][8];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int y, int x) {
  M[y][x] = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 3; j++) {
      int ny = y + dy[i] * j, nx = x + dx[i] * j;
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
        if (M[ny][nx])
          solve(ny, nx);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  scanf("%d", &n);
  REP(i, n) {
    REP(j, 8) {
      REP(k, 8) {
        int val;
        scanf("%1d", &val);
        M[j][k] = val;
      }
    }
    scanf("%d %d", &x, &y);
    solve(y - 1, x - 1);
    printf("Data %d:\n", i + 1);
    REP(j, 8) {
      REP(k, 8) {
        printf("%d", M[j][k]);
      }
      printf("\n");
    }
  }

  return 0;
}