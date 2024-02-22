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

unordered_map<pair<vector<int>, int>, int, pair_hash> mp;
string qes[128];

int search(vector<int> &vi, int start, int end, int depth, int used, int m, int n) {
  pair<vector<int>, int> key = make_pair(vi, used);
  auto it = mp.find(key);
  if (it != mp.end())
    return it->second;
  if (end - start > (1 << (m - depth)))
    return 100;
  if (end - start == 1)
    return depth;
  int res = 100;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;
    int a_start = start, a_end = start, b_start = end, b_end = end;
    for (int j = start; j < end; j++) {
      if (qes[vi[j]][i] == '0')
        swap(vi[a_end++], vi[j]);
      else
        swap(vi[--b_start], vi[j]);
    }
    if (a_end == a_start || b_end == b_start)
      continue;
    res = min(res, max(search(vi, a_start, a_end, depth + 1, used | (1 << i), m, n),
                       search(vi, b_start, b_end, depth + 1, used | (1 << i), m, n)));
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
    cout << search(vi, 0, n, 0, 0, m, n) << endl;
  }
}