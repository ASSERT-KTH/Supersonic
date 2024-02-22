#include <iostream>
#include <algorithm>
using namespace std;

struct Book {
  int f;
  int s;
};

bool compareBooks(const Book& b1, const Book& b2) {
  return (b1.f + b1.s) > (b2.f + b2.s);
}

int solve(int n, Book* books) {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++) {
    sumf += books[i].f;
    sums += books[i].s;
  }

  if (2 * books[0].f <= sumf) {
    return sumf + sums;
  }

  int d = 2 * books[0].f - sumf;
  int dp[3000] = {1};
  int D = d;

  for (int i = 0; i < n; i++) {
    for (int j = D - books[i].s; j >= 0; j--) {
      if (dp[j]) {
        dp[j + books[i].s] = 1;
      }
    }
  }

  while (!dp[D]) {
    D--;
  }

  return sumf + sums + (d - D);
}

int main() {
  int n;
  while (cin >> n && n) {
    Book books[1001];
    for (int i = 0; i < n; i++) {
      cin >> books[i].f >> books[i].s;
    }
    sort(books, books + n, compareBooks);
    cout << solve(n, books) << endl;
  }
  return 0;
}