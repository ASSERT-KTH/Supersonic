#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;
int N;
vector<int> boss, height;
int get_boss(int id) {
  vector<int> path;
  while (boss[id] != id) {
    path.push_back(id);
    id = boss[id];
  }
  for (int i : path) {
    boss[i] = id;
  }
  return id;
}
int is_same(int x, int y) { return get_boss(x) == get_boss(y); }
void unite(int x, int y) {
  int boss_x = get_boss(x);
  int boss_y = get_boss(y);
  if (boss_x == boss_y)
    return;
  if (height[x] > height[y]) {
    boss[boss_y] = boss_x;
  } else if (height[x] < height[y]) {
    boss[boss_x] = boss_y;
  } else {
    boss[boss_y] = boss_x;
    height[x]++;
  }
}
int main() {
  int Q, command, x, y;
  scanf("%d %d", &N, &Q);
  boss.resize(N);
  height.resize(N);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 1;
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    if (command == 0) {
      unite(x, y);
    } else {
      if (is_same(x, y)) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    }
  }
  return 0;
}