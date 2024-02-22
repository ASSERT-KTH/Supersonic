#include <bits/stdc++.h>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[110][110];
int w, h, p, ans;
unordered_set<ull> used;
ull roll[1001] = {};

const int D[256] = [] {
    int tmp[256] = {0};
    for (int i = 'A'; i <= 'Z'; i++)
        tmp[i] = i - 'A';
    for (int i = 'a'; i <= 'z'; i++)
        tmp[i] = i - 'a' + 26;
    for (int i = '0'; i <= '9'; i++)
        tmp[i] = i - '0' + 52;
    tmp['+'] = 62, tmp['/'] = 63;
    return tmp;
} ();

void ppp() {
  ull a = 0;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  if (used.find(a) != used.end())
      return;
  used.insert(a);
  for (int j = 0; j < h; j++) {
    ull b = 0, g = 1;
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i], g *= N;
    roll[p - 1] = b;
    for (int i = p; i < w; i++) {
      roll[i] = roll[i] * N + im[j][i] - im[j][i - p] * g;
      if (roll[i] == a)
        ans++;
    }
  }
}

// ... rest of the code ...

int main() {
  while (cin >> w >> h >> p, w) {
    string s;
    used.clear();
    for (int i = 0; i < h; i++) {
      cin >> s;
      int s_size = s.size();
      for (int j = 0; j < s_size; j++) {
        int t = D[s[j]];
        int a = 6;
        while (a--)
          im[i][j * 6 + a] = t % 2, t /= 2;
      }
    }
    // ... rest of the code ...
  }
  return 0;
}