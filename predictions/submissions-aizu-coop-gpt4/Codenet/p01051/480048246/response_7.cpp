#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

struct Edge {
  int to, cost;
};

typedef std::pair<int, int> P;

const int kMaxSize = 32;
const int kMaxField = kMaxSize * kMaxSize;
const int kCostFriendlyInk = 1;
const int kCostShot = 2;
const int kCostBlank = 2;
const int kShotRange = 3;
const char kWall = '#';
const char kFriend = 'o';
const char kEnemy = 'x';
const char kStart = 'S';
const char kGoal = 'G';
const char kBlank = '.';
const int kInf = 1 << 16;

char field[kMaxField];
int way[4] = {-1, 1, -kMaxSize, kMaxSize};
int d[kMaxField];

std::vector<std::vector<Edge>> cost(kMaxSize, std::vector<Edge>(kMaxSize)); // Changed to 2D vector
int R, C;

inline int xy2pos(const int x, const int y) { return x + y * kMaxSize; }

void initCost() {
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      if (field[pos] == kWall)
        continue;

      for (int i = 0; i < 4; i++) {
        int newpos = pos + way[i];
        if (field[newpos] == kWall)
          continue;
        int newcost = kInf;
        if (field[newpos] == kFriend)
          newcost = kCostFriendlyInk;
        else if (field[newpos] == kEnemy)
          newcost = kCostShot + kCostFriendlyInk;
        else
          newcost = kCostBlank;
        cost[y][x] = {newpos, newcost}; // store the cost directly into the 2D vector
      }
    }
  }
}

void dijkstra(int spos) {
  std::priority_queue<P, std::vector<P>, std::greater<P>> q;
  std::fill(d, d + kMaxField, kInf);
  d[spos] = 0;
  q.push(P(0, spos));
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    if (d[p.second] < p.first)
      continue;

    int x = p.second % kMaxSize;
    int y = p.second / kMaxSize;
    Edge e = cost[y][x]; // access the cost directly from the 2D vector

    if (d[e.to] > d[p.second] + e.cost) {
      d[e.to] = d[p.second] + e.cost;
      q.push(P(d[e.to], e.to));
    }
  }
}

int main() {
  int start, goal;
  std::fill(field, field + kMaxField, '#');
  std::scanf("%d %d", &R, &C);
  for (int y = 1; y <= R; y++)
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      std::scanf(" %c", &field[pos]);
      if (field[pos] == kStart)
        start = pos;
      else if (field[pos] == kGoal)
        goal = pos;
    }
  initCost();
  dijkstra(start);
  printf("%d\n", d[goal]);
  return 0;
}