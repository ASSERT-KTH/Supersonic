#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n, i;
  unordered_map<int, long long> m;
  vector<int> vec;
  while (cin >> n, n) {
    vec.clear();
    m.clear();
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      auto it = m.emplace(i, p * q);
      if (!it.second)
        it.first->second += p * q;
      if (it.first->second >= 1000000) {
        s = 1;
        cout << it.first->first << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}