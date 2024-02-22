#include <iostream>
#include <string>

using ll = long long;

ll getNum(const std::string& S, int& p) {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

ll get(ll a, ll b, char c) {
  if (c == '+')
    a += b;
  if (c == '-')
    a -= b;
  if (c == '*')
    a *= b;
  return a;
}

ll calc(const std::string& S, int& p, const int* ch) {
  ll res, t;
  if (S[p] == '(')
    p++, res = calc(S, p, ch), p++;
  else
    res = getNum(S, p);
  while (p < S.size() && S[p] != ')' && ch[S[p]] > ch[c]) {
    t = S[p++];
    res = get(res, calc(S, p, ch), t);
  }
  return res;
}

ll bnf(const std::string& S, const int* ch) {
  int p = 0;
  ll res = calc(S, p, ch);
  while (p < S.size() && S[p] != ')') {
    int t = S[p++];
    res = get(res, calc(S, p, ch), t);
  }
  return res;
}

int main() {
  std::string S;
  std::cin >> S;
  ll res = bnf(S, ch);
  for (char i : {'+', '-', '*'}) {
    for (char j : {'+', '-', '*'}) {
      for (char k : {'+', '-', '*'}) {
        int ch[1 << 8] = {i, j, k};
        res = std::max(res, bnf(S, ch));
      }
    }
  }
  std::cout << res << std::endl;
}