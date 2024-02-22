#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;
using std::vector;

constexpr int INF = std::numeric_limits<int>::max();
unordered_map<pair<vector<int>, int>, int> mp;
string qes[128];

int search(vector<int>& vi, int depth, int used, int m, int n) {
  if (mp.count({vi, used})) {
    return mp[{vi, used}];
  }

  if (vi.size() == 1) {
    return depth;
  }

  int res = INF;
  for (auto i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;

    vector<int> a(n);
    vector<int> b(n);
    int a_size = 0;
    int b_size = 0;

    for (auto j = 0; j < vi.size(); j++) {
      if (qes[vi[j]][i] == '0') {
        a[a_size++] = vi[j];
      } else {
        b[b_size++] = vi[j];
      }
    }

    if (a_size == 0 || b_size == 0) {
      continue;
    }

    a.resize(a_size);
    b.resize(b_size);

    res = std::min(res, std::max(search(a, depth + 1, used | (1 << i), m, n),
                                 search(b, depth + 1, used | (1 << i), m, n)));
  }

  return mp[{vi, used}] = res;
}

int main() {
  int m, n;
  while (cin >> m >> n, m) {
    for (auto i = 0; i < n; i++) {
      cin >> qes[i];
    }

    vector<int> vi(n);
    for (auto i = 0; i < n; i++) {
      vi[i] = i;
    }

    mp.clear();
    cout << search(vi, 0, 0, m, n) << endl;
  }
}