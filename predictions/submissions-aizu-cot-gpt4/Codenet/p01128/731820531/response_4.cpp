#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <complex>
#include <cmath>

typedef long long ll;
typedef std::pair<int, int> pint;
typedef double gtype;

gtype to_rad(gtype deg) { return deg * M_PI / 180; }
gtype to_deg(gtype rad) { return rad * 180 / M_PI; }

struct Point: public std::complex<gtype> {
  using std::complex<gtype>::complex;
  Point() = default;
  explicit Point(const std::complex<gtype>& c) : std::complex<gtype>(c) {}

  friend std::istream& operator>>(std::istream& is, Point& p) {
    gtype a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
  }
};

struct Line {
  Point first, second;
  Line() {}
  Line(const Point &first, const Point &second) : first(first), second(second) {}
};

bool intersect_SS(const Line &seg1, const Line &seg2);
Point ip_SS(const Line &seg1, const Line &seg2);

int main() {
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  while (T--) {
    Line s;
    std::cin >> s.first >> s.second;
    Point rota(1, -std::arg(s.second - s.first));
    s.first *= rota, s.second *= rota;
    std::vector<std::pair<Point, bool>> c;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      Line t;
      int o, l;
      std::cin >> t.first >> t.second >> o >> l;
      t.first *= rota, t.second *= rota;
      if (intersect_SS(s, t))
        c.push_back(std::make_pair(ip_SS(s, t), (o ^ l)));
    }
    std::sort(c.begin(), c.end());
    int res = 0;
    for (int i = 0; i < static_cast<int>(c.size()) - 1; i++) if (c[i].second != c[i + 1].second)++ res;
    std::cout << res << std::endl;
  }
}