#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;
P project(const P& a, const P& b, const P& c) {
  const P b_a = b - a, c_a = c - a;
  return a + b_a * real(c_a / b_a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  double ax, ay, bx, by;
  int n;
  cin >> ax >> ay >> bx >> by >> n;
  while (n--) {
    double cx, cy;
    cin >> cx >> cy;
    P p = project({ax, ay}, {bx, by}, {cx, cy});
    cout << fixed << setprecision(8) << p.real() << " " << p.imag() << "\n";
  }
  return 0;
}