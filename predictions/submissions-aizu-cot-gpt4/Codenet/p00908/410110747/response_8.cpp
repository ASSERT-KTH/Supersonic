#include <array>
#include <queue>
#include <iostream>

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

int getdis(const array<array<int, 64>, 64>& field, int fx, int fy, int gx, int gy)
{
  int ans = 999999;
  queue<aa> que;
  array<array<int, 64>, 64> memo;
  que.push(aa{fx, fy, 0});
  
  // Other code remains the same.
}

class Compare {
public:
  bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};

array<array<array<int, 4>, 60>, 60> memo2;

int main() 
{
  // Other code remains the same.
}