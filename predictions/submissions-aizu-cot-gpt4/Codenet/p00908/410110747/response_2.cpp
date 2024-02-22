#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};

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

int memo2[60][60][4];

int getdis(const vector<vector<int>> &field, const int fx, const int fy, const int gx, const int gy) {
  int ans = numeric_limits<int>::max();
  queue<aa> que;
  vector<vector<int>> memo(field.size(), vector<int>(field[0].size(), numeric_limits<int>::max()));
  que.push(aa{fx, fy, 0});
  // ... remaining code
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // ... remaining code
}