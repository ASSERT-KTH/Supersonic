#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cassert>

class suffix_array {
  void create_begin_bucket(std::vector<int> &v, std::vector<int> &bucket) {
    std::fill(bucket.begin(), bucket.end(), 0);
    for (int i = 0; i < v.size(); ++i)
      bucket[v[i]]++;
    int sum = 0;
    for (int i = 0; i < bucket.size(); ++i) {
      bucket[i] += sum;
      std::swap(sum, bucket[i]);
    }
  }
  // ...
  // Rest of the code remains the same until main function
  // ...

  int get_lcp(int i, int j) const {
    if (rank[i] > rank[j])
      std::swap(i, j);
    return st.get_min(rank[i], rank[j]);
  }
};
int main() {
  std::string s;
  std::cin >> s;
  suffix_array sa(s);
  int q;
  std::cin >> q;
  while (q--) {
    std::string t;
    std::cin >> t;
    std::cout << sa.contain(t) << "\n";
  }
  return 0;
}