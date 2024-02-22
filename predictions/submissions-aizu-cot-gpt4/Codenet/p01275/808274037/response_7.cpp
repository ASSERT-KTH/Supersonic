#include <iostream>
#include <cstdio>
#define M 10

int k, ans;
int dif[12];

void rec(int d, int p) {
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1);
    return;
  }
  rec(d + 1, p + 1);
  for (int i = p; i < k; ++i) {
    dif[i] = (dif[i] - rot) % M;
  }
  rec(d + 1, p + 1);
  for (int i = p; i < k; ++i) {
    dif[i] = (dif[i] + rot + M) % M;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::string s, t;
  while (std::cin >> k, k) {
    std::cin >> s >> t;
    for (int i = 0; i < k; ++i) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    ans = k;
    rec(0, 0);
    std::cout << ans << "\n";
  }
}