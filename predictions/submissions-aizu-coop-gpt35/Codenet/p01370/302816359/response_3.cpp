#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define rep(i, b) for (int i = 0; i < b; i++)
constexpr int m_t = 60;
constexpr int max = 3 * m_t * (m_t + 1) + 1;
constexpr int zero = max / 2;
constexpr int dx[6] = {0, 1, -1, 1, -1, 0};
constexpr int dy[6] = {1, 1, 0, 0, -1, -1};

int main() {
  int t, n;
  int cnt;

  while (cin >> t >> n, t) {
    int field[max];
    fill(field, field + max, 1);

    int x, y;
    rep(i, n) {
      cin >> x >> y;
      int height = (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[zero + x + y] = 0;
    }

    int sx, sy;
    cin >> sx >> sy;
    x = sx;
    int height = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + x + y] = 0;

    int ans = 0;
    int cx[max], cy[max], ct[max];
    int front = 0, rear = 0;
    cx[rear] = sx;
    cy[rear] = sy;
    ct[rear] = 0;
    rear++;

    while (front < rear) {
      ans++;
      int currX = cx[front];
      int currY = cy[front];
      int currT = ct[front];
      front++;

      if (currT < t) {
        rep(i, 6) {
          int nx = currX + dx[i];
          int ny = (currY + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(currY + dy[i])) / 2;
          if (field[zero + nx + ny]) {
            field[zero + nx + ny] = 0;
            cx[rear] = nx;
            cy[rear] = currY + dy[i];
            ct[rear] = currT + 1;
            rear++;
          }
        }
      }
    }
    cout << ans << endl;
  }
}