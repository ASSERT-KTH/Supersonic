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

vector<int> field(max);
int t, n;
int cnt;

struct Node {
    int x, y, t;
};

int main() {
  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), 1);
    int x, y, y_val;
    rep(i, n) {
      cin >> x >> y;
      y_val = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[zero + x + y_val] = 0;
    }
    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    y_val = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + x + y_val] = 0;
    int ans = 0;
    queue<Node> rt;
    rt.push({sx, sy, 0});
    while (!rt.empty()) {
      ans++;
      Node cur = rt.front();
      rt.pop();
      if (cur.t < t) {
        rep(i, 6) {
          int nx = cur.x + dx[i];
          int new_cy = cur.y + dy[i];
          int ny = new_cy * (m_t * 2 + m_t * 2 + 1 - abs(new_cy)) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push({nx, new_cy, cur.t + 1});
          }
        }
      }
    }
    cout << ans << endl;
  }
}