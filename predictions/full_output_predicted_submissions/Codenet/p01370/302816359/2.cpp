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
int main() {
  while (scanf("%d%d", &t, &n), t) {
    fill(field.begin(), field.end(), 1);
    int x, y;
    rep(i, n) {
      scanf("%d%d", &x, &y);
      y = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
      field[zero + x + y] = 0;
    }
    int sx, sy;
    scanf("%d%d", &sx, &sy);
    x = sx;
    y = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
    field[zero + x + y] = 0;
    int ans = 0;
    queue<pair<pair<int, int>, int>> rt;
    rt.push(mp(mp(sx, sy), 0));
    while (!rt.empty()) {
      ans++;
      int cx = rt.front().first.first;
      int cy = rt.front().first.second;
    