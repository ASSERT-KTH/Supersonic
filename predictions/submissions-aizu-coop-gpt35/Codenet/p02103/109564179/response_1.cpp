#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unordered_set>
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
unordered_set<ll> g;
int cost[100001];

int bfs(int startX, int startY) {
  queue<int> que;
  queue<int> que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  
  for (int i = 1; i <= startX - 1; i++) {
    ll val = (ll)i * n;
    if (g.count(val)) {
      que.push(g[val]);
      cost[g[val]] = 0;
    }
  }
  
  while (!que.empty()) {
    int q = que.front();
    que.pop();