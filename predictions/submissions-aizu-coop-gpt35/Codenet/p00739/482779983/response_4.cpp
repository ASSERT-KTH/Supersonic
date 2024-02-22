#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define REP(i, a, n) for (i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)

typedef long long ll;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int w, h, csize;
int *field, *cx, *cy, *tatu_x, *tatu_y, *kazu_x, *kazu_y;
int **visited;

bool inside(int x, int y) {
  return x >= 0 && x < w && y >= 0 && y < h;
}

bool backtrack(int cnt, ll kS, int init_dir, int f) {
  int i, j, k;
  if (visited[cnt][init_dir][f])
    return false;
  if (csize / 2 == cnt)
    return true;
  rep(i, cnt) {
    rep(k, 4) {
      int tx = tatu_x[i] + dx[k];
      int ty = tatu_y[i] + dy[k];
      if (!inside(tx, ty) || field[ty * w + tx] == 0)
        continue;
      int ttx = kazu_x[i] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
      int tty = kazu_y[i] + dy[(k + init_dir) % 4];
      if ((tx == ttx && ty == tty) || !inside(ttx, tty) || field[tty * w + ttx] == 0)
        continue;
      field[ty * w + tx] = 0;
      tatu_x[cnt] = tx, tatu_y[cnt] = ty;
      field[tty * w + ttx] = 0;
      kazu_x[cnt] = ttx, kazu_y[cnt] = tty;
      if (backtrack(cnt + 1, kS | (1LL << (ttx + tty * w)), init_dir, f))
        return true;
      field[tty * w + ttx] = 1;
      field[ty * w + tx] = 1;
    }
  }
  visited[cnt][init_dir][f] = 1;
  return false;
}

bool solve() {
  int i, j, k;
  if (csize % 2)
    return false;
  tatu_x[0] = cx[0], tatu_y[0] = cy[0];
  field[cy[0] * w + cx[0]] = 0;
  REP(j, 1, csize) {
    kazu_x[0] = cx[j], kazu_y[0] = cy[j];
    field[cy[j] * w + cx[j]] = 0;
    rep(k, 4) {
      if (backtrack(1, 1LL << (cx[j] + cy[j] * w), k, 0))
        return true;
      if (backtrack(1, 1LL << (cx[j] + cy[j] * w), k, 1))
        return true;
    }
    field[cy[j] * w + cx[j]] = 1;
  }
  field[cy[0] * w + cx[0]] = 1;
  return false;
}

int main() {
  int i, j, k, u;
  while (cin >> w >> h, w | h) {
    csize = 0;
    field = new int[w * h];
    cx = new int[20];
    cy = new int[20];
    tatu_x = new int[20];
    tatu_y = new int[20];
    kazu_x = new int[20];
    kazu_y = new int[20];
    visited = new int*[20];
    rep(i, 20) visited[i] = new int[4 * 2];

    rep(i, h) rep(j, w) {
      cin >> field[i * w + j];
      if (field[i * w + j] == 1) {
        cx[csize] = j, cy[csize] = i;
        csize++;
      }
    }

    rep(i, 20) rep(j, 4 * 2) visited[i][j] = 0;

    puts(solve() ? "YES" : "NO");

    delete[] field;
    delete[] cx;
    delete[] cy;
    delete[] tatu_x;
    delete[] tatu_y;
    delete[] kazu_x;
    delete[] kazu_y;
    rep(i, 20) delete[] visited[i];
    delete[] visited;
  }
  return 0;
}