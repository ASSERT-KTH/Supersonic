#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

struct P {
  double x, y;
  P() {}
  P(double x, double y) : x(x), y(y) {}
  P operator+(const P& p) const { return P(x + p.x, y + p.y); }
  P operator-(const P& p) const { return P(x - p.x, y - p.y); }
  P operator*(double d) const { return P(x * d, y * d); }
  P operator/(double d) const { return P(x / d, y / d); }
  double dot(const P& p) const { return x * p.x + y * p.y; }
  double det(const P& p) const { return x * p.y - y * p.x; }
  double norm() const { return x * x + y * y; }
  double abs() const { return sqrt(norm()); }
};

struct L {
  P p1, p2;
  L() {}