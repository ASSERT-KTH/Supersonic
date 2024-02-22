mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  rep(i, n) rep(j, n) {
    if (A[i][j] != 0) {
      rep(k, n) {
        if (B[j][k] != 0) {
          C[i][k] += A[i][j] * B[j][k];
          C[i][k] %= mod;
        }
      }
    }
  }
  return C;
}