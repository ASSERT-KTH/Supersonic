#include <cstdio>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> pii;
int n, m;
vector<int> edge[5000];
int cnt[5000];
int main() {
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }
  vector<int> ans;
  vector<int> next;
  REP(i, n) if (cnt[i] == 0) next.push_back(i);
  REP(i, n) {
    int tar = next.back();
    ans.push_back(tar + 1);
    next.pop_back();
    for(auto &to : edge[tar]) {
      if (--cnt[to] == 0)
        next.push_back(to);
    }
  }
  for(auto &i : ans) printf("%d\n", i);
  puts(next.empty() ? "0" : "1");
  return 0;
}