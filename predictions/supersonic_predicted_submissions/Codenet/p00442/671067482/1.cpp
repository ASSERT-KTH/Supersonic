#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
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
  vector<int> ans;
  bool flag = false;
  vector<int> next;
  REP(i, n) if (cnt[i] == 0) next.push_back(i);
  REP(i, n) {
    int tar = next[next.size() - 1];
    ans.push_back(tar + 1);
    next.erase(next.end() - 1);
    if (next.size() > 0)
      flag = true;
    REP(j, edge[tar].size()) next.push_back(edge[tar][j]);
  }
  REP(i, ans.size()) printf("%d\n", ans[i]);
  if (flag)
    puts("1");
  else
    puts("0");
  return 0;
}
