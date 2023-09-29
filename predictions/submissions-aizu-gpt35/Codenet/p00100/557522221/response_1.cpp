#include <iostream>
#include <unordered_map> // Changed from map to unordered_map
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
      if (!m.count(i)) // Changed from !m[i] to !m.count(i)
        vec.push_back(i);
      m[i] += p * q;
    }
    for (int i = 0; i < vec.size(); i++) {
      auto it = m.find(vec[i]); // Using auto keyword for the iterator
      if (it->second >= 1000000) {
        s = 1;
        cout << it->first << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}