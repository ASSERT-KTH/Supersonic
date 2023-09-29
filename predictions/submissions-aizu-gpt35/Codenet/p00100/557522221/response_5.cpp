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
    vec.reserve(n); // reserve memory for vector
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i])
        vec.push_back(i);
      m[i] += p * q;
    }
    for (auto it = vec.begin(); it != vec.end(); it++) { // use auto instead of explicit type
      if (m[*it] >= 1000000) { // directly access map element instead of using iterator
        s = 1;
        cout << *it << endl; // directly print vector element instead of using iterator
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}