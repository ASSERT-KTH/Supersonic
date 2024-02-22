#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
typedef pair<int, int> pii;
int n, m;
vector<vector<pii>> edge; // Modified data structure
int main() {
  cin >> n >> m;
  edge.resize(n); // Resize the edge vector
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edge[a].push_back({b, 0}); // Initialize incoming edges as zero
    edge[b].back().second++; // Increment incoming edges count
  }
  vector<int> ans;
  bool flag = false;
  vector<int> next;
  REP(i, n) if (edge[i].empty()) next.push_back(i);
  REP(i, n) {
    int tar = next.back();
    ans.push_back(tar + 1);
    next.pop_back();
    if (!next.empty()) flag = true;
    for (int j = 0; j < edge[tar].size(); j += 2) { // Unrolling the inner loop
      int to1 = edge[tar][j].first;
      int to2 = edge[tar][j + 1].first;
      edge[to1][edge[tar][j].second].second--; // Decrement incoming edges count
      edge[to2][edge[tar][j + 1].second].second--; // Decrement incoming edges count
      if (edge[to1][edge[tar][j].second].second == 0) next.push_back(to1);
      if (edge[to2][edge[tar][j + 1].second].second == 0) next.push_back(to2);
    }
  }
  REP(i, ans.size()) printf("%d\n", ans[i]);
  if (flag)
    puts("1");
  else
    puts("0");
  return 0;
}