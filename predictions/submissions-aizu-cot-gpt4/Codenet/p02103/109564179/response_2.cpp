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

// ... rest of the code ... //

int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  g.reserve(k); // Add this line to preallocate the space for elements in unordered_map
  for (int i = 0; i < k; ++i) { // Use pre-increment
    scanf("%d%d", &x[i], &y[i]);
    g[(ll)y[i] * n + x[i]] = i;
  }
  int res = 2;
  res = min(res, bfs());
  res = min(res, bfs2());
  res = min(res, bfs3());
  res = min(res, bfs4());
  printf("%d\n", res);
  return 0;
}

// ... rest of the code ... //