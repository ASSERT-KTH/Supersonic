#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int solve(vector<P>& book) {
  int sumf = accumulate(book.begin(), book.end(), 0, [](int acc, const P& b) { return acc + b.first; });
  int sums = accumulate(book.begin(), book.end(), 0, [](int acc, const P& b) { return acc + b.second; });

  if (2 * book[0].first <= sumf)
    return sumf + sums;

  int d = 2 * book[0].first - sumf;
  vector<int> dp(d + 1);
  dp[0] = 1;

  for (int i = 0; i < book.size(); i++) {
    for (int j = d - book[i].second; j >= 0; j--) {
      dp[j + book[i].second] |= dp[j];
    }
  }

  int D = d;
  for (; D >= 0; D--) {
    if (dp[D])
      break;
  }

  return sumf + sums + (d - D);
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  while (cin >> n, n) {
    vector<P> book(n);
    for (int i = 0; i < n; i++) {
      cin >> book[i].first >> book[i].second;
    }
    sort(book.begin(), book.end(), greater<P>());
    cout << solve(book) << endl;
  }

  return 0;
}