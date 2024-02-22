#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, b) for (int i = 0; i < b; i++)
#define m_t 60
#define max (3 * m_t * (m_t + 1) + 1)
#define zero (max / 2)
#define mp make_pair
vector<int> field(max);
int t, n;
int cnt;

int calculate(int y) {
    return y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
}

int main() {
  int dx[6] = {0, 1, -1, 1, -1, 0};
  int dy[6] = {1, 1, 0, 0, -1, -1};

  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), 1);
    int x, y;
    rep(i, n) {
      cin >> x >> y;
      field[zero + x + calculate(y)] = 0;
    }
    int sx, sy;
    cin >> sx >> sy;
    field[zero + sx + calculate(sy)] = 0;
    int ans = 0;
    queue<pair<pair<int, int>, int>> rt;
    rt.push(mp(mp(sx, sy), 0));
    while (!rt.empty()) {
      ans++;
      int cx = rt.front().first.first;
      int cy = rt.front().first.second;
      int ct = rt.front().second;
      rt.pop();
      if (ct < t) {
        rep(i, 6) {
          int nx = cx + dx[i];
          int nextY = cy + dy[i];
          int ny = calculate(nextY);

          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push(mp(mp(nx, nextY), ct + 1));
          }
        }
      }
    }
    cout << ans << '\n';
  }
}