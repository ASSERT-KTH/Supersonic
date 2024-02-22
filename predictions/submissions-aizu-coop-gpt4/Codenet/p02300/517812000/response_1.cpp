#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
  int x, y;
  Point(int a = 0, int b = 0) : x(a), y(b) {};
  
  bool operator<(const Point &p) const {
    return y < p.y || (y == p.y && x < p.x);
  }
};

inline bool direct(Point &base, Point &a, Point &b) {
  return (a.x - base.x) * (b.y - base.y) - (a.y - base.y) * (b.x - base.x) < 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, i;
  int k = 2;

  cin >> n;
  vector<Point> P(n);
  for (i = 0; i < n; ++i) {
    cin >> P[i].x >> P[i].y;
  }

  sort(P.begin(), P.end());

  vector<Point> H(2 * n);
  H[0] = P[0];
  H[1] = P[1];

  for (i = 0; i < n - 2; ++i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i + 2]))
      k--;
    H[k++] = P[i + 2];
  }

  H[k++] = P[n - 2];

  for (i = n; i > 2; i--) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i - 3]))
      k--;
    H[k++] = P[i - 3];
  }

  cout << k - 1 << endl;
  for (i = 0; i < k - 1; ++i) {
    cout << H[i].x << " " << H[i].y << endl;
  }

  return 0;
}