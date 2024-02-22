#include <iostream>
#include <string>
constexpr int SIZE = 1 << 8;

long long getNum(int &p, const std::string &S) {
  long long res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

long long get(long long &a, long long b, char c) {
  if (c == '+')
    a += b;
  if (c == '-')
    a -= b;
  if (c == '*')
    a *= b;
  return a;
}

long long calc(int &p, const std::string &S, int ch[SIZE], int c);

long long bnf(int &p, const std::string &S, int ch[SIZE]) {
  long long res = calc(p, S, ch, -1);
  while (p < S.size() && S[p] != ')')
    get(res, calc(p, S, ch, ch[S[p++]]), S[p-1]);
  return res;
}

long long calc(int &p, const std::string &S, int ch[SIZE], int c) {
  long long res;
  if (S[p] == '(')
    p++, res = bnf(p, S, ch), p++;
  else
    res = getNum(p, S);
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
    get(res, calc(p, S, ch, ch[S[p++]]), S[p-1]);
  return res;
}

int main() {
  std::string S;
  std::cin >> S;

  int p = 0;
  int ch[SIZE] = {0};

  long long res = bnf(p, S, ch);
  constexpr int MAX_PRIORITY = 3;
  constexpr int MIN_PRIORITY = -100;
  for (int i = 0; i < MAX_PRIORITY; i++)
    for (int j = 0; j < MAX_PRIORITY; j++)
      for (int k = 0; k < MAX_PRIORITY; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        p = 0;
        res = std::max(res, calc(p, S, ch, MIN_PRIORITY));
      }
  std::cout << res << std::endl;
  return 0;
}