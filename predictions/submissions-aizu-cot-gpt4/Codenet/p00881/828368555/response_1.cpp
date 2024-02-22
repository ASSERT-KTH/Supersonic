#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
unordered_map<pair<vector<int>, int>, int> mp;
string qes[128];

int search(vector<int>::iterator begin, vector<int>::iterator end, int depth, int used, int m, int n) {
  vector<int> vi(begin, end);
  auto key = make_pair(vi, used);
  auto result = mp.find(key);
  if (result != mp.end())
    return result->second;
  if (distance(begin, end) > (1 << (m - depth)))
    return 100;
  if (distance(begin, end) == 1)
    return depth;
  int res = 100;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;
    vector<int>::iterator a = begin, b = end;
    for (auto it = begin; it != end; ++it) {
      if (qes[*it][i] == '0')
        swap(*it, *(a++));
      else
        swap(*it, *(--b));
    }
    if (a == begin || b == end)
      continue;
    res = min(res, max(search(begin, a, depth + 1, used | (1 << i), m, n),
                       search(b, end, depth + 1, used | (1 << i), m, n)));
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
    cout << search(vi.begin(), vi.end(), 0, 0, m, n) << endl;
  }
}