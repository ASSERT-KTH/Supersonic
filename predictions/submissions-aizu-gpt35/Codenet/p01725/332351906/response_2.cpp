#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string S;
int ch[1 << 8];
ll bnf();
ll getNum() {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

ll calc(int c, int &p) {
  ll res, t;
  if (S[p] == '(')
    p++, res = bnf(), p++;
  else
    res = getNum();
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
    t = S[p++], get(res, calc(ch[t], p), t);
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

ll bnf() {
  ll res = calc(-1, p);
  while (p < S.size() && S[p] != ')')
    get(res, calc(ch[S[p++]], p), S[p - 1]);
  return res;
}

int main() {
  cin >> S;
  ll res = bnf();
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        int p = 0;
        res = max(res, calc(-100, p));
      }
  cout << res << endl;
  return 0;
}