#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
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
int cost[100001];
vector<int> adj[100001];
bool visited[100001];
void dfs(int u) {
  visited[u] = true;
  for (int v : adj[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}
int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x[i], &y[i]);
    adj[i].clear();
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= 2) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  memset(visited, false, sizeof(visited));
  dfs(0);
  if (visited[k - 1]) {
    printf("0\n");
    return 0;
  }
  bool flag = false;
  for (int i = 0; i < k; i++) {
    if (x[i] <= 1 || n - x[i] <= 2 || y[i] <= 1 || m - y[i] <= 2) {
      memset(visited, false, sizeof(visited));
      dfs(i);
      if (visited[0] && visited[k - 1]) {
        flag = true;
        break;
      }
    }
  }
  if (flag) {
    printf("1\n");
    return 0;
  }
  for (int i = 0; i < k; i++) {
    if (x[i] == 0 || x[i] == n - 1 || y[i] == 0 || y[i] == m - 1) {
      memset(visited, false, sizeof(visited));
      dfs(i);
      if (visited[0] && visited[k - 1]) {
        printf("1\n");
        return 0;
      }
    }
  }
  printf("2\n");
  return 0;
}