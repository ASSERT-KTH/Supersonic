#include <iostream>
#include <vector>
#include <cstring>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[110][110];
int w, h, p, ans;
vector<ull> used;
ull roll[1001][1001] = {};

void ppp() {
  ull a = 0;
  ull g = 1;
  for (int i = 0; i < p; i++)
    g *= N;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  for (int i = 0; i < used.size(); i++)
    if (used[i] == a)
      return;
  used.push_back(a);
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
  for (int j = p - 1; j < w; j++) {
    ull b = 0, g = 1;
    ull n = g;
    for (int i = 0; i < p; i++)
      b = b * n + roll[i][j];
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
  memcpy(pa, npa, sizeof(npa));
}

void ch1() {
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p / 2; j++)
      swap(pa[i][j], pa[i][p - j - 1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
    used.reserve(100); // Assuming maximum size is 100
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
    cout << ans << '\n';
  }
  return 0;
}