#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
typedef pair<int, int> pii;
int n, m;
int edge[5000][5000]; // 2D array instead of vector
int cnt[5000];
int main() {
  cin >> n >> m;
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edge[a][cnt[a]++] = b; // Store in 2D array
    cnt[b]++;
  }
  vector<int> ans;
  bool flag = false;
  vector<int> next;
  REP(i, n) if (cnt[i] == 0) next.push_back(i);
  REP(i, n) {
    int tar = next[next.size() - 1];
    ans.push_back(tar + 1);
    next.pop_back(); // Use pop_back() instead of erase()
    int nextSize = next.size(); // Store size in a variable
    if (nextSize > 0) {
      flag = true;
    }
    REP(j, cnt[tar]) { // Iterate over cnt[tar] instead of edge[tar]
      int to = edge[tar][j];
      if (--cnt[to] == 0) {
        next.push_back(to);
      }
    }
  }
  REP(i, ans.size()) printf("%d\n", ans[i]);
  if (flag) {
    puts("1");
  } else {
    puts("0");
  }
  return 0;
}