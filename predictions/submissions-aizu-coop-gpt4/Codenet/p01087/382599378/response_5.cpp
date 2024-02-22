#include <bits/stdc++.h>
using namespace std;

#define MAX_TERMS 100
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(a) a.begin(), a.end()

int solve(vector<string> &s, vector<int> &lengths, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';

  char op = s[y][x];
  ++y; ++x;

  int term[MAX_TERMS];
  int term_count = 0;
  
  while (y < n && x < lengths[y]) {
    term[term_count++] = solve(s, lengths, n, y, x);
  }

  if (op == '+')
    return accumulate(term, term + term_count, 0);
  else
    return accumulate(term, term + term_count, 1, multiplies<int>());
}

int main(void) {
  int n;
  
  while (cin >> n, n) {
    vector<string> s(n);
    vector<int> lengths(n);
    
    rep(i, n) {
      cin >> s[i];
      lengths[i] = s[i].size();
    }
    
    int y = 0;
    cout << solve(s, lengths, n, y, 0) << endl;
  }
  return 0;
}