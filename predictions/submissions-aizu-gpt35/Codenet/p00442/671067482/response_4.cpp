#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)

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

  queue<int> q;
  REP(i, n) {
    if (cnt[i] == 0) {
      q.push(i);
    }
  }

  vector<int> ans;
  while(!q.empty()) {
    int tar = q.front();
    q.pop();
    ans.push_back(tar + 1);
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0) {
        q.push(to);
      }
    }
  }

  if (ans.size() < n) {
    puts("1");
  } else {
    puts("0");
  }

  REP(i, ans.size()) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
