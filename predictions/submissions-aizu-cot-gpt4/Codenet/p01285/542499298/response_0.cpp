#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define EPS (1e-6)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
using namespace std;

// ... rest of the code ...

void compute(vector<Line> &vec) {
  // ... same code ...
  
  if (answer.size() == 1)
    printf("%.10f %.10f\n", answer[0].x, answer[0].y);
  else if (answer.empty())
    cout << NONE << '\n';
  else
    cout << MANY << '\n';
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