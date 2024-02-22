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

// ... (remaining class and function definitions are not changed) ...

void compute(vector<Line> &vec) {
  if (vec.size() <= 2) {
    cout << MANY << endl;
    return;
  }

  vector<Line> candidateLines;
  int n = vec.size();
  rep(i, n) REP(j, i + 1, n) {
    Point cp;
    if (equals(cross(vec[i].p1 - vec[i].p2, vec[j].p1 - vec[j].p2), 0.0)) {
      // ... (same as before) ...
    } else {
      cp = crosspoint(vec[i], vec[j]);  // Save crosspoint to avoid recomputation
      // ... (same as before) ...
    }
    // ... (same as before) ...
  }

  // ... (same as before) ...

  vector<Point> answer;
  rep(i, candidatePoints.size()) {
    Point p = candidatePoints[i];
    double dist = -1;
    bool success = true;
    rep(j, vec.size()) {
      double tmp = distanceLP(vec[j], p);
      if (equals(dist, -1))
        dist = tmp;
      else if (!equals(dist, tmp)) {
        success = false;
        break;  // Skip remaining iterations if condition is not met
      }
    }
    if (success)
      answer.push_back(p);
    if (answer.size() >= 2)
      break;  // Skip remaining iterations if condition is met
  }

  // ... (same as before) ...
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