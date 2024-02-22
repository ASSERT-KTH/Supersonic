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
  res.clear(); res.resize(N, Ary(N));
  for_(i, 0, N) {
    for_(j, 0, N) {
      int max_val = -1;
      for_(k, 0, N) {
        if (a[i][k] >= 0 && b[k][j] >= 0) {
          max_val = max(max_val, a[i][k] + b[k][j]);
        }
      }
      res[i][j] = max_val;
    }
  }
}

// rest of the code remains the same...