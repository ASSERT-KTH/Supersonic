#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      m[i] += p * q;
    }
    for (auto& it : m) {
      if (it.second >= 1000000) {
        s = 1;
        cout << it.first << endl;
        break;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}