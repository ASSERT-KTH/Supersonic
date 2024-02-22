// Optimized Code
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
  if (c == '+')
    a += b;
  if (c == '-')
    a -= b;
  if (c == '*')
    a *= b;
  return a;
}
ll calc(int c) {
  stack<ll> st;
  if (S[p] == '(')
    p++, st.push(bnf()), p++;
  else
    st.push(getNum());
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
    st.push(get(st.top(), calc(ch[S[p++]]), S[p]));
  return st.top();
}
ll bnf() {
  stack<ll> st;
  st.push(calc(-1));
  while (p < S.size() && S[p] != ')')
    st.push(get(st.top(), calc(ch[S[p++]]), S[p]));
  return st.top();
}
int main() {
  cin >> S;
  ll res = bnf();
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        res = max(res, calc(-100));
      }
  cout << res << endl;
  return 0;
}