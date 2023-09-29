#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5000;

int n, m;
vector<int> edge[MAXN];
int cnt[MAXN];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0, a, b; i < m; i++) {
    scanf("%d %d", &a, &b);
    a--, b--;
    edge[a].push_back(b);
    cnt[b]++;
  }

  vector<int> ans;
  vector<int> next;
  for (int i = 0; i < n; i++) if (!cnt[i]) next.push_back(i);

  for (int i = 0; i < n; i++) {
    int tar = next.back();
    next.pop_back();
    ans.push_back(tar + 1);
    for (int j = 0; j < edge[tar].size(); j++) {
      int to = edge[tar][j];
      cnt[to]--;
      if (!cnt[to]) next.push_back(to);
    }
  }

  for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
  puts(next.empty() ? "0" : "1");
  return 0;
}