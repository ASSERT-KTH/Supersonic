#include <bits/stdc++.h>
using namespace std;

#define for_(i, a, b) for (int i = (a); i < (b); ++i)
#define for_rev(i, a, b) for (int i = (a); i >= (b); --i)

typedef vector<int> Ary;
typedef vector<Ary> Mat;

struct Edge {
  int to, c;
};

// dp and prv are now std::array instead of std::vector
array<array<int, 155>, 155> dp;
array<array<int, 155>, 155> prv;

void maxUpdate(int &a, int b) { a = max(a, b); }

// pass b by reference to avoid copying
void mul(Mat &res, const Mat &a, const Mat &b) {
  int N = a.size();
  res = a;
  for_(i, 0, N) for_(j, 0, N) for_(k, 0, N) {
    if (a[i][k] >= 0 && b[k][j] >= 0)
      maxUpdate(res[i][j], a[i][k] + b[k][j]);
  }
}

// Preallocating memory for vectors
vector<vector<Edge>> adj(155);

bool shortPhase() {
  memset(dp.data(), -1, sizeof(dp));
  memset(prv.data(), -1, sizeof(prv));
  for_(v, 0, V) dp[0][v] = 0;
  int max_score = -1, step = -1, terminal = -1;
  for_(i, 0, 150) {
    for_(v, 0, V) {
      if (dp[i][v] == -1)
        continue;
      for (Edge e : adj[v]) {
        if (dp[i + 1][e.to] < dp[i][v] + e.c) {
          dp[i + 1][e.to] = dp[i][v] + e.c;
          prv[i + 1][e.to] = v;
          if (max_score < dp[i + 1][e.to]) {
            max_score = dp[i + 1][e.to];
            terminal = e.to;
          }
        }
      }
    }
    if (max_score >= K) {
      step = i + 1;
      break;
    }
  }
  if (max_score >= K) {
    cout << step << '\n';  // replaced std::endl with '\n'
    restore(step, terminal);
    return true;
  }
  if (max_score == -1) {
    cout << -1 << '\n';  // replaced std::endl with '\n'
    return true;
  }
  return false;
}

// rest of the code remains the same