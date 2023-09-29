#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
typedef pair<int, int> pii;
const int MAXN = 5000;
int n, m;
vector<int> edge[MAXN];
int cnt[MAXN];
int ans[MAXN];
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
  int ptr = 0;
  REP(i, n) {
    if (cnt[i] == 0) {
      ans[ptr++] = i;
    }
  }
  int start = 0, end = ptr;
  while (start < end) {
    int u = ans[start++];
    for (auto v : edge[u]) {
      if (--cnt[v] == 0) {
        ans[ptr++] = v;
      }
    }
  }
  REP(i, ptr) printf("%d\n", ans[i] + 1);
  if (ptr < n) puts("1");
  else puts("0");
  return 0;
}