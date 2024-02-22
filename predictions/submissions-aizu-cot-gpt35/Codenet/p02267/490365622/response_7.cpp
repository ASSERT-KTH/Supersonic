#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main() {
  int n, q;
  std::cin >> n;

  std::vector<int> S(n);
  for (int i = 0; i < n; i++)
    std::cin >> S[i];

  std::cin >> q;

  std::vector<int> T(q);
  for (int j = 0; j < q; j++)
    std::cin >> T[j];

  std::unordered_set<int> setS(S.begin(), S.end());
  int cnt = 0;
  for (int i = 0; i < q; i++)
    if (setS.find(T[i]) != setS.end())
      cnt++;

  std::cout << cnt << std::endl;
  return 0;
}