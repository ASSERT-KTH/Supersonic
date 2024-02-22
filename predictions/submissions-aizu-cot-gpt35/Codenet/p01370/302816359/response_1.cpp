#include <iostream>
#include <set>
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

int main() {
  int t, n;
  while (cin >> t >> n, t) {
    vector<int> field(max, 1);
    
    set<pair<int, int>> points;
    int x, y;
    rep(i, n) {
      cin >> x >> y;
      int range = m_t * 2 + m_t * 2 + 1;
      y = y * (range - abs(y)) / 2;
      points.insert(mp(x, y));
    }
    
    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    int range = m_t * 2 + m_t * 2 + 1;
    y = sy * (range - abs(sy)) / 2;
    points.insert(mp(x, y));
    
    int visited = 0;
    queue<pair<int, int>> rt;
    rt.push(mp(sx, sy));
    while (!rt.empty()) {
      visited++;
      int cx = rt.front().first;
      int cy = rt.front().second;
      rt.pop();
      if (visited <= t) {
        rep(i, 6) {
          int nx = cx + dx[i];
          int ny = (cy + dy[i]) * (range - abs(cy + dy[i])) / 2;
          if (points.find(mp(nx, ny)) == points.end()) {
            points.insert(mp(nx, ny));
            rt.push(mp(nx, cy + dy[i]));
          }
        }
      }
    }
    cout << visited << endl;
  }
}