#include <cstdio>
#define REP(i, N) for (long long i = 0; i < (N); i++)
int n, y, x, M[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char s[9];
void solve(int y, int x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
      if (M[ny][nx] == 1)
        solve(ny, nx);
    }
  }
}
int main() {
  scanf("%d", &n);
  REP(i, n) {
    REP(j, 8) {
      scanf("%s", s);
      REP(k, 8) { M[j][k] = s[k] - '0'; }
    }
    scanf("%d%d", &x, &y);
    solve(y - 1, x - 1);
    printf("Data %d:\n", i + 1);
    REP(j, 8) {
      REP(k, 8) { printf("%d", M[j][k]); }
      printf("\n");
    }
  }
}