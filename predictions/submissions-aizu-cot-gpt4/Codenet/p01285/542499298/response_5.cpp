#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define EPS (1e-6)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
using namespace std;
class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(a * x, a * y); }
  Point operator/(double a) { return Point(x / a, y / a); }
  Point operator*(Point a) {
    return Point(x * a.x - y * a.y, x * a.y + y * a.x);
  }
  bool operator<(const Point &p) const {
    return !equals(x, p.x) ? x < p.x : (!equals(y, p.y) && y < p.y);
  }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};
// ... rest of the code ...
void compute(vector<Line> &vec) {
  if (vec.size() <= 2) {
    cout << MANY << endl;
    return;
  }
  double toRad180 = toRad(180.0); // Compute toRad(180.0) once
  // ... rest of the code ...
  rep(i, n) REP(j, i + 1, n) {
    bool isCrossZero = equals(cross(vec[i].p1 - vec[i].p2, vec[j].p1 - vec[j].p2), 0.0); // Compute equals once
    // ... rest of the code ...
  }
  // ... rest of the code ...
  rep(i, candidateLines.size()) REP(j, i + 1, candidateLines.size()) {
    Line line1 = candidateLines[i];
    Line line2 = candidateLines[j];
    bool isCrossZero = equals(cross(line1.p1 - line1.p2, line2.p1 - line2.p2), 0.0); // Compute equals once
    if (isCrossZero)
      continue;
    // ... rest of the code ...
  }
  // ... rest of the code ...
}
int main() {
  int n;
  while (cin >> n, n) {
    vector<Line> vec(n);
    rep(i, n) cin >> vec[i].p1.x >> vec[i].p1.y >> vec[i].p2.x >> vec[i].p2.y;
    compute(vec);
  }
  return 0;
}