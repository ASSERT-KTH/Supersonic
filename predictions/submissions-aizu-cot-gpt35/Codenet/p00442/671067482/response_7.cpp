#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  vector<vector<int>> edge(n);
  vector<int> cnt(n);

  for (int i = 0; i < m; i++) {
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
  
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0) {
      next.push_back(i);
    }
  }
  
  for (int i = 0; i < n; i++) {
    int tar = next.back();
    next.pop_back();
    ans.push_back(tar + 1);
    
    if (!next.empty()) {
      flag = true;
    }
    
    for (int j = 0; j < edge[tar].size(); j++) {
      int to = edge[tar][j];
      if (--cnt[to] == 0) {
        next.push_back(to);
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    printf("%d\n", ans[i]);
  }

  if (flag) {
    puts("1");
  } else {
    puts("0");
  }

  return 0;
}