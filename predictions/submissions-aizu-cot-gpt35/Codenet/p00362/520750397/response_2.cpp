#include <iostream>
using namespace std;

const int MAX_N = 2e5 + 1;
const int MAX_K = 7 << 15;

int T[MAX_N][2];
int P[MAX_N], E[MAX_N], C[MAX_N], O[MAX_N], X[MAX_N], B[MAX_N], H[MAX_N], Z[MAX_N];
int A[MAX_N];

int M(int f) {
  return f ? B[f] + M(f ^ (f & -f)) : 0;
}

void S(int a, int i) {
  for (; i < MAX_N; i += i & -i)
    B[i] += a;
}

void D(int f) {
  Z[f] = 1;
  for (int j = 0; j < 2; j++) {
    int d = T[f][j];
    if (!Z[d]) {
      P[d] = f;
      E[d] = E[f] + 1;
      C[d] = T[f][j + 1];
      D(d);
      Z[f] += Z[d];
      if (!H[f] || Z[H[f]] < Z[d]) {
        H[f] = d;
      }
    }
  }
}

int K(int f) {
  int a = X[f];
  int n = X[T[a][0]];
  return (a - n) ? (M(O[E[a] < E[n] ? a = n, n = T[a][0], T[a][0] = f, n : f]) + K(P[a]))
                 : abs(M(O[f]) - M(O[T[a][0]]));
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    T[a][0] = b;
    T[b][0] = a;
    T[a][1] = T[b][1] = c;
  }
  D(1);
  for (int i = 1; i <= n; i++) {
    X[i] = n;
  }
  int a;
  while (cin >> a) {
    if (a & 2) {
      int b;
      cin >> b;
      cout << K(a) << endl;
    } else {
      int b;
      cin >> b;
      S(H[a], O[a]);
      S(a, O[a] - 1);
      A[a] += b;
    }
  }
  return 0;
}