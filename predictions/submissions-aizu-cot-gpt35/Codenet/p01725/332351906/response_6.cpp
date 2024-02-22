#include <iostream>
#include <string>
typedef long long ll;

std::string S;
int p, ch[256];

ll bnf();
ll getNum() {
  ll res = 0;
  while (std::isdigit(S[p]))
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
  ll res = 0, t = 0; // Initialize variables
  if (S[p] == '(')
    p++, res = bnf(), p++;
  else
    res = getNum();
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c) {
    t = S[p++];
    get(res, calc(ch[t]), t);
  }
  return res;
}
ll bnf() {
  ll res = calc(-1), t = 0; // Initialize variables
  while (p < S.size() && S[p] != ')') {
    t = S[p++];
    get(res, calc(ch[t]), t);
  }
  return res;
}
int main() {
  std::cin >> S;
  ll res = bnf();
  for (const int& i : {0, 1, 2})
    for (const int& j : {0, 1, 2})
      for (const int& k : {0, 1, 2}) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        res = std::max(res, calc(-100));
      }
  std::cout << res << std::endl;
  return 0;
}