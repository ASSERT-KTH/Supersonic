#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    map<int, long long>::iterator it;
    long long s = 0;
    while (n--) {
      cin >> i;
      long long p, q;
      cin >> p >> q;
      if (m.find(i) == m.end()) {
        m[i] = 0;
      }
      m[i] += p * q;
    }
    for (const auto& entry : m) {
      if (entry.second >= 1000000) {
        s = 1;
        cout << entry.first << endl;
      }
    }
    if (!s) {
      cout << "NA" << endl;
    }
  }
}