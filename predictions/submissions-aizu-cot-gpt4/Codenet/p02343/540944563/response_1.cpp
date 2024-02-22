#include <iostream>
using namespace std;
#define MAX_N 100005
int N;
int boss[MAX_N], height[MAX_N];

int get_boss(int id) {
  if (boss[id] != id)
    boss[id] = get_boss(boss[id]);
  return boss[id];
}

bool is_same(int x, int y) { 
  return get_boss(x) == get_boss(y); 
}

void unite(int x, int y) {
  x = get_boss(x);
  y = get_boss(y);
  if (x == y)
    return;
  if (height[x] > height[y]) {
    boss[y] = x;
  } else if (height[x] < height[y]) {
    boss[x] = y;
  } else {
    boss[y] = x;
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
    height[i] = 0;
  }
  for (int i = 0; i < Q; i++) {
    cin >> command >> x >> y;
    if (command == 0) {
      unite(x, y);
    } else {
      if (is_same(x, y)) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    }
  }
  return 0;
}