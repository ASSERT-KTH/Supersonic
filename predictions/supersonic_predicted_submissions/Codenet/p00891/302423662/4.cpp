#include <bits/stdc++.h>
#define N 2
using namespace std;
typedef long long ull;
bool im[1010][1010], pa[110][110];
int w, h, p, ans;
vector<ull> used;
void ppp() {
  ull a = 0;
  ull roll[1001][1001] = {};
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  for (int i = 0; i < used.size(); i++)
    if (used[i] == a)
      return;
  used.push_back(a);
  for (int j = 0; j < h; j++) {
    ull b = 0, g = 1;
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i], g *= N;
    roll[j][p - 1] = b;
    for (int i = p; i < w; i++) {
      b = b * N + im[j][i] - im[j][i - p] * g;
      roll[j][i] = b;
    }
  }
  for (int j = p - 1; j < w; j++) {
    ull b = 0, g = 1, n = 1;
    for (int i = 0; i < p; i++)
      n *= N;
    for (int i = 0; i < p; i++)
      b = b * n + roll[i][j], g *= n;
    if (b == a)
      ans++;
    for (int i = p; i < h; i++) {
      b = b * n + roll[i][j] - roll[i - p][j] * g;
      if (b == a)
        ans++;
    }
  }
}
void ch() {
  bool npa[110][110];
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      npa[i][j] = pa[j][p - i - 1];
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      pa[i][j] = npa[i][j];
}
void ch1() {
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p / 2; j++)
      swap(pa[i][j], pa[i][p - j - 1]);
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
        int a = 6;
        while (a--)
          im[i][j * 6 + a] = t % 2, t /= 2;
      }
    }
    for (int i = 0; i < p; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int t = D[s[j]];
        int a = 6;
        while (a--)
          pa[i][j * 6 + a] = t % 2, t /= 2;
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
