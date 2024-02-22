#include <iostream>
#include <string>
using namespace std;

using ll = long long;

string S;
int p, ch[1 << 8];

ll bnf();
ll getNum() {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
  return res;
}

ll get(ll &a, ll b, char c) {
  if (c == '+')
    a += b;
  if (c == '-')
    a -= b;
  if (c == '*')
    a *= b;
  return a;
}

ll calc(int c) {
  ll res = 0, t = 0; // Initialize res and t variables
  if (S[p] == '(')
    p++, res = bnf(), p++;
  else
    res = getNum();
  while (p < S.size() && S[p] != ')' && ch[S[p]] > c) {
    t = S[p++];
    if (ch[t] > c) // Check precedence before calling get
      get(res, calc(ch[t]), t);
  }
  return res;
}

ll bnf() {
  ll res = calc(-1), t = 0; // Initialize res and t variables
  while (p < S.size() && S[p] != ')') {
    t = S[p++];
    if (ch[t] > -1) // Check precedence before calling get
      get(res, calc(ch[t]), t);
  }
  return res;
}

int main() {
  cin >> S;
  ll res = bnf();

  // Precompute values of ch array
  ch['+'] = 0;
  ch['-'] = 1;
  ch['*'] = 2;

  // Use a single loop for i, j, and k values
  for (int counter = 0; counter < 27; counter++) {
    int i = counter / 9;
    int j = (counter % 9) / 3;
    int k = counter % 3;

    p = 0;
    res = max(res, calc(-100));
  }

  cout << res << endl;
  return 0;
}