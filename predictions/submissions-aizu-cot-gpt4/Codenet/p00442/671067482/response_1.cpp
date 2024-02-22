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
  int nextSize = next.size();
  REP(i, n) {
    int tar = next[nextSize - 1];
    ans.push_back(tar + 1);
    nextSize--;
    if (nextSize > 0)
      flag = true;
    int edgeSize = edge[tar].size();
    vector<int> tempNext;
    REP(j, edgeSize) {
      int to = edge[tar][j];
      cnt[to]--;
      if (cnt[to] == 0)
        tempNext.push_back(to);
    }
    next.insert(next.end(), tempNext.begin(), tempNext.end());
  }
  REP(i, ans.size()) printf("%d\n", ans[i]);
  if (flag)
    puts("1");
  else
    puts("0");
  return 0;
}