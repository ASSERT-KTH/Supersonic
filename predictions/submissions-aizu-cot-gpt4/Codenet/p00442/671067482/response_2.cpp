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
    edge[a].emplace_back(b);
    cnt[b]++;
  }
  vector<int> ans;
  ans.reserve(n); // Reserve space for 'n' elements
  bool flag = false;
  vector<int> next;
  next.reserve(n); // Reserve space for 'n' elements
  REP(i, n) if (cnt[i] == 0) next.emplace_back(i);
  REP(i, n) {
    int tar = next.back(); // Get the last element
    ans.emplace_back(tar + 1);
    next.pop_back(); // Remove the last element
    if (!next.empty())
      flag = true;
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0) // Use prefix decrement
        next.emplace_back(to);
    }
  }
  REP(i, ans.size()) printf("%d\n", ans[i]);
  if (flag)
    puts("1");
  else
    puts("0");
  return 0;
}