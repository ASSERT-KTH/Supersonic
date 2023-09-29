#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    vector<int> vec;
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i])
        vec.push_back(i);
      m[i] += p * q;
    }
    for (int i = 0; i < vec.size(); i++) {
      auto it = m.find(vec[i]);
      if (it->second >= 1000000) {
        s = 1;
        cout << it->first << '\n';
      }
    }
    if (!s)
      cout << "NA\n";
  }
}
