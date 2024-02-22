#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  int n, i;
  while (cin >> n, n) {
    unordered_map<int, long long> m;
    vector<int> vec;
    long long p, q;
    bool s = false;
    while (n--) {
      cin >> i >> p >> q;
      if (m.find(i) == m.end())
        vec.push_back(i);
      m[i] += p * q;
    }
    for (const auto &i : vec) {
      if (m[i] >= 1000000) {
        s = true;
        cout << i << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}