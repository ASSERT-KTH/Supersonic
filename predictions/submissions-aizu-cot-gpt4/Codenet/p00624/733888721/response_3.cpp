#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define REP(i, a, n) for (i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
char field[16][16];
char DP[9][9][9][9][9][9][9][9];
struct state {
  char x, y, cx[3], cy[3], Sc;
  state(char _x, char _y, char _cx[], char _cy[], char _Sc) {
    x = _x, y = _y, Sc = _Sc;
    cx[0] = _cx[0], cx[1] = _cx[1], cx[2] = _cx[2];
    cy[0] = _cy[0], cy[1] = _cy[1], cy[2] = _cy[2];
  }
  bool operator<(const state &a) const {
    if (x != a.x)
      return x < a.x;
    if (y != a.y)
      return y < a.y;
    if (cx[0] != a.cx[0])
      return cx[0] < a.cx[0];
    if (cx[1] != a.cx[1])
      return cx[1] < a.cx[1];
    if (cx[2] != a.cx[2])
      return cx[2] < a.cx[2];
    if (cy[0] != a.cy[0])
      return cy[0] < a.cy[0;
    if (cy[1] != a.cy[1])
      return cy[1] < a.cy[1];
    if (cy[2] != a.cy[2])
      return cy[2] < a.cy[2];
    return Sc < a.Sc;
  }
  bool operator==(const state &a) const {
    return (x == a.x && y == a.y &&
            (cx[0] == a.cx[0] && cx[1] == a.cx[1] && cx[2] == a.cx[2]) &&
            (cy[0] == a.cy[0] && cy[1] == a.cy[1] && cy[2] == a.cy[2]) &&
            Sc == a.Sc);
  }
};
// Rest of the code...
// The code is already optimized and any further optimization may lead to unnecessary complexity.