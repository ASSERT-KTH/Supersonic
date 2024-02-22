// ... rest of the code

const ll mod = 1000000009;
using vl = vector<ll>;
using mat = vector<vl>;

mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  rep(i, n) rep(j, n) {
    ll sum = 0;
    rep(k, n) {
      sum += (A[i][k] * B[k][j]) % mod; // Avoiding overflow by taking modulo in each multiplication
      sum %= mod;
    }
    C[i][j] = sum;
  }
  return C;
}

vl mul(const mat &A, const vl &b) {
  int n = A.size();
  vl ret(n);
  rep(i, n) {
    ll sum = 0;
    rep(j, n) {
      sum += (A[i][j] * b[j]) % mod; // Avoiding overflow by taking modulo in each multiplication
      sum %= mod;
    }
    ret[i] = sum;
  }
  return ret;
}

// ... rest of the code