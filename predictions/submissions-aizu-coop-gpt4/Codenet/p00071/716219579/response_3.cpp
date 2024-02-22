#include <cstdio>
using namespace std;
#define REP(i, N) for (int i = 0; i < (N); i++)
int n, y, x, M[9][9];
bool visited[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void solve(int y, int x) {
  M[y][x] = 0;
  visited[y][x] = true;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1 && !visited[ny][nx])
      solve(ny, nx);
  }
}
int main() {
  scanf("%d", &n);
  REP(i, n) {
    REP(j, 8) {
      REP(k, 8) { 
        char c; scanf(" %c", &c); 
        M[j][k] = c - '0'; 
        visited[j][k] = false; 
      }
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