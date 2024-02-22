#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> &s, int n) {
  stack<int> stk;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < s[y].size(); ++x) {
      if (isdigit(s[y][x]))
        stk.push(s[y][x] - '0');
      else {
        vector<int> term;
        term.reserve(n);  // Preallocate term vector
        while (!stk.empty()) {
          term.push_back(stk.top());
          stk.pop();
        }
        if (s[y][x] == '+')
          stk.push(accumulate(term.begin(), term.end(), 0));
        else
          stk.push(accumulate(term.begin(), term.end(), 1, multiplies<int>()));
      }
    }
  }
  return stk.top();
}

int main(void) {
  int n;
  while (scanf("%d", &n) != EOF, n) {
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
      cin >> s[i];
    printf("%d\n", solve(s, n));
  }
  return 0;
}