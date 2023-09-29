#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;
using ll = long long;

ll bnf();
ll getNum(string &S, int &p) {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}
ll get(ll &a, ll b, char c) {
  switch(c)
  {
    case '+':
      a += b;
      break;
    case '-':
      a -= b;
      break;
    case '*':
      a *= b;
      break;
  }
  return a;
}
ll calc(string &S, int &p, vector<int> &ch, int c) {
  ll res, t;
  if (S[p] == '(')
    p++, res = bnf(), p++;
  else
    res = getNum(S, p);
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
    t = S[p++], get(res, calc(S, p, ch, ch[t]), t);
  return res;
}
ll bnf(string &S, int &p, vector<int> &ch) {
  ll res = calc(S, p, ch, -1), t;
  while (p < S.size() && S[p] != ')')
    t = S[p++], get(res, calc(S, p, ch, ch[t]), t);
  return res;
}
int main() {
  string S;
  cin >> S;
  ll res = bnf(S, 0, vector<int>(1 << 8, -100));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        vector<int> ch(1 << 8);
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        int p = 0;
        res = max(res, calc(S, p, ch, -100));
      }
  cout << res << '\n';
  return 0;
}