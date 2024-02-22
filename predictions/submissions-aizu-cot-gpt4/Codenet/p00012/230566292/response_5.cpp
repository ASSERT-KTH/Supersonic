#include <iostream>
#include <vector>
using namespace std;

struct Point {
  double x, y;
};

inline double cross_prod(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}

inline double dot_prod(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

CCWiseState ccwise(Point a, Point b, Point c) {
  b.x -= a.x;
  b.y -= a.y;
  c.x -= a.x;
  c.y -= a.y;
  if (cross_prod(b, c) > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross_prod(b, c) < 0) {
    return CLOCKWISE;
  } else if (dot_prod(b, c) < 0) {
    return ONLINE_BACK;
  } else if (b.x * b.x + b.y * b.y < c.x * c.x + c.y * c.y) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double x, y;
  cin >> x >> y;
  if (cin.eof())
    return true;
  Point A {x, y};
  cin >> x >> y;
  Point B {x, y};
  cin >> x >> y;
  Point C {x, y};
  cin >> x >> y;
  Point P {x, y};
  CCWiseState APB = ccwise(A, P, B);
  CCWiseState BPC = ccwise(B, P, C);
  CCWiseState CPA = ccwise(C, P, A);
  if (APB != BPC || APB != CPA) {
    cout << "NO\n";
    return true;
  }
  cout << "YES\n";
  return false;
}

int main() {
  int solved = 0;
  while (!testcase_ends())
    ++solved;
  return !solved;
}