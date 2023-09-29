#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

const double EPS = 1e-10;

struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y){}
  P operator+(const P &p) const { return P(x + p.x, y + p.y); }
  P operator-(const P &p) const { return P(x - p.x, y - p.y); }
  double operator*(const P &p) const { return x * p.x + y * p.y; }
  double operator^(const P &p) const { return x * p.y - y * p.x; }
  bool operator<(const P &p) const {
    return (x != p.x) ? (x < p.x) : (y < p.y);
  }
};

vector<P> convex_hull(P *ps, int n) {
  sort(ps, ps + n);
  int k = 0;
  vector<P> qs(n * 2);
  for (int i = 0; i < n; i++)
  {
    while (k > 1 && ((qs[k - 1] - qs[k - 2]) ^ (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; i--)
  {
    while (k > t && ((qs[k - 1] - qs[k - 2]) ^ (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

const int MAX_N = 100;
P ps[MAX_N];
int N;

int main() {
  while (cin >> N && N) {
    for (int i=0; i<N; i++) {
      char ch;
      cin >> ps[i].x >> ch >> ps[i].y;
    }
    vector<P> res = convex_hull(ps, N);
    cout << N - res.size() << endl;
  }
}