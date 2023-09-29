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
constexpr int max_size = 3 * m_t * (m_t + 1) + 1;
constexpr int zero = max_size / 2;
#define mp make_pair
int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
vector<int> field(max_size);
int t, n;

inline int encode(int x, int y) {
  return zero + x + y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), 1);
    int x, y;
    rep(i, n) {
      cin >> x >> y;
      field[encode(x, y)] = 0;
    }

    int sx, sy;
    cin >> sx >> sy;
    field[encode(sx, sy)] = 0;

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
          int ny = cy + dy[i];
          if (ny < -m_t || ny > m_t) {
            continue;
          }
          int en = encode(nx, ny);
          if (field[en]) {
            field[en] = 0;
            rt.push(mp(mp(nx, ny), ct + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }
}