#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, i;
  while (cin >> n, n) {
    unordered_map<int, long long> m;
    vector<int> vec;
    long long p, q;
    bool s = false;
    while (n--) {
      cin >> i >> p >> q;
      if (!m.count(i))
        vec.push_back(i);
      m[i] += p * q;
      if (m[i] >= 1000000) {
        s = true;
        cout << i << "\n";
      }
    }
    if (!s)
      cout << "NA\n";
  }
}