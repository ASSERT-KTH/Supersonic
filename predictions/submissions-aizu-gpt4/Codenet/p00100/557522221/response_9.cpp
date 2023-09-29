#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  int n, i;
  while (cin >> n, n) {
    unordered_map<int, long long> m;
    vector<int> vec;
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i]) {
        vec.push_back(i);
      }
      m[i] += p * q;
    }
    for (int i : vec) {
      if (m[i] >= 1000000) {
        s = 1;
        cout << i << '\n';
      }
    }
    if (!s)
      cout << "NA" << '\n';
  }
}