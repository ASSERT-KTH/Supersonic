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
int t, n;
int cnt;
int main() {
  while (cin >> t >> n, t) {
    vector<int> field(max, 1);
    int x, y, y_calc;
    rep(i, n) {
      cin >> x >> y;
      y_calc = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[zero + x + y_calc] = 0;
    }
    int sx, sy;
    cin >> sx >> sy;
    int sy_calc = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + sx + sy_calc] = 0;
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
          int ny_calc = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny_calc]) {
            field[zero + nx + ny_calc] = 0;
            rt.push(mp(mp(nx, cy + dy[i]), ct + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }
}