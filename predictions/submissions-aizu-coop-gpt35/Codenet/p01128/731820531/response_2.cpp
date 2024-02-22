#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Line {
  Point first, second;
