#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int num;
  std::cin >> num;
  std::vector<int> arr(num);
  for (int &i : arr)
    std::cin >> i;

  std::vector<int> h(num);
  int m = 1;
  for (int i = 0; m <= num; ++i) {
    h[i] = m;
    m = 3 * m + 1;
  }

  int count = 0;
  for (auto it = h.rbegin(); it != h.rend(); ++it) {
    for (int i = *it; i < num; i++) {
      int v = arr[i];
      int j = i - *it;
      while (j >= 0 && arr[j] > v) {
        arr[j + *it] = arr[j];
        j -= *it;
        count++;
      }
      arr[j + *it] = v;
    }
  }

  std::cout << h.size() << std::endl;
  for (auto it = h.rbegin(); it != h.rend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << count << std::endl;
  for (int &i : arr)
    std::cout << i << std::endl;

  return 0;
}