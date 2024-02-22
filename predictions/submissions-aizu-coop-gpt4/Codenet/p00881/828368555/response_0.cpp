#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
unordered_map<pair<vector<int>, int>, int> mp;
string qes[128];
int search(vector<int> &vi, int start, int end, int depth, int used, int m, int n) {
  pair<vector<int>, int> key = make_pair(vi, used);
  if (mp.count(key))
    return mp[key];
  if (end - start + 1 > (1 << (m - depth)))
    return 100;
  if (end - start + 1 == 1)
    return depth;
  int res = 100;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;
    vector<int> a, b;
    for (int j = start; j <= end; j++) {
      if (qes[vi[j]][i] == '0')
        a.push_back(vi[j]);
      else
        b.push_back(vi[j]);
    }
    if (a.empty() || b.empty())
      continue;
    res = min(res, max(search(a, 0, a.size() - 1, depth + 1, used | (1 << i), m, n),
                       search(b, 0, b.size() - 1, depth + 1, used | (1 << i), m, n)));
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
    cout << search(vi, 0, vi.size() - 1, 0, 0, m, n) << endl;
  }
}