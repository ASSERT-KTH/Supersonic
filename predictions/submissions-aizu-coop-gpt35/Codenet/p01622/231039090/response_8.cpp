#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int solve() {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++) {
    sumf += book[i].f;
    sums += book[i].s;
  }

  if (2 * book[0].f <= sumf) {
    return sumf + sums;
  }

  int d = 2 * book[0].f - sumf;
  int dp[3000] = {1};
  int D = d;

  for (int i = 1; i < n; i++) {
    for (int j = d - book[i].s; j >= book[i].s; j--) {
      dp[j + book[i].s] |= dp[j];
    }
  }

  while (!dp[D]) {
    D--;
  }

  return sumf + sums + (d - D);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n && n) {
    vector<P> book(n);
    for (int i = 0; i < n; i++) {
      cin >> book[i].f >> book[i].s;
    }

    sort(book.begin(), book.end(), greater<P>());

    cout << solve() << endl;
  }

  return 0;
}