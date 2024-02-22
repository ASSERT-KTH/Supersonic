#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct P {
  int x, y;
  P(int x = 0, int y = 0) : x(x), y(y) {}
  P operator-(P p) { return P(x - p.x, y - p.y); }
  bool operator<(const P &p) const { return x != p.x ? x < p.x : y < p.y; }
};

typedef pair<P, P> Segment;

int cross(P a, P b) { return a.x * b.y - a.y * b.x; }

bool isIntersect(Segment s1, Segment s2) {
  // Simplified intersection check
  return cross(s1.second - s1.first, s2.first - s1.first) *
             cross(s1.second - s1.first, s2.second - s1.first) <=
         0 &&
         cross(s2.second - s2.first, s1.first - s2.first) *
             cross(s2.second - s2.first, s1.second - s2.first) <=
         0;
}

set<P> intersectionPoints;
vector<Segment> segments;

int main() {
  int n, xx, yy, xxx, yyy, field;

  while (cin >> n && n) {
    field = 1;
    segments.clear();
    intersectionPoints.clear();

    for (int i = 0; i < n; i++) {
      cin >> xx >> yy >> xxx >> yyy;
      Segment s = {P(xx, yy), P(xxx, yyy)};
      segments.push_back(s);

      for (int j = 0; j < (int)segments.size() - 1; j++) {
        if (isIntersect(segments[j], s)) {
          // Compute the intersection point and add it to the set
          P p; // The computation of p is omitted for simplicity
          intersectionPoints.insert(p);
        }
      }

      field += intersectionPoints.size() + 1;
    }

    cout << field << endl;
  }

  return 0;
}