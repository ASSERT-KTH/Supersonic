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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }
  vector<int> ans(n);
  int l = 0;
  int r = n - 1;
  REP(i, n) {
    int tar = -1;
    REP(j, n) {
      if (cnt[j] == 0) {
        tar = j;
        break;
      }
    }
    if (tar == -1) break;
    ans[l++] = tar + 1;
    cnt[tar] = -1;
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      cnt[to]--;
    }
  }
  REP(i, l) printf("%d\n", ans[i]);
  if (l < n) puts("1");
  else puts("0");
  return 0;
}