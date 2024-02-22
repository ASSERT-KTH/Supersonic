#include <iostream>
#include <unordered_map>
#include <string>
#include <deque>
using namespace std;
unordered_map<pair<deque<int>, int>, int> mp; // Changed from map to unordered_map
string qes[128];
int search(deque<int> &vi, int depth, int used, int m, int n) {
  auto key = make_pair(vi, used); // Store the key in a local variable to avoid redundant calculations
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
    deque<int> a, b; // Changed from vector to deque
    for (int j = 0; j < vi.size(); j++) {
      if (qes[vi[j]][i] == '0')
        a.push_back(vi[j]);
      else
        b.push_back(vi[j]);
    }
    if (a.empty() || b.empty())
      continue;
    res = min(res, max(search(a, depth + 1, used | (1 << i), m, n),
                       search(b, depth + 1, used | (1 << i), m, n)));
  }
  return mp[key] = res; // Use the stored key here
}
int main() {
  int m, n;
  while (cin >> m >> n, m) {
    for (int i = 0; i < n; i++)
      cin >> qes[i];
    deque<int> vi(n); // Changed from vector to deque
    for (int i = 0; i < n; i++)
      vi[i] = i;
    mp.clear();
    cout << search(vi, 0, 0, m, n) << endl;
  }
}