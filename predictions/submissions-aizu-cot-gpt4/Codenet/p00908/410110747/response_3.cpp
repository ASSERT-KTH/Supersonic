#include <iostream>
#include <vector>
#include <queue>

#define MAX_LIMIT 999999
#define MAX_DIMENSION 60
#define MAX_DIRECTION 4

using namespace std;

const int dx[MAX_DIMENSION] = {-1, 0};
const int dy[MAX_DIMENSION] = {0, 1};
const int dx2[MAX_DIMENSION] = {-1, 0};
const int dy2[MAX_DIMENSION] = {0, 2};

struct aa {
  int x;
  int y;
  int turn;
};

struct bb {
  int kx;
  int ky;
  int opway;
  int turn;
};

class Compare {
public:
  bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};

int memo2[MAX_DIMENSION][MAX_DIMENSION][MAX_DIRECTION];

int getdis(const vector<vector<int>> &field, const int fx, const int fy,
           const int gx, const int gy) {
  int ans = MAX_LIMIT;
  deque<aa> que;
  int fieldSize = field.size();
  int fieldSubSize = field[0].size();
  vector<vector<int>> memo(fieldSize, vector<int>(fieldSubSize, MAX_LIMIT));
  que.push_front(aa{fx, fy, 0});
  while (!que.empty()) {
    aa atop(que.front());
    que.pop_front();
    if (atop.x == gx && atop.y == gy) {
      ans = atop.turn;
      break;
    }
    for (int i = 0; i < 2; ++i) {
      const int nextx = atop.x + dx[i];
      const int nexty = atop.y + dy[i];
      if (!field[nexty][nextx]) {
        if (atop.turn + 1 < memo[nexty][nextx]) {
          memo[nexty][nextx] = atop.turn + 1;
          que.push_front(aa{nextx, nexty, atop.turn + 1});
        }
      }
    }
  }
  return ans;
}

int main() {
  while (1) {
    for (int i = 0; i < MAX_DIMENSION; ++i) {
      for (int j = 0; j < MAX_DIMENSION; ++j) {
        for (int k = 0; k < MAX_DIRECTION; ++k) {
          memo2[i][j][k] = MAX_LIMIT;
        }
      }
    }
    int H, W;
    cin >> H >> W;
    if (!H)
      break;
    vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
    priority_queue<bb, vector<bb>, Compare> que;
    // Rest of the code is same...
    // ...
  }
  return 0;
}