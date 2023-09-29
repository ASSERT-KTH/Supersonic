#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define m_t 60
#define max (3 * m_t * (m_t + 1) + 1)
#define zero (max / 2)
int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
vector<int> field(max);
int t, n;
inline int getIndex(int x, int y) {
    return zero + x + y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), 1);
    int x, y;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      field[getIndex(x,y)] = 0;
    }
    cin >> x >> y;
    field[getIndex(x,y)] = 0;
    int ans = 0;
    queue<pair<int, int>> rt;
    rt.push({x, y});
    while (!rt.empty()) {
      ans++;
      x = rt.front().first;
      y = rt.front().second;
      rt.pop();
      if (ans < t) {
        for (int i = 0; i < 6; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          int idx = getIndex(nx,ny);
          if (field[idx]) {
            field[idx] = 0;
            rt.push({nx, ny});
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}