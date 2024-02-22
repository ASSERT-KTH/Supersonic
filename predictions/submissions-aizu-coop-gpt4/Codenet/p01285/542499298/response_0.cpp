#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>

//... other parts of the code remain the same

void compute(vector<Line>& vec) {
  if (vec.size() <= 2) {
    cout << MANY << '\n';
    return;
  }
  vector<Line> candidateLines;
  candidateLines.reserve(10); // Reserve space in vector
  int n = vec.size();
  for (int i = 0; i < n; ++i) { // Replace macro with loop
    for (int j = i + 1; j < n; ++j) { // Replace macro with loop
      double crossVec = cross(vec[i].p1 - vec[i].p2, vec[j].p1 - vec[j].p2);
      if (equals(crossVec, 0.0)) {
        //... the code remains the same
      } else {
        //... the code remains the same
      }
      if (candidateLines.size() >= 10)
        break;
    }
  }

  //... other parts of the code remain the same

  if (answer.size() == 1)
    printf("%.10f %.10f\n", answer[0].x, answer[0].y);
  else if (answer.empty())
    cout << NONE << '\n'; // Use '\n' instead of endl
  else
    cout << MANY << '\n'; // Use '\n' instead of endl
}