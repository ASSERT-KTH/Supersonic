#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string S;
int ch[1 << 8];
ll bnf(int, int);
ll getNum() {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}
ll get(ll &a, ll b, char c) {
  if (c == '+')
    a += b;
  if (c == '-')
    a -= b;
  if (c == '*')
    a *= b;
  return a;
}
ll calc(int c, int mx) {
  ll res, t;
  if (S[p] == '(')
    p++, res = bnf(c + 1, mx), p++;
  else
    res = getNum();
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c && ch[S[p]] <= mx)
    t = S[p++], get(res, calc(ch[t], mx), t);
  return res;
}
ll bnf(int c, int mx) {
  ll res = calc(c, mx), t;
  while (p < S.size() && S[p] != ')' && ch[S[p]] <= mx)
    t = S[p++], get(res, calc(ch[t], mx), t);
  return res;
}
int main() {
  cin >> S;
  ll res = bnf(-1, 2);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        res = max(res, bnf(-100, 0));
      }
  cout << res << endl;
  return 0;
}