#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Book {
  int f;
  int s;
};

int solve(vector<Book>& books) {
  int sumF = 0, sumS = 0;
  for (const auto& book : books) {
    sumF += book.f;
    sumS += book.s;
  }

  if (2 * books[0].f <= sumF) {
    return sumF + sumS;
  }

  int d = 2 * books[0].f - sumF;
  vector<bool> dp(d + 1, false);
  dp[0] = true;

  for (const auto& book : books) {
    for (int j = d - book.s; j >= 0; j--) {
      dp[j + book.s] |= dp[j];
    }
  }

  int D = d;
  while (!dp[D]) {
    D--;
  }

  return sumF + sumS + (d - D);
}

int main() {
  int n;
  while (cin >> n && n != 0) {
    vector<Book> books(n);
    for (int i = 0; i < n; i++) {
      cin >> books[i].f >> books[i].s;
    }

    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
      return a.f > b.f;
    });

    cout << solve(books) << endl;
  }

  return 0;
}