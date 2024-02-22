#include <iostream>
#include <string>

int bnf(std::string S, int p, int ch[256]);
int getNum(std::string S, int& p);
int calc(std::string S, int& p, int ch[256]);

int main() {
  std::string S;
  std::cin >> S;
  int res = bnf(S, 0, nullptr);
  for (int i = 0; i < 27; i++) {
    int ch[256] = {'+' : i / 9, '-' : (i / 3) % 3, '*' : i % 3};
    int p = 0;
    res = std::max(res, calc(S, p, ch));
  }
  std::cout << res << std::endl;
  return 0;
}

int getNum(std::string S, int& p) {
  int res = 0;
  while (std::isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

int calc(std::string S, int& p, int ch[256]) {
  int res, t;
  if (S[p] == '(')
    p++, res = bnf(S, p, ch), p++;
  else
    res = getNum(S, p);
  while (p < S.size() && S[p] != ')' && ch[S[p]] > -1)
    t = S[p++], res = (t == '+') ? res + calc(S, p, ch) :
                      (t == '-') ? res - calc(S, p, ch) :
                      (t == '*') ? res * calc(S, p, ch) : res;
  return res;
}

int bnf(std::string S, int p, int ch[256]) {
  int res = calc(S, p, ch), t;
  while (p < S.size() && S[p] != ')')
    t = S[p++], res = (t == '+') ? res + calc(S, p, ch) :
                      (t == '-') ? res - calc(S, p, ch) :
                      (t == '*') ? res * calc(S, p, ch) : res;
  return res;
}