#include <bits/stdc++.h>
using namespace std;
typedef vector<int> Ary;
typedef vector<Ary> Mat;
struct Edge {
  int to, c;
};
vector<vector<Edge>> adj;
int V, K, E, dp[155][155], prv[155][155];

void maxUpdate(int &a, int b) { a = max(a, b); }

void mul(Mat &res, Mat &a, Mat &b) {
  int N = a.size();
  res = a;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      int maxScore = res[i][j];
      for(int k=0; k<N; k++) {
        if (a[i][k] >= 0 && b[k][j] >= 0)
          maxScore = max(maxScore, a[i][k] + b[k][j]);
      }
      res[i][j] = maxScore;
    }
  }
}

// ... rest of the code is the same ...