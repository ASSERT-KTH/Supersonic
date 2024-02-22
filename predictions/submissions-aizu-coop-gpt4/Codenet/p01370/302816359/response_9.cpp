#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, b) for (int i = 0; i < b; i++)
#define m_t 60
#define max (3 * m_t * (m_t + 1) + 1)
#define zero (max / 2)
#define mp make_pair
int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};

struct Node {
  int x, y, t;
};

int main() {
  int t, n;
  while (cin >> t >> n, t) {
    vector<int> field(max, 1);
    int x, y;
    rep(i, n) {
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
    deque<Node> rt;
    rt.push_back({sx, sy, 0});
    while (!rt.empty()) {
      ans++;
      Node node = rt.front();
      rt.pop_front();
      if (node.t < t) {
        rep(i, 6) {
          int nx = node.x + dx[i];
          int ny = (node.y + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(node.y + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push_back({nx, node.y + dy[i], node.t + 1});
          }
        }
      }
    }
    cout << ans << endl;
  }
}