#include <bits/stdc++.h>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[110][110];
int w, h, p, ans;
unordered_set<ull> used;
void ppp() {
  ull a = 0;
  ull roll[1001][1001] = {};
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  if (used.count(a))
      return;
  used.insert(a);
  ull g = pow(N, p);
  for (int j = 0; j < h; j++) {
    ull b = 0;
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i];
    roll[j][p - 1] = b;
    for (int i = p; i < w; i++) {
      b = b * N + im[j][i] - im[j][i - p] * g;
      roll[j][i] = b;
    }
  }
  g = pow(N, p);
  for (int j = p - 1; j < w; j++) {
    ull b = 0;
    for (int i = 0; i < p; i++)
      b = b * g + roll[i][j];
    if (b == a)
      ans++;
    for (int i = p; i < h; i++) {
      b = b * g + roll[i][j] - roll[i - p][j] * g;
      if (b == a)
        ans++;
    }
  }
}
void ch() {
  for (int i = 0; i < p; i++)
    for (int j = 0; j < i; j++)
      swap(pa[i][j], pa[j][i]);
  for (int i = 0; i < p; i++)
      reverse(pa[i], pa[i] + p);
}
void ch1() {
  for (int i = 0; i < p; i++)
    reverse(pa[i], pa[i] + p);
}
int main() {
  int D[256];
  for (int i = 'A'; i <= 'Z'; i++)
    D[i] = i - 'A';
  for (int i = 'a'; i <= 'z'; i++)
    D[i] = i - 'a' + 26;
  for (int i = '0'; i <= '9'; i++)
    D[i] = i - '0' + 52;
  D['+'] = 62, D['/'] = 63;
  while (cin >> w >> h >> p, w) {
    string s;
    used.clear();
    for (int i = 0; i < h; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int t = D[s[j]];
        for (int a = 5; a >= 0; --a)
          im[i][j * 6 + a] = t & (1 << a);
      }
    }
    for (int i = 0; i < p; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int t = D[s[j]];
        for (int a = 5; a >= 0; --a)
          pa[i][j * 6 + a] = t & (1 << a);
      }
    }
    ans = 0;
    for (int i = 0; i < 4; i++) {
      ppp();
      ch1();
      ppp();
      ch1();
      ch();
    }
    cout << ans << endl;
  }
  return 0;
}