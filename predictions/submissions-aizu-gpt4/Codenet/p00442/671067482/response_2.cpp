#include <cstdio>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int n, m;
vector<int> edge[5000];
int cnt[5000];

int main() {
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a; --b;
    edge[a].push_back(b);
    ++cnt[b];
  }
  
  vector<int> ans, next;
  ans.reserve(n); next.reserve(n);
  REP(i, n) if (cnt[i] == 0) next.push_back(i);

  REP(i, n) {
    int tar = next.back(); next.pop_back();
    ans.push_back(tar + 1);
    for(auto &to : edge[tar]) {
      if (--cnt[to] == 0)
        next.push_back(to);
    }
  }

  for(auto &a : ans) printf("%d\n", a);
  puts(next.empty() ? "0" : "1");
  
  return 0;
}