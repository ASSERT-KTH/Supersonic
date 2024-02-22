#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m, k;
int x[100001], y[100001];
unordered_map<ll, int> g;
int cost[100001];

int bfs(int start_x, int start_y, int end_x, int end_y) {
// rest of the code
}

int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  memset(cost, -1, sizeof(cost));
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x[i], &y[i]);
    g[(ll)y[i] * n + x[i]] = i;
  }
  int res = 2;
  res = min(res, bfs(1, m-1, n-1, m-1));
  res = min(res, bfs(1, 0, n-1, 0));
  res = min(res, bfs(0, m-2, 0, 0));
  res = min(res, bfs(n-1, m-2, n-1, 0));
  printf("%d\n", res);
  return 0;
}