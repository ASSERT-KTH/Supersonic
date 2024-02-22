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
#include <array>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int W, H, sx, sy, gx, gy;
int bfscost[10][10];
char csize, wsize, wx[3], wy[3];
std::array<char, 3> cx, cy;
char field[16][16];
char DP[9][9][9][9][9][9][9][9];

// ... rest of the code ...

int main() {
  while (scanf("%d%d", &H, &W), H | W) {
    csize = wsize = 0;
    std::fill(std::begin(DP), std::end(DP), -1);
    cx.fill(0);
    cy.fill(0);
    input();
    int res = INT_MAX;
    priority_queue<pair<int, state>, vector<pair<int, state>>,
                   greater<pair<int, state>>>
        q;
    q.emplace(0, state(sx, sy, cx.data(), cy.data(), 0));
    DP[cx[0]][cy[0]][cx[1]][cy[1]][cx[2]][cy[2]][sx][sy] = 0;
    
    // ... rest of the code ...
  }
  return 0;
}