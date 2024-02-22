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
        vec.push_back(i);
      m[i] += p * q;
    }
    for (const auto& i : vec) {  // Use a range-based for loop.
      if (m[i] >= 1000000) {  // Directly access the value using the key.
        s = 1;
        cout << i << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
  return 0;
}