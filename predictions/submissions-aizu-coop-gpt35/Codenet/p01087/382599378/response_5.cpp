#include <bits/stdc++.h>
using namespace std;

int solve(const vector<string>& s, int n) {
  const char* p = s[0].c_str();
  stack<int> stk;
  while (*p) {
    if (isdigit(*p)) {
      stk.push(*p - '0');
      ++p;
    } else if (*p == '+') {
      int sum = 0;
      while (!stk.empty()) {
        sum += stk.top();
        stk.pop();
      }
      stk.push(sum);
      ++p;
    } else {
      int prod = 1;
      while (!stk.empty()) {
        prod *= stk.top();
        stk.pop();
      }
      stk.push(prod);
      ++p;
    }
  }
  return stk.top();
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    cout << solve(s, n) << endl;
  }
  return 0;
}