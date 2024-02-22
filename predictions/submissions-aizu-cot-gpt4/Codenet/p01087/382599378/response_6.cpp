#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int solve(vector<string> &s, int n, int &y, int x) {
  if (s[y][x] >= '0' && s[y][x] <= '9')
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  int sum = 0, product = 1;
  while (y < n && (int)s[y].size() > x) {
    int temp = solve(s, n, y, x);
    sum += temp;
    product *= temp;
  }
  if (op == '+')
    return sum;
  else
    return product;
}

int main(void) {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    int y = 0;
    cout << solve(s, n, y, 0) << endl;
  }
  return 0;
}