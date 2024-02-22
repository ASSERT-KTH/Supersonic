#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

const int MAX_SIZE = 1000; // Define a large enough size

int solve(vector<string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[++y][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  array<int, MAX_SIZE> term; // Use array instead of vector
  int term_count = 0;
  while (y < n && (int)s[y].size() > x) {
    term[term_count++] = solve(s, n, y, x);
  }
  if (op == '+') {
    int sum = 0;
    // Replace accumulate with a simple loop
    for(int i = 0; i < term_count; ++i)
      sum += term[i];
    return sum;
  }
  else {
    int product = 1;
    // Replace accumulate with a simple loop
    for(int i = 0; i < term_count; ++i)
      product *= term[i];
    return product;
  }
}

int main(void) {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int y = 0;
    cout << solve(s, n, y, 0) << endl;
  }
  return 0;
}