#include <bits/stdc++.h>
#include <Eigen/Sparse>

using namespace std;
using ll = long long;
// ... (rest of the code)

// Use Eigen::SparseMatrix instead of vector<vector<ll>>
using mat = Eigen::SparseMatrix<ll>;

// Combine matrix multiplication and power operations into a single function
mat mul_and_pow(const mat &A, const mat &B, ll x) {
  // ... (optimized code for matrix multiplication and power operations)
}

// Use OpenMP to parallelize loops
#pragma omp parallel for
for (int i = 0; i < n; ++i) {
  // ... (code inside the loop)
}

// ... (rest of the code)