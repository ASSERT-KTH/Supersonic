#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define REP(i, a, n) for (i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x)                                                         \
  for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
typedef long long ll;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int w, h, tatu_x[20], tatu_y[20], kazu_x[20], kazu_y[20];
int field[12][12], cx[36], cy[36], csize;
map<pair<int, int>, int> idx;
set<ll> visited[20][4][2];
bool inside(int x, int y) { return !(x < 0 || x >= w || y >= h || y < 0); }
bool backtrack(int cnt, ll kS, int init_dir, int f) {
  int i, j, k;
  if (visited[cnt][init_dir][f].count(kS))
    return false;
  if (csize / 2 == cnt)
    return true;
  rep(i, cnt) {
    rep(k, 4) {
      int tx = tatu_x[i] + dx[k];
      int ty = tatu_y[i] + dy[k];
    