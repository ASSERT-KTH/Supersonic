#include <iostream>
#include <string>

typedef long long ll;

int main() {
  std::string S;
  std::cin >> S;

  const int numOperators = 3;
  const char operators[numOperators] = {'+', '-', '*'};

  ll res = 0;
  for (int i = 0; i < numOperators; i++) {
    for (int j = 0; j < numOperators; j++) {
      for (int k = 0; k < numOperators; k++) {
        char ch['+'] = i, ch['-'] = j, ch['*'] = k;
        int p = 0;
        ll tempRes = bnf(S, ch, p);
        res = std::max(res, tempRes);
      }
    }
  }

  std::cout << res << std::endl;
  return 0;
}

ll getNum(const std::string& S, int& p) {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

ll get(ll a, ll b, char c) {
  if (c == '+')
    return a + b;
  if (c == '-')
    return a - b;
  if (c == '*')
    return a * b;
  return a;
}

ll calc(const std::string& S, const char* ch, int& p) {
  ll res = 0;
  if (S[p] == '(') {
    ++p;
    res = bnf(S, ch, p);
    ++p;
  } else {
    res = getNum(S, p);
  }
  
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c) {
    char t = S[p++];
    res = get(res, calc(S, ch, p), t);
  }
  
  return res;
}

ll bnf(const std::string& S, const char* ch, int& p) {
  ll res = calc(S, ch, p);
  while (p < S.size() && S[p] != ')') {
    char t = S[p++];
    res = get(res, calc(S, ch, p), t);
  }
  return res;
}