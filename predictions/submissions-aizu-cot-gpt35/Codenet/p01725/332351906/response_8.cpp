#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

string S;
int p, ch[1 << 8];

ll bnf();

ll getNum() {
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

void calc(int c, ll& res) {
  if (S[p] == '(') {
    p++;
    bnf();
    p++;
    return;
  }
  
  res = getNum();
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c) {
    char t = S[p++];
    ll sub_res;
    calc(ch[t], sub_res);
    res = get(res, sub_res, t);
  }
}

ll bnf() {
  ll res;
  calc(-1, res);
  return res;
}

int main() {
  cin >> S;
  ll res = bnf();
  
  for (int i = 0; i < (1 << 8); i++) {
    ch['+'] = i & 1;
    ch['-'] = (i >> 1) & 1;
    ch['*'] = (i >> 2) & 1;
    
    p = 0;
    ll temp_res;
    calc(-100, temp_res);
    res = max(res, temp_res);
  }
  
  cout << res << endl;
  return 0;
}