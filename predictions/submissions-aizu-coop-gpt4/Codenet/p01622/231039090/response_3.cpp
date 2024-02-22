#include <iostream>
#include <utility>
#include <algorithm>
#include <array>

#define f first
#define s second

using namespace std;
typedef pair<int, int> P;

int n;
array<P, 1001> book;

int solve(int sumf, int sums) {
  if (2 * book[0].f <= sumf)
    return sumf + sums;
  int d = 2 * book[0].f - sumf, D = d;
  
  // Dynamically sized dp array
  array<int, decltype(d)> dp {1}; 
  
  for (int i = 1; i < n; i++)
    for (int j = d - book[i].s; j >= 0; j--)
      dp[j + book[i].s] |= dp[j];
      
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}

int main() {
  while (cin >> n, n) {
    int sumf = 0, sums = 0;
    for (int i = 0; i < n; i++) {
      cin >> book[i].f >> book[i].s;
      sumf += book[i].f;
      sums += book[i].s;
    }
    sort(book.begin(), book.begin() + n, greater<P>());
    cout << solve(sumf, sums) << endl;
  }
  return 0;
}