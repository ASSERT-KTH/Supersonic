#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
typedef long long ll;
string S;
int ch[1 << 8];

ll bnf(int& p);
ll getNum(int& p) {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

inline ll get(ll &a, const ll &b, const char &c) {
  if (c == '+')
    a += b;
  if (c == '-')
    a -= b;
  if (c == '*')
    a *= b;
  return a;
}

ll calc(int& p, int c) {
  ll res, t;
  if (S[p] == '(')
    ++p, res = bnf(p), ++p;
  else
    res = getNum(p);

  while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
    t = S[p++], get(res, calc(p, ch[t]), t);
  return res;
}

ll bnf(int& p) {
  ll res = calc(p, -1), t;
  while (p < S.size() && S[p] != ')')
    t = S[p++], get(res, calc(p, ch[t]), t);
  return res;
}

int main() {
  cin >> S;
  ll res;
  int p = 0;
  res = bnf(p);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        res = max(res, calc(p, -100));
      }
  cout << res << endl;
  return 0;
}