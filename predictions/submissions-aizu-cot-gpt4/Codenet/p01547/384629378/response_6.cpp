#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;
typedef double D;
typedef complex<D> P;
typedef pair<P, P> L;
typedef vector<P> VP;
typedef vector<VP> Vcon;
const D EPS = 1e-7;

#define X real()
#define Y imag()
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define EQ(n, m) (abs((n) - (m)) < EPS)

D dot(P a, P b) { return (conj(a) * b).X; }
D cross(P a, P b) { return (conj(a) * b).Y; }

//... Rest of the code ...

signed main() {
  int n, m, q;
  cin >> n;
  VP V[n];
  for (int i = 0; i < n; ++i) {
    cin >> m;
    D x[m], y[m];
    V[i].reserve(m); // Reserve space for efficiently push_back elements
    for (int j = 0; j < m; ++j) {
      cin >> x[j] >> y[j];
      V[i].push_back(P(x[j], y[j]));
    }
    //... Rest of the code ...
  }
  //... Rest of the code ...
}