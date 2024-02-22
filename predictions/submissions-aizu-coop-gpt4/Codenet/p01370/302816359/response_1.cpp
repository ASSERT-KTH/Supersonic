#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define rep(i, b) for (int i = 0; i < b; i++)
constexpr int m_t = 60;
constexpr int max = 3 * m_t * (m_t + 1) + 1;
constexpr int zero = max / 2;
int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
vector<int> field(max);
int t, n;

int main() {
  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), 1);
    int x, y;
    rep(i, n) {
      cin >> x >> y;
      y = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[zero + x + y] = 0;
    }
    int sx, sy;
    cin >> sx >> sy;
    y = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + sx + y] = 0;
    int ans = 0;
    queue<pair<int, pair<int, int>>> rt;
    rt.push({sx, {sy, 0}});
    while (!rt.empty()) {
      ans++;
      int cx = rt.front().first;
      int cy = rt.front().second.first;
      int ct = rt.front().second.second;
      rt.pop();
      if (ct < t) {
        rep(i, 6) {
          int nx = cx + dx[i];
          int ny = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push({nx, {cy + dy[i], ct + 1}});
          }
        }
      }
    }
    cout << ans << endl;
  }
}