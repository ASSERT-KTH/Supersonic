#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getNum(const string& S, int& p) {
  ll res = 0;
  while (isdigit(S[p]))
    res = res * 10 + S[p++] - '0';
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

ll calc(const string& S, int& p, const map<char, int>& priorityMap) {
  ll res = 0;
  char op = '+';
  while (p < S.size() && S[p] != ')') {
    if (S[p] == '(') {
      p++;
      ll temp = calc(S, p, priorityMap);
      get(res, temp, op);
    } else if (isdigit(S[p])) {
      ll num = getNum(S, p);
      get(res, num, op);
    } else {
      op = S[p++];
    }
  }
  return res;
}

int main() {
  string S;
  cin >> S;

  int ops[3] = {0};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        ops['+'] = i;
        ops['-'] = j;
        ops['*'] = k;
        map<char, int> priorityMap;
        priorityMap['+'] = ops['+'];
        priorityMap['-'] = ops['-'];
        priorityMap['*'] = ops['*'];
        int p = 0;
        ll res = calc(S, p, priorityMap);
        cout << res << endl;
      }

  return 0;
}