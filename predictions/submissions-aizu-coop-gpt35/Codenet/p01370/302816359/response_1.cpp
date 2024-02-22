#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int m_t = 60;
const int max_size = 3 * m_t * (m_t + 1) + 1;
const int zero = max_size / 2;

int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};

int field[max_size];
int t, n;
int cnt;

int main() {
  while (cin >> t >> n, t) {
    memset(field, 1, sizeof(field));
    int x, y;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      y = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[zero + x + y] = 0;
    }
    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    y = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + x + y] = 0;
    int ans = 0;
    queue<pair<pair<int, int>, int>> rt;
    rt.push(make_pair(make_pair(sx, sy), 0));
    while (!rt.empty()) {
      ans++;
      int cx = rt.front().first.first;
      int cy = rt.front().first.second;
      int ct = rt.front().second;
      rt.pop();
      if (ct < t) {
        for (int i = 0; i < 6; i++) {
          int nx = cx + dx[i];
          int ny = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push(make_pair(make_pair(nx, cy + dy[i]), ct + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }
}