#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EACH(i, c)                                                             \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(A) A.begin(), A.end()
using namespace std;
struct HeavyLight {
  vector<vector<int>> len, tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  HeavyLight(vector<vector<int>> tree)
      : tree(tree), n(tree.size()), size(n), parent(n), in(n), out(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths(0, newPath(0));
    len = vector<vector<int>>(pathCount);
    REP(i, pathCount) {
      int m = pathSize[i];
      len[i].resize(2 * m);
      fill(ALL(len[i]), 0);
      fill(len[i].begin() + m, len[i].begin() + 2 * m, 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j >> 1]