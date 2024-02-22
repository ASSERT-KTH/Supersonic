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

inline void REP(int i, int a, int n) { for (i = a; i < n; i++) }
inline void rep(int i, int n) { REP(i, 0, n) }
inline auto all(auto &x) { return x.begin(), x.end(); }
inline auto rall(auto &x) { return x.rbegin(), x.rend(); }
inline void foreach(auto it, auto &x) { for (auto it = x.begin(); it != x.end(); it++) }

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int *bfscost[10];
char *field[16];
char *DP[9][9][9][9][9][9][9][9];

struct state {
  char x, y, cx[3], cy[3], Sc;
  state(char _x, char _y, char _cx[], char _cy[], char _Sc) {
    x = _x, y = _y, Sc = _Sc;
    cx[0] = _cx[0], cx[1] = _cx[1], cx[2] = _cx[2];
    cy[0] = _cy[0], cy[1] = _cy[1], cy[2] = _cy[2];
  }
  bool operator<(const state &a) const {
    switch (x) {
      case a.x:
        switch (y) {
          case a.y:
            switch (cx[0]) {
              case a.cx[0]:
                switch (cx[1]) {
                  case a.cx[1]:
                    switch (cx[2]) {
                      case a.cx[2]:
                        switch (cy[0]) {
                          case a.cy[0]:
                            switch (cy[1]) {
                              case a.cy[1]:
                                return cy[2] < a.cy[2];
                              default:
                                return cy[1] < a.cy[1];
                            }
                          default:
                            return cy[0] < a.cy[0];
                        }
                      default:
                        return cx[2] < a.cx[2];
                    }
                  default:
                    return cx[1] < a.cx[1];
                }
              default:
                return cx[0] < a.cx[0];
            }
          default:
            return y < a.y;
        }
      default:
        return x < a.x;
    }
  }
  bool operator==(const state &a) const {
    return (x == a.x && y == a.y && (cx[0] == a.cx[0] && cx[1] == a.cx[1] && cx[2] == a.cx[2]) && (cy[0] == a.cy[0] && cy[1] == a.cy[1] && cy[2] == a.cy[2]) && Sc == a.Sc);
  }
};

// Rest of the code remains same