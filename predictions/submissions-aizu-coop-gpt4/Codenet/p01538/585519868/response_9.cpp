#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
  int Q, N, count, max, S;
  bool FLG;
  scanf("%d", &Q);
  unordered_set<int> table;
  for (int loop = 0; loop < Q; loop++) {
    table.clear();
    count = 0;
    scanf("%d", &N);
    table.insert(N);
    FLG = false;
    while (true) {
      if (N / 10 == 0)
        break;
      vector<int> digits;
      for (int tmp = N; tmp > 0; tmp /= 10)
        digits.push_back(tmp % 10);
      max = 0;
      for (int i = 0; i < digits.size(); i++)
        for (int j = i + 1; j < digits.size(); j++)
          max = max(max, digits[i] * digits[j]);
      N = max;
      if (table.find(N) != table.end()) {
        FLG = true;
        break;
      } else {
        table.insert(N);
        count++;
      }
    }
    if (FLG) {
      printf("-1\n");
    } else {
      printf("%d\n", count);
    }
  }
  return 0;
}