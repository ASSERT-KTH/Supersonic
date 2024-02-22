#include <iostream>
#include <unordered_map>

typedef long long ll;

std::string S;
int p;
std::unordered_map<char, int> precedence;

void getNum(ll& res) {
  res = 0;
  while (isdigit(S[p])) {
    res = res * 10 + S[p++] - '0';
  }
}

void get(ll& a, ll b, char c) {
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
}

ll calc(int c, const std::string& S) {
  ll res, t;
  if (S[p] == '(') {
    p++;
    res = calc(-1, S);
    p++;
  } else {
    getNum(res);
  }
  while (p < S.size() && S[p] != ')' && precedence[S[p]] > c) {
    t = S[p++];
    get(res, calc(precedence[t], S), t);
  }
  return res;
}

ll bnf(const std::string& S) {
  p = 0;
  ll res = calc(-1, S), t;
  while (p < S.size() && S[p] != ')') {
    t = S[p++];
    get(res, calc(precedence[t], S), t);
  }
  return res;
}

int main() {
  std::cin >> S;
  ll res = bnf(S);

  precedence['+'] = 0;
  precedence['-'] = 1;
  precedence['*'] = 2;

  for (int i = 0; i < 27; i++) {
    char op1 = i % 3 == 0 ? '+' : i % 3 == 1 ? '-' : '*';
    char op2 = i / 3 % 3 == 0 ? '+' : i / 3 % 3 == 1 ? '-' : '*';
    char op3 = i / 9 == 0 ? '+' : i / 9 == 1 ? '-' : '*';

    precedence['+'] = precedence[op1];
    precedence['-'] = precedence[op2];
    precedence['*'] = precedence[op3];

    p = 0;
    res = std::max(res, calc(-100, S));
  }

  std::cout << res << std::endl;
  return 0;
}