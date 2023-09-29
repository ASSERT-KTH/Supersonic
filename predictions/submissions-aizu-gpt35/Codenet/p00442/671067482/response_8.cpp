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
  scanf("%d %d", &n, &m); // Using scanf instead of cin for faster input
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
  while(!next.empty()) { // Using while loop instead of REP for better performance
    int tar = next.back(); // Using back() instead of next[next.size() - 1] for better performance
    ans.push_back(tar + 1);
    next.pop_back(); // Using pop_back() instead of erase() for better performance
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0)
        next.push_back(to);
    }
  }
  REP(i, ans.size()) printf("%d\n", ans[i]);
  if (!next.empty()) // Using !next.empty() instead of next.size() > 0 for better performance
    puts("1");
  else
    puts("0");
  return 0;
}