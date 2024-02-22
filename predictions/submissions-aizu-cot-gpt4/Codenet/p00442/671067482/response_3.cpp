#include <algorithm>
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }
  vector<int> ans;
  bool flag = false;
  vector<int> next;
  REP(i, n) if (cnt[i] == 0) next.push_back(i);
  REP(i, n) {
    int tar = next.back();
    ans.push_back(tar + 1);
    next.pop_back();
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0) {
        next.push_back(to);
        flag = true;
      }
    }
  }
  REP(i, ans.size()) cout << ans[i] << "\n";
  cout << (flag ? 1 : 0) << "\n";
  return 0;
}