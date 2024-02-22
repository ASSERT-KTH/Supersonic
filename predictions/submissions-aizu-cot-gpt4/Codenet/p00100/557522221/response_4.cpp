#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    vector<int> vec;
    vec.reserve(n); // Reserve space for vector
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i])
        vec.push_back(i);
      m[i] += p * q;
    }
    for (auto i = 0; i < vec.size(); ++i) { // Use prefix increment and 'auto' keyword for iterator
      if (m[vec[i]] >= 1000000) { // Directly access the value from the map
        s = 1;
        cout << vec[i] << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}