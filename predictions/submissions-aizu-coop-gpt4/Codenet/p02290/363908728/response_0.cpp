#include <bits/stdc++.h>
using namespace std;

#define D float
const D EPS = 1e-8;
const D INF = 1e9;
typedef complex<D> Point;

struct Line {
  Point p1, p2;
  Line(const Point &p1 = Point(), const Point &p2 = Point()) : p1(p1), p2(p2) {}
};

void projection(const Point &a, const Point &b, Point &res) { 
    res = a * real(b / a);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  Line L;
  cin >> L.p1 >> L.p2;
  int Q;
  cin >> Q;
  Point p, w;
  while (Q--) {
    cin >> p;
    projection(L.p2 - L.p1, p - L.p1, w);
    cout << fixed << setprecision(15) << w << endl;
  }
  return 0;
}