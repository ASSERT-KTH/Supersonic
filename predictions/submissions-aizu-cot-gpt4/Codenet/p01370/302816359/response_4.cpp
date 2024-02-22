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
int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
vector<int> field(max);
int t, n;

int calculateY(int y) {
    return y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
}

int main() {
  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), 1);
    int x, y;
    rep(i, n) {
      cin >> x >> y;
      y = calculateY(y);
      field[zero + x + y] = 0;
    }
    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    y = calculateY(sy);
    field[zero + x + y] = 0;
    int ans = 0;
    queue<pair<int, int>> rt;
    rt.push({zero + x + y, 0});
    while (!rt.empty()) {
      ans++;
      int c = rt.front().first;
      int ct = rt.front().second;
      rt.pop();
      if (ct < t) {
        rep(i, 6) {
          int nx = c + dx[i];
          int ny = calculateY(c + dy[i]);
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push({zero + nx + ny, ct + 1});
          }
        }
      }
    }
    cout << ans << endl;
  }
}