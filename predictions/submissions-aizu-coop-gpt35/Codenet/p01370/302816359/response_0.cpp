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
#define MAX_FIELD_SIZE (3 * m_t * (m_t + 1) + 1)
#define ZERO_INDEX (MAX_FIELD_SIZE / 2)
#define MAX_NEIGHBORS 6

int dx[MAX_NEIGHBORS] = {0, 1, -1, 1, -1, 0};
int dy[MAX_NEIGHBORS] = {1, 1, 0, 0, -1, -1};

int field[MAX_FIELD_SIZE];
int t, n;
int cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> t >> n, t) {
    memset(field, 1, sizeof(field));

    int x, y;
    rep(i, n) {
      cin >> x >> y;
      y = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[ZERO_INDEX + x + y] = 0;
    }

    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    y = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[ZERO_INDEX + x + y] = 0;

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
        for (int i = 0; i < MAX_NEIGHBORS; i++) {
          int nx = cx + dx[i];
          int ny = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;
          if (field[ZERO_INDEX + nx + ny]) {
            field[ZERO_INDEX + nx + ny] = 0;
            rt.push(make_pair(make_pair(nx, cy + dy[i]), ct + 1));
          }
        }
      }
    }

    cout << ans << endl;
  }
}