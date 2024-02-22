#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

ll getNum(const string& S, int& p) {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

ll calc(const string& S, const int* ch, int& p) {
  ll res, t;
  if (S[p] == '(')
    p++, res = calc(S, ch, p), p++;
  else
    res = getNum(S, p);
  
  while (p < S.size() && S[p] != ')' && ch[S[p]] > ch[-100]) {
    t = S[p++];
    if (t == '+')
      res += calc(S, ch, p);
    else if (t == '-')
      res -= calc(S, ch, p);
    else if (t == '*')
      res *= calc(S, ch, p);
  }
  
  return res;
}

ll bnf(const string& S, const int* ch) {
  int p = 0;
  ll res = calc(S, ch, p);
  
  while (p < S.size() && S[p] != ')') {
    int t = S[p++];
    if (t == '+')
      res += calc(S, ch, p);
    else if (t == '-')
      res -= calc(S, ch, p);
    else if (t == '*')
      res *= calc(S, ch, p);
  }
  
  return res;
}

int main() {
  string S;
  cin >> S;
  
  ll res = bnf(S, ch);
  
  int ch[1 << 8];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        ch['+'] = i, ch['-'] = j, ch['*'] = k;
        res = max(res, bnf(S, ch));
      }
  
  cout << res << endl;
  
  return 0;
}