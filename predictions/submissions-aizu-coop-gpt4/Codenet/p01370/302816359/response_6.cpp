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

struct Node {
    int x;
    int y;
    int t;
};

int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
vector<int> field(max);
int t, n;
int main() {
  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), 1);
    int x, y;
    rep(i, n) {
      cin >> x >> y;
      y = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[zero + x + y] = 0;
    }
    int sx, sy;
    cin >> sx >> sy;
    y = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + sx + y] = 0;
    int ans = 0;
    queue<Node> rt;
    rt.push({sx, sy, 0});
    while (!rt.empty()) {
      ans++;
      Node current = rt.front();
      rt.pop();
      if (current.t < t) {
        rep(i, 6) {
          int nx = current.x + dx[i];
          int ny = (current.y + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(current.y + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push({nx, current.y + dy[i], current.t + 1});
          }
        }
      }
    }
    cout << ans << endl;
  }
}