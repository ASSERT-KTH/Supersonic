#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
typedef struct {
  int to, cost;
} Edge;
typedef std::pair<int, int> P;
const int kMaxSize = 32;
const int kMaxField = kMaxSize * kMaxSize;
const int kCostFriendlyInk = 1;
const int kCost shot = 2;
const int kCostBlank = 2;
const int kShotRange = 3;
const char kWall = '#';
const char kFriend = 'o';
const char kStart = 'S';
const char kGoal = 'G';
const char kBlank = '.';
char field[kMaxField];
int way[4] = {-1, 1, -kMaxSize, kMaxSize};
const int kInf = 1 << 16;
int d[kMaxField];
std::vector<Edge> cost[kMaxField];
int R, C;
inline int xy2pos(const int x, const int y) { return x + y * kMaxSize; }
void initCost() {
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      if (field[pos] == kWall)
        continue;
      for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= kShotRange; j++) {
          int newpos = pos + j * way[i];
          if (field[newpos] == kWall)
            break;
          if (j == 1) {
            d[newpos] = d[