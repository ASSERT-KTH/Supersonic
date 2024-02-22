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
bool field[max][max];
int t, n;
int cnt;
int main() {
  while (cin >> t >> n, t) {
    memset(field, true, sizeof(field));
    int x, y;
    int y_factor = (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
    rep(i, n) {
      cin >> x >> y;
      field[x][y * y_factor] = false;
    }
    int sx, sy;
    cin >> sx >> sy;
    int y_factor_s = (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[sx][sy * y_factor_s] = false;
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
        // Direction 0
        int nx0 = cx + dx[0];
        int ny0 = (cy + dy[0]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[0])) / 2;
        if (field[nx0][ny0]) {
          field[nx0][ny0] = false;
          rt.push(mp(mp(nx0, cy + dy[0]), ct + 1));
        }
        // Direction 1
        int nx1 = cx + dx[1];
        int ny1 = (cy + dy[1]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[1])) / 2;
        if (field[nx1][ny1]) {
          field[nx1][ny1] = false;
          rt.push(mp(mp(nx1, cy + dy[1]), ct + 1));
        }
        // Direction 2
        int nx2 = cx + dx[2];
        int ny2 = (cy + dy[2]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[2])) / 2;
        if (field[nx2][ny2]) {
          field[nx2][ny2] = false;
          rt.push(mp(mp(nx2, cy + dy[2]), ct + 1));
        }
        // Direction 3
        int nx3 = cx + dx[3];
        int ny3 = (cy + dy[3]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[3])) / 2;
        if (field[nx3][ny3]) {
          field[nx3][ny3] = false;
          rt.push(mp(mp(nx3, cy + dy[3]), ct + 1));
        }
        // Direction 4
        int nx4 = cx + dx[4];
        int ny4 = (cy + dy[4]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[4])) / 2;
        if (field[nx4][ny4]) {
          field[nx4][ny4] = false;
          rt.push(mp(mp(nx4, cy + dy[4]), ct + 1));
        }
        // Direction 5
        int nx5 = cx + dx[5];
        int ny5 = (cy + dy[5]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[5])) / 2;
        if (field[nx5][ny5]) {
          field[nx5][ny5] = false;
          rt.push(mp(mp(nx5, cy + dy[5]), ct + 1));
        }
      }
    }
    cout << ans << endl;
  }
}