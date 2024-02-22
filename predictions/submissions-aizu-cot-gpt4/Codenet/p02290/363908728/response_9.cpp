#include <iostream>
#include <vector>
using namespace std;

using D = double;
using Point = D[2];
using Line = Point[2];

istream& operator>>(istream& is, Point& a) {
  is >> a[0] >> a[1];
  return is;
}

ostream& operator<<(ostream& os, Point& a) {
  os << a[0] << " " << a[1];
  return os;
}

istream& operator>>(istream& is, Line& l) {
  is >> l[0] >> l[1];
  return is;
}

int main() {
  Line L;
  cin >> L;

  int Q;
  cin >> Q;

  while (Q--) {
    Point p;
    cin >> p;

    Point w;
    w[0] = L[0][0] + (L[1][0] - L[0][0]) * (p[0] - L[0][0]) / (L[1][0] - L[0][0]);
    w[1] = L[0][1] + (L[1][1] - L[0][1]) * (p[1] - L[0][1]) / (L[1][1] - L[0][1]);

    cout << w << endl;
  }

  return 0;
}