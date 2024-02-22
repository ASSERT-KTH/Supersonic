#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

struct Pair {
  int first;
  int second;
};

int solve(const vector<Pair>& book, int n) {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++) {
    sumf += book[i].first;
    sums += book[i].second;
  }
  if (2 * book[0].first <= sumf) {
    return sumf + sums;
  }
  int d = 2 * book[0].first - sumf;
  bool dp[2001] = {true};
  for (int i = 1; i < n; i++) {
    for (int j = d - book[i].second; j >= 0; j--) {
      dp[j + book[i].second] = dp[j + book[i].second] || dp[j];
    }
  }
  int D = d;
  for (int i = 0; i < d; i++) {
    if (!dp[D]) {
      D--;
    }
  }
  return sumf + sums + (d - D);
}

int main() {
  int n;
  while (cin >> n && n) {
    vector<Pair> book(n);
    for (int i = 0; i < n; i++) {
      cin >> book[i].first >> book[i].second;
    }
    bool sorted = true;
    for (int i = 1; i < n; i++) {
      if (book[i].first > book[i - 1].first) {
        sorted = false;
        break;
      }
    }
    if (!sorted) {
      sort(book.begin(), book.end(), [](const Pair& p1, const Pair& p2) {
        return p1.first > p2.first;
      });
    }
    cout << solve(book, n) << endl;
  }
  return 0;
}