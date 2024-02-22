#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<pair<vector<int>, int>, int> mp;

int search(vector<int> &vi, int depth, int used, int m, int n) {
  if (mp.count(make_pair(vi, used)))
    return mp[make_pair(vi, used)];
  
  int viSize = vi.size();
  int mask = 1;
  if (viSize > (1 << (m - depth)))
    return 100;
  if (viSize == 1)
    return depth;
  
  int res = 100;
  for (int i = 0; i < m; i++) {
    int bit = (used >> i) & mask;
    if (bit)
      continue;
    
    vector<int> a, b;
    for (int j = 0; j < viSize; j++) {
      char qesChar = qes[vi[j]][i];
      if (qesChar == '0')
        a.push_back(vi[j]);
      else
        b.push_back(vi[j]);
    }
    
    int usedBit = used | (mask << i);
    int searchA = search(a, depth + 1, usedBit, m, n);
    int searchB = search(b, depth + 1, usedBit, m, n);
    
    res = min(res, max(searchA, searchB));
  }
  
  mp[make_pair(vi, used)] = res;
  return res;
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
    
    cout << search(vi, 0, 0, m, n) << endl;
  }
}