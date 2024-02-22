#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    vector<int> vec;
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i])
        vec.emplace_back(i);
      m[i] += p * q;
    }
    for (auto& v : vec) {
      if (m[v] >= 1000000) {
        s = 1;
        cout << v << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}