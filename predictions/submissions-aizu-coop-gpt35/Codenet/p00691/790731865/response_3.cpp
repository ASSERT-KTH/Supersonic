#include <algorithm>
#include <iostream>
#include <vector>

const int UPPER_BOUND = 1112;

std::vector<int> tb(UPPER_BOUND);
std::vector<int> ans(UPPER_BOUND);

int nr(int a) {
  int left = 1, right = UPPER_BOUND - 1;
  while (left < right) {
    int mid = left + (right - left + 1) / 2;
    if (tb[mid] <= a) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  return tb[left];
}

int calc(int z) {
  int z3 = z * z * z;
  int ret = z3;

  int left = 1, right = UPPER_BOUND - 1;
  while (left < right) {
    int i3 = left * left * left;
    int j3 = nr(z3 - i3);

    if (i3 + j3 >= z3) {
      break;
    }

    ret = std::min(ret, z3 - i3 - j3);
    left++;
  }

  return ret;
}

int main() {
  for (int i = 1; i < UPPER_BOUND; i++) {
    tb[i] = i * i * i;
  }

  for (int i = 1; i < UPPER_BOUND; i++) {
    ans[i] = calc(i);
  }

  int N;
  while (std::cin >> N && N) {
    std::cout << ans[N] << std::endl;
  }

  return 0;
}