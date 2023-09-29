#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define REP(i, a, n) for (i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x)                                                         \
  for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int W, H, sx, sy, gx, gy;
int bfscost[10][10];
char csize, wsize, wx[3], wy[3], cx[3], cy[3];
char field[16][16];
char DP[9][9][9][9][9][9][9][9];
struct state {
  char x, y, cx[3], cy[3], Sc;
  state(char _x, char _y, char _cx[], char _cy[], char _Sc) {
    x = _x, y = _y, Sc = _sc;
    cx[0] = _cx[0], cx[1] = _cx[1], cx[2] = _cx[2];
    cy[0]