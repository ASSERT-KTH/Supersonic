#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 5000;
vector<int> edge[MAX];
int cnt[MAX];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    edge[a].push_back(b);
    cnt[b]++;
  }
  queue<int> next;
  for (int i = 0; i < n; i++) if (cnt[i] == 0) next.push(i);
  vector<int> ans;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (next.empty()) { flag = true; break; }
    int tar = next.front();
    next.pop();
    ans.push_back(tar + 1);
    for (int to : edge[tar]) {
      if (--cnt[to] == 0)
        next.push(to);
    }
  }
  for (int num : ans) printf("%d\n", num);
  puts(flag ? "1" : "0");
  return 0;
}