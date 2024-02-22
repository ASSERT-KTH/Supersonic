#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <deque>

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define PI 3.141592653589793238
#define int long long

using namespace std;

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}