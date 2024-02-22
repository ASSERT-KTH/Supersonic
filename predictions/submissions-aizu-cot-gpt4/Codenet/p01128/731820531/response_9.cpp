#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;
typedef complex<double> Point;
typedef pair<Point, bool> pPoint;
typedef pair<Point, Point> Line;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define mp make_pair

bool intersect_SS(const Line &s, const Line &t) {
  return (max(real(s.first), real(s.second)) >= min(real(t.first), real(t.second))
    && max(real(t.first), real(t.second)) >= min(real(s.first), real(s.second))
    && max(imag(s.first), imag(s.second)) >= min(imag(t.first), imag(t.second))
    && max(imag(t.first), imag(t.second)) >= min(imag(s.first), imag(s.second))
    && ((cross(s.second - s.first, t.first - s.first) * cross(s.second - s.first, t.second - s.first) <= 0)
    && (cross(t.second - t.first, s.first - t.first) * cross(t.second - t.first, s.second - t.first) <= 0)));
}

Point crosspoint_SS(Line l, Line m) {
  double A = cross(l.second - l.first, m.second - m.first);
  double B = cross(l.second - l.first, l.second - m.first);
  if (abs(A) < 1e-9 && abs(B) < 1e-9) return m.first;
  return m.first + B / A * (m.second - m.first);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    Point s1, s2;
    cin >> s1 >> s2;
    if (imag(s1) > imag(s2)) swap(s1, s2);
    int n;
    cin >> n;
    vector<pPoint> cp;
    rep(i, n) {
      Point t1, t2;
      int o, l;
      cin >> t1 >> t2 >> o >> l;
      if (imag(t1) > imag(t2)) swap(t1, t2);
      if (intersect_SS(mp(s1, s2), mp(t1, t2))) {
        cp.push_back(mp(crosspoint_SS(mp(s1, s2), mp(t1, t2)), o ^ l));
      }
    }
    sort(cp.begin(), cp.end());
    int res = 0;
    rep(i, (int)cp.size() - 1) if (cp[i].second != cp[i + 1].second)++res;
    cout << res << '\n';
  }
  return 0;
}