#include <bits/stdc++.h>
using namespace std;

struct Book {
    int f, s;
};

int n;
Book book[1001];

int solve() {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++) { // Compute sumf and sums in a single loop
    sumf += book[i].f;
    sums += book[i].s;
  }
  if (2 * book[0].f <= sumf)
    return sumf + sums;

  int d = 2 * book[0].f - sumf, dp[3000] = {1}, D = d;
  for (int i = 1; i < n; i++)
    for (int j = d; j >= book[i].s; j--) // Iterate from end to start
      dp[j] |= dp[j - book[i].s];
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}

int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> book[i].f >> book[i].s;
    sort(book, book + n, [](const Book& a, const Book& b) { return a.f > b.f; });
    cout << solve() << endl;
  }
  return 0;
}