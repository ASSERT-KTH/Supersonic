#include <queue>
#include <iostream>
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
int cnt;

int main() {
  while (cin >> t >> n, t) {
    // Initialize field vector to 1
    field.assign(field.size(), 1);

    int x, y;
    rep(i, n) {
      cin >> x >> y;
      y = y * (4 * m_t + 1 - abs(y)) / 2;
      field[zero + x + y] = 0;
    }

    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    y = sy * (4 * m_t + 1 - abs(sy)) / 2;
    field[zero + x + y] = 0;

    int ans = 0;
    queue<pair<pair<int, int>, int>> rt;
    rt.push({{sx, sy}, 0});

    while (!rt.empty()) {
      ans++;
      int cx = rt.front().first.first;
      int cy = rt.front().first.second;
      int ct = rt.front().second;
      rt.pop();
      if (ct < t) {
        rep(i, 6) {
          int nx = cx + dx[i];
          int ny = (cy + dy[i]) * (4 * m_t + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push({{nx, cy + dy[i]}, ct + 1});
          }
        }
      }
    }

    cout << ans << endl;
  }
}