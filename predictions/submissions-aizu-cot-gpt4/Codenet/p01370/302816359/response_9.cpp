#include <algorithm>
#include <cmath>
#include <cstdio>
#include <unordered_set>
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
unordered_set<int> field;
int t, n;
int main() {
  while (cin >> t >> n, t) {
    field.clear();
    int x, y, y_calc;
    rep(i, n) {
      cin >> x >> y;
      y_calc = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field.insert(zero + x + y_calc);
    }
    int sx, sy;
    cin >> sx >> sy;
    y_calc = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field.insert(zero + sx + y_calc);
    int ans = 0;
    queue<pair<int, pair<int, int>>> rt;
    rt.emplace(sx, make_pair(sy, 0));
    while (!rt.empty()) {
      ans++;
      auto cx = rt.front().first;
      auto cy = rt.front().second.first;
      auto ct = rt.front().second.second;
      rt.pop();
      if (ct < t) {
        rep(i, 6) {
          int nx = cx + dx[i];
          int ny_calc = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;
          if (field.count(zero + nx + ny_calc)) {
            field.erase(zero + nx + ny_calc);
            rt.emplace(nx, make_pair(cy + dy[i], ct + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }
}