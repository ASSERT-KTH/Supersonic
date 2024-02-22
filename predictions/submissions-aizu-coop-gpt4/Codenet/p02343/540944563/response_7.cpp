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
#define MAX_N 10000
using namespace std;
int N;
int boss[MAX_N], height[MAX_N];
int get_boss(int id) {
  if (boss[id] == id)
    return id;
  else {
    return boss[id] = get_boss(boss[id]);
  }
}
int is_same(int x, int y) {
  int boss_x = get_boss(x);
  int boss_y = get_boss(y);
  return boss_x == boss_y;
}
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int Q, command, x, y;
  cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 1;
  }
  for (int i = 0; i < Q; i++) {
    cin >> command >> x >> y;
    if (command == 0) {
      unite(x, y);
    } else {
      if (is_same(x, y)) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    }
  }
  return 0;
}