#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct Edge {
  int to, cost;
};

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

char field[kMaxField];
int way[4] = {-1, 1, -kMaxSize, kMaxSize};
const int kInf = 1 << 16;
int d[kMaxField];
vector<Edge> cost[kMaxField];
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
            if (field[newpos] == kFriend)
              cost[pos].push_back({newpos, kCostFriendlyInk});
            else if (field[newpos] == kEnemy)
              cost[pos].push_back({newpos, kCostShot + kCostFriendlyInk});
            else
              cost[pos].push_back({newpos, kCostBlank});
          } else {
            int newcost;
            if (field[newpos] == kFriend)
              newcost = min(kCostShot + kCostFriendlyInk * j,
                                 cost[pos].back().cost + kCostFriendlyInk);
            else if (field[newpos] == kEnemy)
              newcost = kCostShot + kCostFriendlyInk * j;
            else
              newcost = min(kCostShot + kCostFriendlyInk * j,
                                 cost[pos].back().cost + kCostBlank);
            cost[pos].push_back({newpos, newcost});
          }
        }
      }
    }
  }
}

void dijkstra(int spos) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  fill(d, d + kMaxField, kInf);
  d[spos] = 0;
  q.push(make_pair(0, spos));
  while (!q.empty()) {
    pair<int, int> p = q.top();
    q.pop();
    if (d[p.second] < p.first)
      continue;
    for (unsigned int i = 0; i < cost[p.second].size(); i++) {
      Edge e = cost[p.second][i];
      if (d[e.to] > d[p.second] + e.cost) {
        d[e.to] = d[p.second] + e.cost;
        q.push(make_pair(d[e.to], e.to));
      }
    }
  }
}

int main() {
  int start, goal;
  fill(field, field + kMaxField, '#');
  scanf("%d %d", &R, &C);
  for (int y = 1; y <= R; y++)
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      scanf(" %c", &field[pos]);
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