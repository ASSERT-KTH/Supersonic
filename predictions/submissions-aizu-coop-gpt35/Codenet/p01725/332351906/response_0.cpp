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

ll calc(const string& S, int& p, unordered_map<char, int>& ch, unordered_map<string, ll>& cache) {
  string subexp;
  subexp += S[p];
  if (cache.count(subexp)) {
    p++;
    return cache[subexp];
  }
  ll res, t;
  if (S[p] == '(') {
    p++;
    res = bnf(S, p, ch, cache);
    p++;
  } else {
    res = getNum(S, p);
  }
  while (p < S.size() && S[p] != ')' && ch[S[p]] > ch[subexp[0]]) {
    t = S[p++];
    get(res, calc(S, p, ch, cache), t);
  }
  cache[subexp] = res;
  return res;
}

ll bnf(const string& S, unordered_map<char, int>& ch, unordered_map<string, ll>& cache) {
  string subexp;
  subexp += S[p];
  if (cache.count(subexp)) {
    p++;
    return cache[subexp];
  }
  ll res = calc(S, p, ch, cache);
  ll t;
  while (p < S.size() && S[p] != ')') {
    t = S[p++];
    get(res, calc(S, p, ch, cache), t);
  }
  cache[subexp] = res;
  return res;
}

int main() {
  string S;
  cin >> S;

  unordered_map<char, int> ch = {{'+', 0}, {'-', 1}, {'*', 2}};
  unordered_map<string, ll> cache;
  int p = 0;

  ll res = bnf(S, ch, cache);
  for (int i = 0; i < 27; i++) {
    ch['+'] = i % 3;
    ch['-'] = (i / 3) % 3;
    ch['*'] = (i / 9) % 3;
    p = 0;
    res = max(res, calc(S, p, ch, cache));
  }

  cout << res << endl;
  return 0;
}