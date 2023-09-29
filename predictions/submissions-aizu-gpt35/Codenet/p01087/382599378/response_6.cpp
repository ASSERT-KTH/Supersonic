#include <bits/stdc++.h>
using namespace std;
int solve(vector<string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  vector<int> term;
  while (y < n && (int)s[y].size() > x) {
    term.push_back(solve(s, n, y, x));
  }
  int res = term[0];
  for(int i = 1; i < term.size(); i++){
      if(op == '+')
        res += term[i];
      else
        res *= term[i];
  }
  return res;
}
int main(void) {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    int y = 0;
    cout << solve(s, n, y, 0) << endl;
  }
  return 0;
}