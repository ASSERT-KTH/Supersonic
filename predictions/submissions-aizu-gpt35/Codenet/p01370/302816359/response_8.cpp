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
int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
vector<bool> field(max, true);
int t, n;
int cnt;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), true);
    int x, y;
    rep(i, n) {
      cin >> x >> y;
      y = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[zero + x + y] = false;
    }
    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    y = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + x + y] = false;
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
          int ny = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = false;
            rt.push(mp(mp(nx, cy + dy[i]), ct + 1));
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}