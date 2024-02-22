#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;

const ll M1 = 1e9 + 7, M2 = 1e9 + 9;

ll a[2] = {101, 103};
ll d[2][300010], k[2][300010];
unordered_map<ll, int> H;
priority_queue<ll> Q;

void init(const string& s) {
  for (int i = 0; i < 2; i++) {
    k[i][0] = 1;
    for (int j = 0; j < s.size(); j++) {
      d[i][j + 1] = (d[i][j] * a[i] + (s[j] - 'a' + 1)) % M1;
      k[i][j + 1] = (k[i][j] * a[i]) % M1;
    }
  }
}

ll getlr(int l, int r, int i) {
  return (M1 * M1 + d[i][r] - d[i][l] * k[i][r - l]) % M1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 0, m, a, b, i, j, l = 0, r = 1;
  string s, q;
  cin >> m >> s;
  init(s);
  for (i = 0; i < m; i++) {
    cin >> q;
    if (q[0] == 'L')
      l += q[1] - '-' ? 1 : -1;
    else
      r += q[1] - '-' ? 1 : -1;
    ll h = getlr(l, r, 0);
    H[h]++;
    Q.push(h);
  }
  a = Q.top();
  Q.pop();
  for (i = 1; i < m; i++) {
    b = Q.top();
    Q.pop();
    if (H[b] > 0 && H[b] == H[a])
      n++;
    a = b;
  }
  cout << m - n << "\n";
  return 0;
}