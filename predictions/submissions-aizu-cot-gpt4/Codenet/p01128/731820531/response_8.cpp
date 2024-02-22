#include <algorithm>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
typedef complex<double> Point;
typedef pair<Point, Point> Seg;
typedef vector<pair<Point, bool>> VecPair;

bool intersect_SS(const Seg& s1, const Seg& s2);
Point ip_SS(const Seg& s1, const Seg& s2);
void fast_io();

int main() {
  fast_io();
  int T;
  cin >> T;
  while (T--) {
    Seg s;
    cin >> s.first >> s.second;
    VecPair c;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      Seg t;
      int o, l;
      cin >> t.first >> t.second >> o >> l;
      if (intersect_SS(s, t))
        c.push_back(make_pair(ip_SS(s, t), (o ^ l)));
    }
    sort(c.begin(), c.end());
    int res = 0;
    for (int i = 0; i < c.size() - 1; ++i) 
      if (c[i].second != c[i + 1].second)
        ++res;
    cout << res << '\n';
  }
}