#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
typedef pair<int, int> pii;
int n, m;
vector<int> edge[5000];
int cnt[5000];
int main() {
  read(0, &n, sizeof(n));
  read(0, &m, sizeof(m));
  REP(i, m) {
    int a, b;
    read(0, &a, sizeof(a));
    read(0, &b, sizeof(b));
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }
  queue<int> next;
  REP(i, n) if (cnt[i] == 0) next.push(i);
  bool flag = false;
  REP(i, n) {
    int tar = next.front();
    next.pop();
    char buffer[10];
    sprintf(buffer, "%d\n", tar + 1);
    write(1, buffer, sizeof(buffer));
    if (!next.empty())
      flag = true;
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0)
        next.push(to);
    }
  }
  if (flag)
    write(1, "1\n", 2);
  else
    write(1, "0\n", 2);
  return 0;
}