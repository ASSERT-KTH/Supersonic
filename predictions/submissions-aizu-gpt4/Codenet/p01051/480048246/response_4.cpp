#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> P;

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
const int way[4] = {-1, 1, -kMaxSize, kMaxSize};
const int kInf = 1 << 16;

char field[kMaxField];
vector<P> cost[kMaxField];
int d[kMaxField], R, C;

inline int xy2pos(const int x, const int y) { return x + y * kMaxSize; }

void initCost() {
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      if (field[pos] == kWall) continue;
      for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= kShotRange; j++) {
          int newpos = pos + j * way[i];
          if (field[newpos] == kWall) break;
          int addcost = (field[newpos] == kFriend) ? kCostFriendlyInk : (field[newpos] == kEnemy) ? kCostShot + kCostFriendlyInk : kCostBlank;
          int newcost = (j > 1) ? min(kCostShot + kCostFriendlyInk * j, cost[pos].empty() ? kInf : cost[pos].back().second + addcost) : addcost;
          cost[pos].emplace_back(newpos, newcost);
        }
      }
    }
  }
}

void dijkstra(int spos) {
  priority_queue<P, vector<P>, greater<P>> q;
  fill(d, d + kMaxField, kInf);
  d[spos] = 0;
  q.push(P(0, spos));
  while (!q.empty()) {
    P p = q.top(); q.pop();
    if (d[p.second] < p.first) continue;
    for (P& e : cost[p.second]) {
      if (d[e.first] > d[p.second] + e.second) {
        d[e.first] = d[p.second] + e.second;
        q.push(P(d[e.first], e.first));
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
      if (field[pos] == kStart) start = pos;
      else if (field[pos] == kGoal) goal = pos;
    }
  initCost();
  dijkstra(start);
  printf("%d\n", d[goal]);
  return 0;
}