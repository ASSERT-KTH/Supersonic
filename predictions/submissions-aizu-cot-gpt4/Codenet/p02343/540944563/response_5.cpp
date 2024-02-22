#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;

int get_boss(vector<int>& boss, int id) {
  if (boss[id] == id)
    return id;
  else {
    return boss[id] = get_boss(boss, boss[id]);
  }
}

bool is_same(vector<int>& boss, int x, int y) { return get_boss(boss, x) == get_boss(boss, y); }

void unite(vector<int>& boss, vector<int>& height, int x, int y) {
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
  int N, Q, command, x, y;
  cin >> N >> Q;
  vector<int> boss(N);
  vector<int> height(N, 1);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
  }
  for (int i = 0; i < Q; i++) {
    cin >> command >> x >> y;
    if (command == 0) {
      unite(boss, height, x, y);
    } else {
      if (is_same(boss, x, y)) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    }
  }
  return 0;
}