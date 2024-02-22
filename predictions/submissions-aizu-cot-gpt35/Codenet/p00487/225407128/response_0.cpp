#include <iostream>
#include <map>

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::map<long long, int> a_map;
  std::map<long long, int> b_map;
  std::map<int, bool> use_map;

  for (int i = 0; i < n; i++) {
    long long a, b;
    std::cin >> a >> b;
    a_map[a] = i;
    b_map[b] = i;
    use_map[i] = false;
  }

  int ans = 0;
  long long sum = 0;
  int num = 0;

  for (auto it = b_map.begin(); it != b_map.end(); ++it) {
    int b_index = it->second;
    long long b_value = it->first;

    if (!use_map[b_index]) {
      sum += a_map[b_index];
      use_map[b_index] = true;
      num++;
    }

    auto p_it = a_map.begin();
    while (p_it != a_map.end() && p_it->first <= b_value) {
      int p_index = p_it->second;

      if (!use_map[p_index]) {
        sum += p_it->first;
        use_map[p_index] = true;
        num++;
      }

      ++p_it;
    }

    while (p_it != a_map.end()) {
      int p_index = p_it->second;

      if (!use_map[p_index]) {
        if (sum + p_it->first > (num + 1) * b_value)
          break;
        sum += p_it->first;
        use_map[p_index] = true;
        num++;
      }

      ++p_it;
    }

    if (sum <= num * b_value)
      ans = std::max(ans, num);

    sum -= a_map[b_index];
    num--;
  }

  std::cout << ans << std::endl;
}