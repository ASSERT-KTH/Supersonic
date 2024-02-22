#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
typedef pair<int, int> pii;
int n, m;
vector<int> edge[5000];
int cnt[5000];
int main() {
  cin >> n >> m;
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }
  stack<int> ans;
  bool flag = false;
  queue<int> next;
  REP(i, n) if (cnt[i] == 0) next.push(i);
  ans.reserve(n);
  REP(i, n) {
    int tar = next.front();
    next.pop();
    ans.push(tar + 1);
    if (!next.empty())
      flag = true;
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0)
        next.push(to);
    }
  }
  while (!ans.empty()) {
    printf("%d\n", ans.top());
    ans.pop();
  }
  if (flag)
    puts("1");
  else
    puts("0");
  return 0;
}