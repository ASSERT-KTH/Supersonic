#include <iostream>
#include <string>

int ch[1 << 8];
std::string S;
int p;

long long getNum(const std::string& S) {
  long long res = 0;
  while (std::isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

long long get(long long& a, long long b, char c) {
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

long long calc(const std::string& S, int c);

long long bnf(const std::string& S) {
  long long res = calc(S, -1), t;
  while (p < S.size() && S[p] != ')')
    t = S[p++], get(res, calc(S, ch[t]), t);
  return res;
}

long long calc(const std::string& S, int c) {
  long long res, t;
  if (S[p] == '(') {
    p++;
    res = bnf(S);
    p++;
  } else {
    res = getNum(S);
  }
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
    t = S[p++], get(res, calc(S, ch[t]), t);
  return res;
}

int main() {
  std::cin >> S;
  long long res = bnf(S);
  for (char i = '+'; i <= '*'; i++) {
    ch['+'] = i;
    for (char j = '+'; j <= '*'; j++) {
      ch['-'] = j;
      for (char k = '+'; k <= '*'; k++) {
        ch['*'] = k;
        p = 0;
        res = std::max(res, calc(S, -100));
      }
    }
  }
  std::cout << res << std::endl;
  return 0;
}