#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int main() {
  int n, i;
  while (cin >> n, n) {
    unordered_map<int, long long> m;
    unordered_set<int> vec;
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i])
        vec.insert(i);
      m[i] += p * q;
    }
    for (auto i : vec) {
      if (m[i] >= 1000000) {
        s = 1;
        cout << i << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}