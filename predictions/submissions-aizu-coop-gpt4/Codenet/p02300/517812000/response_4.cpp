#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
  int x, y;
  Point(int a = 0, int b = 0) : x(a), y(b){}
  bool operator<(const Point &p) const {
    return y < p.y || (y == p.y && x < p.x);
  }
};

inline bool direct(const Point &base, const Point &a, const Point &b) {
  return (a.x - base.x) * (b.y - base.y) - (a.y - base.y) * (b.x - base.x) < 0;
}

int main() {
  int n;
  cin >> n;
  vector<Point> P(n), H(2 * n);
  int k = 2;

  for (int i = 0; i < n; ++i) {
    cin >> P[i].x >> P[i].y;
  }

  sort(P.begin(), P.end());
  H[0] = P[0];
  H[1] = P[1];

  for (int i = 2; i < n; ++i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i]))
      k--;
    H[k++] = P[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i]))
      k--;
    H[k++] = P[i];
  }

  cout << k - 1 << endl;
  for (int i = 0; i < k - 1; ++i) {
    cout << H[i].x << " " << H[i].y << endl;
  }
  return 0;
}