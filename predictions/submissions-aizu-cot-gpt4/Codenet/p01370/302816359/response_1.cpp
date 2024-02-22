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

int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};

struct Node{
    int x, y, t;
    Node(int _x, int _y, int _t): x(_x), y(_y), t(_t) {}
};

vector<int> field(max);
int t, n;

int main() {
  while (cin >> t >> n, t) {
    field = vector<int>(max, 1);
    rep(i, n) {
      int sx, sy;
      cin >> sx >> sy;
      sy = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
      field[zero + sx + sy] = 0;
    }
    int sx, sy;
    cin >> sx >> sy;
    sy = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + sx + sy] = 0;
    int ans = 0;
    queue<Node> rt;
    rt.push(Node(sx, sy, 0));
    while (!rt.empty()) {
      ans++;
      Node front = rt.front();
      rt.pop();
      if (front.t < t) {
        rep(i, 6) {
          int nx = front.x + dx[i];
          int temp = (front.y + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(front.y + dy[i])) / 2;
          if (field[zero + nx + temp]) {
            field[zero + nx + temp] = 0;
            rt.push(Node(nx, front.y + dy[i], front.t + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }
}