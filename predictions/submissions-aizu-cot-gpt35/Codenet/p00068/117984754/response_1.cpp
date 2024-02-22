#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y){};
};

bool cmp_x(const P &p, const P &q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

vector<P> convex_hull(vector<P>& ps) {
  sort(ps.begin(), ps.end(), cmp_x);
  int n = ps.size();

  int k = 0;
  vector<P> qs(n * 2);

  for (int i = 0; i < n; i++) {
    while (k > 1 && ((qs[k - 1].x - qs[k - 2].x) * (ps[i].y - qs[k - 1].y) - (qs[k - 1].y - qs[k - 2].y) * (ps[i].x - qs[k - 1].x)) <= 0)
      k--;
    qs[k++] = ps[i];
  }

  for (int i = n - 2, t = k; i >= 0; i--) {
    while (k > t && ((qs[k - 1].x - qs[k - 2].x) * (ps[i].y - qs[k - 1].y) - (qs[k - 1].y - qs[k - 2].y) * (ps[i].x - qs[k - 1].x)) <= 0)
      k--;
    qs[k++] = ps[i];
  }

  qs.resize(k - 1);
  return qs;
}

int main() {
  int N;
  while (cin >> N && N) {
    vector<P> ps(N);
    for (int i = 0; i < N; i++) {
      char ch;
      cin >> ps[i].x >> ch >> ps[i].y;
    }
    vector<P> res = convex_hull(ps);
    cout << N - res.size() << endl;
  }
}