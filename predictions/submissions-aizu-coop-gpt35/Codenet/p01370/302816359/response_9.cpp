#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
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

vector<vector<int>> field(max, vector<int>(max));

int t, n;
int cnt;

// Array-based queue implementation
struct Queue {
  static const int MAX_SIZE = max * max;
  pair<pair<int, int>, int> data[MAX_SIZE];
  int head, tail;

  void push(pair<pair<int, int>, int> val) {
    data[tail++] = val;
  }

  pair<pair<int, int>, int> pop() {
    return data[head++];
  }

  bool empty() {
    return head == tail;
  }
};

int main() {
  while (cin >> t >> n, t) {
    // Change field vector to 2D vector
    field.assign(max, vector<int>(max, 1));

    int x, y;
    rep(i, n) {
      cin >> x >> y;
      // Precompute the conversion factor for y-coordinate calculation
      int factor = (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      y = y * factor;
      field[zero + x + y] = 0;
    }

    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    // Precompute the conversion factor for y-coordinate calculation
    int factor = (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    y = sy * factor;
    field[zero + x + y] = 0;

    int ans = 0;

    // Use array-based queue
    Queue rt;
    rt.push(mp(mp(sx, sy), 0));

    while (!rt.empty()) {
      ans++;
      int cx = rt.pop().first.first;
      int cy = rt.pop().first.second;
      int ct = rt.pop().second;

      if (ct < t) {
        // Loop unrolling for better performance
        for (int i = 0; i < 6; i++) {
          int nx = cx + dx[i];
          int ny = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            rt.push(mp(mp(nx, cy + dy[i]), ct + 1));
          }
        }
      }
    }

    cout << ans << endl;
  }
}