#include <bits/stdc++.h>
#include <omp.h> // Include OpenMP library
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout << #x " = " << ((x)) << endl
// ... Rest of the code as before ...

// Optimized 'mul' function
mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  #pragma omp parallel for // Parallelize this loop
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<n; k++) {
        C[i][j] += A[i][k] * B[k][j];
        C[i][j] %= mod;
      }
    }
  }
  return C;
}

// ... Rest of the code as before ...