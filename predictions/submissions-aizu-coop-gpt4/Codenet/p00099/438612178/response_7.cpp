#include <cstdio>
using namespace std;
const int MAX = 1000001;
int S[MAX];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int maxScore = 0;
  int maxNum = 0;
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    // Check if the new score is greater than the current maximum score
    if (S[a] > maxScore) {
      maxScore = S[a];
      maxNum = a;
    }
    printf("%d %d\n", maxNum, maxScore);
  }
  return 0;
}