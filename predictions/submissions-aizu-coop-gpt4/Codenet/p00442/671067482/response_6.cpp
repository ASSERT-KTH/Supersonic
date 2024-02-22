#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>  // Include deque library
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
  deque<int> next;  // Change next to deque
  REP(i, n) if (cnt[i] == 0) next.push_back(i);
  int nextSize = next.size();  // Store size of next
  REP(i, n) {
    int tar = next.back();  // Use back() instead of indexing
    ans.push_back(tar + 1);
    next.pop_back();  // Use pop_back() instead of erase()
    nextSize--;  // Update size of next
    if (nextSize > 0)
      flag = true;
    for(auto &to : edge[tar]) {  // Use range-based for loop
      if (--cnt[to] == 0) {
        next.push_back(to);
        nextSize++;  // Update size of next
      }
    }
  }
  REP(i, ans.size()) printf("%d\n", ans[i]);
  if (flag)
    puts("1");
  else
    puts("0");
  return 0;
}