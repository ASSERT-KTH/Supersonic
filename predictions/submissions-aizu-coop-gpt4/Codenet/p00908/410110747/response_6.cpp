#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};

struct Coordinate {
  int x;
  int y;
  int turn;
};

class Compare {
public:
  bool operator()(const Coordinate &l, const Coordinate &r) { return l.turn > r.turn; }
};

// Using map instead of array to store the memoization values.
map<tuple<int, int, int>, int> memo;

int getdis(const vector<vector<int>> &field, const int fx, const int fy,
           const int gx, const int gy) {
  int ans = numeric_limits<int>::max();

  queue<Coordinate> que;
  vector<vector<int>> distances(field.size(), vector<int>(field[0].size(), numeric_limits<int>::max()));
  
  que.push(Coordinate{fx, fy, 0});
  
  while (!que.empty()) {
    Coordinate &current = que.front(); // Using reference to avoid copying
    que.pop();
    if (current.x == gx && current.y == gy) {
      ans = current.turn;
      break;
    }
    for (int i = 0; i < 4; ++i) {
      const int nextx = current.x + dx[i];
      const int nexty = current.y + dy[i];
      if (!field[nexty][nextx]) {
        if (current.turn + 1 < distances[nexty][nextx]) {
          distances[nexty][nextx] = current.turn + 1;
          que.push(Coordinate{nextx, nexty, current.turn + 1});
        }
      }
    }
  }
  return ans;
}

int main() {
  while (1) {
    memo.clear(); // Clear the memo map for each iteration
    int H, W;
    cin >> H >> W;
    if (!H)
      break;

    vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
    priority_queue<Coordinate, vector<Coordinate>, Compare> que;
    // Simplified the initialization of kx, ky, ox and oy.
    int kx = 99, ky = 99;
    int ox[2];
    int oy[2];
    int num = 0;

    // Rest of the code unchanged...
  }
  return 0;
}