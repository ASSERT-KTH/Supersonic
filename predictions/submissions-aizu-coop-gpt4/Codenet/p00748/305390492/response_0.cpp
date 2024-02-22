#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];
int memo2[1000001];
int main() {
  // Calculate the pentagonal numbers that are less than 1000000.
  int i = 0;
  while (true) {
    int pentagonal = i * (i + 1) * (i + 2) / 6;
    if (pentagonal > 1000000)
      break;
    p[i] = pentagonal;
    i++;
  }
  // Initialize the dynamic programming tables.
  fill(memo[0], memo[1000001], INF);
  fill(memo2, memo2 + 1000001, INF);
  memo[0][0] = memo2[0] = 0;
  // Fill in the dynamic programming tables.
  for (int n = 1; n <= 1000000; n++) {
    for (int count = 1; count <= 5; count++) {
      for (int j = 0; j < i && p[j] <= n; j++) {
        memo[n][count] = min(memo[n][count], memo[n - p[j]][count - 1] + 1);
      }
    }
    for (int j = 0; j < i && p[j] <= n; j++) {
      if (p[j] % 2)
        memo2[n] = min(memo2[n], memo2[n - p[j]] + 1);
    }
  }
  // Answer the queries.
  int n;
  while (cin >> n, n)
    cout << memo[n][5] << " " << memo2[n] << endl;
}