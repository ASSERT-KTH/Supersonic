#include <iostream>
#include <algorithm>
using namespace std;

int n;
int book_values[1001];
int book_weights[1001];

int solve() {
  int sum_values = 0, sum_weights = 0;
  for (int i = 0; i < n; i++)
    sum_values += book_values[i], sum_weights += book_weights[i];
  if (2 * book_weights[0] <= sum_weights)
    return sum_values + sum_weights;
  int d = 2 * book_weights[0] - sum_weights;
  int dp[3000] = {1}, D = d;
  for (int i = 1; i < n; i++)
    for (int j = d; j >= book_weights[i]; j--)
      dp[j] |= dp[j - book_weights[i]];
  while (!dp[D])
    D--;
  return sum_values + sum_weights + (d - D);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> book_values[i] >> book_weights[i];
    sort(book_weights, book_weights + n, greater<int>());
    cout << solve() << endl;
  }
  
  return 0;
}