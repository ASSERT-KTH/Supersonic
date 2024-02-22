#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  vector<bool> num(1000000, true);
  num[0] = num[1] = false;
  int sqrtN = sqrt(1000000);
  for (int i = 2; i <= sqrtN; i++) {
    if (num[i]) {
      for (int j = i * i; j < 1000000; j += i)
        num[j] = false;
    }
  }
  for (int i = 1; i < 1000000 - 1; i++) {
    if (num[i])
      num[i + 1] += num[i];
  }
  int queryCount;
  scanf("%d", &queryCount);
  for (int i = 0; i < queryCount; i++) {
    int n;
    scanf("%d", &n);
    printf("%d\n", num[n]);
  }
  return 0;
}