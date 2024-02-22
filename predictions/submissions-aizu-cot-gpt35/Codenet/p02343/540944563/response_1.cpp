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

int get_boss(std::vector<int>& boss, int id) {
  std::stack<int> stack;
  while (boss[id] != id) {
    stack.push(id);
    id = boss[id];
  }
  while (!stack.empty()) {
    boss[stack.top()] = id;
    stack.pop();
  }
  return id;
}

int is_same(std::vector<int>& boss, int x, int y) {
  return get_boss(boss, x) == get_boss(boss, y);
}

void unite(std::vector<int>& boss, std::vector<int>& height, int x, int y) {
  int boss_x = get_boss(boss, x);
  int boss_y = get_boss(boss, y);
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
  int N;
  int Q, command, x, y;
  scanf("%d %d", &N, &Q);
  std::vector<int> boss(N);
  std::vector<int> height(N);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 1;
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    if (command == 0) {
      unite(boss, height, x, y);
    } else {
      if (is_same(boss, x, y)) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    }
  }
  return 0;
}