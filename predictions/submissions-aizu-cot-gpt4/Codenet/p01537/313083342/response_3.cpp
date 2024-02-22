#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using Point = pair<ld, ld>;
using Circle = pair<ld, Point>;
const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

ld cross(const Point &a, const Point &b) {
  return a.first * b.second - a.second * b.first;
}

ld dot(const Point &a, const Point &b) {
  return a.first * b.first + a.second * b.second;
}

Circle c3(const Point &a, const Point &b, const Point &c) {
    ld A = norm(b - c);
    ld B = norm(c - a);
    ld C = norm(a - b);
    ld S = abs(cross(b - a, c - a));
    Point p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) /
          (4 * S * S);
    ld r = abs(p - a);
    return make_pair(r, p);
}

Circle c2(const Point &a, const Point &b) {
    Point c = (a + b) / (ld)2;
    ld r = abs(a - c);
    return make_pair(r, c);
}

bool in_circle(const Point &a, const Circle &c) {
    return norm(a - c.second) <= c.first * c.first + eps;
}

// ... rest of the code ... 