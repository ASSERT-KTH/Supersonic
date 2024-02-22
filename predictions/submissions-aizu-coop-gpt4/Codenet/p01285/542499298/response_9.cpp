// ... (the rest of the code remains the same)

void compute(vector<Line> &vec) {
  if (vec.size() <= 2) {
    cout << MANY << "\n";
    return;
  }
  
  // ... (the rest of the code remains the same)

  vector<Point> candidatePoints;
  rep(i, candidateLines.size()) REP(j, i + 1, candidateLines.size()) {
    Line line1 = candidateLines[i];
    Line line2 = candidateLines[j];
    if (equals(cross(line1.p1 - line1.p2, line2.p1 - line2.p2), 0.0))
      continue;
    Point cp = crosspoint(line1, line2);
    candidatePoints.push_back(cp);
  }
  
  // Optimize unique usage
  auto& v = candidatePoints;
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());

  // ... (the rest of the code remains the same)

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