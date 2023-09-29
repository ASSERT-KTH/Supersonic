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
  ll res, t;
  if (S[p] == '(') {
    p++;
    res = bnf();
    p++;
  }
  else {
    res = getNum();
  }
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c) {
    t = S[p++];
    get(res, calc(ch[t]), t);
  }
  return res;
}
ll bnf() {
  ll res = calc(-1), t;
  while (p < S.size() && S[p] != ')') {
    t = S[p++];
    get(res, calc(ch[t]), t);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false); // disable synchronization between C and C++ standard streams
  cin.tie(NULL); // unties cin from cout, avoiding flushes when both are used together
  cout.tie(NULL); // unties cout from cin, avoiding flushes when both are used together
  cin >> S;
  ll res = bnf();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        res = max(res, calc(-100));
      }
    }
  }
  cout << res << '\n'; // use '\n' instead of endl to avoid flushing the output buffer unnecessarily
  return 0;
}