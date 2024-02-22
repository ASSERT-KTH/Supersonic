#include <iostream>
#include <string>
#include <algorithm>

typedef long long ll;

std::string S;
int p, ch[1 << 8];
ll res, t;
int len;

ll bnf();
ll getNum() {
  ll res = 0;
  while (std::isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

ll get(ll &a, ll b, char c) {
  switch(c) {
    case '+': a += b; break;
    case '-': a -= b; break;
    case '*': a *= b; break;
  }
  return a;
}

ll calc(int c) {
  if (S[p] == '(')
    p++, res = bnf(), p++;
  else
    res = getNum();
  while (p < len && S[p] != ')' && ch[S[p]] > c)
    t = S[p++], get(res, calc(ch[t]), t);
  return res;
}

ll bnf() {
  res = calc(-1);
  while (p < len && S[p] != ')')
    t = S[p++], get(res, calc(ch[t]), t);
  return res;
}

int main() {
  std::cin >> S;
  len = S.size();
  res = bnf();
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        res = std::max(res, calc(-100));
      }
  std::cout << res << std::endl;
  return 0;
}