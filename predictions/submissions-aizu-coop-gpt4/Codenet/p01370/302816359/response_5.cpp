#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
#define rep(i, b) for (int i = 0; i < b; i++)
#define m_t 60
#define max (3 * m_t * (m_t + 1) + 1)
#define zero (max / 2)
#define mp make_pair
int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
set<int> visited;
unordered_map<pair<int, int>, int> coord_to_index;
int t, n;
int cnt;
int main() {
  while (cin >> t >> n, t) {
    visited.clear();
    coord_to_index.clear();
    int x, y;
    rep(i, n) {
      cin >> x >> y;
      if (coord_to_index.find(mp(x, y)) == coord_to_index.end())
        coord_to_index[mp(x, y)] = zero + x + y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      visited.insert(coord_to_index[mp(x, y)]);
    }
    int sx, sy;
    cin >> sx >> sy;
    if (coord_to_index.find(mp(sx, sy)) == coord_to_index.end())
        coord_to_index[mp(sx, sy)] = zero + sx + sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    visited.insert(coord_to_index[mp(sx, sy)]);
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
          if (coord_to_index.find(mp(nx, ny)) == coord_to_index.end())
            coord_to_index[mp(nx, ny)] = zero + nx + ny * (m_t * 2 + m_t * 2 + 1 - abs(ny)) / 2;
          if (visited.find(coord_to_index[mp(nx, ny)]) == visited.end()) {
            visited.insert(coord_to_index[mp(nx, ny)]);
            rt.push(mp(mp(nx, ny), ct + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }
}