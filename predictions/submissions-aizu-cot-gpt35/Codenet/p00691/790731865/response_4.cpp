#include <algorithm>
#include <iostream>

const int MAX_N = 1112;
int tb[MAX_N], ans[MAX_N], N;

int nr(int a) {
  int left = 0, right = MAX_N - 1;
  while (left < right) {
    int mid = left + (right - left + 1) / 2;
    if (tb[mid] <= a)
      left = mid;
    else
      right = mid - 1;
  }
  return tb[left];
}

int calc(int z) {
  int z3 = z * z * z;
  int ret = z3;
  int i3 = 1, j3 = nr(z3 - i3 * i3 * i3);
  while (i3 * i3 * i3 + j3 < z3) {
    ret = std::min(ret, z3 - i3 * i3 * i3 - j3);
    i3++;
    j3 = nr(z3 - i3 * i3 * i3);
  }
  return ret;
}

int main() {
  for (int i = 1; i < MAX_N; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < MAX_N; i++)
    ans[i] = calc(i);
  while (std::cin >> N, N)
    std::cout << ans[N] << '\n';

  return 0;
}