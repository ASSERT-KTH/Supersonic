#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;

ll bnf(string &S, int &p, int ch[1 << 8]);

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

ll calc(string &S, int &p, int ch[1 << 8], int c) {
  ll res, t;
  if (S[p] == '(')
    p++, res = bnf(S, p, ch), p++;
  else
    res = getNum(S, p);
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
    t = S[p++], get(res, calc(S, p, ch, ch[t]), t);
  return res;
}

ll bnf(string &S, int &p, int ch[1 << 8]) {
  ll res = calc(S, p, ch, -1), t;
  while (p < S.size() && S[p] != ')')
    t = S[p++], get(res, calc(S, p, ch, ch[t]), t);
  return res;
}

int main() {
  string S;
  cin >> S;
  int p = 0;
  ll res = bnf(S, p, new int[1 << 8]);
  ll temp_result;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        int ch[1 << 8];
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        temp_result = calc(S, p, ch, -100);
        res = max(res, temp_result);
      }
    }
  }
  cout << res << endl;
  return 0;
}