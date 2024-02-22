#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getNum(string &S, int &p) {
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

ll calc(string &S, int &p, int c, vector<int> &ch);
ll bnf(string &S, int &p, vector<int> &ch) {
  ll res = calc(S, p, -1, ch), t;
  int S_size = S.size();
  while (p < S_size && S[p] != ')')
    t = S[p++], get(res, calc(S, p, ch[t], ch), t);
  return res;
}

ll calc(string &S, int &p, int c, vector<int> &ch) {
  ll res, t;
  int S_size = S.size();
  if (S[p] == '(')
    p++, res = bnf(S, p, ch), p++;
  else
    res = getNum(S, p);
  while (p < S_size && S[p] != ')' && ch[S[p]] > c)
    t = S[p++], get(res, calc(S, p, ch[t], ch), t);
  return res;
}

int main() {
  string S;
  cin >> S;
  vector<int> ch(1 << 8);
  int p = 0;
  ll res = bnf(S, p, ch);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        res = max(res, calc(S, p, -100, ch));
      }
  cout << res << endl;
  return 0;
}