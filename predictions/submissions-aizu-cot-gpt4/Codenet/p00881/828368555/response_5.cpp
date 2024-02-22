#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

unordered_map<pair<vector<int>, int>, int> mp;
string qes[128];

int search(vector<int> &vi, int depth, int used, int m, int n) {
  auto key = make_pair(vi, used);
  if (mp.count(key))
    return mp[key];
  if (vi.size() > (1 << (m - depth)))
    return 100;
  if (vi.size() == 1)
    return depth;
  int res = 100;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;
    vector<int> a, b;
    int count_a = 0, count_b = 0;
    for (int j = 0; j < vi.size(); j++) {
      if (qes[vi[j]][i] == '0') {
        count_a++;
        if (res > depth + 1) a.push_back(vi[j]);
      } else {
        count_b++;
        if (res > depth + 1) b.push_back(vi[j]);
      }
    }
    if (count_a == 0 || count_b == 0)
      continue;
    if (res > depth + 1) {
      res = min(res, max(search(a, depth + 1, used | (1 << i), m, n),
                         search(b, depth + 1, used | (1 << i), m, n)));
    }
  }
  return mp[key] = res;
}

int main() {
  int m, n;
  while (cin >> m >> n, m) {
    for (int i = 0; i < n; i++)
      cin >> qes[i];
    vector<int> vi(n);
    for (int i = 0; i < n; i++)
      vi[i] = i;
    mp.clear();
    cout << search(vi, 0, 0, m, n) << endl;
  }
}