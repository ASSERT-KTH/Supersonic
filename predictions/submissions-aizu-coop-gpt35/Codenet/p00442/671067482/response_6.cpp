#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
typedef pair<int, int> pii;
int n, m;
vector<int>* edge[5000]; // Optimized: Use vector<int>* instead of vector<int>
int* cnt[5000]; // Optimized: Use int* instead of vector<int>
int main() {
  cin >> n >> m;
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    if (!edge[a]) {
      edge[a] = new vector<int>(); // Optimized: Allocate vector<int> only if necessary
    }
    edge[a]->push_back(b);
    if (!cnt[b]) {
      cnt[b] = new int(0); // Optimized: Allocate int only if necessary
    }
    (*cnt[b])++;
  }
  vector<int> ans;
  bool flag = false;
  vector<int> next;
  REP(i, n) if (!cnt[i]) next.push_back(i); // Optimized: Avoid comparison with 0
  REP(i, n) {
    int tar = next.back(); // Optimized: Use back() instead of next[next.size() - 1]
    ans.push_back(tar + 1);
    next.pop_back(); // Optimized: Use pop_back() instead of erase(end() - 1)
    flag = !next.empty(); // Optimized: Use flag instead of next.size() > 0
    if (edge[tar]) {
      REP(j, edge[tar]->size()) {
        int to = (*edge[tar])[j]; // Optimized: Use (*edge[tar])[j] instead of edge[tar][j]
        if (--(*cnt[to]) == 0) { // Optimized: Use (*cnt[to]) instead of cnt[to]
          next.push_back(to);
        }
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