#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001];
int memo2[1000001];

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++) {
    p[i] = i * (i + 1) * (i + 2) / 6;  // Generate pentagonal numbers
    if (p[i] % 2) {  // Generate odd pentagonal numbers
      memo2[i] = i ? INF : 0;  // Initialize memo2
      for (int j = 0; p[j] <= i; j++)
        if (p[j] % 2)
          memo2[i] = min(memo2[i], memo2[i - p[j]] + 1);
    }
    memo[i] = i ? INF : 0;  // Initialize memo
    for (int j = 0; p[j] <= i; j++)
      memo[i] = min(memo[i], memo[i - p[j]] + 1);
  }

  while (cin >> n, n)
    cout << memo[n] << " " << memo2[n] << endl;

  return 0;
}