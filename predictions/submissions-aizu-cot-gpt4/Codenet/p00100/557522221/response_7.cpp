#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  int n, i;
  while (cin >> n, n) {
    unordered_map<int, long long> m;
    vector<int> vec;
    vec.reserve(n);  // Reserve space for vector
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      // Avoid unnecessary lookup in the map
      auto [it, inserted] = m.insert({i, 0});
      if(inserted)
        vec.push_back(i);
      it->second += p * q;
    }
    for (int i = 0; i < vec.size(); ++i) {  // Use prefix increment
      long long value = m[vec[i]];
      if (value >= 1000000) {
        s = 1;
        cout << vec[i] << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}