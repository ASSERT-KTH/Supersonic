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
    Node(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};

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
    x = sx;
    y = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + x + y] = 0;
    int ans = 0;
    queue<Node> rt;
    rt.push(Node(sx, sy, 0));
    while (!rt.empty()) {
      ans++;
      Node current_node = rt.front();
      rt.pop();
      if (current_node.t < t) {
        rep(i, 6) {
          int nx = current_node.x + dx[i];
          int cy = current_node.y + dy[i];
          int ny = cy * (m_t * 2 + m_t * 2 + 1 - abs(cy)) / 2; // Compute once and reuse
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push(Node(nx, cy, current_node.t + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }
}