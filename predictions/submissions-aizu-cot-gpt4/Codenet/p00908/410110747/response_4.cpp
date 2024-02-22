#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

const int MAX_DISTANCE = 999999;
const int MAX_SIZE = 60;
const int DIRECTION_COUNT = 4;

const int dx[DIRECTION_COUNT] = {-1, 0, 1, 0};
const int dy[DIRECTION_COUNT] = {0, 1, 0, -1};
const int dx2[DIRECTION_COUNT] = {-1, 0, 2, 1};
const int dy2[DIRECTION_COUNT] = {0, 2, 1, -1};

struct aa {
  int x;
  int y;
  int turn;
  aa(int x, int y, int turn) : x(x), y(y), turn(turn) {} // Using initialization list
};

struct bb {
  int kx;
  int ky;
  int opway;
  int turn;
  bb(int kx, int ky, int opway, int turn) : kx(kx), ky(ky), opway(opway), turn(turn) {} // Using initialization list
};

class Compare {
public:
  bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};

int memo2[MAX_SIZE][MAX_SIZE][DIRECTION_COUNT];

// ... the rest of the program remains unchanged ...