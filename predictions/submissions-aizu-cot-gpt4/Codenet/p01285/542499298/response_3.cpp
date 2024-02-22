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
const double PI_OVER_180 = M_PI / 180.0; // New constant for toRad function
//... rest of the code remains the same...
double toRad(double agl) { return agl * PI_OVER_180; } // Uses the new constant
//... rest of the code remains the same...
Point crosspoint(Line l, Line m) {
  //... code before this remains the same...
  if (abs(A) < EPS && abs(B) < EPS) {
    array<Point, 4> arr = {l.p1, l.p2, m.p1, m.p2}; // Using array instead of vector
    sort(arr.begin(), arr.end());
    assert(arr[1] == arr[2]);
    return arr[1];
  }
  //... code after this remains the same...
}
//... rest of the code remains the same...
void compute(vector<Line> &vec) {
  //... code before this remains the same...
  set<Point> candidatePoints; // Using set instead of vector
  // ... rest of the code remains the same...
  for(auto p : candidatePoints) { // Using range-based for loop
    //... rest of the code remains the same...
  }
  //... rest of the code remains the same...
}
//... rest of the code remains the same...