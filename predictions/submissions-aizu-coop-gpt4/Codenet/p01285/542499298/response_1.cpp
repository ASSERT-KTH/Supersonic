// ... (same as the original code)

void compute(vector<Line> &vec) {
  if (vec.size() <= 2) {
    cout << MANY << "\n";
    return;
  }
  vector<Line> candidateLines;
  int n = vec.size();
  set<Point> candidatePoints;
  rep(i, n) REP(j, i + 1, n) {
    double crossValue = cross(vec[i].p1 - vec[i].p2, vec[j].p1 - vec[j].p2);
    if (equals(crossValue, 0.0)) {
      // ... (same as the original code)
    } else {
      // ... (same as the original code)
    }
    if (candidateLines.size() >= 10)
      break;
  }
  rep(i, candidateLines.size()) REP(j, i + 1, candidateLines.size()) {
    Line line1 = candidateLines[i];
    Line line2 = candidateLines[j];
    double crossValue = cross(line1.p1 - line1.p2, line2.p1 - line2.p2);
    if (equals(crossValue, 0.0))
      continue;
    Point cp = crosspoint(line1, line2);
    candidatePoints.insert(cp);
  }
  vector<Point> answer;
  for (auto p : candidatePoints) {
    // ... (same as the original code)
  }
  if (answer.size() == 1)
    printf("%.10f %.10f\n", answer[0].x, answer[0].y);
  else if (answer.empty())
    cout << NONE << "\n";
  else
    cout << MANY << "\n";
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