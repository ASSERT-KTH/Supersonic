#include <bits/stdc++.h>
#define N 3
#define MAX_H 1010
#define MAX_P 110
#define MAX_IM 6060
using namespace std;
typedef unsigned long long ull;
bool im[MAX_H][MAX_IM], pa[MAX_P][MAX_P];
int w, h, p, ans;
vector<ull> used;
ull powN[MAX_P * MAX_P];
void ppp() {
  ull a = 0;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  for (int i = 0; i < used.size(); i++)
    if (used[i] == a)
      return;
  used.push_back(a);
  ull roll[MAX_H][MAX_IM] = {};
  for (int j = 0; j < h; j++) {
    ull b = 0;
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i], roll[j][p - 1] = b;
    for (int i = p; i < w; i++)
      roll[j][i] = (b = b * N + im[j][i] - im[j][i - p] * powN[p]);
  }
  for (int j = p - 1; j < w; j++) {
    ull b = 0, n = powN[p];
    for (int i = 0; i < p; i++)
      b = b * n + roll[i][j];
    if (b == a)
      ans++;
    for (int i = p; i < h; i++)
      if ((b = b * n + roll[i][j] - roll[i - p][j] * powN[p]) == a)
        ans++;
  }
}
void ch() {
  bool npa[MAX_P][MAX_P];
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
  powN[0] = 1;
  for (int i = 1; i <= MAX_P * MAX_P; i++)
    powN[i] = powN[i - 1] * N;
  while (cin >> w >> h >> p, w) {
    string s;
    used.clear();
    for (int i = 0; i < h; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int t = D[s[j]];
        for (int a = 5; a >= 0; a--)
          im[i][j * 6 + (5 - a)] = t & (1 << a);
      }
    }
    for (int i = 0; i < p; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int t = D[s[j]];
        for (int a = 5; a >= 0; a--)
          pa[i][j * 6 + (5 - a)] = t & (1 << a);
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
    cout << ans << '\n';
  }
  return 0;
}