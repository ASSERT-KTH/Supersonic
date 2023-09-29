#include <bits/stdc++.h>
#define N 3
using namespace std;
typedef unsigned long long ull;
const int MAX_H = 1010, MAX_P = 110, MAX_W = 100100;
bool im[MAX_H][MAX_W], pa[MAX_P][MAX_P];
int w, h, p, ans;
ull used[MAX_H];
void ppp() {
  ull a = 0;
  ull roll[MAX_H] = {};
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  for (int i = 0; i < h; i++) {
    ull b = 0, g = 1;
    for (int j = 0; j < p; j++)
      b = b * N + im[i][j], g *= N;
    roll[p - 1] = b;
    for (int j = p; j < w; j++) {
      b = b * N + im[i][j] - im[i][j - p] * g;
      roll[j] = b;
    }
    bool found = false;
    for (int j = p - 1; j < w; j++) {
      if (j == p - 1 || roll[j] != roll[j-p]) {
        if (roll[j] == a) {
          ans++;
          found = true;
        }
      }
      if (found) continue;
    }
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
  while (cin >> w >> h >> p, w) {
    string s;
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