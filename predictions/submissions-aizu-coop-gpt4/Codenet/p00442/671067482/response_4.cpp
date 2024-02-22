#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
typedef pair<int, int> pii;
int n, m;
vector<int> edge[5000];
int cnt[5000];
int main() {
  ios_base::sync_with_stdio(false); // to improve the performance of cin
  cin.tie(NULL); // to untie cin and cout
  cin >> n >> m;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }
  bool flag = false;
  deque<int> next;
  REP(i, n) if (cnt[i] == 0) next.push_back(i);
  REP(i, n) {
    int tar = next.back();
    next.pop_back();
    printf("%d\n", tar + 1);
    if (next.size() > 1)
      flag = true;
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0)
        next.push_back(to);
    }
  }
  if (flag)
    puts("1");
  else
    puts("0");
  return 0;
}