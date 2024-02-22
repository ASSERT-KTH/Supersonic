#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string S;
int p, ch[1 << 8];
ll bnf();
ll getNum() {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}
ll get(ll &a, ll b, char c) {
  switch (c) {
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
ll calc(int c) {
  ll res, t;
  if (S[p] == '(')
    p++, res = bnf(), p++;
  else
    res = getNum();
  int size = S.size();
  while (p < size && S[p] != ')' && ch[S[p]] > c)
    t = S[p++], get(res, calc(ch[t]), t);
  return res;
}
ll bnf() {
  ll res = calc(-1), t;
  int size = S.size();
  bool cond = p < size && S[p] != ')';
  while (cond)
    t = S[p++], get(res, calc(ch[t]), t), cond = p < size && S[p] != ')';
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> S;
  ll res = bnf();
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        ll temp = calc(-100);
        res = res > temp ? res : temp;
      }
  cout << res << '\n';
  return 0;
}