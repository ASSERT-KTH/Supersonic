#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

constexpr double EPS = 1e-6;
constexpr int COUNTER_CLOCKWISE = 1;
constexpr int CLOCKWISE = -1;
constexpr int ONLINE_BACK = 2;
constexpr int ONLINE_FRONT = -2;
constexpr int ON_SEGMENT = 0;
constexpr double M_PI = 3.14159265358979323846;

bool equals(double a, double b) { return std::fabs((a) - (b)) < EPS; }

// ... rest of the code ...

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