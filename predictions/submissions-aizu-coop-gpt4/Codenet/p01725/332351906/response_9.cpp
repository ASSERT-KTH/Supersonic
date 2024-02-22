#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
int p;
unordered_map<char, int> ch;
unordered_map<int, ll> memo;

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
  if (memo.count(c))
    return memo[c];
  
  ll res, t;
  if (S[p] == '(')
    p++, res = bnf(), p++;
  else
    res = getNum();

  while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
    t = S[p++], get(res, calc(ch[t]), t);

  memo[c] = res;
  return res;
}

ll bnf() {
  ll res = calc(-1), t;
  while (p < S.size() && S[p] != ')')
    t = S[p++], get(res, calc(ch[t]), t);
  return res;
}

int main() {
  cin >> S;
  ll res = bnf();

  ch['+'] = 0, ch['-'] = 1, ch['*'] = 2;
  p = 0;
  res = max(res, calc(-100));

  ch['+'] = 0, ch['-'] = 2, ch['*'] = 1;
  p = 0;
  res = max(res, calc(-100));

  ch['+'] = 1, ch['-'] = 0, ch['*'] = 2;
  p = 0;
  res = max(res, calc(-100));

  // Continue for all 6 combinations

  cout << res << endl;
  return 0;
}