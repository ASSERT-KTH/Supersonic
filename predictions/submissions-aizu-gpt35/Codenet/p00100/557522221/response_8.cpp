#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    vector<int> vec;
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i]){
        vec.push_back(i);
      }
      m[i] += p * q;
    }
    for (const auto& i : vec) {
      auto it = m.find(i);
      if (it->second >= 1000000) {
        s = 1;
        cout << it->first << endl;
      }
    }
    if (!s){
      cout << "NA" << endl;
    }
  }
  return 0;
}