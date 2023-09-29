#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n, i;
  while (cin >> n) {
    if (n == 0) {
        break;
    }
    map<int, long long> m;
    vector<int> vec;
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      m[i] += p * q;
    }
    for (const auto& [key, value] : m) {
      if (value >= 1000000) {
        s = 1;
        cout << key << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}