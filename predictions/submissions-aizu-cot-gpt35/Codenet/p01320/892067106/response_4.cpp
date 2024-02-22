#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct S {
  double x, y;
  S(double x = 0, double y = 0) : x(x), y(y) {}
  S operator+(const S &s) const { return S(x + s.x, y + s.y); }
  S operator-(const S &s) const { return S(x - s.x, y - s.y); }
  S operator*(double k) const { return S(x * k, y * k); }