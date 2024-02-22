#include <iostream>
#include <algorithm>
using namespace std;

struct Book {
  int pages;
  int stickers;
};

bool compareBooks(const Book& b1, const Book& b2) {
  return b1.pages > b2.pages;
}

int solve(const Book* books, int n) {
  int sumPages = 0, sumStickers = 0;
  for (int i = 0; i < n; i++) {
    sumPages += books[i].pages;
    sumStickers += books[i].stickers;
  }
  if (2 * books[0].pages <= sumPages) {
    return sumPages + sumStickers;
  }
  int d = 2 * books[0].pages - sumPages;
  int D = d;
  bool dp[3000] = {true};
  for (int i = 1; i < n; i++) {
    for (int j = d - books[i].stickers; j >= 0; j--) {
      dp[j + books[i].stickers] |= dp[j];
    }
  }
  while (!dp[D]) {
    D--;
  }
  return sumPages + sumStickers + (d - D);
}

int main() {
  int n;
  while (cin >> n && n) {
    Book* books = new Book[n];
    for (int i = 0; i < n; i++) {
      cin >> books[i].pages >> books[i].stickers;
    }
    sort(books, books + n, compareBooks);
    cout << solve(books, n) << endl;
    delete[] books;
  }
  return 0;
}