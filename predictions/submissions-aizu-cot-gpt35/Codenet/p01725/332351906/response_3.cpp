#include <iostream>
#include <string>

typedef long long ll;

ll getNum(const std::string& S, int& p) {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

ll get(ll& a, ll b, char c) {
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

ll calc(const std::string& S, int& p, const int* ch) {
  ll res = getNum(S, p);
  while (p < S.size() && S[p] != ')' && ch[S[p]] > -1) {
    char t = S[p++];
    get(res, calc(S, p, ch), t);
  }
  return res;
}

ll bnf(const std::string& S, const int* ch) {
  int p = 0;
  ll res = calc(S, p, ch);
  while (p < S.size() && S[p] != ')') {
    char t = S[p++];
    get(res, calc(S, p, ch), t);
  }
  return res;
}

int main() {
  std::string S;
  std::cin >> S;
  
  int ch[1 << 8];
  ll res = bnf(S, ch);
  
  for (int i = 0; i < 27; i++) {
    ch['+'] = i / 9;
    ch['-'] = (i / 3) % 3;
    ch['*'] = i % 3;
    res = std::max(res, bnf(S, ch));
  }
  
  std::cout << res << std::endl;
  
  return 0;
}