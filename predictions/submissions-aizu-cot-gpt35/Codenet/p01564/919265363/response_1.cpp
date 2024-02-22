#include <iostream>
#include <vector>
using intl32 = std::int_least32_t;

struct ass {
  intl32 data;
  ass(intl32 a = 0) : data(a) {}
  ass operator*(const ass &other) { return other; }
};

struct douse {
  intl32 all;
  bool id;
  douse() : id(1) {}
  douse(int32 a) : all(a), id(0) {}
  douse operator~() {
    douse ret = *this;
    return ret;
  }
  douse operator+(const douse &other) {
    if (id)
      return other;
    if (other.id)
      return *this;
    douse ret;
    ret.all = std::max(std::max(all, other.all), all + other.all);
    ret.id = 0;
    return ret;
  }
  douse operator*(const ass &other) {
    douse ret;
    ret.all = other.data > 0 ? other.data : 0;
    ret.id = id;
    return ret;
  }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  uint32 n, q;
  std::cin >> n >> q;
  std::vector<douse> a(n);
  int32 t1;
  for (uint32 i = 0; i < n; ++i) {
    std::cin >> t1;
    a[i] = douse(t1);
  }
  std::vector<std::vector<uint32>> tree(n);
  uint32 t2, t3;
  for (uint32 i = 0; i < n - 1; ++i) {
    std::cin >> t2 >> t3;
    tree[t2 - 1].push_back(t3 - 1);
    tree[t3 - 1].push_back(t2 - 1);
  }
  std::vector<intl32> parent(n, -1);
  parent[0] = 0;
  std::vector<douse> dp(n);
  std::vector<bool> visited(n, false);
  std::vector<uint32> stack;
  stack.push_back(0);
  while (!stack.empty()) {
    uint32 u = stack.back();
    stack.pop_back();
    visited[u] = true;
    for (uint32 v : tree[u]) {
      if (!visited[v]) {
        parent[v] = u;
        stack.push_back(v);
      }
    }
  }
  for (uint32 i = 0; i < q; ++i) {
    std::cin >> t2 >> t3 >> t1;
    if (t2 == 1) {
      a[t3 - 1] = a[t3 - 1] * ass(t1);
    } else {
      douse result = a[t3 - 1];
      while (t3 != t4) {
        t4 = parent[t4 - 1];
        result = result + a[t4 - 1];
      }
      std::cout << result.all << "\n";
    }
  }
  return 0;
}