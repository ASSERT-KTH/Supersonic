#include <bits/stdc++.h>
using namespace std;
#define for_(i, a, b) for (int i = (a); i < (b); ++i)
#define for_rev(i, a, b) for (int i = (a); i >= (b); --i)
typedef vector<int> Ary;
typedef vector<Ary> Mat;
struct Edge {
  int to, c;
};
void maxUpdate(int &a, int b) { a = max(a, b); }
void mul(Mat &res, const Mat &a, const Mat &b) {
  int N = a.size();
  res.resize(N, Ary(N));
  #pragma omp parallel for
  for_(i, 0, N) {
    for_(j, 0, N) {
      for_(k, 0, N) {
        int aik = a[i][k], bkj = b[k][j];
        if (aik >= 0 && bkj >= 0)
          maxUpdate(res[i][j], aik + bkj);
      }
    }
  }
}
// rest of the code remains the same...
void restore(int step, int v) {
  int c = step;
  vector<int> path;
  path.reserve(step + 1);
  while (v != -1) {
    path.push_back(v);
    v = prv[c--][v];
  }
  reverse(path.begin(), path.end());
  for_(i, 0, step + 1) cout << path[i] << (i < step ? " " : "\n");
}
// rest of the code remains the same...