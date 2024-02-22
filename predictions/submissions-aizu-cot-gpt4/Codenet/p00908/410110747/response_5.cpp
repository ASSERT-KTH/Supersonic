#include "bits/stdc++.h"
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};
const int MAX_VALUE = 999999;
const int MAX_SIZE = 60;

struct aa {
  int x, y, turn;
};
struct bb {
  int kx, ky, opway, turn;
};

class Compare {
public:
  bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};

int memo2[MAX_SIZE][MAX_SIZE][4];

int getdis(const vector<vector<int>> &field, const int fx, const int fy, const int gx, const int gy) {
  int ans = MAX_VALUE;
  queue<aa> que;
  vector<vector<int>> memo(field.size(), vector<int>(field[0].size(), MAX_VALUE));
  que.push(aa{fx, fy, 0});
  // Remainder of getdis function...
}

int main() {
  while (1) {
    // Reset memo2 array to MAX_VALUE
    fill(&memo2[0][0][0], &memo2[0][0][0] + sizeof(memo2), MAX_VALUE);
    int H, W;
    cin >> H >> W;
    if (!H) break;

    vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
    priority_queue<bb, vector<bb>, Compare> que;

    // Remainder of main function...
    while (!que.empty()) {
      bb atop(que.top());
      que.pop();
      const int fkx = atop.kx;
      const int fky = atop.ky;
      const int fway = atop.opway;
      const int fturn = atop.turn;

      // Remainder of main function...
    }
    cout << ans << endl;
  }
  return 0;
}