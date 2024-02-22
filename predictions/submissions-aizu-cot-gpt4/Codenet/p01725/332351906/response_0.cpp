#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p;
char ch[1 << 8];
string S;

ll bnf();
ll getNum();

ll calc(int c) {
  ll res;
  if (S[p] == '(')
    ++p, res = bnf(), ++p;
  else
    res = getNum();
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
    res = ((S[p] == '+') ? res += calc(ch[S[p++]]) : ((S[p] == '-') ? res -= calc(ch[S[p++]]) : res *= calc(ch[S[p++]])));
  return res;
}

ll bnf() {
  ll res = calc(-1);
  while (p < S.size() && S[p] != ')')
    res = ((S[p] == '+') ? res += calc(ch[S[p++]]) : ((S[p] == '-') ? res -= calc(ch[S[p++]]) : res *= calc(ch[S[p++]])));
  return res;
}

ll getNum() {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

int main() {
  cin >> S;
  ll res = bnf();
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        res = max(res, calc(-100));
      }
  cout << res << "\n";
  return 0;
}