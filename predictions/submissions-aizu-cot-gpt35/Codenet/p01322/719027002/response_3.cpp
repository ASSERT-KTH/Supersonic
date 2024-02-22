#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main() {
  int n, m;
  std::vector<std::pair<std::string, int>> bo;

  while (std::cin >> n >> m && (n != 0 || m != 0)) {
    bo.resize(n);
    for (int i = 0; i < n; i++)
      std::cin >> bo[i].first >> bo[i].second;

    std::vector<int> answers(m);
    for (int i = 0; i < m; i++) {
      std::string l;
      std::cin >> l;
      
      auto it = std::find_if(bo.begin(), bo.end(), [&](const auto& pair) {
        return std::equal(pair.first.begin(), pair.first.end(), l.begin());
      });

      if (it != bo.end())
        answers[i] = it->second;
    }

    int sum = std::accumulate(answers.begin(), answers.end(), 0);
    std::cout << sum << std::endl;
  }
}