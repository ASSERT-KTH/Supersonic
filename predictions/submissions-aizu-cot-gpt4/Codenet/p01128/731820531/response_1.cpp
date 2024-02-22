#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

typedef std::pair<std::complex<double>, bool> PointPair;
typedef std::pair<std::complex<double>, std::complex<double>> Line;
typedef std::vector<PointPair> PointPairVector;

constexpr double EPSILON = 1e-9;

// Insert the necessary functions here. 

int main() {
  std::ios_base::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    Line s;
    std::cin >> s.first >> s.second;
    std::complex<double> rota(1, -arg(s.second - s.first));
    s.first *= rota, s.second *= rota;
    PointPairVector c;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      Line t;
      int o, l;
      std::cin >> t.first >> t.second >> o >> l;
      t.first *= rota, t.second *= rota;
      if (intersect_SS(s, t))
        c.push_back(PointPair(ip_SS(s, t), (o ^ l)));
    }
    std::sort(c.begin(), c.end());
    int res = 0;
    for (int i = 0; i < static_cast<int>(c.size()) - 1; ++i) 
      if (c[i].second != c[i + 1].second)
        ++res;
    std::cout << res << std::endl;
  }
  return 0;
}