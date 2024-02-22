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
int field[max];
int t, n;
int cnt;
int main() {
  while (cin >> t >> n, t) {
    fill(field, field + max, 1);
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
    rt.emplace(0, make_pair(sx, sy));
    while (!rt.empty()) {
      ans++;
      int cx = rt.front().second.first;
      int cy = rt.front().second.second;
      int ct = rt.front().first;
      rt.pop();
      if (ct < t) {
        rep(i, 6) {
          int nx = cx + dx[i];
          int ny = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.emplace(ct + 1, make_pair(nx, cy + dy[i]));
          }
        }
      }
    }
    cout << ans << endl;
  }
}