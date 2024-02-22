#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int ch[256];

ll calc(const string& S, int& p);

ll bnf(const string& S, int& p) {
  ll res = calc(S, p), t;
  while (p < S.size() && S[p] != ')') {
    t = S[p++];
    res = get(res, calc(S, p), t);
  }
  return res;
}

ll calc(const string& S, int& p) {
  ll res, t;
  if (S[p] == '(') {
    p++;
    res = bnf(S, p);
    p++;
  } else {
    res = stoi(S.substr(p));
    p += to_string(res).size();
  }
  while (p < S.size() && S[p] != ')' && ch[S[p]] > ch[S[p - 1]]) {
    t = S[p++];
    res = get(res, calc(S, p), t);
  }
  return res;
}

ll get(ll& a, ll b, char c) {
  if (c == '+')
    a += b;
  if (c == '-')
    a -= b;
  if (c == '*')
    a *= b;
  return a;
}

int main() {
  string S;
  cin >> S;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        ch['+'] = i;
        ch['-'] = j;
        ch['*'] = k;
        int p = 0;
        ll res = bnf(S, p);
        cout << res << endl;
      }
    }
  }

  return 0;
}