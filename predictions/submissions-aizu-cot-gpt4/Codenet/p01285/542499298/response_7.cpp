#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>

#define EPS (1e-6)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(a * x, a * y); }
  Point operator/(double a) { return Point(x / a, y / a); }
  // ...
};

// ...

void compute(std::vector<Line> &vec) {
  // ...
  if (answer.size() == 1)
    std::cout << std::fixed << std::setprecision(10) << answer[0].x << " " << answer[0].y << '\n';
  else if (answer.empty())
    std::cout << NONE << '\n';
  else
    std::cout << MANY << '\n';
}

int main() {
  int n;
  while (std::cin >> n, n) {
    std::vector<Line> vec(n);
    for(int i=0; i<n; i++)
      std::cin >> vec[i].p1.x >> vec[i].p1.y >> vec[i].p2.x >> vec[i].p2.y;
    compute(vec);
  }
  return 0;
}