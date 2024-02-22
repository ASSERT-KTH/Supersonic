#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second); 
        return h1 ^ h2;  
    }
};

int search(unordered_map<pair<vector<int>, int>, int, pair_hash> &mp, vector<string> &qes, vector<int> &vi, int depth, int used, int m, int n) {
  pair<vector<int>, int> key = make_pair(vi, used);
  auto it = mp.insert({key, 100});
  if (!it.second)
    return it.first->second;
  if (vi.size() > (1 << (m - depth)))
    return 100;
  if (vi.size() == 1)
    return depth;
  int res = 100;
  vector<int> a, b;
  for (int i = 0; i < m; i++) {
    a.clear(); b.clear();
    if ((used >> i) & 1)
      continue;
    for (int j = 0; j < vi.size(); j++) {
      if (qes[vi[j]][i] == '0')
        a.push_back(vi[j]);
      else
        b.push_back(vi[j]);
    }
    if (a.empty() || b.empty())
      continue;
    res = min(res, max(search(mp, qes, a, depth + 1, used | (1 << i), m, n),
                       search(mp, qes, b, depth + 1, used | (1 << i), m, n)));
  }
  return it.first->second = res;
}

int main() {
  int m, n;
  while (cin >> m >> n, m) {
    vector<string> qes(n);
    for (int i = 0; i < n; i++)
      cin >> qes[i];
    vector<int> vi(n);
    for (int i = 0; i < n; i++)
      vi[i] = i;
    unordered_map<pair<vector<int>, int>, int, pair_hash> mp;
    cout << search(mp, qes, vi, 0, 0, m, n) << endl;
  }
}