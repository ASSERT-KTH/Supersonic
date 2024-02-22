#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::complex;
using std::istream;
using std::ostream;
using std::make_pair;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int, int> pint;
typedef double gtype;
typedef complex<gtype> Point;
const gtype EPS_FOR_LIB = 1e-9;

void fast_io() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
}

istream &operator>>(istream &is, Point &p) {
  gtype a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}

ostream &operator<<(ostream &os, const Point &p) {
  return os << "(" << p.real() << ", " << p.imag() << ")";
}

struct Line {
  Point first, second;
  Line() {}
  Line(const Point &first, const Point &second) : first(first), second(second) {
    if (first == second)
      this->first.real() += 1e-12;
  }
};

typedef Line Seg;

ostream &operator<<(ostream &os, const Line &line) {
  return os << "(" << line.first << ", " << line.second << ")";
}

bool intersect_SS(const Line &seg1, const Line &seg2) {
  const gtype feps = 1e-9;
  return (cross(seg1.second - seg1.first, seg2.first - seg1.first) *
                  cross(seg1.second - seg1.first, seg2.second - seg1.first) <
              -feps &&
          cross(seg2.second - seg2.first, seg1.first - seg2.first) *
                  cross(seg2.second - seg2.first, seg1.second - seg2.first) <
              -feps) ||
         intersect_SP(seg1, seg2.first) || intersect_SP(seg1, seg2.second) ||
         intersect_SP(seg2, seg1.first) || intersect_SP(seg2, seg1.second);
}

Point ip_SS(const Line &seg1, const Line &seg2) {
  if (!intersect_SS(seg1, seg2)) {
    cerr << "ip_SS: 前提条件満たしてない" << endl;
    exit(1);
  }
  gtype a = abs(cross(seg1.second - seg1.first, seg2.first - seg1.first));
  gtype b = abs(cross(seg1.second - seg1.first, seg2.second - seg1.first));
  if (a < 1e-9 && b < 1e-9) {
    cerr << "same line" << endl;
    exit(1);
  }
  gtype t = a / (a + b);
  return seg2.first + t * (seg2.second - seg2.first);
}

int main() {
  fast_io();
  int T;
  cin >> T;
  while (T--) {
    Seg s;
    cin >> s.first >> s.second;
    Point rota(1, -arg(s.second - s.first));
    s.first *= rota, s.second *= rota;
    vector<pair<Point, bool>> c;
    int n;
    cin >> n;
    rep(i, n) {
      Seg t;
      int o, l;
      cin >> t.first >> t.second >> o >> l;
      t.first *= rota, t.second *= rota;
      if (intersect_SS(s, t))
        c.push_back(make_pair(ip_SS(s, t), (o ^ l)));
    }
    sort(all(c));
    int res = 0;
    rep(i, static_cast<int>(c.size()) - 1) if (c[i].second != c[i + 1].second)++ res;
    cout << res << endl;
  }
}