#include <iostream>
#include <vector>
#define N 3
#define MAX_H_W 1010
#define MAX_P 110
typedef unsigned long long ull;

bool im[MAX_H_W][MAX_H_W], pa[MAX_P][MAX_P];
int w, h, p, ans;
std::vector<ull> used;
ull roll[MAX_H_W][MAX_H_W];

void ppp() {
  ull a = 0;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];

  for (auto &u : used)
    if (u == a)
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
      std::swap(pa[i][j], pa[i][p - j - 1]);
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

  std::string s;
  while (std::cin >> w >> h >> p, w) {
    used.clear();
    for (int i = 0; i < h; i++) {
      std::cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int t = D[s[j]];
        for (int a = 5; a >= 0; a--)
          im[i][j * 6 + a] = t >> a & 1;
      }
    }
    for (int i = 0; i < p; i++) {
      std::cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int t = D[s[j]];
        for (int a = 5; a >= 0; a--)
          pa[i][j * 6 + a] = t >> a & 1;
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
    std::cout << ans << "\n";
  }
  return 0;
}