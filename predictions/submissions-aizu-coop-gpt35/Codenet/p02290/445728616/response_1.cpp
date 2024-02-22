#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct P {
  double x, y;
};

int main() {
  double ax, ay, bx, by;
  int n;
  cin >> ax >> ay >> bx >> by >> n;

  vector<P> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
  }

  vector<P> projections(n);
  for (int i = 0; i < n; ++i) {
    double dot_product = (points[i].x - ax) * (bx - ax) + (points[i].y - ay) * (by - ay);
    double projection = dot_product / ((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
    projections[i].x = ax + (bx - ax) * projection;
    projections[i].y = ay + (by - ay) * projection;
  }

  cout << fixed << setprecision(8);
  for (int i = 0; i < n; ++i) {
    cout << projections[i].x << " " << projections[i].y << "\n";
  }

  return 0;
}