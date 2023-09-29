#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

typedef long long int ll;

#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001

using namespace std;

const int MAXN = 100005;

int N, Q;
int boss[MAXN], height[MAXN];

int get_boss(int id) {
  if (boss[id] == id) return id;
  return boss[id] = get_boss(boss[id]);
}

bool is_same(int x, int y) { return get_boss(x) == get_boss(y); }

void unite(int x, int y) {
  int boss_x = get_boss(x), boss_y = get_boss(y);
  if (boss_x == boss_y) return;
  if (height[boss_x] > height[boss_y])
    boss[boss_y] = boss_x;
  else {
    boss[boss_x] = boss_y;
    if (height[boss_x] == height[boss_y]) height[boss_y]++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> Q;

  for (int i = 0; i < N; i++) boss[i] = i, height[i] = 1;

  for (int i = 0; i < Q; i++) {
    int command, x, y;
    cin >> command >> x >> y;

    if (command == 0)
      unite(x, y);
    else if (is_same(x, y))
      cout << "1\n";
    else
      cout << "0\n";
  }

  return 0;
}