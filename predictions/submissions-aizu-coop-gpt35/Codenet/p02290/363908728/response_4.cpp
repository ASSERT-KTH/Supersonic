#include <bits/stdc++.h>
using namespace std;

struct CWW {
  CWW() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} STAR;

using D = float;  // Change data type from double to float

const D EPS = 1e-8;
const D INF = 1e9;

using Point = complex<D>;

istream& operator>>(istream& is, Point& a) {
  D x, y;
  is >> x >> y;
  a = Point(x, y);
  return is;
}

ostream& operator<<(ostream& os, const Point& a) {  // Pass Point by const reference
  os << real(a) << " " << imag(a);
  return os;
}

int main() {
  Point p1, p2, p;

  scanf("%f %f", &p1.real(), &p1.imag());  // Use scanf for faster input
  scanf("%f %f", &p2.real(), &p2.imag());  // Use scanf for faster input

  int Q;
  scanf("%d", &Q);  // Use scanf for faster input

  Point diff = p2 - p1;  // Calculate difference vector only once

  while (Q--) {
    scanf("%f %f", &p.real(), &p.imag());  // Use scanf for faster input

    Point diff_p = p - p1;  // Calculate difference vector only once
    Point w = p1 + (diff * (diff_p / diff));  // Reuse difference vectors

    printf("%.15f %.15f\n", real(w), imag(w));  // Use printf for faster output
  }

  return 0;
}