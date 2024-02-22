#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int w, h, Col;
typedef pair<int, int> C;
typedef vector<int> P;
P V;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;
P temp;

void calc(int y, int x) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (temp[y * w + x] == Col) {
    temp[y * w + x] = 0;
    res++;
    queue<C> Q;
    Q.push(make_pair(y, x));
    while (!Q.empty()) {
      C now = Q.front();
      Q.pop();
      for (int r = 0; r < 4; r++) {
        int ny = now.first + dy[r], nx = now.second + dx[r];
        if (ny < 0 || nx < 0 || ny >= h || nx >= w)
          continue;
        if (temp[ny * w + nx] == Col) {
          temp[ny * w + nx] = 0;
          Q.push(make_pair(ny, nx));
        }
      }
    }
  }
}

void on(P& N, int count, int c) {
  if (count == 5) {
    temp = N;
    res = 0;
    calc(0, 0);
    return;
  }
  int nc = N[0];
  queue<C> Q;
  Q.push(make_pair(0, 0));
  while (!Q.empty()) {
    C now = Q.front();
    Q.pop();
    N[now.first] = c;
    for (int r = 0; r < 4; r++) {
      int ny = now.first + dy[r], nx = now.second + dx[r];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w)
        continue;
      if (N[ny * w + nx] == nc)
        Q.push(make_pair(ny, nx));
    }
  }
  if (count != 4)
    for (int i = 1; i <= 6; i++)
      on(N, count + 1, i);
  else
    on(N, count + 1, Col);
}

void solve() {
  res = 0;
  V.clear();
  V.resize(h * w);
  for (int i = 0; i < h * w; i++) {
    cin >> V[i];
  }
  for (int i = 1; i <= 6; i++) {
    if (V[0] != i)
      on(V, 0, i);
  }
  cout << res << endl;
}

int main() {
  while (cin >> h >> w >> Col) {
    if (w == 0)
      break;
    solve();
  }
  return 0;
}