#include <cstdio>
#include <iostream>
const int MAX = 1000001;
int S[MAX];
struct data {
  int num, score;
  data() {}
  data(int n, int s) : num(n), score(s) {}
  bool operator<(const data &d) const {
    if (score != d.score)
      return score < d.score;
    return num > d.num;
  }
};
int main() {
  int n, m;
  std::scanf("%d %d", &n, &m);
  int maxScore[MAX] = {0}; // Array to store the maximum score for each index
  int maxIndex = 0, maxScoreValue = 0; // Variables to store the index and score with maximum value
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::scanf("%d %d", &a, &b);
    S[a] += b;
    if (S[a] > maxScore[a]) { // Update the maximum score for the index if necessary
      maxScore[a] = S[a];
      if (S[a] > maxScoreValue) { // Update the index and score with maximum value if necessary
        maxIndex = a;
        maxScoreValue = S[a];
      }
    }
    std::printf("%d %d\n", maxIndex, maxScoreValue); // Print the maximum index and score
  }
  return 0;
}