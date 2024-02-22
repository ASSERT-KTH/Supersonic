#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

string S;
int p, ch[1 << 8];

ll bnf();
void getNum(ll& res) {
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
}

ll get(ll &a, ll b, char c) {
  switch (c) {
    case '+': a += b; break;
    case '-': a -= b; break;
    case '*': a *= b; break;
  }
  return a;
}

ll calc(int c) {
  ll res;
  if (S[p] == '(') {
    p++;
    res = bnf();
    p++;
  } else {
    getNum(res);
  }
  
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c) {
    get(res, calc(ch[S[p]]), S[p]);
    p++;
  }
  
  return res;
}

ll bnf() {
  ll res = calc(-1);
  while (p < S.size() && S[p] != ')') {
    get(res, calc(ch[S[p]]), S[p]);
    p++;
  }
  return res;
}

int main() {
  cin >> S;
  ll res = bnf();
  
  for (int i = 0; i < 27; i++) {
    ch['+'] = i % 3;
    ch['-'] = (i / 3) % 3;
    ch['*'] = (i / 9) % 3;
    p = 0;
    res = max(res, calc(-100));
  }
  
  cout << res << endl;
  return 0;
}