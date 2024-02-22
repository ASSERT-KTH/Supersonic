#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<pair<vector<int>, int>, int> mp;
string qes[128];
int search(vector<int> &vi, int depth, int used, int m, int n) {
  pair<vector<int>, int> key = make_pair(vi, used); // Store the key
  auto it = mp.find(key); // Find the key in the map
  if (it != mp.end())
    return it->second; // Return the value if key is found
  if (vi.size() > (1 << (m - depth)))
    return 100;
  if (vi.size() == 1)
    return depth;
  int res = 100;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;
    vector<int> a, b;
    for (int &j : vi) { // Use reference to avoid copying
      char temp = qes[j][i]; // Store the accessed string
      if (temp == '0')
        a.push_back(j);
      else
        b.push_back(j);
    }
    if (a.empty() || b.empty())
      continue;
    res = min(res, max(search(a, depth + 1, used | (1 << i), m, n),
                       search(b, depth + 1, used | (1 << i), m, n)));
  }
  return mp[key] = res; // Use stored key for insertion
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