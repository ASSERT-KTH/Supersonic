#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define m_t 60
#define max (3 * m_t * (m_t + 1) + 1)
#define zero (max / 2)
#define mp make_pair
int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
int main() {
  int t, n;
  while (cin >> t >> n, t) {
    vector<int> field(max, 1);
    int x, y;
    for(int i = 0; i < n; i++) {
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
    queue<pair<int, int>> rt;
    rt.push(mp(sx, sy));
    for (int ct = 0; ct < t && !rt.empty(); ct++) {
      int len = rt.size();
      for(int i = 0; i < len; i++){
        ans++;
        int cx = rt.front().first;
        int cy = rt.front().second;
        rt.pop();
        for(int i = 0; i < 6; i++) {
          int nx = cx + dx[i];
          int ny = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push(mp(nx, cy + dy[i]));
          }
        }
      }
    }
    cout << ans << endl;
  }
}