#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Book {
  int f;
  int s;
};

int solve(int n, const vector<Book>& books) {
  int sumf = 0, sums = 0;
  for (const auto& book : books) {
    sumf += book.f;
    sums += book.s;
  }
  
  if (2 * books[0].f <= sumf) {
    return sumf + sums;
  }
  
  int d = 2 * books[0].f - sumf;
  int D = d;
  vector<bool> dp(d + 1, false);
  dp[0] = true;
  
  for (const auto& book : books) {
    for (int j = d - book.s; j >= 0; j--) {
      dp[j + book.s] |= dp[j];
    }
  }
  
  while (!dp[D]) {
    D--;
  }
  
  return sumf + sums + (d - D);
}

int main() {
  int n;
  while (cin >> n, n) {
    vector<Book> books(n);
    for (int i = 0; i < n; i++) {
      cin >> books[i].f >> books[i].s;
    }
    
    priority_queue<Book, vector<Book>, greater<Book>> pq(books.begin(), books.end());
    cout << solve(n, vector<Book>(pq.begin(), pq.end())) << endl;
  }
  
  return 0;
}