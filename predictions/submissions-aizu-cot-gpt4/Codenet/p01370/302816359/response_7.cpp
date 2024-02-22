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

struct data {
    int x, y, t;
};

int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
vector<int> field(max);
int t, n;

int main() {
  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), 1);
    int x, y, index;
    rep(i, n) {
      cin >> x >> y;
      index = zero + x + y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[index] = 0;
    }
    cin >> x >> y;
    index = zero + x + y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
    field[index] = 0;
    int ans = 0;
    queue<data> rt;
    rt.push({x, y, 0});
    while (!rt.empty()) {
      data d = rt.front();
      rt.pop();
      ans++;
      if (d.t < t) {
        rep(i, 6) {
          int nx = d.x + dx[i];
          int ny = d.y + dy[i];
          int abs_ny = abs(ny);
          index = zero + nx + ny * (m_t * 2 + m_t * 2 + 1 - abs_ny) / 2;
          if (field[index]) {
            field[index] = 0;
            rt.push({nx, ny, d.t + 1});
          }
        }
      }
    }
    cout << ans << endl;
  }
}